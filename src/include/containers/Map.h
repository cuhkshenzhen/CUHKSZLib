#ifndef CUHKSZ_CONTAINERS_MAP
#define CUHKSZ_CONTAINERS_MAP

#include <map>
#include <utility>

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

    bool isEmpty();

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

    iterator find(const KeyType& key) {
        return privateMultiMap.find(key);
    }
    const_iterator find(const KeyType& key) const {
        return privateMultiMap.find(key);
    }

    typedef typename std::pair<iterator, iterator> pair;
    typedef typename std::pair<const_iterator, const_iterator> constPair;

    pair equal_range(const KeyType& key) {
        return privateMultiMap.equal_range(key);
    }
    constPair equal_range(const KeyType& key) const {
        return privateMultiMap.equal_range(key);
    }

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
bool MultiMap<KeyType, ValueType>::isEmpty() {
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

} //end namespace

#endif //CUHKSZ_CONTAINERS_MAP
