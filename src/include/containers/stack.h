#ifndef CUHKSZ_CONTAINERS_STACK
#define CUHKSZ_CONTAINERS_STACK

#include <stack>
#include <iostream>
#include <cstdlib>

namespace cuhksz {

template <typename ValueType>
class stack {
public:
	stack();

	virtual ~stack();

	stack& operator =(const stack& stack2);

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
stack<ValueType>::stack() {
	//do nothing
}

template <typename ValueType>
stack<ValueType>::~stack() {
	//do nothing
}

template <typename ValueType>
stack<ValueType> stack<ValueType>::operator =(const stack& stack2) {
	privateStack = stack2.privateStack;
	return *this;
}

template <typename ValueType>
int stack<ValueType>::size() const {
	return privateStack.size();
}

template <typename ValueType>
ValueType& stack<ValueType>::top() {
	return privateStack.top();
}

template <typename ValueType>
const ValueType& stack<ValueType>::top() const {
	return privateStack.top();
}

template <typename ValueType>
bool stack<ValueType>::isEmpty() {
	return privateStack.empty();
}

template <typename ValueType>
void stack<ValueType>::push(const ValueType& value) {
	privateStack.push(value);
}

template <typename ValueType>
ValueType stack<ValueType>::pop() {
	emptyCheck();
	ValueType lastElement = privateStack.top();
	privateStack.pop();
	return lastElement;
}

void stack<ValueType>::emptyCheck() {
	if(privateStack.empty()) {
		std::cout << "The stack is empty!" << '\n';
		std::exit(EXIT_FAILURE);
	}

}

} //end namespace

#endif