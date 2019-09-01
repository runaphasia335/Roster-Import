
/* 
 * File:   student.cpp
 * Author: user
 * 
 * Created on August 24, 2019, 2:50 PM
 */

#include "student.h"
#include <iostream>
#include <string>
using namespace std;

//default constructor
Student::Student() {
	this->studentID    = "id";
	this->firstName    = "fname";
	this->lastName     = "lname";
	this->studentEmail = "email";
	this->studentAge   = 0;
	for (int i = 0; i < num_days; ++i) {this->numDays[i] = 0;}
}
//constructor will be added to the subclasses to the appropriate subclasses
Student::Student(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int* numDays){
	this->studentID    = studentID;
	this->firstName    = firstName;
	this->lastName     = lastName;
	this->studentEmail = studentEmail;
	this->studentAge   = studentAge;
	for(int i = 0; i < num_days; ++i){
		this->numDays[i] = numDays[i];}
        
}
// setters
void Student::setStudentID(string studentID){
	this->studentID = studentID;
}
void Student::setFirstName(string firstName){
	this->firstName = firstName;
}
void Student::setLastName(string lastName){
	this->lastName = lastName;
}
void Student::setStudentEmail(string studentEmail){
	this->studentEmail = studentEmail;
}
void Student::setStudentAge(int studentAge){
	this->studentAge = studentAge;
}
void Student::setNumDays(int numDays[]){
	for (int i = 0; i < num_days; ++i){
		this->numDays[i] = numDays[i];
	}
}
//getters
string Student::getStudentID(){
	return this->studentID;
}
string Student::getFirstName(){
	return this->firstName;
}
string Student::getLastName(){
	return this->lastName;
}
string Student::getStudentEmail(){
	return this->studentEmail;
}
int Student::getStudentAge(){
	return this->studentAge;
}
int* Student::getNumDays(){
	return this->numDays; 
                
}
//will be overridden by each subclass
void Student::print(){
	

}
Student::~Student(){
}

