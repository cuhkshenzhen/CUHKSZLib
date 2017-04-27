#ifndef CUHKSZ_CONTAINERS_SET
#define CUHKSZ_CONTAINERS_SET

#include <set>
#include <utility>

namespace cuhksz {

template<typename ValueType>
class Set {
public:
    Set();
    Set( std::initializer_list<ValueType> init );
    Set(const Set& other);

    ~Set();

    Set& operator =(const Set& set2);

    bool isEmpty() const;

    int size() const;

    void insert(const ValueType& value);

    void erase(int index);

    int count(const ValueType& value) const;

    void clear();

    bool contains(ValueType value) const;

    typedef typename std::set<ValueType>::iterator iterator;
    typedef typename std::set<ValueType>::const_iterator const_iterator;

    iterator begin() {
        return privateSet.begin();
    }

    const_iterator begin() const {
        return privateSet.begin();
    }

    iterator end() {
        return privateSet.end();
    }

    const_iterator end() const {
        return privateSet.end();
    }

    std::set<ValueType> toStlSet(const Set& originSet);

    bool operator ==(const Set& set2);
    bool operator !=(const Set& set2);
    bool operator <(const Set& set2);
    bool operator <=(const Set& set2);
    bool operator >(const Set& set2);
    bool operator >=(const Set& set2);

private:
    std::set<ValueType> privateSet;

};

template<typename ValueType>
Set<ValueType>::Set() {
    //do nothing
}

template<typename ValueType>
Set<ValueType>::Set( std::initializer_list<ValueType> init ) {
    privateSet = init;
}

template<typename ValueType>
Set<ValueType>::Set(const Set& other) {
    privateSet = other.privateSet;
}

template<typename ValueType>
Set<ValueType>& Set<ValueType>::operator =(const Set& set2) {
    privateSet = set2.privateSet;
    return *this;
}

template<typename ValueType>
bool Set<ValueType>::isEmpty() const {
    return privateSet.empty();
}

template<typename ValueType>
int Set<ValueType>::size() const {
    return privateSet.size();
}

template<typename ValueType>
void Set<ValueType>::insert(const ValueType& value) {
    privateSet.insert(value);
}

template<typename ValueType>
void Set<ValueType>::erase(int index) {
    auto itr = privateSet.begin();
    std::advance(itr, index);
    privateSet.erase(itr);
}

template<typename ValueType>
int Set<ValueType>::count(const ValueType& value) const {
    return privateSet.count(value);
}

template<typename ValueType>
void Set<ValueType>::clear() {
    privateSet.clear();
}

template<typename ValueType>
bool Set<ValueType>::contains(ValueType value) const {
    return (privateSet.find(value) != privateSet.find())? true : false;
}


template<typename ValueType>
std::set<ValueType> Set<ValueType>::toStlSet(const Set& originSet) {
    return originSet.privateSet;
}

template<typename ValueType>
bool Set<ValueType>::operator ==(const Set& set2) {
    return privateSet == set2.privateSet;
}

template<typename ValueType>
bool Set<ValueType>::operator !=(const Set& set2) {
    return privateSet != set2.privateSet;
}
template<typename ValueType>
bool Set<ValueType>::operator <(const Set& set2) {
    return privateSet < set2.privateSet;
}

template<typename ValueType>
bool Set<ValueType>::operator <=(const Set& set2) {
    return privateSet <= set2.privateSet;
}

template<typename ValueType>
bool Set<ValueType>::operator >(const Set& set2) {
    return privateSet > set2.privateSet;
}

template<typename ValueType>
bool Set<ValueType>::operator >=(const Set& set2) {
    return privateSet >= set2.privateSet;
}

} //end namespace

#endif //CUHKSZ_CONTAINERS_SET
