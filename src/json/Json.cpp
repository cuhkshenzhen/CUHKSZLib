#include <string>
#include <deque>
#include <map>
#include <cmath>
#include "json/Json.h"
#include "string_utils.h"
#include "utils.h"

namespace cuhksz {
namespace JSON {
JSONObject::JSONObject() : Data(), Type(Type::Null) {}

JSONObject::JSONObject(std::deque<JSONObject> list)
    : JSONObject() {
  setType(Type::Object);
  for (auto i = list.begin(), e = list.end(); i != e; ++i, ++i)
    operator[](i->toString()) = *std::next(i);
}

JSONObject::JSONObject(JSONObject &&other)
    : Data(other.Data), Type(other.Type) {
  other.Type = Type::Null;
  other.Data.Map = nullptr;
}

JSONObject::~JSONObject() {
  clearData();
}

void JSONObject::setType(enum Type type) {
  if (type == Type)
    return;

  clearData();

  switch (type) {
    case Type::Null: Data.Map = nullptr;
      break;
    case Type::Object: Data.Map = new std::map<std::string, JSONObject>();
      break;
    case Type::Array: Data.List = new std::deque<JSONObject>();
      break;
    case Type::String: Data.String = new std::string();
      break;
    case Type::Float: Data.Float = 0.0;
      break;
    case Type::Integral: Data.Int = 0;
      break;
    case Type::Boolean: Data.Bool = false;
      break;
  }
  Type = type;
}

void JSONObject::clearData() {
  switch (Type) {
    case Type::Object: delete Data.Map;
      break;
    case Type::Array: delete Data.List;
      break;
    case Type::String: delete Data.String;
      break;
    default:;
  }
};

JSONObject::JSONObject(const JSONObject &src) {
  switch (src.Type) {
    case Type::Object:
      Data.Map = new std::map<std::string, JSONObject>(src.Data.Map->begin(),
                                                       src.Data.Map->end());
      break;
    case Type::Array:
      Data.List = new std::deque<JSONObject>(src.Data.List->begin(),
                                             src.Data.List->end());
      break;
    case Type::String:Data.String = new std::string(*src.Data.String);
      break;
    default:Data = src.Data;
  }
  Type = src.Type;
}

JSONObject &JSONObject::operator=(JSONObject &&src) {

  clearData();
  Data = src.Data;
  Type = src.Type;
  src.Data.Map = nullptr;
  src.Type = Type::Null;
  return *this;

}

JSONObject &JSONObject::operator=(JSONObject &src) {
  clearData();
  switch (src.Type) {
    case Type::Object:
      Data.Map = new std::map<std::string, JSONObject>(src.Data.Map->begin(),
                                                       src.Data.Map->end());
      break;
    case Type::Array:
      Data.List = new std::deque<JSONObject>(src.Data.List->begin(),
                                             src.Data.List->end());
      break;
    case Type::String:Data.String = new std::string(*src.Data.String);
      break;
    default:Data = src.Data;
  }
  Type = src.Type;
  return *this;
}

JSONObject &JSONObject::operator[](const char key[]) {
  setType(Type::Object);
  return Data.Map->operator[](std::string(key));
}

JSONObject &JSONObject::operator[](const std::string &key) {
  setType(Type::Object);
  return Data.Map->operator[](key);
}

JSONObject &JSONObject::operator[](int index) {
  setType(Type::Array);
  if (index >= (int) Data.List->size()) Data.List->resize(index + 1);
  return Data.List->operator[](index);
}

JSONObject &JSONObject::at(const std::string &key) {
  return operator[](key);
}

const JSONObject &JSONObject::at(const std::string &key) const {
  return Data.Map->operator[](key);
}

JSONObject &JSONObject::at(unsigned index) {
  return operator[](index);
}

const JSONObject &JSONObject::at(unsigned index) const {
  return Data.List->at(index);
}

unsigned long JSONObject::length() const {
  if (Type == Type::Array)
    return Data.List->size();
  else
    return (unsigned long) -1;
}

bool JSONObject::hasKey(const std::string &key) const {
  if (Type == Type::Object)
    return Data.Map->find(key) != Data.Map->end();
  return false;
}

unsigned long JSONObject::size() const {
  if (Type == Type::Object)
    return Data.Map->size();
  else if (Type == Type::Array)
    return Data.List->size();
  else
    return (unsigned long) -1;
}

std::string JSONObject::toString() const {
  return Type == Type::String ? jsonEscape(*Data.String) : std::string("");
}

double JSONObject::toDouble() const {
  return Type == Type::Float ? Data.Float : 0.0;
}

float JSONObject::toFloat() const {
  return (float) (Type == Type::Float ? Data.Float : 0.0);
}

int JSONObject::toInt() const {
  return Type == Type::Integral ? Data.Int : 0;
}

long JSONObject::toLong() const {
  return (long) (Type == Type::Integral ? Data.Int : 0);
}

bool JSONObject::toBool() const {
  return Type == Type::Boolean ? Data.Bool : false;
}

JSONObject::operator std::string() const {
  return toString();
}

JSONObject::operator float() const {
  return toFloat();
}

JSONObject::operator double() const {
  return toDouble();
}

JSONObject::operator long() const {
  return toLong();
}

JSONObject::operator int() const {
  return toInt();
}

JSONObject::operator bool() const {
  return toBool();
}

std::string JSONObject::dump(int depth, std::string tab) const {
  std::string pad = "";
  for (int i = 0; i < depth; ++i, pad += tab);

  switch (Type) {
    case Type::Null:return "null";
    case Type::Object: {
      std::string s = "{\n";
      bool skip = true;
      for (auto &p : *Data.Map) {
        if (!skip) s += ",\n";
        s += (pad + "\"" + p.first + "\" : " + p.second.dump(depth + 1, tab));
        skip = false;
      }
      s += ("\n" + pad.erase(0, 2) + "}");
      return s;
    }
    case Type::Array: {
      std::string s = "[";
      bool skip = true;
      for (auto &p : *Data.List) {
        if (!skip) s += ", ";
        s += p.dump(depth + 1, tab);
        skip = false;
      }
      s += "]";
      return s;
    }
    case Type::String:return "\"" + jsonEscape(*Data.String) + "\"";
    case Type::Float:return std::to_string(Data.Float);
    case Type::Integral:return std::to_string(Data.Int);
    case Type::Boolean:return Data.Bool ? "true" : "false";
    default:return "";
  }
  return "";
}

void skip_whitespaces(const std::string &str, size_t &offset) {
  while (isspace(str[offset])) ++offset;
}

JSONObject parse_object(const std::string &str, size_t &offset) {
  JSONObject Object = JSONObject::Build(JSONObject::Type::Object);

  ++offset;
  skip_whitespaces(str, offset);
  if (str[offset] == '}') {
    ++offset;
    return Object;
  }

  while (true) {
    JSONObject Key = parse_next(str, offset);
    skip_whitespaces(str, offset);
    if (str[offset] != ':') {
      cuhksz::error("ERROR: Object: Expected colon, found '" + std::string(1, str[offset]) + "'");
      break;
    }
    skip_whitespaces(str, ++offset);
    JSONObject Value = parse_next(str, offset);
    Object[Key.toString()] = Value;

    skip_whitespaces(str, offset);
    if (str[offset] == ',') {
      ++offset;
      continue;
    } else if (str[offset] == '}') {
      ++offset;
      break;
    } else {
      cuhksz::error("ERROR: Object: Expected comma, found '" + std::string(1, str[offset]) + "'");
      break;
    }
  }

  return Object;
}

JSONObject parse_array(const std::string &str, size_t &offset) {
  JSONObject Array = JSONObject::Build(JSONObject::Type::Array);
  unsigned index = 0;

  ++offset;
  skip_whitespaces(str, offset);
  if (str[offset] == ']') {
    ++offset;
    return Array;
  }

  while (true) {
    Array[index++] = parse_next(str, offset);
    skip_whitespaces(str, offset);

    if (str[offset] == ',') {
      ++offset;
      continue;
    } else if (str[offset] == ']') {
      ++offset;
      break;
    } else {
      cuhksz::error("Array: Expected ',' or ']', found '" + std::string(1, str[offset]) + "'");
    }
  }

  return Array;
}

JSONObject parse_string(const std::string &str, size_t &offset) {
  JSONObject String;
  std::string val;
  for (char c = str[++offset]; c != '\"'; c = str[++offset]) {
    if (c == '\\') {
      switch (str[++offset]) {
        case '\"': val += '\"';
          break;
        case '\\': val += '\\';
          break;
        case '/' : val += '/';
          break;
        case 'b' : val += '\b';
          break;
        case 'f' : val += '\f';
          break;
        case 'n' : val += '\n';
          break;
        case 'r' : val += '\r';
          break;
        case 't' : val += '\t';
          break;
        case 'u' : {
          val += "\\u";
          for (unsigned i = 1; i <= 4; ++i) {
            c = str[offset + i];
            if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
              val += c;
            else {
              cuhksz::error("String: Expected hex character in unicode escape, found '" + std::string(1, c) + "'");
            }
          }
          offset += 4;
        }
          break;
        default  : val += '\\';
          break;
      }
    } else
      val += c;
  }
  ++offset;
  String = val;
  return String;
}

JSONObject parse_number(const std::string &str, size_t &offset) {
  JSONObject Number;
  std::string val, exp_str;
  char c;
  bool isDouble = false;
  long exp = 0;
  while (true) {
    c = str[offset++];
    if ((c == '-') || (c >= '0' && c <= '9'))
      val += c;
    else if (c == '.') {
      val += c;
      isDouble = true;
    } else
      break;
  }
  if (c == 'E' || c == 'e') {
    c = str[offset++];
    if (c == '-') {
      ++offset;
      exp_str += '-';
    }
    while (true) {
      c = str[offset++];
      if (c >= '0' && c <= '9')
        exp_str += c;
      else if (!isspace(c) && c != ',' && c != ']' && c != '}') {
        cuhksz::error("Number: Expected a number for exponent, found '" + std::string(1, c) + "'");
      } else
        break;
    }
    exp = cuhksz::stringCast<long>(exp_str);
  } else if (!isspace(c) && c != ',' && c != ']' && c != '}') {
    cuhksz::error("Number: unexpected character '" + std::string(1, c) + "'");
  }
  --offset;

  if (isDouble)
    Number = (int) cuhksz::stringCast<int>(val) * std::pow(10, exp);
  else if (!exp_str.empty())
    Number = (int) cuhksz::stringCast<int>(val) * std::pow(10, exp);
  else
    Number = (int) cuhksz::stringCast<int>(val);
  return Number;
}

JSONObject parse_bool(const std::string &str, size_t &offset) {
  JSONObject Bool;
  if (str.substr(offset, 4) == "true")
    Bool = true;
  else if (str.substr(offset, 5) == "false")
    Bool = false;
  else {
    cuhksz::error("Bool: Expected 'true' or 'false', found '" + str.substr(offset, 5) + "'");
  }
  offset += (Bool.toBool() ? 4 : 5);
  return Bool;
}

JSONObject parse_null(const std::string &str, size_t &offset) {
  JSONObject Null;
  if (str.substr(offset, 4) != "null") cuhksz::error("Null: Expected 'null', found '" + str.substr(offset, 4) + "'");
  offset += 4;
  return Null;
}

JSONObject parse_next(const std::string &str, size_t &offset) {
  char value;
  skip_whitespaces(str, offset);
  value = str[offset];
  switch (value) {
    case '[' : return parse_array(str, offset);
    case '{' : return parse_object(str, offset);
    case '\"': return parse_string(str, offset);
    case 't' :
    case 'f' : return parse_bool(str, offset);
    case 'n' : return parse_null(str, offset);
    default  :
      if ((value <= '9' && value >= '0') || value == '-')
        return parse_number(str, offset);
  }
  cuhksz::error("Parse: Unknown starting character '" + std::string(1, value) + "'");
  return JSONObject();
}

JSONObject load(const std::string &str) {
  size_t offset = 0;
  return parse_next(str, offset);
}

std::ostream &operator<<(std::ostream &os, const JSONObject &json) {
  os << json.dump();
  return os;
}

JSONObject Array() {
  return JSONObject::Build(JSONObject::Type::Array);
}

JSONObject Object() {
  return JSONObject::Build(JSONObject::Type::Object);
}
}
}