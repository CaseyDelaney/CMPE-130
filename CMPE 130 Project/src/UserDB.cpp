/*
 * UserDB.cpp
 *
 *  Created on: Apr 27, 2020
 *      Author: caseydelaney
 */

#include "UserDB.h"
//TODO: User Deletion
UserDB::UserDB() {
	for (int i = 0; i < MAXSIZE; i++) {
		statusTable[i] = 0;
	}

}
void UserDB::insertUser(UserProfile U) { //Corner Cases Complete
	int index = hashFunction(U.getEmail());
	int count = 0;
if (statusTable[index] == -1) { //Check if there are deleted elements
	database[index] = U;
	statusTable[index] = 1;
	U.printInfo();
	cout
	<< "\n\nYour user profile has now been registered. Log in to proceed."
	<< endl;
} else if (statusTable[index] == 0) {
	database[index] = U;
	statusTable[index] = 1;
	U.printInfo();
	cout
	<< "\n\nYour user profile has now been registered. Log in to proceed."
	<< endl;
} else if(statusTable[index] == 1) {
	while (statusTable[index] == 1) { ///linear probing
		if (database[index].getEmail() == U.getEmail()) {
			cout << "\nUser is already Registered" << endl;
			return;
		} else{
			index = (index + 1) % MAXSIZE;
			count++;
			if(count == MAXSIZE){
				cout <<"Database is full"<<endl;
				return;
			}
		}
	}
	database[index] = U;
		statusTable[index] = 1;
		U.printInfo();
		cout
		<< "\n\nYour user profile has now been registered. Log in to proceed."
		<< endl;
}

}

bool UserDB::checkUserInfo(string email, string password) {
int count = 0;
bool correctPassword = false;
int index = hashFunction(email);
while (statusTable[index] == -1) { //Check if there are deleted elements
	index = (index + 1) % MAXSIZE;
	count++;
	if (count == MAXSIZE) {
		cout << "Error. User Database is full" << endl;
	}
}
if (statusTable[index] == 1) { //User is found
	UserProfile temp = database[index];
	while (statusTable[index] == 1) { ///linear probing
			if (temp.getEmail() == email) {
					if (temp.getPassword() == password) {
						correctPassword = true;
						cout << "\n\n\nPassword is correct.\n";
					} else {
						correctPassword = false;
						cout << "\n\n\nIncorrect email or password.\n";
					}
					return correctPassword;
			} else{
				index = (index + 1) % MAXSIZE;
				count++;
				if(count == MAXSIZE){
					cout <<"User was not found"<<endl;
					return false;
				}
			}
		}

} else if (statusTable[index] == 0) { //user is not found
	cout <<"\nUser was not found"<<endl;
	return false;
} else {
	cout << "Error with new user function.";
	return false;
}
return false;
}
int UserDB::hashFunction(string email) {
char a = email[0];
char b = email[1];
char c = email[2];
char d = email[4];
int hashNumber = a * b * c * d;
hashNumber = hashNumber % 1000; //maximum of 1000 users
return hashNumber;
}
