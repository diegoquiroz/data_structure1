/*
 * timer.h
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <string>
#include <sstream>

class Timer {
private:
	int hours, minutes;

public:
	Timer();
	Timer(int, int);
	Timer(const Timer&);

	int getHours() const;
	int getMinutes() const;
	std::string toString() const;

	void operator= (const Timer&);
	void operator+= (const Timer&);
};

Timer::Timer() : hours(0), minutes(0) {}

Timer::Timer(int hh, int mm) {
}

Timer::Timer(const Timer &t) {}

int Timer::getHours() const {
}

int Timer::getMinutes() const {
}

std::string Timer::toString() const {
	 std::stringstream aux;

	 if (hours < 10) {
		 aux << "0";
	 }
	 aux << hours << ":";
	 if (minutes < 10) {
		 aux << "0";
	 }
	 aux << minutes;
	 return aux.str();
}

void Timer::operator= (const Timer &right) {
}

void Timer::operator+= (const Timer &right) {
}

bool operator== (const Timer &left, const Timer &right) {
}

bool operator> (const Timer &left, const Timer &right) {
}

#endif /* TIMER_H_ */
