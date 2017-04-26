#ifndef CUHKSZ_CONTAINERS_MultiMap
#define CUHKSZ_CONTAINERS_MultiMap

#include <map>
#include <set>
#include <utility>

using std::set;

namespace cuhksz {

template <typename KeyType, typename ValueType>
class MultiMap {
public:
    typedef std::pair<const KeyType, ValueType> StdValueType;
    MultiMap();
    MultiMap(const std::multimap<KeyType, ValueType>& other);
    MultiMap( std::initializer_list<StdValueType> init );

    ~MultiMap();

    MultiMap& operator =(MultiMap& multimap2);

    bool isEmpty() const;

    int size() const;

    void clear();

    void erase(const KeyType& key);

    int count(const KeyType& key) const;

    typedef typename std::multimap<KeyType, ValueType>::iterator iterator;
    typedef typename std::multimap<KeyType, ValueType>::const_iterator const_iterator;

    iterator begin() {
        return privateMultiMap.begin();
    }
    const_iterator begin() const {
        return privateMultiMap.begin();
    }

    iterator end() {
        return privateMultiMap.end();
    }
    const_iterator end() const {
        return privateMultiMap.end();
    }


    set<ValueType>& find(const KeyType& key);

    bool operator ==(const MultiMap& multimap2);
    bool operator !=(const MultiMap& multimap2);
    bool operator <(const MultiMap& multimap2);
    bool operator <=(const MultiMap& multimap2);
    bool operator >(const MultiMap& multimap2);
    bool operator >=(const MultiMap& multimap2);

private:
    std::multimap<KeyType, ValueType> privateMultiMap;
};

template <typename KeyType, typename ValueType>
MultiMap<KeyType, ValueType>::MultiMap() {
    //do nothing
}

template <typename KeyType, typename ValueType>
MultiMap<KeyType, ValueType>::MultiMap(const std::multimap<KeyType, ValueType>& other) {
    privateMultiMap = other;
}

// typedef std::pair<const KeyType, ValueType> StdValueType;
template <typename KeyType, typename ValueType>
MultiMap<KeyType, ValueType>::MultiMap( std::initializer_list<StdValueType> init) {
    privateMultiMap = init;
}

template <typename KeyType, typename ValueType>
MultiMap<KeyType, ValueType>::~MultiMap() {
    //do nothing
}

template <typename KeyType, typename ValueType>
MultiMap<KeyType, ValueType>&
MultiMap<KeyType, ValueType>::operator =(MultiMap& multimap2) {
    privateMultiMap = multimap2.privateMultiMap;
    return *this;
}

template <typename KeyType, typename ValueType>
bool MultiMap<KeyType, ValueType>::isEmpty() const {
    return privateMultiMap.empty();
}

template <typename KeyType, typename ValueType>
int MultiMap<KeyType, ValueType>::size() const {
    return privateMultiMap.size();
}

template <typename KeyType, typename ValueType>
void MultiMap<KeyType, ValueType>::clear() {
    privateMultiMap.clear();
}

template <typename KeyType, typename ValueType>
void MultiMap<KeyType, ValueType>::erase(const KeyType& key) {
    privateMultiMap.erase(key);
}

template <typename KeyType, typename ValueType>
int MultiMap<KeyType, ValueType>::count(const KeyType& key) const {
    return privateMultiMap.count(key);
}


template <typename KeyType, typename ValueType>
set<ValueType>& MultiMap<KeyType, ValueType>::find(const KeyType& key) {
    static set<ValueType> valueSet;
    auto elementsFound = privateMultiMap.equal_range(key);
    for (auto i = elementsFound.first; i != elementsFound.second; ++i) {
        valueSet.insert(i->second());
    }
    return valueSet;
}

template <typename KeyType, typename ValueType>
bool MultiMap<ValueType>::operator ==(const MultiMap& multimap2) {
    return privateMultiMap == multimap2.privateMultiMap;
}

template <typename KeyType, typename ValueType>
bool MultiMap<ValueType>::operator !=(const MultiMap& multimap2) {
  return privateMultiMap != multimap2.privateMultiMap;
}

template <typename KeyType, typename ValueType>
bool MultiMap<ValueType>::operator <(const MultiMap& multimap2) {
  return privateMultiMap < multimap2.privateMultiMap;
}

template <typename KeyType, typename ValueType>
bool MultiMap<ValueType>::operator <=(const MultiMap& multimap2) {
  return privateMultiMap <= multimap2.privateMultiMap;
}

template <typename KeyType, typename ValueType>
bool MultiMap<ValueType>::operator >(const MultiMap& multimap2) {
  return privateMultiMap > multimap2.privateMultiMap;
}

template <typename KeyType, typename ValueType>
bool MultiMap<ValueType>::operator >=(const MultiMap& multimap2) {
  return privateMultiMap >= multimap2.privateMultiMap;
}

} //end namespace

#endif //CUHKSZ_CONTAINERS_MultiMap
