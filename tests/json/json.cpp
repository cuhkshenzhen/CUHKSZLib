#include "json/Json.h"
#include "gtest/gtest.h"

TEST(Json, DumpJson) {
  cuhksz::JSON::JSONObject obj;
  // Create a new Array as a field of an Object.
  obj["array"] = cuhksz::JSON::Array(true, "Two", 3, 4.0);
  // Create a new Object as a field of another Object.
  obj["obj"] = cuhksz::JSON::Object();
  // Assign to one of the inner object's fields
  obj["obj"]["inner"] = "Inside";

  // We don't need to specify the type of the JSON object:
  obj["new"]["some"]["deep"]["key"] = "Value";
  obj["array2"].append(false, "three");

  // We can also parse a string into a JSON object:
  obj["parsed"] = cuhksz::JSON::load("[ { \"Key\" : \"Value\" }, false ]");

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
  auto jsonObject = cuhksz::JSON::load(json);
  EXPECT_EQ((std::string) jsonObject["new"]["some"]["deep"]["key"], "Value");
}

TEST(Json, loadWithInitList) {
  cuhksz::JSON::JSONObject obj = {
      "array", cuhksz::JSON::Array(true, "Two", 3, 4.0),
      "obj", {
          "inner", "Inside"
      },
      "new", {
          "some", {
              "deep", {
                  "key", "Value"
              }
          }
      },
      "array2", cuhksz::JSON::Array(false, "three"),
      "s", "string"
  };
  cuhksz::JSON::JSONObject obj2 = {
      "Key", 1,
      "Key3", true,
      "Key4", nullptr,
      "Key2", {
          "Key4", "VALUE",
          "Arr", cuhksz::JSON::Array(1, "Str", false)
      }
  };
  EXPECT_EQ((std::string) obj["obj"]["inner"], "Inside");
  EXPECT_EQ((bool) obj2["Key3"], true);
}

TEST(Json, arrayTest) {
  cuhksz::JSON::JSONObject array;

  array[2] = "Test2";
  array[1] = "Test1";
  array[0] = "Test0";
  array[3] = "Test4";
  EXPECT_EQ((std::string) array[0], "Test0");
  EXPECT_EQ((std::string) array[1], "Test1");
  EXPECT_EQ((std::string) array[2], "Test2");
  EXPECT_EQ((std::string) array[3], "Test4");


  // Arrays can be nested:
  cuhksz::JSON::JSONObject Array2;

  Array2[2][0][1] = true;

  EXPECT_EQ((bool) Array2[2][0][1], true);

}

TEST(Json, primTest) {
  cuhksz::JSON::JSONObject obj;
  obj = false;
  EXPECT_EQ((bool)obj, false);
  obj = "Test String";
  EXPECT_EQ((std::string)obj, "Test String");
  obj = 2.2;
  EXPECT_NEAR((float)obj, (float)2.2, 0.0001);
  obj = 3;
  EXPECT_EQ((int)obj, 3);
}