#ifndef CUHKSZ_CONTAINERS_QUEUE
#define CUHKSZ_CONTAINERS_QUEUE

#include <queue>
#include <iostream>
#include <cstdlib>


namespace cuhksz {

template <typename ValueType>
class queue {
public:
	queue();
	~queue();
	
	queue operator =(const queue& queue2);

	ValueType& first();
	const ValueType& first() const;

	ValueType& last();
	const ValueType& last() const;

	int size() const;

	bool isEmpty();

	void push(const ValueType& value);

	ValueType pop();

	void clear();

private:
	std::queue<ValueType> privateQueue;
	void emptyCheck();


};

template <typename ValueType>
queue<ValueType>::queue() {
	//do nothing
}

template <typename ValueType>
queue<ValueType>::~queue(){
	//do nothing
}

template <typename ValueType>
queue<ValueType> queue::operator =(const queue& queue2) {
	privateQueue = queue2.privateQueue;
	return *this;
}

template <typename ValueType>
ValueType& queue<ValueType>::first() {
	return privateQueue.front();
}

template <typename ValueType>
const ValueType& queue<ValueType>::first() const {
	return privateQueue.front();
}

template <typename ValueType>
ValueType& queue<ValueType>::last() {
	return privateQueue.back();
}

template <typename ValueType>
const ValueType& queue<ValueType>::last() const {
	return privateQueue.back();
}

template <typename ValueType>
int queue<ValueType>::size() const {
	return privateQueue.size();
}

template <typename ValueType>
bool queue<ValueType>::isEmpty() {
	return privateQueue.empty();
}

template <typename ValueType>
void queue<ValueType>::push(const ValueType& value) {
	privateQueue.push(value);
}

template <typename ValueType>
ValueType queue<ValueType>::pop() {
	emptyCheck();
	ValueType lastElement = privateQueue.back();
	privateQueue.pop();
	return lastElement;
}

template <typename ValueType>
void queue<ValueType>::clear() {
	if(!privateQueue.empty()) {
		privateQueue.pop();
	}
}

void emptyCheck() {
	if (privateQueue.empty()) {
		std::cout << "The queue is empty!" << '\n';
	}
	std::exit(EXIT_FAILURE);
}

} //end namespace


#endif