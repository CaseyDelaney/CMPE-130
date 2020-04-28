/*
 * User.h
 *
 *  Created on: Apr 26, 2020
 *      Author: caseydelaney
 */
#include <iostream>
using namespace std;

#ifndef USER_H_
#define USER_H_

class User {
public:
	User();
	User(double i, string n);
	void setID(double i);
	void setName(string n);
	string getName();
	double getID();
private:
	string name;
	double ID;
};

#endif /* USER_H_ */
