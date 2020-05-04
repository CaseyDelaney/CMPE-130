/*
 * TrainDB.cpp
 *
 *  Created on: May 2, 2020
 *      Author: caseydelaney
 */

#include "TrainDB.h"

TrainDB::TrainDB() {
	// TODO Auto-generated constructor stub
	numberOfDestinations = 0;

}
void TrainDB::loadFile(string filename) {
	ifstream ifs;
	ifs.open(filename.c_str());
	if (ifs.fail()) {
		cout << "Error opening file" << endl;
	}
	string destination;
	Time tempTime;
	char temp;
	string newline;
	while (!ifs.eof()) {
		getline(ifs, newline,'\n');
		getline(ifs, destination, ',');
		ifs >> tempTime.year >> temp >> tempTime.month >> temp >> tempTime.day
				>> temp >> tempTime.hour >> temp >> tempTime.minute;
		inputDestination(destination, tempTime);
	}

	ifs.close();
}
void TrainDB::inputDestination(string des, Time t) {
	for (int i = 0; i < trainMAXSIZE; i++) {
		if (DB[i].getDestination() == des) {
			DB[i].insertTrainTime(t);
		return;
	}
}
	if(numberOfDestinations < trainMAXSIZE){
	Train temp(des);
	temp.insertTrainTime(t);
	DB[numberOfDestinations] = temp;
	numberOfDestinations++;

	}
	else{
		cout <<"Error. Too many train locations."<<endl;
	}

}
void TrainDB::printAll(){
	for(int i = 0; i< trainMAXSIZE; i++){
		if(DB[i].getDestination() != " "){
			DB[i].printTrainInfo();
		}
	}
}
int TrainDB::searchDestination(string des){
	for (int i = 0; i < trainMAXSIZE; i++) {
			if (DB[i].getDestination() == des) {
				DB[i].printTrainInfo();
			return i;
		}
	}
				cout<<"No train destinations matched the location you gave. "
						"\nPlease search for available train schedules first."<<endl;
				return 1000;

}
