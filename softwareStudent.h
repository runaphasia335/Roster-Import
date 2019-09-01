/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   softwareStudent.h
 * Author: user
 *
 * Created on August 24, 2019, 2:52 PM
 */

#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H
#include <iostream>
#include <string>
#include "student.h"
using std::string;

class SoftwareStudent : public Student {
public:
//    default constructor and constructor for software subclass
	SoftwareStudent();
	SoftwareStudent(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int* numDays, Degree degree);
//setter, getter, and virtual functions
	void setDegree(Degree);
        
	Degree getDegreeProgram();

	void print();

	virtual ~SoftwareStudent();
        
        int* Days = getNumDays();
};

#endif /* SOFTWARESTUDENT_H */

