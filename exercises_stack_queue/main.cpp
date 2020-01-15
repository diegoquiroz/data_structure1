/*
 * main.cpp
 *
 *  Created on: 10/08/2015
 *      Author: pperezm
 */
#include <iostream>
#include <cstring>
#include "unit.h"
#include "stacksandqueues.h"

class SAQTest : public UnitTest {
public:
	void runTest() {
		StacksAndQueues saq;
		UnitTest::total_test = 37;

		/* TEST 1 */
		std::cout << "Test 1...";
		ASSERT_TRUE(saq.balancedBrackets(""));
		std::cout << "PASSED.\nTest 2...";
		
		/* TEST 2 */
		ASSERT_TRUE(saq.balancedBrackets("(7)"));
		std::cout << "PASSED.\nTest 3...";
		
		/* TEST 3 */
		ASSERT_TRUE(saq.balancedBrackets("[]{}()([]{})"));
		std::cout << "PASSED.\nTest 4...";
		
		/* TEST 4 */
		ASSERT_TRUE(saq.balancedBrackets("[({(([[{}][{}][{}]]))})]"));
		std::cout << "PASSED.\nTest 5...";
		
		/* TEST 5 */
		ASSERT_FALSE(saq.balancedBrackets("{"));
		std::cout << "PASSED.\nTest 6...";
		
		/* TEST 6 */
		ASSERT_FALSE(saq.balancedBrackets("]({})"));
		std::cout << "PASSED.\nTest 7...";
		
		/* TEST 7 */
		ASSERT_FALSE(saq.balancedBrackets("(((("));
		std::cout << "PASSED.\nTest 8...";
		
		/* TEST 8 */
		ASSERT_FALSE(saq.balancedBrackets("))))"));
		std::cout << "PASSED.\nTest 9...";
		
		/* TEST 9 */
		ASSERT_FALSE(saq.balancedBrackets("(]{)[}"));
		std::cout << "PASSED.\nTest 10...";
		
		/* TEST 10 */
		ASSERT_FALSE(saq.balancedBrackets("[]{}()[]{})([])"));
		std::cout << "PASSED.\nTest 11...";
		
		/* TEST 11 */
		ASSERT_FALSE(saq.balancedBrackets("[[({(([[{}][{}][{}]]))})]"));
		std::cout << "PASSED.\nTest 12...";

		/* TEST 12 */
		queue<int> q1;
		queue<int> q2;
		queue<int> r1;
		ASSERT_TRUE(r1 == saq.merge(q1, q2));
		std::cout << "PASSED.\nTest 13...";

		for (int i = 0; i <= 6; i++) {
			q1.push((2*i) + 1);
			r1.push((2*i) + 1);
		}
		/* TEST 13 */
		ASSERT_TRUE(r1 == saq.merge(q1, q2));
		std::cout << "PASSED.\nTest 14...";
		
		/* TEST 14 */
		ASSERT_TRUE(r1 == saq.merge(q2, q1));
		std::cout << "PASSED.\nTest 15...";

		queue<int> r2;
		for (int i = 1; i <= 5; i++) {
			q2.push(2*i);
		}
		for (int i = 1; i <= 11; i++) {
			r2.push(i);
		}
		r2.push(13);

		/* TEST 15 */
		ASSERT_TRUE(r2 == saq.merge(q1, q2));
		std::cout << "PASSED.\nTest 16...";
		
		/* TEST 16 */
		ASSERT_TRUE(r2 == saq.merge(q2, q1));
		std::cout << "PASSED.\nTest 17...";
		
		/* TEST 17 */
		ASSERT_TRUE(!strcmp("42", saq.convertInfixToPostfix("42").c_str()));
		std::cout << "PASSED.\nTest 18...";
		
		/* TEST 18 */
		ASSERT_TRUE(!strcmp("1 2 +", saq.convertInfixToPostfix("(1 + 2)").c_str()));
		std::cout << "PASSED.\nTest 19...";
		
		/* TEST 19 */
		ASSERT_TRUE(!strcmp("1 2 * 3 +", saq.convertInfixToPostfix("1 * 2 + 3").c_str()));
		std::cout << "PASSED.\nTest 20...";
		
		/* TEST 20 */
		ASSERT_TRUE(!strcmp("1 2 + 3 + 4 +", saq.convertInfixToPostfix("1 + 2 + 3 + 4").c_str()));
		std::cout << "PASSED.\nTest 21...";
		
		/* TEST 21 */
		ASSERT_TRUE(!strcmp("1 2 +", saq.convertInfixToPostfix("(1 + 2)").c_str()));
		std::cout << "PASSED.\nTest 22...";
		
		/* TEST 22 */
		ASSERT_TRUE(!strcmp("1 2 3 4 + + +", saq.convertInfixToPostfix("(1 + (2 + (3 + 4)))").c_str()));
		std::cout << "PASSED.\nTest 23...";
		
		/* TEST 23 */
		ASSERT_TRUE(!strcmp("1 2 3 * +", saq.convertInfixToPostfix("1 + 2 * 3").c_str()));
		std::cout << "PASSED.\nTest 24...";
		
		/* TEST 24 */
		ASSERT_TRUE(!strcmp("1 2 + 3 *", saq.convertInfixToPostfix("(1 + 2) * 3").c_str()));
		std::cout << "PASSED.\nTest 25...";
		
		/* TEST 25 */
		ASSERT_TRUE(!strcmp("1 2 3 * + 4 +", saq.convertInfixToPostfix("1 + 2 * 3 + 4").c_str()));
		std::cout << "PASSED.\nTest 26...";
		
		/* TEST 26 */
		ASSERT_TRUE(!strcmp("1 2 + 3 4 + *", saq.convertInfixToPostfix("(1 + 2) * (3 + 4)").c_str()));
		std::cout << "PASSED.\nTest 27...";
		
		/* TEST 27 */
		ASSERT_TRUE(!strcmp("1 2 + 3 4 * 5 / -", saq.convertInfixToPostfix("1 + 2 - 3 * 4 / 5").c_str()));
		std::cout << "PASSED.\nTest 28...";
		
		/* TEST 28 */
		ASSERT_TRUE(!strcmp("1 2 / 3 * 4 - 5 +", saq.convertInfixToPostfix("1 / 2 * 3 - 4 + 5").c_str()));
		std::cout << "PASSED.\nTest 29...";
		
		/* TEST 29 */
		ASSERT_TRUE(!strcmp("1 2 / 3 4 * - 5 +", saq.convertInfixToPostfix("1 / 2 - 3 * 4 + 5").c_str()));
		std::cout << "PASSED.\nTest 30...";
		
		/* TEST 30 */
		ASSERT_TRUE(!strcmp("1 2 3 - + 4 5 / *", saq.convertInfixToPostfix("(1 + (2 - 3)) * (4 / 5)").c_str()));
		std::cout << "PASSED.\nTest 31...";
		
		/* TEST 31 */
		ASSERT_TRUE(!strcmp("1 2 3 - / 4 5 + *", saq.convertInfixToPostfix("1 / (2 - 3) * (4 + 5)").c_str()));
		std::cout << "PASSED.\nTest 32...";
		
		/* TEST 32 */
		ASSERT_TRUE(!strcmp("1 2 3 - 4 5 + * /", saq.convertInfixToPostfix("1 / ((2 - 3) * (4 + 5))").c_str()));
		std::cout << "PASSED.\nTest 33...";
		
		/* TEST 33 */
		ASSERT_TRUE(!strcmp("1 2 3 4 * - 5 + /", saq.convertInfixToPostfix("1 / (2 - 3 * 4 + 5)").c_str()));
		std::cout << "PASSED.\nTest 34...";
		
		/* TEST 34 */
		ASSERT_TRUE(!strcmp("42", saq.convertInfixToPostfix("(42)").c_str()));
		std::cout << "PASSED.\nTest 35...";
		
		/* TEST 35 */
		ASSERT_TRUE(!strcmp("42", saq.convertInfixToPostfix("(((42)))").c_str()));
		std::cout << "PASSED.\nTest 36...";
		
		/* TEST 36 */
		ASSERT_TRUE(!strcmp("1 2 +", saq.convertInfixToPostfix("(1 + 2)").c_str()));
		std::cout << "PASSED.\nTest 37...";
		
		/* TEST 37 */
		ASSERT_TRUE(!strcmp("1 2 *", saq.convertInfixToPostfix("(((1) * (2)))").c_str()));
		std::cout << "PASSED.\n";
	}
};

int main(int argc, char* argv[]) {
	SAQTest test;

	test.runTest();
	std::cout << "SUCESS!\n";
	return 0;
}



