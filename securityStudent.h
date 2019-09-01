/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   securityStudent.h
 * Author: user
 *
 * Created on August 24, 2019, 2:51 PM
 */

#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H
#include <iostream>
#include <string>
#include "student.h"
using std::string;

class SecurityStudent : public Student {
public:
//    default and constructor for security subclass
	SecurityStudent();
	SecurityStudent(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int* numDays, Degree degree);
//setter, getter, and virtual functions
	void setDegree(Degree);

	Degree getDegreeProgram();

	void print();

	virtual ~SecurityStudent();
        
        int* Days = getNumDays();
};


#endif /* SECURITYSTUDENT_H */

