#ifndef CUHKSZ_CONTAINERS_SET
#define CUHKSZ_CONTAINERS_SET

#include <set>
#include <utility>
#include "utils/error.h"

namespace cuhksz {
/**
	cuhksz::Set is a container which similar to stl set except
	some simplifications and modifications of interface.
**/
template<typename ValueType>
class Set {
public:
    typedef typename std::set<ValueType> stlSet;
    typedef ValueType value_type;

    Set();

    /**
        Construct a Set using a initializer_list.
        Usage:
        ```
        cuhksz::Set<ValueType> s {value1, value2};
        ```
    **/
    Set( std::initializer_list<ValueType> init );

    /**
		Initialize a List with a stl list.
		Usage:
		```
		cuhksz::List<ValueType> li(stlList);
		```
	**/
    Set(stlSet& stlSet2);

    ~Set();

    /**
		Assign a Set to another Set.
	**/
    Set& operator =(const Set& set2);

    /**
        Check whether the Set is empty.
    **/
    bool isEmpty() const;

    /**
		Return the size of the Set.
	**/
    int size() const;

    /**
		Insert the value into the Set.
	**/
    void insert(const ValueType& value);

    /**
        Erase the value in the Set.
    **/
    void erase(const ValueType& value);

    /**
        Empty the Set.
    **/
    void clear();

    /**
        Check if the Set contains the value.
    **/
    bool contains(ValueType value) const;

    typedef typename std::set<ValueType>::iterator iterator;
    typedef typename std::set<ValueType>::const_iterator const_iterator;

    /**
        Return the begin iterator.
    **/
    iterator begin() {
        return privateSet.begin();
    }

    /**
      Return the const iterator of begin.
    **/
    const_iterator begin() const {
        return privateSet.begin();
    }

    /**
        Return the end iterator.
    **/
    iterator end() {
        return privateSet.end();
    }

    /**
      Return the const iterator of end.
    **/
    const_iterator end() const {
        return privateSet.end();
    }

    /**
        Convert the Set to stl set explicitly.
        Usage:
        ```
        auto s = Set.toStlSet();
        ```
    **/
    stlSet toStlSet() {
        return privateSet;
    }

    /**
		Convert the Set to stl set implicitly.
		Usage:
		```
		std::set<ValueType> s = Set;
		```
	**/
    operator stlSet() { return privateSet; }

    /**
        Check if Set equals to set2.
    **/
    bool operator ==(const Set& set2);

    /**
        Check if Set does not equal to set2.
    **/
    bool operator !=(const Set& set2);

    /**
		Compare the contents of Set and set2 lexicographically.
	**/
    bool operator <(const Set& set2);

    /**
		Compare the contents of Set and set2 lexicographically.
	**/
    bool operator <=(const Set& set2);

    /**
		Compare the contents of Set and set2 lexicographically.
	**/
    bool operator >(const Set& set2);

    /**
		Compare the contents of Set and set2 lexicographically.
	**/
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
Set<ValueType>::Set(stlSet& stlSet2) {
    privateSet = stlSet2;
}

template<typename ValueType>
Set<ValueType>::~Set() {
    //do nothing
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
void Set<ValueType>::erase(const ValueType& value) {
        privateSet.erase(value);
}

template<typename ValueType>
void Set<ValueType>::clear() {
    privateSet.clear();
}

template<typename ValueType>
bool Set<ValueType>::contains(ValueType value) const {
    return (privateSet.find(value) != privateSet.end())? true : false;
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
