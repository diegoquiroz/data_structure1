/*
 * saq.h
 *
 *  Created on: 10/08/2015
 *      Author: pperezm
 */

#ifndef STACKSANDQUEUES_H_
#define STACKSANDQUEUES_H_

#include <iostream>
#include <string>
#include <cctype>
#include <queue>
#include <stack>

using namespace std;

class StacksAndQueues {
private:
	queue<string> tokenize(string);
	bool hasHigherPrecedence(const string&, const string&);

public:
	bool balancedBrackets(const string&);
	queue<int> merge(const queue<int>&, const queue<int>&);
	string convertInfixToPostfix(const string&);
};

queue<string> StacksAndQueues::tokenize(string str) {
	int i = 0;
	int length = str.size();
	string aux;
	queue<string> result;

	while (i < length) {
		if (isdigit(str[i])) {
			aux.clear();
			do {
				aux += str[i];
				i++;
			} while(isdigit(str[i]));
			result.push(aux);
		} else if (isspace(str[i])) {
			i++;
		} else {
			aux.clear();
			aux += str[i];
			result.push(aux);
			i++;
		}
	}
	return result;
}

bool StacksAndQueues::hasHigherPrecedence(const string &stackTop, const string &op) {
	return !((stackTop == string("+") || stackTop == string("-")) &&
			 (op == string("*")       || op == string("/")));
}

bool StacksAndQueues::balancedBrackets(const string &expr) {
	return false;
}

queue<int> StacksAndQueues::merge(const queue<int> &queue1, const queue<int> &queue2) {
	queue<int> result;
	
	return result;
}

string StacksAndQueues::convertInfixToPostfix(const string &expr) {
	return string("");
}

#endif /* STACKSANDQUEUES_H_ */
