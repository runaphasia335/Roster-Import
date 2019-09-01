/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   networkStudent.h
 * Author: user
 *
 * Created on August 24, 2019, 2:51 PM
 */

#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H
#include <iostream>
#include <string>
#include "student.h"
using std::string;

class NetworkStudent : public Student {
public:
//default and constructor for network subclass
	NetworkStudent();
	NetworkStudent(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int* numDays, Degree degree);
//setter, getter, and virtual functions
	void setDegree(Degree);

	Degree getDegreeProgram();

	void print();

	virtual ~NetworkStudent();
        
        int* Days = getNumDays();
};


#endif /* NETWORKSTUDENT_H */

