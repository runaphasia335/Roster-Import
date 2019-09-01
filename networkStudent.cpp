/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   networkStudent.cpp
 * Author: user
 * 
 * Created on August 24, 2019, 2:51 PM
 */

#include "networkStudent.h"
#include <iostream>
#include <string>
#include "student.h"
using namespace std;

//default constructor
NetworkStudent::NetworkStudent() : Student(){
}
//constructor to inherit from Student class
NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int* numDays, Degree degree)
:Student(studentID, firstName, lastName, studentEmail, studentAge, numDays){
	degree = NETWORK;
}
//will override Student function 
Degree NetworkStudent::getDegreeProgram(){
	return NETWORK;
}
//will print when called. same as others but the degree. 
void NetworkStudent::print(){
	cout << "ID  "<< getStudentID() <<"\t";
	cout << "First Name:  "<< getFirstName() <<"\t";
	cout << "Last Name:  "<< getLastName() <<"\t";
	cout << "Email:  "<< getStudentEmail() <<"\t";
	cout << "Age:  "<< getStudentAge() << "\t";
	cout << "Days in Course:  "<<  Days[0] << " " << Days[1] << " " << Days[2] << "\t";
        cout << "Degree: Network" << endl;
}
//destructor
NetworkStudent::~NetworkStudent(){
}
