#ifndef CUHKSZ_CONTAINERS_VECTOR
#define CUHKSZ_CONTAINERS_VECTOR

#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include "utils/error.h"

namespace cuhksz {

template <typename ValueType>
class Vector {
 public:
  typedef typename std::vector<ValueType> stlVector;
  typedef ValueType value_type;

  Vector();

  /**
              Construct a Vector with n value(s).
              Usage:
              ```
              cuhksz::Vector<ValueType> vec(n, value);
              ```
      **/
  explicit Vector(int n, ValueType value = ValueType());

  /**
              Construct a Vector using a initializer_list.
              Usage:
              ```
              cuhksz::Vector<ValueType> vec {value1, value2};
              ```
      **/
  Vector(std::initializer_list<ValueType> init);

  /**
              Initialize a Vector with a stl vector.
              Usage:
              ```
              cuhksz::Vector<ValueType> vec(stlVector);
              ```
      **/
  Vector(stlVector& stlVector2);

  ~Vector();

  /**
      Get the element at index.
      Return a reference to it.
  **/
  ValueType& get(int index);

  /**
      Get the element at index.
      Return a const reference to it.
  **/
  const ValueType& get(int index) const;

  /**
      Get the first element in the Vector.
      Return a reference to that element.
  **/
  ValueType& first();

  /**
      Get the first element in the Vector.
      Return a const reference to that element.
  **/
  const ValueType& first() const;

  /**
              Get the last element in the Vector.
              Return a reference to that element.
      **/
  ValueType& last();

  /**
              Get the last element in the Vector.
              Return a const reference to that element.
      **/
  const ValueType& last() const;

  /**
              Get the element at the specified index.
              Return a reference to that element.
      **/
  ValueType& operator[](int index);

  /**
      Get the element at the specified index.
      Return a const reference to that element.
  **/
  const ValueType& operator[](int index) const;

  /**
      Check whether the Vector is empty.
  **/
  bool isEmpty() const;

  /**
              Return the size of the Vector.
      **/
  int size() const;

  /**
      Empty the Vector.
  **/
  void clear();

  /**
              Insert value before index, it is allowed to
              insert value at the end. It will cause error
      if index out of range.
      **/
  void insert(int index, const ValueType& value);

  /**
              Erase the element at index with boundary checking.
      **/
  void erase(int index);

  /**
              Set the value at specified index.
      **/
  void set(int index, const ValueType& value);

  /**
              Push the value to the back of Vector.
      **/
  void push(const ValueType& value);

  /**
              Pop the value at the end of Vector. Return the value.
      **/
  ValueType pop();

  /**
              Convert the Vector to stl vector explicitly.
              Usage:
              ```
              auto vec = Vector.toStlVector();
              ```
      **/
  stlVector toStlVector() { return vec; }

  /**
      Convert the Vector to stl vector implicitly.
      Usage:
      ```
      std::vector<ValueType> vec = Vector;
      ```
  **/
  operator stlVector() { return vec; }

  /**
      Check if Vector equals to v2.
  **/
  bool operator==(const Vector& v2);

  /**
      Check if Vector does not equal to v2.
  **/
  bool operator!=(const Vector& v2);

  /**
      Compare the contents of Vector and v2 lexicographically.
  **/
  bool operator<(const Vector& v2);

  /**
      Compare the contents of Vector and v2 lexicographically.
  **/
  bool operator<=(const Vector& v2);

  /**
      Compare the contents of Vector and v2 lexicographically.
  **/
  bool operator>(const Vector& v2);

  /**
      Compare the contents of Vector and v2 lexicographically.
  **/
  bool operator>=(const Vector& v2);

  typedef typename std::vector<ValueType>::iterator iterator;
  typedef typename std::vector<ValueType>::const_iterator const_iterator;

  /**
              Return the begin iterator.
      **/
  iterator begin() { return vec.begin(); }

  /**
    Return the const iterator of begin.
  **/
  const_iterator begin() const { return vec.begin(); }

  /**
      Return the end iterator.
  **/
  iterator end() { return vec.end(); }

  /**
    Return the const iterator of end.
  **/
  const_iterator end() const { return vec.end(); }

 private:
  std::vector<ValueType> vec;
  void boundaryCheck(int index) const;
  void emptyCheck() const;
};

template <typename ValueType>
Vector<ValueType>::Vector() {
  // do nothing
}

template <typename ValueType>
Vector<ValueType>::Vector(int n, ValueType value) {
  vec.resize(n, value);
}

template <typename ValueType>
Vector<ValueType>::Vector(std::initializer_list<ValueType> init) {
  vec = init;
}

template <typename ValueType>
Vector<ValueType>::Vector(stlVector& stlVector2) {
  vec = stlVector2;
}

template <typename ValueType>
Vector<ValueType>::~Vector() {
  // do nothing
}

template <typename ValueType>
const ValueType& Vector<ValueType>::get(int index) const {
  boundaryCheck(index);
  return vec.at(index);
}

template <typename ValueType>
ValueType& Vector<ValueType>::get(int index) {
  boundaryCheck(index);
  return vec.at(index);
}

template <typename ValueType>
ValueType& Vector<ValueType>::first() {
  emptyCheck();
  return vec.front();
}

template <typename ValueType>
const ValueType& Vector<ValueType>::first() const {
  emptyCheck();
  return vec.front();
}

template <typename ValueType>
ValueType& Vector<ValueType>::last() {
  emptyCheck();
  return vec.back();
}

template <typename ValueType>
const ValueType& Vector<ValueType>::last() const {
  emptyCheck();
  return vec.back();
}

template <typename ValueType>
ValueType& Vector<ValueType>::operator[](int index) {
  boundaryCheck(index);
  return vec.at(index);
}

template <typename ValueType>
const ValueType& Vector<ValueType>::operator[](int index) const {
  boundaryCheck(index);
  return vec.at(index);
}

template <typename ValueType>
bool Vector<ValueType>::isEmpty() const {
  return vec.empty();
}

template <typename ValueType>
int Vector<ValueType>::size() const {
  return vec.size();
}

template <typename ValueType>
void Vector<ValueType>::clear() {
  vec.clear();
}

template <typename ValueType>
void Vector<ValueType>::insert(int index, const ValueType& value) {
  size_t unsignedIndex = index;
  if (index < 0 || unsignedIndex > vec.size()) {
    error("The index out of range!");
  }
  auto iterator = vec.begin();
  std::advance(iterator, index);
  vec.insert(iterator, value);
}

template <typename ValueType>
void Vector<ValueType>::erase(int index) {
  boundaryCheck(index);
  auto iterator = vec.begin();
  std::advance(iterator, index);
  vec.erase(iterator);
}

template <typename ValueType>
void Vector<ValueType>::set(int index, const ValueType& value) {
  boundaryCheck(index);
  vec[index] = value;
}

template <typename ValueType>
void Vector<ValueType>::push(const ValueType& value) {
  vec.push_back(value);
}

template <typename ValueType>
ValueType Vector<ValueType>::pop() {
  emptyCheck();
  ValueType lastElement = vec.back();
  vec.pop_back();
  return lastElement;
}

template <typename ValueType>
bool Vector<ValueType>::operator==(const Vector& v2) {
  return vec == v2.vec;
}

template <typename ValueType>
bool Vector<ValueType>::operator!=(const Vector& v2) {
  return vec != v2.vec;
}

template <typename ValueType>
bool Vector<ValueType>::operator<(const Vector& v2) {
  return vec < v2.vec;
}

template <typename ValueType>
bool Vector<ValueType>::operator<=(const Vector& v2) {
  return vec <= v2.vec;
}

template <typename ValueType>
bool Vector<ValueType>::operator>(const Vector& v2) {
  return vec > v2.vec;
}

template <typename ValueType>
bool Vector<ValueType>::operator>=(const Vector& v2) {
  return vec >= v2.vec;
}

template <typename ValueType>
void Vector<ValueType>::boundaryCheck(int index) const {
  size_t unsignedIndex = index;
  if (index < 0 || unsignedIndex >= vec.size()) {
    error("The index out of range!");
  }
}

template <typename ValueType>
void Vector<ValueType>::emptyCheck() const {
  if (vec.empty()) {
    error("The vector is empty!");
  }
}

template <typename ValueType>
std::ostream& operator<<(std::ostream& os, const Vector<ValueType>& vec) {
  std::stringstream ss;
  if (vec.size() == 0) {
    return os << "{}";
  }
  if (vec.size() == 1) {
    return os << '{' << vec.last() << '}';
  }
  std::copy(vec.begin(), --vec.end(),
            std::ostream_iterator<ValueType>(ss, ", "));
  return os << '{' << ss.str() << vec.last() << '}';
}

template <typename ValueType>
std::istream& operator>>(std::istream& is, Vector<ValueType>& vec) {
  char ch;
  is >> ch;
  if (ch != '{') {
    error("A vector should startwith \'{\'");
  }
  vec.clear();
  is >> ch;
  if (ch != '}') {
    is.unget();
    while (true) {
      ValueType value;
      is >> value;
      vec.push(value);
      is >> ch;
      if (is.eof()) {
        error("A vector must endwith \'}\'");
      }
      if (ch == '}') {
        break;
      } else if (ch != ',') {
        error(std::string("Unexpected character ") + ch);
      }
    }
  }
  return is;
}

}  // end namespace cuhksz

#endif  // CUHKSZ_CONTAINERS_VECTOR
