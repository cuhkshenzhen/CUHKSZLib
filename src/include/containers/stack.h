#ifndef CUHKSZ_CONTAINERS_STACK
#define CUHKSZ_CONTAINERS_STACK

#include <stack>
#include <iostream>
#include <cstdlib>

namespace cuhksz {

template <typename ValueType>
class Stack {
public:
	Stack();

	~Stack();

	Stack& operator =(const Stack& stack2);

	int size() const;

	ValueType& top();
	const ValueType& top() const;

	bool isEmpty();

	void push(const ValueType& value);

	ValueType pop();

private:
	std::stack<ValueType> privateStack;
	void emptyCheck();

};

template <typename ValueType>
Stack<ValueType>::Stack() {
	//do nothing
}

template <typename ValueType>
Stack<ValueType>::~Stack() {
	//do nothing
}

template <typename ValueType>
Stack<ValueType> Stack<ValueType>::operator =(const Stack& stack2) {
	privateStack = stack2.privateStack;
	return *this;
}

template <typename ValueType>
int Stack<ValueType>::size() const {
	return privateStack.size();
}

template <typename ValueType>
ValueType& Stack<ValueType>::top() {
	return privateStack.top();
}

template <typename ValueType>
const ValueType& Stack<ValueType>::top() const {
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

void Stack<ValueType>::emptyCheck() {
	if(privateStack.empty()) {
		std::cout << "The stack is empty!" << '\n';
		std::exit(EXIT_FAILURE);
	}

}

} //end namespace

#endif
