/*
 * main.cpp
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */
#include <iostream>
#include <cstring>
#include "unit.h"
#include "timer.h"

class TimerTest : public UnitTest {
public:
	void runTest() {
		Timer t;
		UnitTest::total_test = 17;
		
		/* TEST 1 */
		std::cout << "Test 1";
		ASSERT_TRUE(!strcmp("00:00", Timer().toString().c_str()));
		std::cout << " PASSED.\nTest 2";
		
		/* TEST 2 */
		ASSERT_TRUE(!strcmp("20:13", Timer(20, 13).toString().c_str()));
		std::cout << " PASSED.\nTest 3";
		
		/* TEST 3 */
		ASSERT_TRUE(!strcmp("01:59", Timer(0, 119).toString().c_str()));
		std::cout << " PASSED.\nTest 4";
		
		/* TEST 4 */
		ASSERT_TRUE(!strcmp("11:59", Timer(10, 119).toString().c_str()));
		std::cout << " PASSED.\nTest 5";
		
		/* TEST 5 */
		ASSERT_TRUE(!strcmp("01:59", Timer(24, 119).toString().c_str()));
		std::cout << " PASSED.\nTest 6";
		
		/* TEST 6 */
		ASSERT_TRUE(10 == Timer(10, 13).getHours());
		std::cout << " PASSED.\nTest 7";
		
		/* TEST 7 */
		ASSERT_TRUE(13 == Timer(10, 13).getMinutes());
		std::cout << " PASSED.\nTest 8";
		
		/* TEST 8 */
		t = Timer(1, 59);
		ASSERT_TRUE(!strcmp("01:59", t.toString().c_str()));
		std::cout << " PASSED.\nTest 9";
		
		/* TEST 9 */
		t += Timer(0, 1);
		ASSERT_TRUE(!strcmp("02:00", t.toString().c_str()));
		std::cout << " PASSED.\nTest 10";
		
		/* TEST 10 */
		t += Timer(23, 1);
		ASSERT_TRUE(!strcmp("01:01", t.toString().c_str()));
		std::cout << " PASSED.\nTest 11";
		
		/* TEST 11 */
		ASSERT_TRUE(Timer(10,10) == Timer(10, 10));
		std::cout << " PASSED.\nTest 12";
		
		/* TEST 12 */
		ASSERT_FALSE(Timer(10,10) == Timer(10, 20));
		std::cout << " PASSED.\nTest 13";
		
		/* TEST 13 */
		ASSERT_FALSE(Timer(20,10) == Timer(10, 10));
		std::cout << " PASSED.\nTest 14";
		
		/* TEST 14 */
		ASSERT_TRUE(Timer(10,11) > Timer(10, 10));
		std::cout << " PASSED.\nTest 15";
		
		/* TEST 15 */
		ASSERT_FALSE(Timer(10,10) > Timer(10, 11));
		std::cout << " PASSED.\nTest 16";
		
		/* TEST 16 */
		ASSERT_TRUE(Timer(20,10) > Timer(19, 10));
		std::cout << " PASSED.\nTest 17";
		
		/* TEST 17 */
		ASSERT_FALSE(Timer(19,10) > Timer(20, 10));
		std::cout << " PASSED.\n";
	}
};

int main(int argc, char* argv[]) {
	TimerTest test;

	test.runTest();
	std::cout << "SUCCESS!\n";
	return 0;
}
