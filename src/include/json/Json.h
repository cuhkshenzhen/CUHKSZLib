#ifndef CUHKSZ_JSON_JSON
#define CUHKSZ_JSON_JSON

#include <deque>
#include <initializer_list>
#include <map>
#include <string>
#include <type_traits>

#include "json/json_functions.h"

namespace cuhksz {

/**
 * Iterator to support range-based for loop
 */
template <typename Container>
class JSONIterator {
  Container *object;

 public:
  explicit JSONIterator(Container *val) : object(val) {}
  explicit JSONIterator(std::nullptr_t) : object(nullptr) {}

  typename Container::iterator begin() {
    return object ? object->begin() : typename Container::iterator();
  }
  typename Container::iterator end() {
    return object ? object->end() : typename Container::iterator();
  }
  typename Container::const_iterator begin() const { return begin(); }
  typename Container::const_iterator end() const { return end(); }
};

/**
 * Const iterator to support range-based for loop
 */
template <typename Container>
class JSONConstIterator {
  const Container *object;

 public:
  explicit JSONConstIterator(const Container *val) : object(val) {}
  explicit JSONConstIterator(std::nullptr_t) : object(nullptr) {}

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
  /**
   * Copy from another JSONObject.
   * @param src Source object
   * @return this
   */
  JSONObject &operator=(JSONObject &&src);

  /**
   * Copy from another JSONObject.
   * @param src Source object
   * @return this
   */
  JSONObject &operator=(const JSONObject &src);

  /**
   * Copy constructor. Deep copying from another JSONObject.
   * @param src Source object
   */
  JSONObject(const JSONObject &src);

  /**
   * Load a bool into the JSONObject.
   * @tparam T Bool
   * @param bool_value Value of the bool variable
   * @return *this
   */
  template <typename T, typename std::enable_if<
                            std::is_same<T, bool>::value>::type * = nullptr>
  JSONObject operator=(T bool_value) {
    setType(Type::Boolean);
    Data.Bool = bool_value;
    return *this;
  }

  /**
   * Load a integral number (int) into the JSONObject.
   * @tparam T Integral-like type
   * @param value Value of the integral number
   * @return *this
   */
  template <typename T, typename std::enable_if<
                            std::is_integral<T>::value &&
                            !std::is_same<T, bool>::value>::type * = nullptr>
  JSONObject operator=(T value) {
    setType(Type::Integral);
    Data.Int = value;
    return *this;
  }

  /**
   * Load a float number into the JSONObject.
   * @tparam T Float-like type
   * @param value Value of the float number
   * @return *this
   */
  template <typename T, typename std::enable_if<
                            std::is_floating_point<T>::value>::type * = nullptr>
  JSONObject operator=(T value) {
    setType(Type::Float);
    Data.Float = value;
    return *this;
  }

  /**
   * Load a string into the JSONObject.
   * @tparam T String-like type
   * @param value Value of the string
   * @return *this
   */
  template <typename T, typename std::enable_if<std::is_convertible<
                            T, std::string>::value>::type * = nullptr>
  JSONObject operator=(T value) {
    setType(Type::String);
    *Data.String = std::string(value);
    return *this;
  }

  /**
   * Look up a value with specific key in a map object. Will convert itself to
   * an Object if not before.
   * @param key C-style string. Key to look up.
   * @return Pointer to the element found.
   */
  JSONObject &operator[](const char key[]);

  /**
   * Look up a value with specific key in a map object. Will convert itself to
   * an Object if not before.
   * @param key Key to look up.
   * @return Pointer to the element found.
   */
  JSONObject &operator[](const std::string &key);

  /**
   * Look up a value with specific index in a list. Will convert itself to a
   * List if not before.
   * @param index index to look up
   * @return Pointer to the value
   */
  JSONObject &operator[](int index);

  /**
   * Look up a value with specific key in a map object. Will convert itself to an Object if not before.
   * @param key key to look up
   * @return Pointer to the value
   */
  JSONObject &at(const std::string &key);

  /**
   * Look up a value with specific key in a map object.
   * @param key key to look up
   * @return Pointer to the value
   */
  const JSONObject &at(const std::string &key) const;

  /**
   * Look up a value with specific index in a list. Will convert itself to a
   * List if not before.
   * @param index index to look up
   * @return Pointer to the value
   */
  JSONObject &at(unsigned index);

  /**
   * Look up a value with specific index in a list.
   * @param index index to look up
   * @return Pointer to the value
   */
  const JSONObject &at(unsigned index) const;

  /**
   * Append an element to a array. Will clear all contents if not a array type
   * object.
   * @tparam T Type of the element
   * @param arg Value of the element
   */
  template <typename T>
  void append(T arg) {
    setType(Type::Array);
    Data.List->emplace_back(arg);
  }

  /**
   * Append elements to a array. Will clear all contents if not a array type
   * object.
   *
   * It calls the append(arg) one by one using a recursive method.
   * @tparam T Type of the first element
   * @tparam U Types of the remaining elements
   * @param arg Value of the first element
   * @param args Values of the remaining elements
   */
  template <typename T, typename... U>
  void append(T arg, U... args) {
    append(arg);
    append(args...);
  }

  /**
   * Length of a list
   * @return length
   */
  int length() const;

  /**
   * Size of a list or an Object
   * @return size
   */
  int size() const;

  /**
   * See if the key is in the object. Only for an Object.
   * @param key key to look up
   * @return True if in.
   */
  bool hasKey(const std::string &key) const;

  /**
   * Build an empty object for specific type
   * @param type JSONObject::Type
   * @return JSONObject
   */
  static JSONObject Build(Type type) {
    JSONObject ret;
    ret.setType(type);
    return ret;
  }

  /**
   * Convert a JSONObject to a string. Only for String object.
   *
   * Use dump() method if you want to convert other types of objects into a
   * string.
   * @return string
   */
  std::string toString() const;

  /**
   * Convert a JSONObject to a double. Only for Float object.
   * @return double
   */
  double toDouble() const;

  /**
   * Convert a JSONObject to an float number. Only for Float object.
   * @return float
   */
  float toFloat() const;

  /**
   * Convert a JSONObject to standard int type. Only for Integral object.
   * @return int
   */
  int toInt() const;

  /**
   * Convert a JSONObject to bool type. Only for Bool object.
   * @return True or False
   */
  bool toBool() const;

  /**
   * Convert a JSONObject to a string. Only for String object.
   *
   * Use dump() method if you want to convert other types of objects into a
   * string.
   * @return string
   */
  operator std::string() const;

  /**
   * Convert a JSONObject to an float number. Only for Float object.
   * @return float
   */
  operator float() const;

  /**
   * Convert a JSONObject to a double. Only for Float object.
   * @return double
   */
  operator double() const;

  /**
   * Convert a JSONObject to standard int type. Only for Integral object.
   * @return int
   */
  operator int() const;

  /**
   * Convert a JSONObject to bool type. Only for Bool object.
   * @return True or False
   */
  operator bool() const;

  /**
   * Get the type of a JSON object
   * @return JSONObject::Type
   */
  Type getType() const { return objType; }

  /**
   * Return an iterator for object. Useful in range-based for loop.
   *
   * Usage:
   * @code
   * for (auto &j : array.ObjectRange()){
   * std::cout << j.first << j.second << std::endl;
   * }
   * @endcode
   * @return Iterator to the json object. Null if not an object.
   */
  JSONIterator<std::map<std::string, JSONObject>> ObjectRange() {
    return objType == Type::Object
               ? JSONIterator<std::map<std::string, JSONObject>>(Data.Map)
               : JSONIterator<std::map<std::string, JSONObject>>(nullptr);
  }
  /**
   * Return an iterator for array object. Useful in range-based for loop.
   *
   * Usage:
   * @code
   * for (auto &j : array.ArrayRange()){
   * std::cout << j << std::endl;
   * }
   * @endcode
   * @return Iterator to the json object. Null if not an array.
   */
  JSONIterator<std::deque<JSONObject>> ArrayRange() {
    return objType == Type::Array
               ? JSONIterator<std::deque<JSONObject>>(Data.List)
               : JSONIterator<std::deque<JSONObject>>(nullptr);
  }

  /**
   * Return a const iterator for object. Useful in range-based for loop.
   *
   * Usage:
   * @code
   * for (auto &j : array.ObjectRange()){
   * std::cout << j.first << j.second << std::endl;
   * }
   * @endcode
   * @return Const iterator to the json object. Null if not an object.
   */
  JSONConstIterator<std::map<std::string, JSONObject>> ObjectRange() const {
    return objType == Type::Object
               ? JSONConstIterator<std::map<std::string, JSONObject>>(Data.Map)
               : JSONConstIterator<std::map<std::string, JSONObject>>(nullptr);
  }

  /**
   * Return a const iterator for array object. Useful in range-based for loop.
   *
   * Usage:
   * @code
   * for (auto &j : array.ArrayRange()){
   * std::cout << j << std::endl;
   * }
   * @endcode
   * @return Const iterator to the json object. Null if not an array.
   */
  JSONConstIterator<std::deque<JSONObject>> ArrayRange() const {
    return objType == Type::Array
               ? JSONConstIterator<std::deque<JSONObject>>(Data.List)
               : JSONConstIterator<std::deque<JSONObject>>(nullptr);
  }

  /**
   * Is the JSONObject a Null object?
   * @return True if Null.
   */
  bool isNull() const { return objType == Type::Null; }

  /**
   * Dump out JSON data to a string
   * @param depth
   * @param tab
   * @return
   */
  std::string dump(int depth = 1, std::string tab = "  ") const;

  /**
   * Implement operator<< to support output to stream.
   * @param os ostream
   * @param json JSONObject to output
   * @return ostream
   */
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
