#ifndef CUHKSZ_CONTAINERS_MAP
#define CUHKSZ_CONTAINERS_MAP

#include <map>
#include <utility>
#include "utils/error.h"

namespace cuhksz {
/**
        cuhksz::Map is a container which similar to stl map except
        some simplifications and modifications of interface.
**/

template <typename KeyType, typename ValueType>
class Map {
 public:
  typedef std::pair<const KeyType, ValueType> StdValueType;
  typedef typename std::map<KeyType, ValueType> stlMap;
  typedef ValueType value_type;

  Map();

  /**
          Construct a Map using a initializer_list.
          Usage:
          ```
          cuhksz::Map<KeyType, ValueType> m {
          {key1, value1},
          {key2, value2},
          };
          ```
  **/
  Map(std::initializer_list<StdValueType> init);

  /**
          Initialize a Map with a stl map.
          Usage:
          ```
          cuhksz::Map<KeyType, ValueType> m(stlMap);
          ```
  **/
  Map(stlMap& stlMap2);

  ~Map();

  /**
          Assign a Map to another Map.
  **/
  Map& operator=(Map& map2);

  /**
          Get the value with correspond key.
          It will cause error if the key does not exist.
          Return a reference to the value.
  **/
  ValueType& get(const KeyType& key);

  /**
          Get the value with correspond key.
          It will cause error if the key does not exist.
          Return a const reference to the value.
  **/
  const ValueType& get(const KeyType& key) const;

  /**
          Set the value with correspond key.
          If the key doesn't exist, it will create a
          new key-value pair.
  **/
  void set(const KeyType& key, const ValueType& value);

  /**
          Return a reference to the value with correspond key.
          If the key does not exist, it will create a new key-value pair.
  **/
  ValueType& operator[](const KeyType& key);

  /**
          Check if the Map is empty.
  **/
  bool isEmpty() const;

  /**
          Return the size of the Map.
  **/
  int size() const;

  /**
          Empty the Map.
  **/
  void clear();

  /**
          Erase the value with correspond key.
  **/
  void erase(const KeyType& key);

  /**
          Check if the Map contains the key.
  **/
  bool contains(const KeyType& key);

  typedef typename std::map<KeyType, ValueType>::iterator iterator;
  typedef typename std::map<KeyType, ValueType>::const_iterator const_iterator;

  /**
          Return a begin iterator.
  **/
  iterator begin() { return privateMap.begin(); }

  /**
          Return a const iterator.
  **/
  const_iterator begin() const { return privateMap.begin(); }

  /**
          Return a end iterator.
  **/
  iterator end() { return privateMap.end(); }

  /**
          Return a const iterator.
  **/
  const_iterator end() const { return privateMap.end(); }

  /**
          Convert the Map to stl map explicitly.
          Usage:
          ```
          auto m = Map.toStlMap();
          ```
  **/
  stlMap toStlMap() { return privateMap; }

  /**
          Convert the Map to stl map implicitly.
          Usage:
          ```
          std::map<KeyType, ValueType> m = Map;
          ```
  **/
  operator stlMap() { return privateMap; }

  /**
          Check if Map equals to map2.
  **/
  bool operator==(const Map& map2);

  /**
          Check if Map does not equal to map2.
  **/
  bool operator!=(const Map& map2);

  /**
          Compare the contents of Map and map2 lexicographically.
  **/
  bool operator<(const Map& map2);

  /**
          Compare the contents of Map and map2 lexicographically.
  **/
  bool operator<=(const Map& map2);

  /**
          Compare the contents of Map and map2 lexicographically.
  **/
  bool operator>(const Map& map2);

  /**
          Compare the contents of Map and map2 lexicographically.
  **/
  bool operator>=(const Map& map2);

 private:
  std::map<KeyType, ValueType> privateMap;
  void keyCheck(const KeyType& key) const;
};

template <typename KeyType, typename ValueType>
Map<KeyType, ValueType>::Map() {
  // do nothing
}

template <typename KeyType, typename ValueType>
Map<KeyType, ValueType>::Map(std::initializer_list<StdValueType> init) {
  privateMap = init;
}

template <typename KeyType, typename ValueType>
Map<KeyType, ValueType>::Map(stlMap& stlMap2) {
  privateMap = stlMap2;
}

template <typename KeyType, typename ValueType>
Map<KeyType, ValueType>::~Map() {
  // do nothing
}

template <typename KeyType, typename ValueType>
Map<KeyType, ValueType>& Map<KeyType, ValueType>::operator=(Map& map2) {
  privateMap = map2.privateMap;
  return *this;
}

template <typename KeyType, typename ValueType>
ValueType& Map<KeyType, ValueType>::get(const KeyType& key) {
  keyCheck(key);
  return privateMap.at(key);
}

template <typename KeyType, typename ValueType>
const ValueType& Map<KeyType, ValueType>::get(const KeyType& key) const {
  keyCheck(key);
  return privateMap.at(key);
}

template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::set(const KeyType& key, const ValueType& value) {
  privateMap[key] = value;
}

template <typename KeyType, typename ValueType>
ValueType& Map<KeyType, ValueType>::operator[](const KeyType& key) {
  return privateMap[key];
}

template <typename KeyType, typename ValueType>
bool Map<KeyType, ValueType>::isEmpty() const {
  return privateMap.empty();
}

template <typename KeyType, typename ValueType>
int Map<KeyType, ValueType>::size() const {
  return privateMap.size();
}

template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::clear() {
  privateMap.clear();
}

template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::erase(const KeyType& key) {
  privateMap.erase(key);
}

template <typename KeyType, typename ValueType>
bool Map<KeyType, ValueType>::contains(const KeyType& key) {
  return (privateMap.find(key) != privateMap.end()) ? true : false;
}

template <typename KeyType, typename ValueType>
bool Map<KeyType, ValueType>::operator==(const Map& map2) {
  return privateMap == map2.privateMap;
}

template <typename KeyType, typename ValueType>
bool Map<KeyType, ValueType>::operator!=(const Map& map2) {
  return privateMap != map2.privateMap;
}

template <typename KeyType, typename ValueType>
bool Map<KeyType, ValueType>::operator<(const Map& map2) {
  return privateMap < map2.privateMap;
}

template <typename KeyType, typename ValueType>
bool Map<KeyType, ValueType>::operator<=(const Map& map2) {
  return privateMap <= map2.privateMap;
}

template <typename KeyType, typename ValueType>
bool Map<KeyType, ValueType>::operator>(const Map& map2) {
  return privateMap > map2.privateMap;
}

template <typename KeyType, typename ValueType>
bool Map<KeyType, ValueType>::operator>=(const Map& map2) {
  return privateMap >= map2.privateMap;
}

template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::keyCheck(const KeyType& key) const {
  if (privateMap.find(key) == privateMap.end()) {
    error("The Map doesn't have this key!");
  }
}

}  // namespace cuhksz

#endif  // CUHKSZ_CONTAINERS_MAP
