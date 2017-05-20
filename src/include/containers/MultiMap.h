#ifndef CUHKSZ_CONTAINERS_MULTIMAP
#define CUHKSZ_CONTAINERS_MULTIMAP

#include <map>
#include <utility>
#include "Set.h"

namespace cuhksz {
/**
        cuhksz::MultiMap is a container which similar to stl multimap except
        some simplifications and modifications of interface.
**/

template <typename KeyType, typename ValueType>
class MultiMap {
 public:
  typedef std::pair<const KeyType, ValueType> StdValueType;
  typedef std::multimap<KeyType, ValueType> stlMultimap;
  typedef ValueType value_type;

  MultiMap();

  /**
              Construct a MultiMap using a initializer_list.
      A key can be mapped to more than one value.
              Usage:
              ```
              cuhksz::MultiMap<KeyType, ValueType> multim {
              {key1, value1},
      {key1, value2},
      {key2, value3},
              };
              ```
      **/
  MultiMap(std::initializer_list<StdValueType> init);

  /**
      Initialize a MultiMap with a stl multimap.
      Usage:
      ```
      cuhksz::MultiMap<KeyType, ValueType> multim(stlMultimap);
      ```
  **/
  MultiMap(stlMultimap& stlMultimap2);

  ~MultiMap();

  /**
              Assign a MultiMap to another MultiMap.
      **/
  MultiMap& operator=(MultiMap& multimap2);

  /**
              Check if the MultiMap is empty.
      **/
  bool isEmpty() const;

  /**
      Return the size of the MultiMap.
  **/
  int size() const;

  /**
              Empty the MultiMap.
      **/
  void clear();

  /**
      Erase the value with correspond key.
  **/
  void erase(const KeyType& key);

  /**
      Return the number of value with correspond key.
  **/
  int count(const KeyType& key) const;

  typedef typename std::multimap<KeyType, ValueType>::iterator iterator;
  typedef
      typename std::multimap<KeyType, ValueType>::const_iterator const_iterator;

  /**
              Return a begin iterator.
      **/
  iterator begin() { return privateMultimap.begin(); }

  /**
      Return a const iterator.
  **/
  const_iterator begin() const { return privateMultimap.begin(); }

  /**
      Return a end iterator.
  **/
  iterator end() { return privateMultimap.end(); }

  /**
      Return a const iterator.
  **/
  const_iterator end() const { return privateMultimap.end(); }

  /**
      Return Set of value with correspond key.
      If the key does not exist, return a empty Set.
  **/
  Set<ValueType> find(const KeyType& key);

  /**
              Convert the MultiMap to stl multimap explicitly.
              Usage:
              ```
              auto multim = MultiMap.toStlMultimap();
              ```
      **/
  stlMultimap toStlMultimap() { return privateMultimap; }

  /**
              Convert the MultiMap to stl multimap implicitly.
              Usage:
              ```
              std::multimap<KeyType, ValueType> multim = MultiMap;
              ```
      **/
  operator stlMultimap() { return privateMultimap; }

  /**
              Check if MultiMap equals to multimap2.
      **/
  bool operator==(const MultiMap& multimap2);

  /**
      Check if MultiMap does not equal to multimap2.
  **/
  bool operator!=(const MultiMap& multimap2);

  /**
      Compare the contents of MultiMap and multimap2 lexicographically.
  **/
  bool operator<(const MultiMap& multimap2);

  /**
      Compare the contents of MultiMap and multimap2 lexicographically.
  **/
  bool operator<=(const MultiMap& multimap2);

  /**
      Compare the contents of MultiMap and multimap2 lexicographically.
  **/
  bool operator>(const MultiMap& multimap2);

  /**
      Compare the contents of MultiMap and multimap2 lexicographically.
  **/
  bool operator>=(const MultiMap& multimap2);

 private:
  std::multimap<KeyType, ValueType> privateMultimap;
};

template <typename KeyType, typename ValueType>
MultiMap<KeyType, ValueType>::MultiMap() {
  // do nothing
}

template <typename KeyType, typename ValueType>
MultiMap<KeyType, ValueType>::MultiMap(
    std::initializer_list<StdValueType> init) {
  privateMultimap = init;
}

template <typename KeyType, typename ValueType>
MultiMap<KeyType, ValueType>::MultiMap(stlMultimap& stlMultimap2) {
  privateMultimap = stlMultimap2;
}

template <typename KeyType, typename ValueType>
MultiMap<KeyType, ValueType>::~MultiMap() {
  // do nothing
}

template <typename KeyType, typename ValueType>
MultiMap<KeyType, ValueType>& MultiMap<KeyType, ValueType>::operator=(
    MultiMap& multimap2) {
  privateMultimap = multimap2.privateMultimap;
  return *this;
}

template <typename KeyType, typename ValueType>
bool MultiMap<KeyType, ValueType>::isEmpty() const {
  return privateMultimap.empty();
}

template <typename KeyType, typename ValueType>
int MultiMap<KeyType, ValueType>::size() const {
  return privateMultimap.size();
}

template <typename KeyType, typename ValueType>
void MultiMap<KeyType, ValueType>::clear() {
  privateMultimap.clear();
}

template <typename KeyType, typename ValueType>
void MultiMap<KeyType, ValueType>::erase(const KeyType& key) {
  privateMultimap.erase(key);
}

template <typename KeyType, typename ValueType>
int MultiMap<KeyType, ValueType>::count(const KeyType& key) const {
  return privateMultimap.count(key);
}

template <typename KeyType, typename ValueType>
Set<ValueType> MultiMap<KeyType, ValueType>::find(const KeyType& key) {
  Set<ValueType> valueSet;
  auto elementsFound = privateMultimap.equal_range(key);
  for (auto i = elementsFound.first; i != elementsFound.second; ++i) {
    valueSet.insert(i->second);
  }
  return valueSet;
}

template <typename KeyType, typename ValueType>
bool MultiMap<KeyType, ValueType>::operator==(const MultiMap& multimap2) {
  return privateMultimap == multimap2.privateMultimap;
}

template <typename KeyType, typename ValueType>
bool MultiMap<KeyType, ValueType>::operator!=(const MultiMap& multimap2) {
  return privateMultimap != multimap2.privateMultimap;
}

template <typename KeyType, typename ValueType>
bool MultiMap<KeyType, ValueType>::operator<(const MultiMap& multimap2) {
  return privateMultimap < multimap2.privateMultimap;
}

template <typename KeyType, typename ValueType>
bool MultiMap<KeyType, ValueType>::operator<=(const MultiMap& multimap2) {
  return privateMultimap <= multimap2.privateMultimap;
}

template <typename KeyType, typename ValueType>
bool MultiMap<KeyType, ValueType>::operator>(const MultiMap& multimap2) {
  return privateMultimap > multimap2.privateMultimap;
}

template <typename KeyType, typename ValueType>
bool MultiMap<KeyType, ValueType>::operator>=(const MultiMap& multimap2) {
  return privateMultimap >= multimap2.privateMultimap;
}

}  // namespace cuhksz

#endif  // CUHKSZ_CONTAINERS_MULTIMAP
