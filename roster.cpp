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
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <string>
#include <regex>
#include "roster.h"
#include "student.h"

using namespace std;

const static int totalStudents = 5;
Student* classRosterArray[totalStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };

//Constructor
Roster::Roster() {};
//Destructor
Roster::~Roster() {
    for (int i = 0; i < totalStudents; i++){
        cout << "Dynamic descructor called for " << classRosterArray[i]->GetStudentID() << endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
};

Student** Roster::getStudent(){
    return classRosterArray;
}
//Parsing using regular expresions.
void Roster::parseArray(const std::string studentData[]){
    regex regex("\\,");
    
    for (int i = 0; i < 5; i++) {
        string tempString = studentData[i];
        std::vector<string> studentDataElements(
                                     std::sregex_token_iterator(tempString.begin(), tempString.end(), regex, -1), std::sregex_token_iterator());
        DegreeProgram dp = DegreeProgram::UNDECLARED;
            if (studentDataElements.at(8).back() == 'Y') dp = DegreeProgram::SECURITY;
            if (studentDataElements.at(8).back() == 'K') dp = DegreeProgram::NETWORK;
            if (studentDataElements.at(8).back() == 'E') dp = DegreeProgram::SOFTWARE;
            add(studentDataElements.at(0),
                studentDataElements.at(1),
                studentDataElements.at(2),
                studentDataElements.at(3),
                stoi(studentDataElements.at(4)),
                stoi(studentDataElements.at(5)),
                stoi(studentDataElements.at(6)),
                stoi(studentDataElements.at(7)),
                dp);
    }
};

//a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
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
        classRosterArray[++studentIndex] = new Student(studentID, firstName, lastName, emailAddress, age, courseDays, degreeProgram);

};
//c. public void printAll() that prints a complete tab-separated list of student data
void Roster::printAll() {
    /*Header for each student*/
    //Student::printHeader();
    for (int i = 0; i <= Roster::studentIndex; i++) {
        if (classRosterArray[i] == nullptr){}
        else { classRosterArray[i]->print();
        }
    }
};
//e.  public void printInvalidEmails()
void Roster::printInvalidEmails() {
    cout << endl << "Invalid email address(s), please check for missing '@' and '.' or spaces : " << endl << endl;
        for (int i = 0; i < totalStudents; i++) {
            if ( (classRosterArray[i]->GetEmailAddress()).find('@') == -1) {
                cout << classRosterArray[i]->GetEmailAddress() << endl;
            }
            else if ( (classRosterArray[i]->GetEmailAddress()).find('.') == -1) {
                cout << classRosterArray[i]->GetEmailAddress() << endl;
            }
            else if ( (classRosterArray[i]->GetEmailAddress()).find(' ') != -1) {
                cout << classRosterArray[i]->GetEmailAddress() << endl;
            }
        }
};
//d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i <= Roster::studentIndex; i++) {
        if (classRosterArray[i]->GetStudentID() == studentID) {
            cout << studentID << " : ";
            cout << ((classRosterArray[i]->GetCourseDays()[0]
                + classRosterArray[i]->GetCourseDays()[1]
                + classRosterArray[i]->GetCourseDays()[2])
                / 3) << endl;
        }
    }
};
//f.  public void printByDegreeProgram(DegreeProgram degreeProgram)
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i <= Roster::studentIndex; i++) {
        if (Roster::classRosterArray[i]->GetDegreeProgram() == degreeProgram) classRosterArray[i]->print();
    }
    cout << endl;
};
//b.  public void remove(string studentID)
void Roster::removeStudent(string studentID) {
    bool REMOVE = false;
    for (int i = 0; i <= Roster::studentIndex; i++) {
        if (classRosterArray[i]->GetStudentID() == studentID) {
            REMOVE = true;
            if (i < 5 - 1) {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[5 - 1];
                classRosterArray[totalStudents - 1] = temp;
            }
            Roster::studentIndex--;
        }

    }
    if (REMOVE) {
        cout << studentID << " removed." << endl << endl;
        this->printAll();
    }
    else cout << studentID << " not found in roster." << endl << endl;
};
