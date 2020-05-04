/*
 * Time.cpp
 *
 *  Created on: May 2, 2020
 *      Author: caseydelaney
 */

#include "Time.h"

Time::Time() {
	year = 0;
	month = 0;
	day = 0;
	hour = 0;
	minute = 0;
	ticketsLeft = 40;
}

Time::Time(int y, int m, int d, int h, int min) {
	year = y;
	month = m;
	day = d;
	hour = h;
	minute = min;
	ticketsLeft = 40;
}

void Time::printTime(){
	switch(month){
	case 1:
		cout<<"January";
		break;
	case 2:
		cout<<"February";
		break;
	case 3:
		cout<<"March";
		break;
	case 4:
		cout<<"April";
		break;
	case 5:
		cout<<"May";
		break;
	case 6:
		cout<<"June";
		break;
	case 7:
		cout<<"July";
		break;
	case 8:
		cout<<"August";
		break;
	case 9:
		cout<<"September";
		break;
	case 10:
		cout<<"October";
		break;
	case 11:
		cout<<"November";
		break;
	case 12:
		cout<<"December";
		break;
	default:
		cout<<"Error Displaying Month"<<endl;
	}
	cout <<" "<<day<<", "<<year <<" at "<< hour<<":";
			if(minute == 0){
				cout <<"00"<<endl;
			}
			else if(minute < 10){
				cout <<"0"<<minute<<endl;
			}
			else{
			cout<<minute<<endl;
			}
}
void Time::buyTicket(){
	if(ticketsLeft > 0){
	ticketsLeft--;
	cout <<"You purchased one ticket."<<endl;
	}
	else{
		cout<<"Sorry. There are no more tickets left for this train ride."<<endl;
	}
}
