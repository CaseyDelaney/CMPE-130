/*
 * TrainDB.h
 *
 *  Created on: May 2, 2020
 *      Author: caseydelaney
 */
//Idea: Each train station gets a location in the table.
//To add a new train departure time, search to see if any train stops have the same time
//If one matches, add a new time to that train
//If not, make a new entry of that train type to the table

#include <iostream>
#include <fstream>
#include "Train.h"

using namespace std;

#ifndef TRAINDB_H_
#define TRAINDB_H_
const int trainMAXSIZE = 100;
class TrainDB {
public:
	TrainDB();
	Train DB[trainMAXSIZE];

	void loadFile(string filename);
	void inputDestination(string des, Time t);
	void printAll();
	int searchDestination(string des);
	void swap(Train &a, Train &b);
	int partition(int low, int high);
	friend bool operator <(Train a, Train b);
	void quickSort(int low, int high);
	int binarySearch(int l, int r, string x);

private:
	int numberOfDestinations;
};

#endif /* TRAINDB_H_ */
