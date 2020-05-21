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
	quickSort(0,numberOfDestinations-1);
}
void TrainDB::printAll(){
	for(int i = 0; i< trainMAXSIZE; i++){
		if(DB[i].getDestination() != " "){
			DB[i].printTrainInfo();
		}
	}
}
int TrainDB::searchDestination(string des){
//	for (int i = 0; i < trainMAXSIZE; i++) {
//			if (DB[i].getDestination() == des) {
//				DB[i].printTrainInfo();
//			return i;
//		}
//	}

	return binarySearch(0,numberOfDestinations - 1, des);;


}
int TrainDB::binarySearch(int l, int r, string x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (DB[mid].getDestination() == x) {
            DB[mid].printTrainInfo();
            return mid;
        }
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (DB[mid].getDestination() > x) {
            return binarySearch(l, mid - 1, x);
        }
        else{
        return binarySearch(mid + 1, r, x);
        }
    }
    return 1000;
}
bool operator < (Train a, Train b){
	if(a.getDestination() < b.getDestination()){
		cout <<"Train a < b";
		return true;
	}
	else	return false;

}
void TrainDB::swap(Train &a, Train &b)
{
    Train temp = a;
    a = b;
    b = temp;
}
int TrainDB::partition (int low, int high)
{
    Train pivot = DB[high]; // pivot
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (DB[j] < pivot)
        {
            i++;
           swap(DB[i], DB[j]);
        }
    }
    swap(DB[i + 1], DB[high]);
    return (i + 1);
}
void TrainDB::quickSort(int low, int high) //for
{
    if (low < high)
    {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}
