/*
 * UserDB.h
 *
 *  Created on: Apr 27, 2020
 *      Author: caseydelaney
 */
#include <iostream>
using namespace std;

#include "User.h"
#ifndef USERDB_H_
#define USERDB_H_
const int MAXSIZE = 100000;
class UserDB {
public:
	UserDB();

	void insertUser(User U);
	void printUserInfo(int ID);

	User database[MAXSIZE];
	int statusTable[MAXSIZE];
	int hashFunction(int ID);
};

#endif /* USERDB_H_ */
