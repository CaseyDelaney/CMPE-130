//============================================================================
// Name        : CMPE.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "UserDB.h"
#include "UserProfile.h"
#include "TrainDB.h"
using namespace std;

bool userLogin(UserDB &DB);
void userRegistration(UserDB &DB);
void searchTrains(TrainDB &d);
void buyTickets(TrainDB &d);
void refundTickets();
void editUserInfo();

string currentUserEmail;
int main() {
	//creating user DB and Train DB
	UserDB DB;
	TrainDB trainDataBase;
	//Loading Train Schedules from txt file
	trainDataBase.loadFile("trainSchedules.txt");
	//trainDataBase.printAll();


// the following items choose a page
	bool homePage = true; //
	bool loggedInPage = false;

	//Menu Options for different pages
	char homeMenuOption = '0'; // A user input that chooses between Main Page menu options
	char loggedInMenuOption = '0'; // A user input that chooses between Logged In Page menu options
	while (1) {
		while (homePage) { //Menu

			cout << "\n\n\nCmpe Train Company " << endl;
			cout << "******************************************"
					<< endl;
			cout << "Choose an option to continue:" << endl;
			cout << "1. Login" << endl;
			cout << "2. Register User" << endl;

			cin >> homeMenuOption;

			if (homeMenuOption == '1') {
				bool correctInfo = userLogin(DB); //Calls userLogin function to allow user to login

				if(correctInfo){
					homePage = false; //exits main page and goes to a logged in page
					loggedInPage = true; //proceeds to a page where the user can access train scheduling functions
				}
				else{

				}

			} else if (homeMenuOption == '2') {
				userRegistration(DB); //allows user to make a new profile
				//stay within homeMenu and user must log into their account after registration
			} else if (homeMenuOption == '3') {
				cout << "Shutting down program" << endl;
				exit(1);
			} else {
				cout << homeMenuOption
						<< " is not an option. Please enter a number from 1 - 3."
						<< endl;
			}

		}
		while (loggedInPage) {
			cout << "\n\nStatus: Logged In" << endl;
			cout << "******************************************\n"
					<< endl;

			cout << "What would you like to do next?" << endl;
			cout << "1. Search for a train schedule" << endl; //Allow user to input information and find the closest match
			cout << "2. Buy Tickets" << endl; //Search for a train schedule and then allow user to buy a ticket
			cout << "3. Edit Account Information" << endl;
			cout << "4. Logout" << endl;

			cin >> loggedInMenuOption;

			if (loggedInMenuOption == '1') {
				searchTrains(trainDataBase); //Display all available train rides
			} else if (loggedInMenuOption == '2') {
				buyTickets(trainDataBase); //Allows user to buy train tickets
			} else if (loggedInMenuOption == '3') {
				editUserInfo();
			} else if (loggedInMenuOption == '4') {
				cout << "You are now logged out.\n\n" << endl;
				homePage = true;
				loggedInPage = false;
			}
		}

	}
	//cout <<"test"<<endl;////////////
	return 0;
}

bool userLogin(UserDB &DB) {
	string password;
	cout<<"Please enter your email address:\n"<<endl;
	cin >>currentUserEmail;
	cout<<"Please enter your password:\n"<<endl;
	cin >>password;

	return DB.checkUserInfo(currentUserEmail, password);
	;
}

void userRegistration(UserDB &DB){
	string fName;
	string lName;
	string email;
	string password;

	cout << "\n\nUser Registration Form" << endl;
	cout << "******************************************\n";
	cout << "Please enter your First Name:"<<endl;
	cin >>fName;
	cout << "Please enter your Last Name:"<<endl;
	cin >>lName;
	cout <<"Please enter your email address"<<endl;
	cin >> email;
	cout <<"Please enter a password:"<<endl;
	cin >>password;
	UserProfile newUser(fName, lName, email, password);
	DB.insertUser(newUser);
}

void searchTrains(TrainDB &d) {
d.printAll();
}
void buyTickets(TrainDB &d) {
	string destination;
	cout <<"Please enter a destination:"<<endl;
	cin.ignore();
	getline (cin, destination);
	int valid = d.searchDestination(destination);
	if(valid == 1000){
		return;
	}
	cout<<"Choose the number of which train you would like to pick:";
	int choice = 0;
	cin >> choice;
	if(choice > d.DB[valid].getI() ||choice < 1){
		cout<<"\n\nError. "<<choice <<" is not a valid option"<<endl;
	}
	else{
cout<<"\n\n\nYou have bought a ticket at ";
		d.DB[valid].buySingleTrain(choice - 1);
	}
}
void refundTickets() {

}
void editUserInfo() {

}
