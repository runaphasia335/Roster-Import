/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   securityStudent.cpp
 * Author: user
 * 
 * Created on August 24, 2019, 2:51 PM
 */

#include "securityStudent.h"
#include <iostream>
#include <string>
#include "student.h"
using namespace std;

//default constructor
SecurityStudent::SecurityStudent() : Student(){
}
//constructor will inherit from the Student class. 
SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int* numDays, Degree degree)
:Student(studentID, firstName, lastName, studentEmail, studentAge, numDays){
	degree = SECURITY;
}
//will override Student function
Degree SecurityStudent::getDegreeProgram(){
	return SECURITY;
}
//will print when called. same as others but the degree.
void SecurityStudent::print(){
        cout << "ID  "<< getStudentID() <<"\t";
	cout << "First Name:  "<< getFirstName() <<"\t";
	cout << "Last Name:  "<< getLastName() <<"\t";
	cout << "Email:  "<< getStudentEmail() <<"\t";
	cout << "Age:  "<< getStudentAge() << "\t";
	cout << "Days in Course:  "<< Days[0] << " " << Days[1] << " " << Days[2]  << "\t";
        cout << "Degree: Security" << endl;
}
SecurityStudent::~SecurityStudent(){
}

