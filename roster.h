/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   roster.h
 * Author: user
 *
 * Created on August 24, 2019, 2:52 PM
 */

#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"
#include <iostream>
#include <string>
using std::string;

class Roster {
public:
    
//    constructor and destructor 
	Roster();
        ~Roster();
//classRosterArray will hold the data for each student. 5 students in total
	Student * classRosterArray[5];
	
        static const int student_data = 5;
	
        int lastIndex = 0;
//function declarations
        void add(string ID, string fName, string lName, string Email, int Age, int day1, int day2, int day3, Degree tempDegree);

	void remove (string studentID);

	void printAll();

	void printInvalidEmails();

	void printByDegreeProgram(Degree degree);

	void printDaysInCourse(string studentID);


};


#endif /* ROSTER_H */

