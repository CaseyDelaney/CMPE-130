/*
 * User.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: caseydelaney
 */

#include "User.h"

User::User() {
ID = 0;
name = ' ';
}
User::User(double i, string n){
	ID = i;
	name = n;
}

void User::setID(double i){
ID = i;
}
double User::getID(){
return ID;
}
void User::setName(string n){
	name = n;
}
string User::getName(){
	return name;
}
