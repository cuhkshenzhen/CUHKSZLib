#ifndef CUHKSZ_CONTAINERS_STACK
#define CUHKSZ_CONTAINERS_STACK

#include <stack>
#include "utils/error.h"

namespace cuhksz {

template <typename ValueType>
class Stack {
 public:
  typedef typename std::stack<ValueType> stlStack;
  typedef ValueType value_type;

	Stack();

	/**
		Initialize a Stack with a stl stack.
		Usage:
		```
		cuhksz::Stack<ValueType> s(stlStack);
		```
	**/
	Stack( stlStack& stlStack2 );


  ~Stack();

	/**
		Assign a Stack to another Stack.
	**/
	Stack operator =(const Stack& stack2);

	/**
		Return the size of the Stack.
	**/
	int size() const;

	/**
		Return a reference to the element on the top.
	**/
	ValueType& top();

	/**
		Return a const reference to the element on the top.
	**/
	const ValueType& top() const;

	/**
		Check whether the Stack is empty.
	**/
	bool isEmpty();

	/**
		Push the value into the Stack.
	**/
	void push(const ValueType& value);

	/**
		Pop a element of the Stack based on the LILO principle.
		Return the value.
	**/
	ValueType pop();

	/**
		Empty the Stack.
	**/
	void clear();

	/**
		Convert the Stack to stl stack explicitly.
		Usage:
		```
		auto s = Stack.toStlStack();
		```
	**/
	stlStack toStlStack() {
		return privateStack;
	}

	/**
		Convert the Stack to stl stack implicitly.
		Usage:
		```
		std::stack<ValueType> s = Stack;
		```
	**/
	operator stlStack() { return privateStack; }

	/**
		Check if Stack equals to stack2.
	**/
	bool operator ==(const Stack& stack2);

	/**
		Check if Stack does not equal to stack2.
	**/
    bool operator !=(const Stack& stack2);

	/**
		Compare the contents of Stack and stack2 lexicographically.
	**/
    bool operator <(const Stack& stack2);

	/**
		Compare the contents of Stack and stack2 lexicographically.
	**/
    bool operator <=(const Stack& stack2);

	/**
		Compare the contents of Stack and stack2 lexicographically.
	**/
    bool operator >(const Stack& stack2);

	/**
		Compare the contents of Stack and stack2 lexicographically.
	**/
    bool operator >=(const Stack& stack2);

private:
	std::stack<ValueType> privateStack;
	void emptyCheck() const;
};

template <typename ValueType>
Stack<ValueType>::Stack() {
  // do nothing
}

template <typename ValueType>
Stack<ValueType>::Stack(stlStack& stlStack2) {
  privateStack = stlStack2;
}

template <typename ValueType>
Stack<ValueType>::~Stack() {
  // do nothing
}

template <typename ValueType>
Stack<ValueType> Stack<ValueType>::operator=(const Stack& stack2) {
  privateStack = stack2.privateStack;
  return *this;
}

template <typename ValueType>
int Stack<ValueType>::size() const {
  return privateStack.size();
}

template <typename ValueType>
ValueType& Stack<ValueType>::top() {
  emptyCheck();
  return privateStack.top();
}

template <typename ValueType>
const ValueType& Stack<ValueType>::top() const {
  emptyCheck();
  return privateStack.top();
}

template <typename ValueType>
bool Stack<ValueType>::isEmpty() {
  return privateStack.empty();
}

template <typename ValueType>
void Stack<ValueType>::push(const ValueType& value) {
  privateStack.push(value);
}

template <typename ValueType>
ValueType Stack<ValueType>::pop() {
  emptyCheck();
  ValueType lastElement = privateStack.top();
  privateStack.pop();
  return lastElement;
}

template <typename ValueType>
void Stack<ValueType>::clear() {
  int size = privateStack.size();
  for (int i = 0; i != size; i++) {
    privateStack.pop();
  }
}

template <typename ValueType>
bool Stack<ValueType>::operator==(const Stack& stack2) {
  return privateStack == stack2.privateStack;
}

template <typename ValueType>
bool Stack<ValueType>::operator!=(const Stack& stack2) {
  return privateStack != stack2.privateStack;
}

template <typename ValueType>
bool Stack<ValueType>::operator<(const Stack& stack2) {
  return privateStack < stack2.privateStack;
}

template <typename ValueType>
bool Stack<ValueType>::operator<=(const Stack& stack2) {
  return privateStack <= stack2.privateStack;
}

template <typename ValueType>
bool Stack<ValueType>::operator>(const Stack& stack2) {
  return privateStack > stack2.privateStack;
}

template <typename ValueType>
bool Stack<ValueType>::operator>=(const Stack& stack2) {
  return privateStack >= stack2.privateStack;
}

template <typename ValueType>
void Stack<ValueType>::emptyCheck() const {
  if (privateStack.empty()) {
    error("The stack is empty!");
  }
}

}  // namespace cuhksz

#endif  // CUHKSZ_CONTAINERS_STACK
