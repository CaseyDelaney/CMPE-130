//============================================================================
// Name        : CMPE.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

void userLogin();
void userRegistration();
void userRegistration();
void searchTrains();
void buyTickets();
void refundTickets();
void editUserInfo();

int main() {

	// the following items choose a page
	bool homePage = true; //
	bool loggedInPage = false;

	//Menu Options for different pages
	char homeMenuOption = '0'; // A user input that chooses between Main Page menu options
	char loggedInMenuOption = '0'; // A user input that chooses between Logged In Page menu options
	while (1) {
		while (homePage) { //Menu

			cout << "\nCmpe Train Company " << endl;
			cout << "__________________________________________________\n"
					<< endl;
			cout << "Choose an option to continue:" << endl;
			cout << "1. Login" << endl;
			cout << "2. Register User" << endl;

			cin >> homeMenuOption;

			if (homeMenuOption == '1') {
				userLogin(); //Calls userLogin function to allow user to login
				homePage = false; //exits main page and goes to a logged in page
				loggedInPage = true; //proceeds to a page where the user can access train scheduling functions
			} else if (homeMenuOption == '2') {
				userRegistration(); //allows user to make a new profile
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
			cout << "\nUser is now logged in." << endl;
			cout << "__________________________________________________\n"
					<< endl;

			cout << "What would you like to do next?" << endl;
			cout << "1. Search for a train schedule" << endl; //Allow user to input information and find the closest match
			cout << "2. Buy Tickets" << endl; //Search for a train schedule and then allow user to buy a ticket
			cout << "3. Ticket Refund" << endl; //User can cancel train ticket
			cout << "4. Edit Account Information" << endl;
			cout << "5. Logout" << endl;

			cin >> loggedInMenuOption;

			if (loggedInMenuOption == '1') {
				searchTrains(); //search for available train rides
			} else if (loggedInMenuOption == '2') {
				buyTickets(); //Allows user to buy train tickets
			} else if (loggedInMenuOption == '3') {
				refundTickets(); //Cancel train ticket
			} else if (loggedInMenuOption == '4') {
				editUserInfo();
			} else if (loggedInMenuOption == '5') {
				cout << "You are now logged out.\n\n" << endl;
				homePage = true;
				loggedInPage = false;
			}
		}

	}
	//cout <<"test"<<endl;////////////
	return 0;
}

void userLogin() {
	//TODO: Create Login Function
	cout << "Logged in" << endl;
	;
}

void userRegistration() {
	//TODO: Create User Registration Function
}

void searchTrains() {

}
void buyTickets() {

}
void refundTickets() {

}
void editUserInfo() {

}
