/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   student.h
 * Author: user
 *
 * Created on August 24, 2019, 2:50 PM
 */

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "degree.h"
using std::string;

class Student {
public:
	Student();
	Student(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int numDays[]);
	const static int num_days = 3;

private:
//    private student variables
	string studentID;
	string firstName;
	string lastName;
	string studentEmail;
	int studentAge;
	int numDays[num_days];
	Degree degree;

public:
//    setters and getters
	void setStudentID(string);
	void setFirstName(string);
	void setLastName(string);
	void setStudentEmail(string);
	void setStudentAge(int);
	void setNumDays(int numDays[]);
	void setDegree(Degree);

	string getStudentID();
	string getFirstName();
	string getLastName();
	string getStudentEmail();
        int    getStudentAge();
	int*   getNumDays();
//        virtual functions will be overridden
	virtual void print() = 0;
	virtual Degree getDegreeProgram() = 0;
//destructor
	virtual ~Student();




};



#endif /* STUDENT_H */

