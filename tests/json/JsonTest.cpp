#include <string>

#include "json/Json.h"

#include "gtest/gtest.h"

TEST(Json, DumpJson) {
  cuhksz::JSONObject obj;
  // Create a new Array as a field of an Object.
  obj["array"] = cuhksz::JSONObject::Array(true, "Two", 3, 4.0);

  // Create a new Object as a field of another Object.
  obj["obj"] = cuhksz::JSONObject::Object();
  // Assign to one of the inner object's fields
  obj["obj"]["inner"] = "Inside";

  // We don't need to specify the type of the JSON object:
  obj["new"]["some"]["deep"]["key"] = "Value";
  obj["array2"].append(false, "three");

  // We can also parse a string into a JSON object:
  obj["parsed"] = cuhksz::loadJSON("[ { \"Key\" : \"Value\" }, false ]");

  std::string result = R"({
  "array" : [true, "Two", 3, 4.000000],
  "array2" : [false, "three"],
  "new" : {
    "some" : {
      "deep" : {
        "key" : "Value"
      }
    }
  },
  "obj" : {
    "inner" : "Inside"
  },
  "parsed" : [{
      "Key" : "Value"
    }, false]
})";
  std::string dump = obj.dump();
  EXPECT_EQ(dump, result);
  std::stringstream operatorDump;
  operatorDump << obj;
  EXPECT_EQ(operatorDump.str(), result);
}

TEST(Json, LoadJson) {
  std::string json = R"({
  "array" : [true, "Two", 3, 4.000000],
  "array2" : [false, "three"],
  "new" : {
    "some" : {
      "deep" : {
        "key" : "Value"
      }
    }
  },
  "obj" : {
    "inner" : "Inside"
  },
  "parsed" : [{
      "Key" : "Value"
    }, false]
})";
  auto jsonObject = cuhksz::loadJSON(json);
  EXPECT_EQ((std::string)jsonObject["new"]["some"]["deep"]["key"], "Value");
}

TEST(Json, loadWithInitList) {
  cuhksz::JSONObject obj = {
      "array",  cuhksz::JSONObject::Array(true, "Two", 3, 4.0),
      "obj",    {"inner", "Inside"},
      "new",    {"some", {"deep", {"key", "Value"}}},
      "array2", cuhksz::JSONObject::Array(false, "three"),
      "s",      "string"};
  cuhksz::JSONObject obj2 = {
      "Key",
      1,
      "Key3",
      true,
      "Key4",
      nullptr,
      "Key2",
      {"Key4", "VALUE", "Arr", cuhksz::JSONObject::Array(1, "Str", false)}};
  EXPECT_EQ((std::string)obj["obj"]["inner"], "Inside");
  EXPECT_EQ((bool)obj2["Key3"], true);
}

TEST(Json, arrayTest) {
  cuhksz::JSONObject array;

  array[2] = "Test2";
  array[1] = "Test1";
  array[0] = "Test0";
  array[3] = "Test4";
  EXPECT_EQ((std::string)array[0], "Test0");
  EXPECT_EQ((std::string)array[1], "Test1");
  EXPECT_EQ((std::string)array[2], "Test2");
  EXPECT_EQ((std::string)array[3], "Test4");

  // Arrays can be nested:
  cuhksz::JSONObject Array2;

  Array2[2][0][1] = true;

  EXPECT_EQ((bool)Array2[2][0][1], true);
}

TEST(Json, primTest) {
  cuhksz::JSONObject obj;
  obj = false;
  EXPECT_EQ((bool)obj, false);
  obj = "Test String";
  EXPECT_EQ((std::string)obj, "Test String");
  obj = 2.2;
  EXPECT_NEAR((float)obj, (float)2.2, 0.0001);
  obj = 3;
  EXPECT_EQ((int)obj, 3);
}

TEST(Json, iterTest) {
  cuhksz::JSONObject array =
      cuhksz::JSONObject::Build(cuhksz::JSONObject::Type::Array);
  cuhksz::JSONObject obj =
      cuhksz::JSONObject::Build(cuhksz::JSONObject::Type::Object);

  array[0] = "Test0";
  array[1] = "Test1";
  array[2] = "Test2";
  array[3] = "Test3";

  obj["Key0"] = "Value0";
  obj["Key1"] = "Value1";
  obj["Key2"] = "Value2";

  int count = 0;
  for (auto &j : array.ArrayRange()) {
    EXPECT_EQ((std::string)j, std::string("Test") + std::to_string(count++));
  }

  count = 0;
  for (auto &j : obj.ObjectRange()) {
    EXPECT_EQ((std::string)j.first, std::string("Key") + std::to_string(count));
    EXPECT_EQ((std::string)j.second,
              std::string("Value") + std::to_string(count++));
  }
}

TEST(Json, loadJSONFailure) {
  std::string json = R"({"array" : ][true, "Two", 3, 4.000000],)";
  EXPECT_EXIT(cuhksz::loadJSON(json), ::testing::ExitedWithCode(1), ".* Parse: Unknown starting character .*");

  json = R"({"array" : [true, "Two[】"3, 4.000000]})";
  EXPECT_EXIT(cuhksz::loadJSON(json), ::testing::ExitedWithCode(1), ".*Array: Expected.*");

  json = R"({"array", [true, "Two[】"3, 4.000000]})";
  EXPECT_EXIT(cuhksz::loadJSON(json), ::testing::ExitedWithCode(1), ".*Object: Expected colon.*");

  json = R"({"array": [true, "Two[】", 3, 4.000000]/})";
  EXPECT_EXIT(cuhksz::loadJSON(json), ::testing::ExitedWithCode(1), ".*Object: Expected comma.*");

  json = R"({"array": [true, "Two[】\u%9P", 3, 4.000000]})";
  EXPECT_EXIT(cuhksz::loadJSON(json),
              ::testing::ExitedWithCode(1),
              ".*String: Expected hex character in unicode escape.*");

  json = R"({"array": [trlue, "Two[】\u%9P", 3, 4.000000]})";
  EXPECT_EXIT(cuhksz::loadJSON(json), ::testing::ExitedWithCode(1), ".*Bool: Expected 'true' or 'false', found.*");
}