/*
 * User.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: caseydelaney
 */

#include "UserProfile.h"

UserProfile::UserProfile() {
firstName = ' ';
lastName = ' ';
email = ' ';
password = ' ';
}
UserProfile::UserProfile(string f, string l, string e, string p){
	firstName = f;
	lastName = l;
	email = e;
	password = p;
}

void UserProfile::setFirstName(string f){
	firstName = f;

}
void UserProfile::setLastName(string l){
	lastName = l;
}
void UserProfile::setEmail(string e){
	email = e;
}
void UserProfile::setPassword(string p){
	password = p;
}
string UserProfile::getEmail(){
	return email;
}
string UserProfile::getPassword(){
	return password;
}
void UserProfile::printInfo(){
	cout <<"User Profile" <<endl;
	cout << "******************************************\n";
	cout <<left<<setw(15)<<"Name: "<<firstName <<" "<< lastName<<endl;
	cout <<left<<setw(15)<<"Email Address:" << email<<endl;
	cout <<left<<setw(15) <<"Password:"<<password[0]<<password[1]<<"*********"<<endl;
}
