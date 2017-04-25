#include "json/Json.h"
#include "gtest/gtest.h"

TEST(Json, DumpJson) {
  cuhksz::JSON::JSONObject obj;
  // Create a new Array as a field of an Object.
  obj["array"] = cuhksz::JSON::Array( true, "Two", 3, 4.0 );
  // Create a new Object as a field of another Object.
  obj["obj"] = cuhksz::JSON::Object();
  // Assign to one of the inner object's fields
  obj["obj"]["inner"] = "Inside";

  // We don't need to specify the type of the JSON object:
  obj["new"]["some"]["deep"]["key"] = "Value";
  obj["array2"].append( false, "three" );

  // We can also parse a string into a JSON object:
  obj["parsed"] = cuhksz::JSON::load( "[ { \"Key\" : \"Value\" }, false ]" );

  std::string result = "{\n"
      "  \"array\" : [true, \"Two\", 3, 4.000000],\n"
      "  \"array2\" : [false, \"three\"],\n"
      "  \"new\" : {\n"
      "    \"some\" : {\n"
      "      \"deep\" : {\n"
      "        \"key\" : \"Value\"\n"
      "      }\n"
      "    }\n"
      "  },\n"
      "  \"obj\" : {\n"
      "    \"inner\" : \"Inside\"\n"
      "  },\n"
      "  \"parsed\" : [{\n"
      "      \"Key\" : \"Value\"\n"
      "    }, false]\n"
      "}";
  std::string dump = obj.dump();
  EXPECT_EQ(dump, result);
}

TEST(Json, LoadJson) {
  std::string json = "{\n"
      "  \"array\" : [true, \"Two\", 3, 4.000000],\n"
      "  \"array2\" : [false, \"three\"],\n"
      "  \"new\" : {\n"
      "    \"some\" : {\n"
      "      \"deep\" : {\n"
      "        \"key\" : \"Value\"\n"
      "      }\n"
      "    }\n"
      "  },\n"
      "  \"obj\" : {\n"
      "    \"inner\" : \"Inside\"\n"
      "  },\n"
      "  \"parsed\" : [{\n"
      "      \"Key\" : \"Value\"\n"
      "    }, false]\n"
      "}";
  auto jsonObject = cuhksz::JSON::load(json);
  EXPECT_EQ((std::string)jsonObject["new"]["some"]["deep"]["key"], "Value");
}

TEST(Json, loadWithInitList) {
  cuhksz::JSON::JSONObject obj = {
      "array", cuhksz::JSON::Array( true, "Two", 3, 4.0 ),
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
      "array2", cuhksz::JSON::Array( false, "three" ),
      "s", "string"
  };
  EXPECT_EQ((std::string)obj["obj"]["inner"], "Inside");
}