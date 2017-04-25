
#ifndef CUHKSZ_JSON_JSON
#define CUHKSZ_JSON_JSON

#include <string>
#include <deque>
#include <initializer_list>
#include <map>
#include <type_traits>
#include "json_functions.h"

namespace cuhksz {
namespace JSON {
template<typename Container>
class JSONWrapper {
  Container *object;

 public:
  JSONWrapper(Container *val) : object(val) {}
  JSONWrapper(std::nullptr_t) : object(nullptr) {}

  typename Container::iterator begin() { return object ? object->begin() : typename Container::iterator(); }
  typename Container::iterator end() { return object ? object->end() : typename Container::iterator(); }
  typename Container::const_iterator begin() const { return begin(); }
  typename Container::const_iterator end() const { return end(); }
};

template<typename Container>
class JSONConstWrapper {
  const Container *object;

 public:
  JSONConstWrapper(const Container *val) : object(val) {}
  JSONConstWrapper(std::nullptr_t) : object(nullptr) {}

  typename Container::const_iterator begin() const {
    return object ? object->begin() : typename Container::const_iterator();
  }
  typename Container::const_iterator end() const {
    return object ? object->end() : typename Container::const_iterator();
  }
};

class JSONObject {
  union data {
    std::deque<JSONObject> *List;
    std::map<std::string, JSONObject> *Map;
    std::string *String;
    double Float;
    int Int;
    bool Bool;

    data(double value) : Float(value) {};
    data(int value) : Int(value) {};
    data(bool value) : Bool(value) {};
    data(std::string value) : String(new std::string(value)) {};
    data() : Bool(false) {};

  } Data;
 public:
  enum class Type {
    Null,
    Object,
    Array,
    String,
    Float,
    Integral,
    Boolean
  };

  // Initializers
  JSONObject();
  JSONObject(std::initializer_list<JSONObject> list);
  JSONObject(JSONObject &&other);

  template<typename T>
  JSONObject(T b, typename std::enable_if<std::is_same<T, bool>::value>::type * = nullptr)
      : Data(b), objType(Type::Boolean) {}

  template<typename T>
  JSONObject(T i,
             typename std::enable_if<std::is_integral<T>::value && !std::is_same<T, bool>::value>::type * = nullptr)
      : Data((int) i), objType(Type::Integral) {}

  template<typename T>
  JSONObject(T f, typename std::enable_if<std::is_floating_point<T>::value>::type * = nullptr)
      : Data((double) f), objType(Type::Float) {}

  template<typename T>
  JSONObject(T s, typename std::enable_if<std::is_convertible<T, std::string>::value>::type * = nullptr)
      : Data(std::string(s)), objType(Type::String) {}

  JSONObject(std::nullptr_t) : Data(), objType(Type::Null) {}

  // Destructor
  ~JSONObject();

  // Copy Operator
  JSONObject &operator=(JSONObject &&src);
  JSONObject &operator=(const JSONObject &src);
  JSONObject(const JSONObject &src);

  // Equal Operator
  template<typename T, typename std::enable_if<std::is_same<T, bool>::value>::type * = nullptr>
  JSONObject operator=(T bool_value) {
    setType(Type::Boolean);
    Data.Bool = bool_value;
    return *this;
  }

  template<typename T, typename std::enable_if<
      std::is_integral<T>::value && !std::is_same<T, bool>::value>::type * = nullptr>
  JSONObject operator=(T value) {
    setType(Type::Integral);
    Data.Int = value;
    return *this;
  }

  template<typename T, typename std::enable_if<std::is_floating_point<T>::value>::type * = nullptr>
  JSONObject operator=(T value) {
    setType(Type::Float);
    Data.Float = value;
    return *this;
  }

  template<typename T, typename std::enable_if<std::is_convertible<T, std::string>::value>::type * = nullptr>
  JSONObject operator=(T value) {
    setType(Type::String);
    *Data.String = std::string(value);
    return *this;
  }

  // Subscript Operator
  JSONObject &operator[](const char key[]);
  JSONObject &operator[](const std::string &key);
  JSONObject &operator[](int index);
  JSONObject &at(const std::string &key);
  const JSONObject &at(const std::string &key) const;
  JSONObject &at(unsigned index);
  const JSONObject &at(unsigned index) const;

  template<typename T>
  void append(T arg) {
    setType(Type::Array);
    Data.List->emplace_back(arg);
  }

  template<typename T, typename... U>
  void append(T arg, U... args) {
    append(arg);
    append(args...);
  }

  unsigned long length() const;
  unsigned long size() const;

  bool hasKey(const std::string &key) const;

  static JSONObject Build(Type type) {
    JSONObject ret;
    ret.setType(type);
    return ret;
  }

  std::string toString() const;
  double toDouble() const;
  float toFloat() const;
  int toInt() const;
  long toLong() const;
  bool toBool() const;

  operator std::string() const;
  operator float() const;
  operator double() const;
  operator long() const;
  operator int() const;
  operator bool() const;

  Type getType() const { return objType; }

  JSONWrapper<std::map<std::string, JSONObject>> ObjectRange() {
    return objType == Type::Object ?
           JSONWrapper<std::map<std::string, JSONObject>>(Data.Map) :
           JSONWrapper<std::map<std::string, JSONObject>>(nullptr);
  }

  JSONWrapper<std::deque<JSONObject>> ArrayRange() {
    return objType == Type::Array ?
           JSONWrapper<std::deque<JSONObject>>(Data.List) :
           JSONWrapper<std::deque<JSONObject>>(nullptr);
  }

  JSONConstWrapper<std::map<std::string, JSONObject>> ObjectRange() const {
    return objType == Type::Object ?
           JSONConstWrapper<std::map<std::string, JSONObject>>(Data.Map) :
           JSONConstWrapper<std::map<std::string, JSONObject>>(nullptr);
  }

  JSONConstWrapper<std::deque<JSONObject>> ArrayRange() const {
    return objType == Type::Array ?
           JSONConstWrapper<std::deque<JSONObject>>(Data.List) :
           JSONConstWrapper<std::deque<JSONObject>>(nullptr);
  }

  bool isNull() const { return objType == Type::Null; }

  std::string dump(int depth = 1, std::string tab = "  ") const;

  friend std::ostream &operator<<(std::ostream &os, const JSONObject &json);

 private:
  void clearData();
  void setType(Type type);

  Type objType = Type::Null;
};

// Parsers
void skip_whitespaces(const std::string &str, size_t &offset);

JSONObject parse_object(const std::string &str, size_t &offset);
JSONObject parse_array(const std::string &str, size_t &offset);
JSONObject parse_string(const std::string &str, size_t &offset);
JSONObject parse_number(const std::string &str, size_t &offset);
JSONObject parse_bool(const std::string &str, size_t &offset);
JSONObject parse_null(const std::string &str, size_t &offset);
JSONObject parse_next(const std::string &str, size_t &offset);
JSONObject load(const std::string &str);

// Objects
JSONObject Array();

template<typename... T>
JSONObject Array(T... args) {
  JSONObject arr = JSONObject::Build(JSONObject::Type::Array);
  arr.append(args...);
  return arr;
}

JSONObject Object();

};

}

#endif //CUHKSZ_JSON_JSON

// Code adopted from https://github.com/nbsdx/SimpleJSON