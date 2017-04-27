#ifndef CUHKSZ_CONTAINERS_MULTISET
#define CUHKSZ_CONTAINERS_MULTISET

#include <set>
#include <utility>

namespace cuhksz {

template <typename ValueType>
class Multiset {
public:
    Multiset();
    Multiset(std::initializer_list<ValueType> init);
    Multiset(const Multiset& other);

    ~Multiset();

    Multiset& operator =(const Multiset& multiset2);

    bool isEmpty() const;

    int size() const;

    void insert(ValueType& value);

    void erase(int index);

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

    std::multiset<ValueType> toStlMultiSet(const Multiset& multiset2);

    bool operator ==(const Multiset& multiset2);
    bool operator !=(const Multiset& multiset2);
    bool operator <(const Multiset& multiset2);
    bool operator <=(const Multiset& multiset2);
    bool operator >(const Multiset& multiset2);
    bool operator >=(const Multiset& multiset2);

private:
    std::multiset<ValueType> privateMultiset;
};

template <typename ValueType>
Multiset<ValueType>::Multiset() {
    //do nothing
}

template <typename ValueType>
Multiset<ValueType>::Multiset(std::initializer_list<ValueType> init) {
    privateMultiset = init;
}

template <typename ValueType>
Multiset<ValueType>::Multiset(const Multiset& other) {
    privateMultiset = other.privateMultiset;
}

template <typename ValueType>
Multiset<ValueType>::~Multiset() {
    //do nothing
}

template <typename ValueType>
Multiset<ValueType>&
Multiset<ValueType>::operator =(const Multiset& multiset2) {
    privateMultiset = multiset2.privateMultiset;
    return *this;
}

template <typename ValueType>
bool Multiset<ValueType>::isEmpty() const {
    return privateMultiset.empty();
}

template <typename ValueType>
int Multiset<ValueType>::size() const {
    return privateMultiset.size();
}

template <typename ValueType>
void Multiset<ValueType>::insert(ValueType& value) {
    privateMultiset.insert(value);
}

template <typename ValueType>
void Multiset<ValueType>::erase(int index) {
    auto itr = privateMultiset.begin();
    std::advance(itr, index);
    privateMultiset.erase(itr);
}

template <typename ValueType>
int Multiset<ValueType>::count(const ValueType& value) const {
    return privateMultiset.count(value);
}

template <typename ValueType>
void Multiset<ValueType>::clear() {
    privateMultiset.clear();
}

template <typename ValueType>
bool Multiset<ValueType>::contains(ValueType& value) const {
    return (privateMultiset.find(value) != privateMultiset.end())? true : false;
}

template <typename ValueType>
std::multiset<ValueType>
Multiset<ValueType>::toStlMultiSet(const Multiset& multiset2) {
    return multiset2.privateMultiset;
}

template <typename ValueType>
bool Multiset<ValueType>::operator ==(const Multiset& multiset2) {
    return privateMultiset == multiset2.privateMultiset;
}

template <typename ValueType>
bool Multiset<ValueType>::operator !=(const Multiset& multiset2) {
    return privateMultiset != multiset2.privateMultiset;
}

template <typename ValueType>
bool Multiset<ValueType>::operator <(const Multiset& multiset2) {
    return privateMultiset < multiset2.privateMultiset;
}

template <typename ValueType>
bool Multiset<ValueType>::operator <=(const Multiset& multiset2) {
    return privateMultiset <= multiset2.privateMultiset;
}

template <typename ValueType>
bool Multiset<ValueType>::operator >(const Multiset& multiset2) {
    return privateMultiset > multiset2.privateMultiset;
}

template <typename ValueType>
bool Multiset<ValueType>::operator >=(const Multiset& multiset2) {
    return privateMultiset >= multiset2.privateMultiset;
}

} //end namespace

#endif //CUHKSZ_CONTAINERS_MULTISET
