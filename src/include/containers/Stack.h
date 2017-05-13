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
  Stack(stlStack& stlStack2);

  ~Stack();

  Stack operator=(const Stack& stack2);

  int size() const;

  ValueType& top();
  const ValueType& top() const;

  bool isEmpty();

  void push(const ValueType& value);

  ValueType pop();

  void clear();

  stlStack toStlStack() { return privateStack; }

  operator stlStack() { return privateStack; }

  bool operator==(const Stack& stack2);
  bool operator!=(const Stack& stack2);
  bool operator<(const Stack& stack2);
  bool operator<=(const Stack& stack2);
  bool operator>(const Stack& stack2);
  bool operator>=(const Stack& stack2);

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
