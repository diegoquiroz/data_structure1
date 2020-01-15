/*
 * main.cpp
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */
#include <iostream>
#include <cstring>
#include "unit.h"
#include "list.h"

class ListTest : public UnitTest {
public:
	void runTest() {
		List<int> b1, b2;
		UnitTest::total_test = 11;
		
		b1.add(2); b1.add(3); b1.add(4);
		b2.add(2); b2.add(3); b2.add(4);
		
		/* TEST 1 */
		b1.set(0, 1);
		ASSERT_TRUE(!strcmp("[1, 3, 4]", b1.toString().c_str()));
		std::cout << " PASSED.\nTest 2";
		
		/* TEST 2 */
		b1.set(1, 2);
		ASSERT_TRUE(!strcmp("[1, 2, 4]", b1.toString().c_str()));
		std::cout << " PASSED.\nTest 3";
		
		/* TEST 3 */
		try {
			b1.set(-1, 10);
			FAIL("IndexOutOfBounds not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("IndexOutOfBounds", e.what()));
			std::cout << " PASSED.\nTest 4";
		}
		
		/* TEST 4 */
		try {
			b1.set(3, 10);
			FAIL("IndexOutOfBounds not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("IndexOutOfBounds", e.what()));
			std::cout << " PASSED.\nTest 5";
		}
		
		/* TEST 5 */
		b1.addFirst(1);
		b1.add(1);
		b1.add(5);
		b1.add(1);
		ASSERT_TRUE(0 == b1.indexOf(1));
		std::cout << " PASSED.\nTest 6";
		
		/* TEST 6 */
		ASSERT_TRUE(6 == b1.lastIndexOf(1));
		std::cout << " PASSED.\nTest 7";
		
		/* TEST 7 */
		ASSERT_TRUE(1 == b1.remove(4));
		ASSERT_TRUE(6 == b1.length());
		ASSERT_TRUE(!strcmp("[1, 1, 2, 4, 5, 1]", b1.toString().c_str()));
		std::cout << " PASSED.\nTest 8";
		
		/* TEST 8 */
		ASSERT_TRUE(true == b1.removeFirstOcurrence(1));
		ASSERT_TRUE(5 == b1.length());
		ASSERT_TRUE(!strcmp("[1, 2, 4, 5, 1]", b1.toString().c_str()));
		std::cout << " PASSED.\nTest 9";
		
		/* TEST 9 */
		ASSERT_TRUE(false == b1.removeFirstOcurrence(100));
		std::cout << " PASSED.\nTest 10";
		
		/* TEST 10 */
		ASSERT_TRUE(true == b1.removeLastOcurrence(1));
		ASSERT_TRUE(4 == b1.length());
		ASSERT_TRUE(!strcmp("[1, 2, 4, 5]", b1.toString().c_str()));
		std::cout << " PASSED.\nTest 11";
		
		/* TEST 11 */
		ASSERT_TRUE(false == b1.removeLastOcurrence(100));
		std::cout << " PASSED.";
	}
};

int main(int argc, char* argv[]) {
	ListTest test;

	test.runTest();
	std::cout << "SUCESS!\n";
	return 0;
}


