//
//  roster.cpp
//  C867 - JYM1 TASK 1 - CLASS ROSTER
//
//  Created by Toni Work on 12/19/22.
//
/*
 E.  Create a Roster class (roster.cpp) by doing the following:
 //1.  Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.” (Constructors included)
 */

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"
using namespace std;

//Constructor
Roster::Roster() {
    for (int i = 0; i < totalStudents; ++i) {
        classRosterArray[i] = nullptr;
    }
}
//Destructor
Roster::~Roster() {}

//a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.
void Roster::add(std::string studentID,
                 std::string firstName,
                 std::string lastName,
                 std::string emailAddress,
                 int age,
                 int courseDays1,
                 int courseDays2,
                 int courseDays3,
                 DegreeProgram degreeProgram){
    int courseDays[Student::daysArray]{courseDays1, courseDays2, courseDays3};
    
    for (int i = 0; i <= studentIndex; i++) {
        if (classRosterArray[i] == nullptr) {
            classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, courseDays, degreeProgram);
            break;
        }
    }
}
//c. public void printAll() that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.
void Roster::printAll() {
    /*Header for each student*/
    //Student::printHeader();
    //OPTION 1
    for (int i = 0; i <= studentIndex; i++) {
        if (classRosterArray[i] == nullptr){}
        else { classRosterArray[i]->print();
        }
        return;
     //OPTION 2
//        for (int i = 0; i <= Roster::studentIndex; i++) {
//            cout << classRosterArray[i]->GetStudentID(); cout << '\t';
//            cout << classRosterArray[i]->GetFirstName(); cout << '\t';
//            cout << classRosterArray[i]->GetLastName(); cout << '\t';
//            cout << classRosterArray[i]->GetEmailAddress(); cout << '\t';
//            cout << classRosterArray[i]->GetAge(); cout << '\t';
//            cout << classRosterArray[i]->GetCourseDays()[0]; cout << '\t';
//            cout << classRosterArray[i]->GetCourseDays()[1]; cout << '\t';
//            cout << classRosterArray[i]->GetCourseDays()[2]; cout << '\t';
//            cout << degreeProgramString[classRosterArray[i]->GetDegreeProgram()] << std::endl;
    }
}

//d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i <= Roster::studentIndex; i++) {
        if (classRosterArray[i]->GetStudentID() == studentID) {
            cout << studentID << " : ";
            cout << ((classRosterArray[i]->GetCourseDays()[0]
                + classRosterArray[i]->GetCourseDays()[1]
                + classRosterArray[i]->GetCourseDays()[2])
                / 3) << std::endl;
        }
    }
}

//b.  public void remove(string studentID)  that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
void Roster::removeStudent(string studentID) {
    bool REMOVE = false;
    for (int i = 0; i <= Roster::studentIndex; i++) {
        if (classRosterArray[i]->GetStudentID() == studentID) {
            REMOVE = true;
            if (i < totalStudentCount - 1) {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[totalStudentCount - 1];
                classRosterArray[totalStudentCount - 1] = temp;
            }
            Roster::studentIndex--;
        }

    }
    if (REMOVE) {
        cout << studentID << " removed." << std::endl << std::endl;
        this->printAll();
    }
    else cout << studentID << " not found in roster." << std::endl << std::endl;
}

//e.  public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.
void Roster::printInvalidEmails() {
    bool ALL = false;
    /*checks each email against '@',' ','.'*/
    for (int i = 0; i <= studentIndex; i++) {
        string emailAddress = (classRosterArray[i]->GetEmailAddress());
        if (emailAddress.find('@') == string::npos || (emailAddress.find(' ') == string::npos && emailAddress.find('.') == string::npos)) {
            ALL = true;
            /*prints each email*/
            cout << emailAddress << endl;
        }
        else if (!ALL) {
            cout << "All email addresses are valid" << endl << endl;
        }
    }
}

//f.  public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    Student::printHeader();
    for (int i = 0; i <= Roster::studentIndex; i++) {
        if (Roster::classRosterArray[i]->GetDegreeProgram() == degreeProgram) 
         classRosterArray[i]->print();
    }
    cout << endl;
}

/*
//a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.
void Roster::parseArray(std::string studentData) {
        
    size_t rhs = studentData.find(",");
    string studentID = studentData.substr(0, rhs);
        
    size_t lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstName = studentData.substr(lhs, rhs - lhs);
        
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);
        
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string emailAddress = studentData.substr(lhs, rhs - lhs);
        
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = stoi(studentData.substr(lhs, rhs - lhs));
        
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));
        
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));
        
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    if (studentData.substr(lhs, rhs - lhs) == "SECURITY") {
        degreeProgram = DegreeProgram::SECURITY;
    }
    else if (studentData.substr(lhs, rhs - lhs) == "NETWORK") {
        degreeProgram = DegreeProgram::NETWORK;
    }
    else if (studentData.substr(lhs, rhs - lhs) == "SOFTWARE") {
        degreeProgram = DegreeProgram::SOFTWARE;
    }
               
        this->add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    }
*/
