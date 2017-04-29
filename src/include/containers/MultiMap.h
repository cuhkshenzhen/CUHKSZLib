#ifndef CUHKSZ_CONTAINERS_MULTIMAP
#define CUHKSZ_CONTAINERS_MULTIMAP

#include <map>
#include "Set.h"
#include <utility>

namespace cuhksz {

template <typename KeyType, typename ValueType>
class MultiMap {
public:
    typedef std::pair<const KeyType, ValueType> StdValueType;
    typedef std::multimap<KeyType, ValueType> stlMultimap;

    MultiMap();
    MultiMap(const MultiMap& other);
    MultiMap( std::initializer_list<StdValueType> init );
    MultiMap( stlMultimap& stlMultimap2 );

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
        return privateMultimap.begin();
    }
    const_iterator begin() const {
        return privateMultimap.begin();
    }

    iterator end() {
        return privateMultimap.end();
    }
    const_iterator end() const {
        return privateMultimap.end();
    }


    Set<ValueType> find(const KeyType& key);

    stlMultimap toStlMultimap() {
        return privateMultimap;
    }

    operator stlMultimap() { return privateMultimap; }

    bool operator ==(const MultiMap& multimap2);
    bool operator !=(const MultiMap& multimap2);
    bool operator <(const MultiMap& multimap2);
    bool operator <=(const MultiMap& multimap2);
    bool operator >(const MultiMap& multimap2);
    bool operator >=(const MultiMap& multimap2);

private:
    std::multimap<KeyType, ValueType> privateMultimap;
};

template <typename KeyType, typename ValueType>
MultiMap<KeyType, ValueType>::MultiMap() {
    //do nothing
}

template <typename KeyType, typename ValueType>
MultiMap<KeyType, ValueType>::MultiMap(const MultiMap& other) {
    privateMultimap = other.privateMultimap;
}

template <typename KeyType, typename ValueType>
MultiMap<KeyType, ValueType>::MultiMap( std::initializer_list<StdValueType> init) {
    privateMultimap = init;
}

template <typename KeyType, typename ValueType>
MultiMap<KeyType, ValueType>::MultiMap( stlMultimap& stlMultimap2 ) {
    privateMultimap = stlMultimap2;
}

template <typename KeyType, typename ValueType>
MultiMap<KeyType, ValueType>::~MultiMap() {
    //do nothing
}

template <typename KeyType, typename ValueType>
MultiMap<KeyType, ValueType>&
MultiMap<KeyType, ValueType>::operator =(MultiMap& multimap2) {
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
bool MultiMap<KeyType, ValueType>::operator ==(const MultiMap& multimap2) {
    return privateMultimap == multimap2.privateMultimap;
}

template <typename KeyType, typename ValueType>
bool MultiMap<KeyType, ValueType>::operator !=(const MultiMap& multimap2) {
  return privateMultimap != multimap2.privateMultimap;
}

template <typename KeyType, typename ValueType>
bool MultiMap<KeyType, ValueType>::operator <(const MultiMap& multimap2) {
  return privateMultimap < multimap2.privateMultimap;
}

template <typename KeyType, typename ValueType>
bool MultiMap<KeyType, ValueType>::operator <=(const MultiMap& multimap2) {
  return privateMultimap <= multimap2.privateMultimap;
}

template <typename KeyType, typename ValueType>
bool MultiMap<KeyType, ValueType>::operator >(const MultiMap& multimap2) {
  return privateMultimap > multimap2.privateMultimap;
}

template <typename KeyType, typename ValueType>
bool MultiMap<KeyType, ValueType>::operator >=(const MultiMap& multimap2) {
  return privateMultimap >= multimap2.privateMultimap;
}

} //end namespace

#endif //CUHKSZ_CONTAINERS_MULTIMAP
