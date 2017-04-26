#ifndef CUHKSZ_CONTAINERS_QUEUE
#define CUHKSZ_CONTAINERS_QUEUE

#include <queue>
#include <iostream>
#include <cstdlib>


namespace cuhksz {

template <typename ValueType>
class Queue {
public:
	Queue();
	~Queue();

	Queue operator =(const Queue& queue2);

	ValueType& first();
	const ValueType& first() const;

	ValueType& last();
	const ValueType& last() const;

	int size() const;

	bool isEmpty();

	void enqueue(const ValueType& value);

	ValueType dequeue();

	void clear();

	bool operator ==(const Queue& queue2);
    bool operator !=(const Queue& queue2);
    bool operator <(const Queue& queue2);
    bool operator <=(const Queue& queue2);
    bool operator >(const Queue& queue2);
    bool operator >=(const Queue& queue2);

private:
	std::queue<ValueType> privateQueue;
	void emptyCheck();


};

template <typename ValueType>
Queue<ValueType>::Queue() {
	//do nothing
}

template <typename ValueType>
Queue<ValueType>::~Queue(){
	//do nothing
}

template <typename ValueType>
Queue<ValueType> Queue<ValueType>::operator =(const Queue& queue2) {
	privateQueue = queue2.privateQueue;
	return *this;
}

template <typename ValueType>
ValueType& Queue<ValueType>::first() {
	return privateQueue.front();
}

template <typename ValueType>
const ValueType& Queue<ValueType>::first() const {
	return privateQueue.front();
}

template <typename ValueType>
ValueType& Queue<ValueType>::last() {
	return privateQueue.back();
}

template <typename ValueType>
const ValueType& Queue<ValueType>::last() const {
	return privateQueue.back();
}

template <typename ValueType>
int Queue<ValueType>::size() const {
	return privateQueue.size();
}

template <typename ValueType>
bool Queue<ValueType>::isEmpty() {
	return privateQueue.empty();
}

template <typename ValueType>
void Queue<ValueType>::enqueue(const ValueType& value) {
	privateQueue.push(value);
}

template <typename ValueType>
ValueType Queue<ValueType>::dequeue() {
	emptyCheck();
	ValueType firstElement = privateQueue.front();
	privateQueue.pop();
	return firstElement;
}

template <typename ValueType>
void Queue<ValueType>::clear() {
	int size = privateQueue.size();
	for (int i = 0; i != size; i++) {
		privateQueue.pop();
	}
}

template <typename ValueType>
bool Queue<ValueType>::operator ==(const Queue& queue2) {
    return privateQueue == queue2.privateQueue;
}

template <typename ValueType>
bool Queue<ValueType>::operator !=(const Queue& queue2) {
  return privateQueue != queue2.privateQueue;
}

template <typename ValueType>
bool Queue<ValueType>::operator <(const Queue& queue2) {
  return privateQueue < queue2.privateQueue;
}

template <typename ValueType>
bool Queue<ValueType>::operator <=(const Queue& queue2) {
  return privateQueue <= queue2.privateQueue;
}

template <typename ValueType>
bool Queue<ValueType>::operator >(const Queue& queue2) {
  return privateQueue > queue2.privateQueue;
}

template <typename ValueType>
bool Queue<ValueType>::operator >=(const Queue& queue2) {
  return privateQueue >= queue2.privateQueue;
}

template <typename ValueType>
void Queue<ValueType>::emptyCheck() {
	if (privateQueue.empty()) {
		std::cout << "The queue is empty!" << '\n';
		std::exit(EXIT_FAILURE);
	}
}

} //end namespace


#endif
