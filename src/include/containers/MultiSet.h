#ifndef CUHKSZ_CONTAINERS_MULTISET
#define CUHKSZ_CONTAINERS_MULTISET

#include <set>
#include <utility>
#include "utils/error.h"

namespace cuhksz {
/**
        cuhksz::MultiSet is a container which similar to stl multiset except
        some simplifications and modifications of interface.
**/
template <typename ValueType>
class MultiSet {
 public:
  typedef typename std::multiset<ValueType> stlMultiset;
  typedef ValueType value_type;

  MultiSet();

  /**
              Construct a MultiSet using a initializer_list.
      It could contain more than one same value.
              Usage:
              ```
              cuhksz::MultiSet<ValueType> multis {value1, value1, value2};
              ```
      **/
  MultiSet(std::initializer_list<ValueType> init);

  /**
      Initialize a MultiSet with a stl multiset.
      Usage:
      ```
      cuhksz::MultiSet<ValueType> multis(stlMultiset);
      ```
  **/
  MultiSet(stlMultiset& stlMultiset2);

  ~MultiSet();

  /**
      Assign a MultiSet to another MultiSet.
  **/
  MultiSet& operator=(const MultiSet& multiset2);

  /**
      Check whether a MultiSet is empty.
  **/
  bool isEmpty() const;

  /**
      Return the size of the MultiSet.
  **/
  int size() const;

  /**
      Insert the value into the MultiSet.
  **/
  void insert(const ValueType& value);

  /**
      Erase the specified value in the MultiSet.
  **/
  void erase(const ValueType& value);

  /**
      Return the number of value in the MultiSet.
  **/
  int count(const ValueType& value) const;

  /**
      Empty the MultiSet.
  **/
  void clear();

  /**
      Check if the MultiSet contains the value.
  **/
  bool contains(const ValueType& value) const;

  typedef typename std::multiset<ValueType>::iterator iterator;
  typedef typename std::multiset<ValueType>::const_iterator const_iterator;

  /**
      Return the begin iterator.
  **/
  iterator begin() { return privateMultiset.begin(); }

  /**
    Return the const iterator of begin.
  **/
  const_iterator begin() const { return privateMultiset.begin(); }

  /**
              Return the end iterator.
      **/
  iterator end() { return privateMultiset.end(); }

  /**
    Return the const iterator of end.
  **/
  const_iterator end() const { return privateMultiset.end(); }

  /**
              Convert the MultiSet to stl multiset explicitly.
              Usage:
              ```
              auto multis = MultiSet.toStlMultiset();
              ```
      **/
  stlMultiset toStlMultiset() { return privateMultiset; }

  /**
              Convert the MultiSet to stl multiset implicitly.
              Usage:
              ```
              std::multiset<ValueType> multis = MultiSet;
              ```
      **/
  operator stlMultiset() { return privateMultiset; }

  /**
              Check if MultiSet equals to multiset2.
      **/
  bool operator==(const MultiSet& multiset2);

  /**
              Check if MultiSet does not equal to multiset2.
      **/
  bool operator!=(const MultiSet& multiset2);

  /**
              Compare the contents of MultiSet and multiset2 lexicographically.
      **/
  bool operator<(const MultiSet& multiset2);

  /**
              Compare the contents of MultiSet and multiset2 lexicographically.
      **/
  bool operator<=(const MultiSet& multiset2);

  /**
              Compare the contents of MultiSet and multiset2 lexicographically.
      **/
  bool operator>(const MultiSet& multiset2);

  /**
              Compare the contents of MultiSet and multiset2 lexicographically.
      **/
  bool operator>=(const MultiSet& multiset2);

 private:
  std::multiset<ValueType> privateMultiset;
};

template <typename ValueType>
MultiSet<ValueType>::MultiSet() {
  // do nothing
}

template <typename ValueType>
MultiSet<ValueType>::MultiSet(std::initializer_list<ValueType> init) {
  privateMultiset = init;
}

template <typename ValueType>
MultiSet<ValueType>::MultiSet(stlMultiset& stlMultiset2) {
  privateMultiset = stlMultiset2;
}

template <typename ValueType>
MultiSet<ValueType>::~MultiSet() {
  // do nothing
}

template <typename ValueType>
MultiSet<ValueType>& MultiSet<ValueType>::operator=(const MultiSet& multiset2) {
  privateMultiset = multiset2.privateMultiset;
  return *this;
}

template <typename ValueType>
bool MultiSet<ValueType>::isEmpty() const {
  return privateMultiset.empty();
}

template <typename ValueType>
int MultiSet<ValueType>::size() const {
  return privateMultiset.size();
}

template <typename ValueType>
void MultiSet<ValueType>::insert(const ValueType& value) {
  privateMultiset.insert(value);
}

template <typename ValueType>
void MultiSet<ValueType>::erase(const ValueType& value) {
  if (privateMultiset.find(value) == privateMultiset.end()) {
    error("No such value in the multiset!");
  } else {
    privateMultiset.erase(value);
  }
}

template <typename ValueType>
int MultiSet<ValueType>::count(const ValueType& value) const {
  return privateMultiset.count(value);
}

template <typename ValueType>
void MultiSet<ValueType>::clear() {
  privateMultiset.clear();
}

template <typename ValueType>
bool MultiSet<ValueType>::contains(const ValueType& value) const {
  return (privateMultiset.find(value) != privateMultiset.end()) ? true : false;
}

template <typename ValueType>
bool MultiSet<ValueType>::operator==(const MultiSet& multiset2) {
  return privateMultiset == multiset2.privateMultiset;
}

template <typename ValueType>
bool MultiSet<ValueType>::operator!=(const MultiSet& multiset2) {
  return privateMultiset != multiset2.privateMultiset;
}

template <typename ValueType>
bool MultiSet<ValueType>::operator<(const MultiSet& multiset2) {
  return privateMultiset < multiset2.privateMultiset;
}

template <typename ValueType>
bool MultiSet<ValueType>::operator<=(const MultiSet& multiset2) {
  return privateMultiset <= multiset2.privateMultiset;
}

template <typename ValueType>
bool MultiSet<ValueType>::operator>(const MultiSet& multiset2) {
  return privateMultiset > multiset2.privateMultiset;
}

template <typename ValueType>
bool MultiSet<ValueType>::operator>=(const MultiSet& multiset2) {
  return privateMultiset >= multiset2.privateMultiset;
}

}  // namespace cuhksz

#endif  // CUHKSZ_CONTAINERS_MULTISET
