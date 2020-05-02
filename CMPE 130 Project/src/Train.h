/*
 * Train.h
 *
 *  Created on: May 2, 2020
 *      Author: caseydelaney
 */
#include <iostream>
#include "Time.h"
#include <fstream>

using namespace std;

#ifndef TRAIN_H_
#define TRAIN_H_

class Train {
public:
	Train();
	Train(string d);
	void insertTrainTime(Time T);
	string getDestination();
	void printTrainInfo();

private:
	string destination;
	Time T[10]; //Up to ten different schedules for a single location
	int i;
};

#endif /* TRAIN_H_ */
