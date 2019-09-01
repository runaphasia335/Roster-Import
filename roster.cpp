/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   roster.cpp
 * Author: user
 * 
 * Created on August 24, 2019, 2:52 PM
 */
#include "roster.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include "degree.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
using namespace std;
using std::stoi;

Roster::Roster(){
}
//destructor to free dynamic memory
Roster::~Roster(){
    for(int i = 0; i < student_data; ++i){
        if(classRosterArray[i] != nullptr){
            delete classRosterArray[i];
        }
    }
}
//will add each piece of data to a new student object of each subclass. 
//each day was added individually, so number of days to finish course will be added to student object as an array. 
void Roster::add(string ID, string fName, string lName, string Email, int Age, int day1, int day2, int day3, Degree tempDegree){
	int numberDays[Student::num_days];
	numberDays[0] = day1;
	numberDays[1] = day2;
	numberDays[2] = day3;
	if(tempDegree == SECURITY){
	        classRosterArray[lastIndex] = new SecurityStudent(ID, fName, lName, Email, Age, numberDays, tempDegree);
	}
	else if(tempDegree == NETWORK){
		classRosterArray[lastIndex] = new NetworkStudent(ID, fName, lName, Email, Age, numberDays, tempDegree);
	}
	else if(tempDegree == SOFTWARE){
		classRosterArray[lastIndex] = new SoftwareStudent(ID, fName, lName, Email, Age, numberDays, tempDegree);
	}
	lastIndex++;

}

//removing student by their student ID. 
//will loop through each student until the student id is found and delete. if not found, cout will execute. 
void Roster::remove(string studentID){
	for (int i = 0; i < student_data; ++i){
            if(classRosterArray[i] != nullptr){               
                if(classRosterArray[i]->getStudentID() == studentID){
                    delete classRosterArray[i];
                    classRosterArray[i] = nullptr;
                    return;
                }
            }
        }
        cout << studentID << " cannot be found";
}
           
                

//will print all students. loop through each student and make sure the student object is not a null. then will print. 
void Roster::printAll(){
	for(int i = 0; i < student_data; ++i){
            if(classRosterArray[i] != nullptr){
		classRosterArray[i]->print();
            }
	}
}
//print the average days in course by looping through each student and call getNumDays from Student class to print days.
void Roster::printDaysInCourse(string studentID){
    for(int i = 0; i < student_data; ++i){
        int* avg = classRosterArray[i]->getNumDays();
        if(classRosterArray[i]->getStudentID() == studentID){
            cout << "Average days in course: " << (avg[0] + avg[1] + avg[2])/3 << endl;
                    
        }           
    }  
}
//loop through each student to read email. if emails are not valid, will print out each invalid email that does not meet criteria
//of a valid email. 
void Roster::printInvalidEmails(){
    for(int i = 0; i < student_data; ++i){
        if(classRosterArray[i] != nullptr){
            if(classRosterArray[i]->getStudentEmail().find('@') == string::npos){
                 cout << classRosterArray[i]->getStudentEmail() <<endl;
            }
            else  if(classRosterArray[i]->getStudentEmail().find('.') == string::npos){
                 cout << classRosterArray[i]->getStudentEmail() <<endl;
            }
            else if(classRosterArray[i]->getStudentEmail().find(' ') != string::npos){
                 cout << classRosterArray[i]->getStudentEmail() <<endl;
            }
        }
    }
}
//print students by their degree. 
void Roster::printByDegreeProgram(Degree degree){
    for(int i = 0; i < student_data; ++i){
        if(classRosterArray[i]->getDegreeProgram() == degree){
          classRosterArray[i]->print(); 
        }
    }
}

int main(){
//    instance of class Roster that will call each function. 
	Roster classRoster;

	static const int student_data = 5;
	string studentData[5] =
	        {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		 "A5,Carlos,Perez,cpere89@wgu.edu,29,35,40,37,SOFTWARE"};
//for loop will loop through studentData and parse the data
//then it will add each piece of data to add(). 
//each data will be added to its appropriate data member
	for (int i = 0; i < student_data; ++i){
		string courseData[9];
		string outputData;
		istringstream inputData(studentData[i]);
		Degree tempDegree;
		for (int x = 0; x < 9; ++x){
			if(x < 9){
				getline(inputData, outputData, ',');
				courseData[x] = outputData;
			}
			else if(x == 9){
				break;
			}
		}
		if (courseData[8] == "SECURITY"){
			tempDegree = SECURITY;
		}
		else if (courseData[8] == "NETWORK"){
			tempDegree = NETWORK;
		}
		else if (courseData[8] == "SOFTWARE"){
			tempDegree = SOFTWARE;
		}
		else {
			throw runtime_error("Degree does not match that of given");
		}
//                convert data parse data into data members. then added to add().
		        string ID    = courseData[0];
		        string fName = courseData[1];
		        string lName = courseData[2];
		        string Email = courseData[3];
		        int Age      = stoi(courseData[4]);
		        int day1     = stoi(courseData[5]);
		        int day2     = stoi(courseData[6]);
		        int day3     = stoi(courseData[7]);

		        classRoster.add(ID, fName, lName, Email, Age, day1, day2, day3, tempDegree);

	}
        cout << "Programming and Scripting - C867" << endl;
        cout << "******* C++ *******" << endl;
        cout << "**** 000819792 ****" <<endl;
        cout << "*** Carlos Perez ***" <<endl;
        
        
        cout << endl;
//        printing all students. 
        cout << "Printing all students:" << endl;
        classRoster.printAll();
        cout << endl;
//        printing all invalid members
        cout << "Invalid email(s):" << endl;
        classRoster.printInvalidEmails();
        cout << endl;
//        loop through each student and print average days in class
        cout << "Average days for each student:" << endl;
        for(int i = 0; i < student_data; ++i){    
        cout << classRoster.classRosterArray[i]->getStudentID() << ":  ";
        classRoster.printDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
        }
        cout << endl;
//        print students by degree
        cout << "Students by degree: " <<endl;
        classRoster.printByDegreeProgram(SOFTWARE);
//        removing students from roster by id
        classRoster.remove("A3");
        cout << endl;
//        verifying student has been delete. 
        classRoster.remove("A3");

        

                   
        return 0;
}


