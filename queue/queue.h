/*
 * queue.h
 *
 *  Created on: 09/10/2015
 *      Author: clase
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "exception.h"
#include <list>
#include <string>
#include <sstream>

template <class T>
class Queue {
public:
	virtual void enqueue(T) = 0;
	virtual void dequeue() throw (NoSuchElement) = 0 ;
	virtual T front() const throw (NoSuchElement) = 0 ;
	virtual bool empty() const = 0;
	virtual void clear() = 0;
	virtual std::string toString() const = 0;
};

template <class T>
class QueueVector : public Queue<T> {
private:
	T *data;
	int head, tail, size, counter;

public:
	QueueVector(int) throw (OutOfMemory);
	~QueueVector();
	void enqueue(T) throw (Overflow);
	void dequeue() throw (NoSuchElement);
	T front() const throw (NoSuchElement);
	bool empty() const;
	bool full() const;
	void clear();
	std::string toString() const;
};

template <class T>
QueueVector<T>::QueueVector(int sze) throw (OutOfMemory) {
}

template <class T>
QueueVector<T>::~QueueVector() {
}

template <class T>
bool QueueVector<T>::empty() const {
}

template <class T>
bool QueueVector<T>::full() const {
}

template <class T>
void QueueVector<T>::enqueue(T val) throw (Overflow) {
}

template <class T>
T QueueVector<T>::front() const throw (NoSuchElement) {
	T aux;
	return aux;
}

template <class T>
void QueueVector<T>::dequeue() throw (NoSuchElement) {
}

template <class T>
void QueueVector<T>::clear() {
}

template <class T>
std::string QueueVector<T>::toString() const {
	std::stringstream aux;
	int i;

	aux << "[";
	if (!empty()) {
		i = head;
		aux << data[i];
		i = (i + 1) % size;
		while (i != tail) {
			aux << ", " << data[i];
			i = (i + 1) % size;
		}
	} 
	aux << "]";
	return aux.str();
}

template <class T>
class QueueList : public Queue<T> {
private:
	std::list<T> data;

public:
	void enqueue(T);
	void dequeue() throw (NoSuchElement);
	T front() const throw (NoSuchElement);
	bool empty() const;
	void clear();	
	std::string toString() const;
};

template <class T>
void QueueList<T>::enqueue(T val) {
}

template <class T>
T QueueList<T>::front() const throw (NoSuchElement) {
	T aux;
	return aux;
}

template <class T>
void QueueList<T>::dequeue() throw (NoSuchElement) {
}

template <class T>
bool QueueList<T>::empty() const {
}

template <class T>
void QueueList<T>::clear() {
}

template <class T>
std::string QueueList<T>::toString() const {
	std::stringstream aux;
	typename std::list<T>::const_iterator itr = data.begin();

	aux << "[";
	if (!data.empty()) {
		aux << (*itr);
		itr++;
		while (itr != data.end()) {
			aux << ", " << (*itr);
			itr++;
		}
	}
	aux << "]";
	return aux.str();
}

#endif /* QUEUE_H_ */