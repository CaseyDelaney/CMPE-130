/*
 * User.h
 *
 *  Created on: Apr 26, 2020
 *      Author: caseydelaney
 */
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#ifndef USER_H_
#define USER_H_

class UserProfile {
public:
	UserProfile();
	UserProfile(string f, string l, string e, string password);

	void setFirstName(string f);
	void setLastName(string l);
	void setEmail(string e);
	void setPassword(string p);

	string getEmail();
	string getPassword();


	void printInfo();

private:
	string firstName;
	string lastName;
	string email;
	string password;
};

#endif /* USER_H_ */
