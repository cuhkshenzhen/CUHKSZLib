#ifndef CUHKSZ_CONTAINERS_LIST
#define CUHKSZ_CONTAINERS_LIST

#include <list>
#include <utility>
#include "utils/error.h"

namespace cuhksz {

template <typename ValueType>
class List {
public:
	typedef typename std::list<ValueType> stlList;

	List(); //constructor
	explicit List(int n, ValueType value = ValueType());
	List(std::initializer_list<ValueType> init);
	List(stlList& stlList2);

	~List(); //deconstructor

	List& operator =(const List& list2);

	ValueType& first();
	const ValueType& first() const;

	ValueType& last();
	const ValueType& last() const;

	ValueType& operator [](int index);
	const ValueType& operator [](int index) const;

	bool isEmpty() const;

	int size() const;

	void clear();

	void insert(int index, ValueType value);

	void erase(int index);


	void push(const ValueType& value);
	void push_front(const ValueType& value);

	ValueType pop();
	ValueType pop_front();

	void sort();

	void reverse();

	void merge(List& list2);

	stlList toStlList() {
		return privateList;
	}

	operator stlList() const { return privateList; }

	bool operator ==(const List& list2);
	bool operator !=(const List& list2);
	bool operator <(const List& list2);
	bool operator <=(const List& list2);
	bool operator >(const List& list2);
	bool operator >=(const List& list2);

	typedef typename std::list<ValueType>::const_iterator const_iterator;
	typedef typename std::list<ValueType>::iterator iterator;

	iterator begin() {
      	  return privateList.begin();
      }

    	const_iterator begin() const {
      	  return privateList.begin();
      }

	iterator end() {
      	  return privateList.end();
      }

    	const_iterator end() const {
      	  return privateList.end();
      }

private:
	std::list<ValueType> privateList;
	void boundaryCheck(int index);
	void emptyCheck();

}; //end list class

/*-------Implementation-------*/

template <typename ValueType>
List<ValueType>::List() {
	//do nothing
}

template <typename ValueType>
List<ValueType>::List(int n, ValueType value) {
	privateList.resize(n, value);
}

template <typename ValueType>
List<ValueType>::List(std::initializer_list<ValueType> init) {
	privateList = init;
}

template <typename ValueType>
List<ValueType>::List(stlList& stlList2) {
	privateList = stlList2;
}

template <typename ValueType>
List<ValueType>::~List() {
	//do nothing
}

template <typename ValueType>
List<ValueType>& List<ValueType>::operator =(const List& list2) {
	privateList = list2.privateList;
	return *this;
}

template <typename ValueType>
ValueType& List<ValueType>::first() {
	emptyCheck();
	return privateList.front();
}

template <typename ValueType>
const ValueType& List<ValueType>::first() const {
	emptyCheck();
	return privateList.front();
}

template <typename ValueType>
ValueType& List<ValueType>::last() {
	emptyCheck();
	return privateList.back();
}

template <typename ValueType>
const ValueType& List<ValueType>::last() const {
	emptyCheck();
	return privateList.back();
}

template <typename ValueType>
ValueType& List<ValueType>::operator [](int index) {
	boundaryCheck(index);
	auto iterator = privateList.begin();
	for (int i = 0; i != index; i++) {
		++iterator;
	}
	return *iterator;
}

template <typename ValueType>
const ValueType& List<ValueType>::operator [](int index) const {
	boundaryCheck(index);
	auto iterator = privateList.begin();
	for (int i = 0; i != index; i++) {
		++iterator;
	}
	return *iterator;
}


template <typename ValueType>
bool List<ValueType>::isEmpty() const {
	 return privateList.empty();
}

template <typename ValueType>
int List<ValueType>::size() const {
	return privateList.size();
}

template <typename ValueType>
void List<ValueType>::clear() {
	privateList.clear();
}

template <typename ValueType>
void List<ValueType>::insert(int index, ValueType value) {
	boundaryCheck(index);
	auto iterator = privateList.begin();
	std::advance(iterator, index);
	privateList.insert(iterator, value);
}

template <typename ValueType>
void List<ValueType>::erase(int index) {
	boundaryCheck(index);
	auto iterator = privateList.begin();
    std::advance(iterator, index);
    privateList.erase(iterator);
}

template <typename ValueType>
void List<ValueType>::push(const ValueType& value) {
	privateList.push_back(value);
}

template <typename ValueType>
void List<ValueType>::push_front(const ValueType& value) {
	privateList.push_front(value);
}

template <typename ValueType>
ValueType List<ValueType>::pop() {
	emptyCheck();
	ValueType lastElement = privateList.back();
    privateList.pop_back();
    return lastElement;
}

template <typename ValueType>
ValueType List<ValueType>::pop_front() {
	emptyCheck();
	ValueType firstElement = privateList.front();
	privateList.pop_front();
	return firstElement;
}

template <typename ValueType>
void List<ValueType>::sort() {
	privateList.sort();
}

template <typename ValueType>
void List<ValueType>::reverse() {
	privateList.reverse();
}

template <typename ValueType>
void List<ValueType>::merge(List& list2) {
	privateList.merge(list2.privateList);
}

template <typename ValueType>
bool List<ValueType>::operator ==(const List& list2) {
	return privateList == list2.privateList;
}

template <typename ValueType>
bool List<ValueType>::operator !=(const List& list2) {
	return privateList != list2.privateList;
}

template <typename ValueType>
bool List<ValueType>::operator <(const List& list2) {
	return privateList < list2.privateList;
}

template <typename ValueType>
bool List<ValueType>::operator <=(const List& list2) {
	return privateList <= list2.privateList;
}

template <typename ValueType>
bool List<ValueType>::operator >(const List& list2) {
	return privateList > list2.privateList;
}

template <typename ValueType>
bool List<ValueType>::operator >=(const List& list2) {
	return privateList >= list2.privateList;
}

template <typename ValueType>
void List<ValueType>::boundaryCheck(int index) {
	if (index < 0 || index >= privateList.size()) {
		error("The index out of range!");
	}
}

template <typename ValueType>
void List<ValueType>::emptyCheck() {
	if (privateList.empty()) {
		error("The list is empty!");
	}
}

} //end namespace

#endif //CUHKSZ_CONTAINERS_LIST
