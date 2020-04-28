/*
 * UserDB.cpp
 *
 *  Created on: Apr 27, 2020
 *      Author: caseydelaney
 */

#include "UserDB.h"

UserDB::UserDB() {


}
void UserDB::insertUser(User U){
int index = hashFunction(U.getID());
database[index] = U;
}
void UserDB::printUserInfo(int ID){
	int index = hashFunction(ID);
	User temp = database[index];
	cout <<"User ID is "<< temp.getID()<<endl;
	cout <<"User name is"<<temp.getName()<<endl;

}
int UserDB::hashFunction(int ID){
	return ID % 100000;
}
