/*
 * main.cpp
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include "unit.h"
#include "sorts.h"

template <class T>
std::string arrayToString(const std::vector<T> &v) {
	std::stringstream aux;

	aux << "[" << v[0];
	for (int i = 1; i < v.size(); i++) {
		aux << ", " << v[i];
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string listToString(const std::list<T> &v) {
	typename std::list<T>::const_iterator itr;
	std::stringstream aux;

	itr = v.begin();
	aux << "[" << *itr++;
	for (; itr != v.end(); itr++) {
		aux << ", " << *itr;
	}
	aux << "]";
	return aux.str();
}


class SortsTest : public UnitTest {
public:
	void runTest() {
		UnitTest::total_test = 3;
		int array[] = {58, 92, 75, 5, 21, 92, 84, 91, 64, 54, 3, 28, 11, 61, 65, 4, 1, 8, 52, 78};
		std::vector<int> source (array, array + sizeof(array) / sizeof(int) );
		std::vector<int> v;
		Sorts<int> sorts;

		/* TEST 1 */
		v = sorts.bucketSort(source);
		ASSERT_TRUE(!strcmp("[1, 3, 4, 5, 8, 11, 21, 28, 52, 54, 58, 61, 64, 65, 75, 78, 84, 91, 92, 92]",
				             arrayToString(v).c_str()));
		std::cout << "PASSED.\nTest 2...";
		
		/* TEST 2 */
		int a1[] = {35, 55, 59, 60, 69, 96};
		std::list<int> lst1 (a1, a1 + sizeof(a1) / sizeof(int) );

		int a2[] = {51, 57, 71, 74};
		std::list<int> lst2 (a2, a2 + sizeof(a2) / sizeof(int) );

		std::list<int> result;
		result = sorts.mergeList(lst1, lst2);
		ASSERT_TRUE(!strcmp("[35, 51, 55, 57, 59, 60, 69, 71, 74, 96]",
						    listToString(result).c_str()));
		std::cout << "PASSED.\nTest 3...";
		
		/* TEST 3 */
		result = sorts.mergeList(lst2, lst1);
		ASSERT_TRUE(!strcmp("[35, 51, 55, 57, 59, 60, 69, 71, 74, 96]",
							listToString(result).c_str()));
		std::cout << "PASSED.\n";
	}
};

int main(int argc, char* argv[]) {
	SortsTest test;

	test.runTest();
	std::cout << "SUCCESS!\n";
	return 0;
}
