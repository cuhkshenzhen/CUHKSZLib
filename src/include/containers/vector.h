#ifndef CUHKSZ_CONTAINERS_VECTOR
#define CUHKSZ_CONTAINERS_VECTOR

#include <vector>
#include <iostream>

namespace cuhksz {

template <typename ValueType>
class vector {
public:

    vector();
    explicit vector(int n, ValueType value = ValueType());


    virtual ~vector();


    const ValueType& get(int index) const;


    ValueType& operator [](int index);
    const ValueType& operator [](int index) const;


    bool isEmpty() const;


    int size() const;

    void clear();

    void insert(int index, const ValueType& value);

    void erase(int index);

    void set(int index, const ValueType& value);

    void push(const ValueType& value);

    ValueType& pop();

    bool operator ==(const vector& v2);
    bool operator !=(const vector& v2);
    bool operator <(const vector& v2);
    bool operator <=(const vector& v2);
    bool operator >(const vector& v2);
    bool operator >=(const vector& v2);

    typedef typename std::vector<ValueType>::const_iterator const_iterator;

    const_iterator begin() const {
      return vec.begin();
    }

    const_iterator end() const {
      return vec.end();
    }




private:
    std::vector<ValueType> vec;
};

//constructor
template <typename ValueType>
vector<ValueType>::vector() {

}

template <typename ValueType>
vector<ValueType>::vector(int n, ValueType value) {
    if (n == 0) {
        vec.clear();
    } else {
        for (int i = 0; i < n; i++) {
            vec.push_back(value);
        }
    }
}

template <typename ValueType>
const ValueType& vector<ValueType>::get(int index) const {
    return vec.at(index);
}

template <typename ValueType>
ValueType& vector<ValueType>::operator [](int index) {
    return vec.at(index);
}

template <typename ValueType>
const ValueType& vector<ValueType>::operator [](int index) const {
    return vec.at(index);
}

template <typename ValueType>
bool vector<ValueType>::isEmpty() const {
    return vec.empty();
}

template <typename ValueType>
int vector<ValueType>::size() const {
    return vec.size();
}

template <typename ValueType>
void vector<ValueType>::clear() {
    vec.clear();
}

template <typename ValueType>
void vector<ValueType>::insert(int index, const ValueType& value) {
    auto begin = vec.begin();
    vec.insert(begin + index, value);
}

template <typename ValueType>
void vector<ValueType>::erase(int index) {
    auto begin = vec.begin();
    vec.erase(begin + index);
}

template <typename ValueType>
void vector<ValueType>::set(int index, const ValueType& value) {
    auto begin = vec.begin();
    auto followingElement = vec.erase(begin + index);
    vec.insert(followingElement, value);
}

template <typename ValueType>
void vector<ValueType>::push(const ValueType& value) {
    vec.push_back(value);
}

template <typename ValueType>
ValueType& vector<ValueType>::pop() {
    ValueType lastElement = vec.back();
    vec.pop_back();
    return lastElement;
}

template <typename ValueType>
bool vector<ValueType>::operator ==(const vector& v2) {
    return vec == v2.vec;
}

template <typename ValueType>
bool vector<ValueType>::operator !=(const vector& v2) {
  return vec != v2.vec;
}

template <typename ValueType>
bool vector<ValueType>::operator <(const vector& v2) {
  return vec < v2.vec;
}

template <typename ValueType>
bool vector<ValueType>::operator <=(const vector& v2) {
  return vec <= v2.vec;
}

template <typename ValueType>
bool vector<ValueType>::operator >(const vector& v2) {
  return vec > v2.vec;
}

template <typename ValueType>
bool vector<ValueType>::operator >=(const vector& v2) {
  return vec >= v2.vec;
}

template <typename ValueType>
std::ostream & operator <<(std::ostream& os, const vector<ValueType>& vec) {
  return os << vec;
}

template <typename ValueType>
std::istream & operator >>(std::istream & is, const vector<ValueType>& vec) {
  char ch;
  is >> ch;
  if (ch != '{') {
    std::cout << "Error: The first character of a vector should be '{'" << '\n';
    return is;
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
      if (ch == '}') {
        break;
      } else if (ch != ','){
        std::cout << "Error: Unexpected character " << ch << " when input a vector" << '\n';
        return is;
      }
    }
  }
  return is;
}

} // end namespace cuhksz

#endif
