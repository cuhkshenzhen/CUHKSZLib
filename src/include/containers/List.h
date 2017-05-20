#ifndef CUHKSZ_CONTAINERS_LIST
#define CUHKSZ_CONTAINERS_LIST

#include <list>
#include <utility>
#include "utils/error.h"

namespace cuhksz {
/**
	cuhksz::List is a container which similar to stl list except
	some simplifications of interface.
**/

template <typename ValueType>
class List {
 public:
  typedef typename std::list<ValueType> stlList;
  typedef ValueType value_type;


	List(); //constructor

	/**
		Construct a List with n value(s).
		Usage:
		```
		cuhksz::List<ValueType> li(n, value);
		```
	**/
	explicit List(int n, ValueType value = ValueType());

	/**
		Construct a List using a initializer_list.
		Usage:
		```
		cuhksz::List<ValueType> li {value1, value2};
		```
	**/
	List(std::initializer_list<ValueType> init);

	/**
		Initialize a List with a stl list.
		Usage:
		```
		cuhksz::List<ValueType> li(stlList);
		```
	**/
	List(stlList& stlList2);

  ~List();  // deconstructor


	/**
		Assign a List to another List.
	**/
	List& operator =(const List& list2);

	/**
		Get the first element in the List.
		Return a reference to that element.
	**/
	ValueType& first();

	/**
		Get the first element in the List.
		Return a const reference to that element.
	**/
	const ValueType& first() const;

	/**
		Get the last element in the List.
		Return a reference to that element.
	**/
	ValueType& last();

	/**
		Get the last element in the List.
		Return a const reference to that element.
	**/
	const ValueType& last() const;

	/**
		Get the element at the specified index.
		Return a reference to that element.
	**/
	ValueType& operator [](int index);

	/**
		Get the element at the specified index.
		Return a const reference to that element.
	**/
	const ValueType& operator [](int index) const;

	/**
		Check whether the List is empty.
	**/
	bool isEmpty() const;

	/**
		Return the size of the List.
	**/
	int size() const;

	/**
		Empty the List.
	**/
	void clear();

	/**
		Insert value before index, it is allowed to
		insert value at the end. It will cause error
		if index out of range.
	**/
	void insert(int index, ValueType value);

	/**
		Erase the element at index with boundary checking.
	**/
	void erase(int index);

	/**
		Push the value to the end.
	**/
	void push(const ValueType& value);

	/**
		Push the value to the front.
	**/
	void push_front(const ValueType& value);

	/**
		Return and remove the last element.
	**/
	ValueType pop();

	/**
		Return and remove the first element.
	**/
	ValueType pop_front();

	/**
		Sort the List.
	**/
	void sort();

	/**
		Reverse the List.
	**/
	void reverse();

	/**
		Merge List with list2.
	**/
	void merge(List& list2);

	/**
		Convert the List to stl list explicitly.
		Usage:
		```
		auto li = List.toStlList();
		```
	**/
	stlList toStlList() {
		return privateList;
	}

	/**
		Convert the List to stl list implicitly.
		Usage:
		```
		std::list<ValueType> li = List;
		```
	**/
	operator stlList() const { return privateList; }

	/**
		Check if List equals to list2.
	**/
	bool operator ==(const List& list2);

	/**
		Check if List does not equal to list2.
	**/
	bool operator !=(const List& list2);

	/**
		Compare the contents of List and list2 lexicographically.
	**/
	bool operator <(const List& list2);

	/**
		Compare the contents of List and list2 lexicographically.
	**/
	bool operator <=(const List& list2);

	/**
		Compare the contents of List and list2 lexicographically.
	**/
	bool operator >(const List& list2);

	/**
		Compare the contents of List and list2 lexicographically.
	**/
	bool operator >=(const List& list2);


  typedef typename std::list<ValueType>::const_iterator const_iterator;
  typedef typename std::list<ValueType>::iterator iterator;

	/**
		Return the begin iterator.
	**/
	iterator begin() {
      	  return privateList.begin();
      }

	  /**
    	Return the const iterator of begin.
      **/
    	const_iterator begin() const {
      	  return privateList.begin();
      }

	/**
  		Return the end iterator.
  	**/
	iterator end() {
      	  return privateList.end();
      }

	  /**
    	Return the const iterator of end.
      **/
    	const_iterator end() const {
      	  return privateList.end();
      }

private:
	std::list<ValueType> privateList;
	void boundaryCheck(int index) const;
	void emptyCheck() const;

}; //end list class

/*-------Implementation-------*/

template <typename ValueType>
List<ValueType>::List() {
  // do nothing
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
  // do nothing
}

template <typename ValueType>
List<ValueType>& List<ValueType>::operator=(const List& list2) {
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
ValueType& List<ValueType>::operator[](int index) {
  boundaryCheck(index);
  auto iterator = privateList.begin();
  for (int i = 0; i != index; i++) {
    ++iterator;
  }
  return *iterator;
}

template <typename ValueType>
const ValueType& List<ValueType>::operator[](int index) const {
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
  size_t unsignedIndex = index;
  if (index < 0 || unsignedIndex > privateList.size()) {
    error("The index out of range!");
  }
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
bool List<ValueType>::operator==(const List& list2) {
  return privateList == list2.privateList;
}

template <typename ValueType>
bool List<ValueType>::operator!=(const List& list2) {
  return privateList != list2.privateList;
}

template <typename ValueType>
bool List<ValueType>::operator<(const List& list2) {
  return privateList < list2.privateList;
}

template <typename ValueType>
bool List<ValueType>::operator<=(const List& list2) {
  return privateList <= list2.privateList;
}

template <typename ValueType>
bool List<ValueType>::operator>(const List& list2) {
  return privateList > list2.privateList;
}

template <typename ValueType>
bool List<ValueType>::operator>=(const List& list2) {
  return privateList >= list2.privateList;
}

template <typename ValueType>
void List<ValueType>::boundaryCheck(int index) const {
  size_t unsignedIndex = index;
  if (index < 0 || unsignedIndex >= privateList.size()) {
    error("The index out of range!");
  }
}

template <typename ValueType>
void List<ValueType>::emptyCheck() const {
  if (privateList.empty()) {
    error("The list is empty!");
  }
}

}  // namespace cuhksz

#endif  // CUHKSZ_CONTAINERS_LIST
