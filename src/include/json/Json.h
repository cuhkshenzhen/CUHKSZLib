
#ifndef CUHKSZ_JSON_JSON
#define CUHKSZ_JSON_JSON

#include <deque>
#include <initializer_list>
#include <map>
#include <string>
#include <type_traits>

#include "json/json_functions.h"

namespace cuhksz {

template <typename Container>
class JSONWrapper {
  Container *object;

 public:
  JSONWrapper(Container *val) : object(val) {}
  JSONWrapper(std::nullptr_t) : object(nullptr) {}

  typename Container::iterator begin() {
    return object ? object->begin() : typename Container::iterator();
  }
  typename Container::iterator end() {
    return object ? object->end() : typename Container::iterator();
  }
  typename Container::const_iterator begin() const { return begin(); }
  typename Container::const_iterator end() const { return end(); }
};

template <typename Container>
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

/**
 * Object to save javascript-like data.

  Usage:
  ```
  cuhksz::JSONObject obj;
  ```
 */
class JSONObject {
  /**
   * Use a union to store data and save memory
   */
  union data {
    std::deque<JSONObject> *List;
    std::map<std::string, JSONObject> *Map;
    std::string *String;
    double Float;
    int Int;
    bool Bool;

    data(double value) : Float(value) {}
    data(int value) : Int(value) {}
    data(bool value) : Bool(value) {}
    data(std::string value) : String(new std::string(value)) {}
    data() : Bool(false) {}
  } Data;

 public:
  /**
   * JSON Object types
   */
  enum class Type { Null, Object, Array, String, Float, Integral, Boolean };

  /**
   * Initializer of a new empty JSONObject
   *
   * Example:
   * @code
   * cuhksz::JSONObject obj;
   * @endcode
   */
  JSONObject();

  /**
   * Initialize a new JSONObject with a initializer_list
   *
   * Example:
   * @code
   * cuhksz::JSONObject obj2 = {
      "Key", 1,
      "Key3", true,
      "Key4", nullptr,
      "Key2", {
          "Key4", "VALUE",
          "Arr", cuhksz::JSONObject::Array(1, "Str", false)
      }
    };
   * @endcode
   * @param list std::initializer_list
   */
  JSONObject(std::initializer_list<JSONObject> list);

  /**
   * Copy from another JSONObject
   * @param other copy source
   */
  JSONObject(JSONObject &&other);

  /**
   * Construct bool JSON object
   * @tparam T: bool
   * @param b: boolean value
   */
  template <typename T>
  JSONObject(
      T b,
      typename std::enable_if<std::is_same<T, bool>::value>::type * = nullptr)
      : Data(b), objType(Type::Boolean) {}

  /**
   * Construct integral JSON object
   * @tparam T: integral-like types, like char, int, long, etc
   * @param i: integral value
   */
  template <typename T>
  JSONObject(
      T i,
      typename std::enable_if<std::is_integral<T>::value &&
                              !std::is_same<T, bool>::value>::type * = nullptr)
      : Data((int)i), objType(Type::Integral) {}

  /**
   * Construct float-number JSON object
   * @tparam T: float, double, etc
   * @param f: number
   */
  template <typename T>
  JSONObject(T f,
             typename std::enable_if<std::is_floating_point<T>::value>::type * =
                 nullptr)
      : Data((double)f), objType(Type::Float) {}

  /**
   * Construct string-type JSON object
   * @tparam T: string-like types, like [const] char *, [const] char[],
   * std::string, etc
   * @param s: string
   */
  template <typename T>
  JSONObject(T s,
             typename std::enable_if<
                 std::is_convertible<T, std::string>::value>::type * = nullptr)
      : Data(std::string(s)), objType(Type::String) {}

  /**
   * Construct null-type JSON object
   */
  JSONObject(std::nullptr_t) : Data(), objType(Type::Null) {}

  /**
   * Destruct the JSON object. Usually internal usage only.
   */
  ~JSONObject();

  // Copy Operator
  JSONObject &operator=(JSONObject &&src);
  JSONObject &operator=(const JSONObject &src);
  JSONObject(const JSONObject &src);

  // Equal Operator
  template <typename T, typename std::enable_if<
                            std::is_same<T, bool>::value>::type * = nullptr>
  JSONObject operator=(T bool_value) {
    setType(Type::Boolean);
    Data.Bool = bool_value;
    return *this;
  }

  template <typename T, typename std::enable_if<
                            std::is_integral<T>::value &&
                            !std::is_same<T, bool>::value>::type * = nullptr>
  JSONObject operator=(T value) {
    setType(Type::Integral);
    Data.Int = value;
    return *this;
  }

  template <typename T, typename std::enable_if<
                            std::is_floating_point<T>::value>::type * = nullptr>
  JSONObject operator=(T value) {
    setType(Type::Float);
    Data.Float = value;
    return *this;
  }

  template <typename T, typename std::enable_if<std::is_convertible<
                            T, std::string>::value>::type * = nullptr>
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

  template <typename T>
  void append(T arg) {
    setType(Type::Array);
    Data.List->emplace_back(arg);
  }

  template <typename T, typename... U>
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
    return objType == Type::Object
               ? JSONWrapper<std::map<std::string, JSONObject>>(Data.Map)
               : JSONWrapper<std::map<std::string, JSONObject>>(nullptr);
  }

  JSONWrapper<std::deque<JSONObject>> ArrayRange() {
    return objType == Type::Array
               ? JSONWrapper<std::deque<JSONObject>>(Data.List)
               : JSONWrapper<std::deque<JSONObject>>(nullptr);
  }

  JSONConstWrapper<std::map<std::string, JSONObject>> ObjectRange() const {
    return objType == Type::Object
               ? JSONConstWrapper<std::map<std::string, JSONObject>>(Data.Map)
               : JSONConstWrapper<std::map<std::string, JSONObject>>(nullptr);
  }

  JSONConstWrapper<std::deque<JSONObject>> ArrayRange() const {
    return objType == Type::Array
               ? JSONConstWrapper<std::deque<JSONObject>>(Data.List)
               : JSONConstWrapper<std::deque<JSONObject>>(nullptr);
  }

  bool isNull() const { return objType == Type::Null; }

  std::string dump(int depth = 1, std::string tab = "  ") const;

  friend std::ostream &operator<<(std::ostream &os, const JSONObject &json);

  /**
   * Empty JSON array
   * @return JSONObject
   */
  static JSONObject Array();

  /**
   * Load data into a new JSON array
   *
   * Example:
   * @code
   * cuhksz::JSONObject::Array(true, "Two", 3, 4.0)
   * @endcode
   * @tparam T Type of the First Data to Load
   * @param args data to load
   * @return JSONObject, array type
   */
  template <typename... T>
  static JSONObject Array(T... args) {
    JSONObject arr = JSONObject::Build(JSONObject::Type::Array);
    arr.append(args...);
    return arr;
  }

  /**
   * Build an empty JSON object.
   * @return
   */
  static JSONObject Object();

 private:
  void clearData();
  void setType(Type type);

  Type objType = Type::Null;
};

// Parsers

/*!
 * Load JSON from string
 *
 * @code
 * std::string json = R"({
 *   "array" : [true, "Two", 3, 4.000000],
 *   "array2" : [false, "three"],
 *   "new" : {
 *      "some" : {
 *          "deep" : {
 *              "key" : "Value"
 *          }
 *      }
 *   },
 *   "obj" : {
 *      "inner" : "Inside"
 *   },
 *   "parsed" : [{
 *      "Key" : "Value"
 *   }, false]
 * })";
 * auto jsonObject = cuhksz::loadJSON(json);
 * @endcode
 * @param str valid JSON string
 * @return JSONObject, containing all information in the string
 */
JSONObject loadJSON(const std::string &str);

}  // namespace cuhksz

#endif  // CUHKSZ_JSON_JSON

// Code adopted from https://github.com/nbsdx/SimpleJSON
