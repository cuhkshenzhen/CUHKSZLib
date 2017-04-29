#ifndef CUHKSZ_CONTAINERS_MULTISET
#define CUHKSZ_CONTAINERS_MULTISET

#include <set>
#include <utility>

namespace cuhksz {

template <typename ValueType>
class MultiSet {
public:
    typedef typename std::multiset<ValueType> stlMultiset;

    MultiSet();
    MultiSet(std::initializer_list<ValueType> init);
    MultiSet(stlMultiset& stlMultiset2);

    ~MultiSet();

    MultiSet& operator =(const MultiSet& multiset2);

    bool isEmpty() const;

    int size() const;

    void insert(ValueType& value);

    void erase(const ValueType& value);

    int count(const ValueType& value) const;

    void clear();

    bool contains(ValueType& value) const;

    typedef typename std::multiset<ValueType>::iterator iterator;
    typedef typename std::multiset<ValueType>::const_iterator const_iterator;

    iterator begin() {
        return privateMultiset.begin();
    }

    const_iterator begin() const {
        return privateMultiset.begin();
    }

    iterator end() {
        return privateMultiset.end();
    }

    const_iterator end() const {
        return privateMultiset.end();
    }

    stlMultiset toStlMultiSet() {
        return privateMultiset;
    }

    operator stlMultiset() { return privateMultiset; }

    bool operator ==(const MultiSet& multiset2);
    bool operator !=(const MultiSet& multiset2);
    bool operator <(const MultiSet& multiset2);
    bool operator <=(const MultiSet& multiset2);
    bool operator >(const MultiSet& multiset2);
    bool operator >=(const MultiSet& multiset2);

private:
    std::multiset<ValueType> privateMultiset;
};

template <typename ValueType>
MultiSet<ValueType>::MultiSet() {
    //do nothing
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
    //do nothing
}

template <typename ValueType>
MultiSet<ValueType>&
MultiSet<ValueType>::operator =(const MultiSet& multiset2) {
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
void MultiSet<ValueType>::insert(ValueType& value) {
    privateMultiset.insert(value);
}

template <typename ValueType>
void MultiSet<ValueType>::erase(const ValueType& value) {
        privateMultiset.erase(value);
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
bool MultiSet<ValueType>::contains(ValueType& value) const {
    return (privateMultiset.find(value) != privateMultiset.end())? true : false;
}

template <typename ValueType>
bool MultiSet<ValueType>::operator ==(const MultiSet& multiset2) {
    return privateMultiset == multiset2.privateMultiset;
}

template <typename ValueType>
bool MultiSet<ValueType>::operator !=(const MultiSet& multiset2) {
    return privateMultiset != multiset2.privateMultiset;
}

template <typename ValueType>
bool MultiSet<ValueType>::operator <(const MultiSet& multiset2) {
    return privateMultiset < multiset2.privateMultiset;
}

template <typename ValueType>
bool MultiSet<ValueType>::operator <=(const MultiSet& multiset2) {
    return privateMultiset <= multiset2.privateMultiset;
}

template <typename ValueType>
bool MultiSet<ValueType>::operator >(const MultiSet& multiset2) {
    return privateMultiset > multiset2.privateMultiset;
}

template <typename ValueType>
bool MultiSet<ValueType>::operator >=(const MultiSet& multiset2) {
    return privateMultiset >= multiset2.privateMultiset;
}

} //end namespace

#endif //CUHKSZ_CONTAINERS_MULTISET
