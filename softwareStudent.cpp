/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   softwareStudent.cpp
 * Author: user
 * 
 * Created on August 24, 2019, 2:52 PM
 */

#include "softwareStudent.h"
#include <iostream>
#include <string>
#include "student.h"
using namespace std;

//default constructor
SoftwareStudent::SoftwareStudent() : Student(){
}
//constructor will inherit from Student class
SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int* numDays, Degree degree)
:Student(studentID, firstName, lastName, studentEmail, studentAge, numDays){
	degree = SOFTWARE;
}
//will override the student function.
Degree SoftwareStudent::getDegreeProgram(){
	return SOFTWARE;
}
//will print when called. same as others but the degree.
void SoftwareStudent::print(){
        cout << "ID  "<< getStudentID() <<"\t";
	cout << "First Name:  "<< getFirstName() <<"\t";
	cout << "Last Name:  "<< getLastName() <<"\t";
	cout << "Email:  "<< getStudentEmail() <<"\t";
	cout << "Age:  "<< getStudentAge() << "\t";
	cout << "Days in Course:  "<< Days[0] << " " << Days[1] << " " << Days[2] << "\t";
        cout << "Degree: Software" << endl;
}
SoftwareStudent::~SoftwareStudent(){
}

