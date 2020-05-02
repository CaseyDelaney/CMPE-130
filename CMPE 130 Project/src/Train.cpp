/*
 * Train.cpp
 *
 *  Created on: May 2, 2020
 *      Author: caseydelaney
 */

#include "Train.h"

Train::Train() {
	destination = ' ';
	i = 0;
}

Train::Train(string d) {
	destination = d;
	i = 0;
}
void Train::insertTrainTime(Time t) {
	if (i < 10) {
		T[i] = t;
		i++;
	} else {
		cout << "\nError. Too many train schedules at this location" << endl;
	}
}
string Train::getDestination() {
	return destination;
}
void Train::printTrainInfo() {
	cout << "Destination: " << destination << endl;
	for (int j = 0; j < i; j++) {
		cout << "\t";
		T[j].printTime();
	}
}
