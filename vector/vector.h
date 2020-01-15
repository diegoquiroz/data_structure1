/*
 * vector.h
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include "exception.h"
#include <sstream>

template <class T>
class Vector {
private:
	unsigned int size;
	T	*data;

public:
	Vector(unsigned int) throw (RangeError,OutOfMemory);
	Vector(unsigned int, T&) throw (RangeError, OutOfMemory);
	Vector(const Vector<T>&) throw (OutOfMemory);
	~Vector();

	unsigned int length() const;
	unsigned int resize(unsigned int) throw (RangeError, OutOfMemory);
	unsigned int resize(unsigned int, T&) throw (RangeError, OutOfMemory);
	std::string toString() const;

	T& operator[](unsigned int) const throw (IndexOutOfBounds);
	void operator=(const Vector<T>&);
};

template <class T>
Vector<T>::Vector(unsigned int numberOfElements) throw (RangeError, OutOfMemory) {
}

template <class T>
Vector<T>::Vector(unsigned int numberOfElements, T &initialValue) throw (RangeError, OutOfMemory) {
}

template <class T>
Vector<T>::Vector(const Vector<T> &source) throw (OutOfMemory) {
}

template <class T>
Vector<T>::~Vector() {
}

template <class T>
unsigned int Vector<T>::length() const {
	return 0;
}

template <class T>
unsigned int Vector<T>::resize(unsigned int newSize) throw (RangeError, OutOfMemory) {
	return 0;
}

template <class T>
unsigned int Vector<T>::resize(unsigned int newSize, T &initValue) throw (RangeError, OutOfMemory) {
	return 0;
}

template <class T>
std::string Vector<T>::toString() const {
	std::stringstream aux;

	aux << "[" << data[0];
	for (unsigned int i = 1; i < size; i++) {
		aux << ", " << data[i];
	}
	aux << "]";
	return aux.str();
}

template <class T>
T& Vector<T>::operator[] (unsigned int index) const throw (IndexOutOfBounds) {
	return data[0];
}

template <class T>
void Vector<T>::operator=(const Vector<T> &right) {
}

#endif /* VECTOR_H_ */
