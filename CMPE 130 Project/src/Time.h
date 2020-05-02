/*
 * Time.h
 *
 *  Created on: May 2, 2020
 *      Author: caseydelaney
 */
#include <iostream>
using namespace std;

#ifndef TIME_H_
#define TIME_H_

class Time {
public:
	Time();
	Time(int y, int m, int d, int h, int min);

	int year;
	int month;
	int day;
	int hour;
	int minute;
	void printTime();
};

#endif /* TIME_H_ */
