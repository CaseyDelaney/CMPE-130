/*
 * UserDB.h
 *
 *  Created on: Apr 27, 2020
 *      Author: caseydelaney
 */
#include <iostream>
using namespace std;

#include "UserProfile.h"
#ifndef USERDB_H_
#define USERDB_H_
const int MAXSIZE = 1000;
class UserDB {
public:
	UserDB();

	void insertUser(UserProfile U);
	bool checkUserInfo(string email, string password);

	UserProfile database[MAXSIZE];
	int statusTable[MAXSIZE]; // -1 = deleted, 0 = empty; 1 = full
	int hashFunction(string email);
};

#endif /* USERDB_H_ */
