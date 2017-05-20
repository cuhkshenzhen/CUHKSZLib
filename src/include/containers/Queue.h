#ifndef CUHKSZ_CONTAINERS_QUEUE
#define CUHKSZ_CONTAINERS_QUEUE

#include <queue>
#include "utils/error.h"

namespace cuhksz {
/**
	cuhksz::Queue is a container which similar to stl queue except
	some simplifications and modifications of interface.
**/
template <typename ValueType>
class Queue {
 public:
  typedef typename std::queue<ValueType> stlQueue;
  typedef ValueType value_type;


	Queue();

	/**
		Initialize a Queue with a stl queue.
		Usage:
		```
		cuhksz::Queue<ValueType> q(stlQueue);
		```
	**/
	Queue( stlQueue& stlQueue2 );


  ~Queue();

	/**
		Assign a Queue to another Queue.
	**/
	Queue operator =(const Queue& queue2);

	/**
		Return a reference to the first element.
	**/
	ValueType& first();

	/**
		Return a const reference to the first element.
	**/
	const ValueType& first() const;

	/**
		Return a reference to the last element.
	**/
	ValueType& last();

	/**
		Return a const reference to the last element.
	**/
	const ValueType& last() const;

	/**
		Return the size of the Queue.
	**/
	int size() const;

	/**
		Check whether the Queue is empty.
	**/
	bool isEmpty();

	/**
		Enqueue a element.
	**/
	void enqueue(const ValueType& value);

	/**
		Dequeue a element based on the FIFO principle.
		Return the value.
	**/
	ValueType dequeue();

	/**
		Empty the Queue.
	**/
	void clear();

	/**
		Convert the Queue to stl queue explicitly.
		Usage:
		```
		auto q = Queue.toStlQueue();
		```
	**/
	stlQueue toStlQueue() {
		return privateQueue;
	}

	/**
		Convert the Queue to stl queue implicitly.
		Usage:
		```
		std::queue<ValueType> q = Queue;
		```
	**/
	operator stlQueue() { return privateQueue; }

	/**
		Check if Queue equals to queue2.
	**/
	bool operator ==(const Queue& queue2);

	/**
		Check if Queue does not equal to queue2.
	**/
    bool operator !=(const Queue& queue2);

	/**
		Compare the contents of Queue and queue2 lexicographically.
	**/
    bool operator <(const Queue& queue2);

	/**
		Compare the contents of Queue and queue2 lexicographically.
	**/
    bool operator <=(const Queue& queue2);

	/**
		Compare the contents of Queue and queue2 lexicographically.
	**/
    bool operator >(const Queue& queue2);

	/**
		Compare the contents of Queue and queue2 lexicographically.
	**/
    bool operator >=(const Queue& queue2);

private:
	std::queue<ValueType> privateQueue;
	void emptyCheck() const;

};

template <typename ValueType>
Queue<ValueType>::Queue() {
  // do nothing
}

template <typename ValueType>
Queue<ValueType>::Queue(stlQueue& stlQueue2) {
  privateQueue = stlQueue2;
}

template <typename ValueType>
Queue<ValueType>::~Queue() {
  // do nothing
}

template <typename ValueType>
Queue<ValueType> Queue<ValueType>::operator=(const Queue& queue2) {
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
bool Queue<ValueType>::operator==(const Queue& queue2) {
  return privateQueue == queue2.privateQueue;
}

template <typename ValueType>
bool Queue<ValueType>::operator!=(const Queue& queue2) {
  return privateQueue != queue2.privateQueue;
}

template <typename ValueType>
bool Queue<ValueType>::operator<(const Queue& queue2) {
  return privateQueue < queue2.privateQueue;
}

template <typename ValueType>
bool Queue<ValueType>::operator<=(const Queue& queue2) {
  return privateQueue <= queue2.privateQueue;
}

template <typename ValueType>
bool Queue<ValueType>::operator>(const Queue& queue2) {
  return privateQueue > queue2.privateQueue;
}

template <typename ValueType>
bool Queue<ValueType>::operator>=(const Queue& queue2) {
  return privateQueue >= queue2.privateQueue;
}

template <typename ValueType>
void Queue<ValueType>::emptyCheck() const {
  if (privateQueue.empty()) {
    error("The queue is empty!");
  }
}

}  // namespace cuhksz

#endif  // CUHKSZ_CONTAINERS_QUEUE
