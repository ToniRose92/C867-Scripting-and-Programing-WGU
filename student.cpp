//  student.cpp
//  C867 - JYM1 TASK 1 - CLASS ROSTER
//
//  Created by Toni Work on 12/19/22.
//
/*
 D.  For the Student class, do the following:
    2.  c.  All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.
 */
#include <stdio.h>
#include <iostream>
#include "student.h"
#include "degree.h"

using namespace std;

//d.  constructor using all of the input parameters provided in the table
Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = -1;
    for (int i = 0; i < daysArray; i++) {
        this->courseDays[i] = 0;
    }
    this->degreeProgram = DegreeProgram::UNDECLARED;
};

Student::Student(std::string studentID,
                 std::string firstName,
                 std::string lastName,
                 std::string emailAddress,
                 int age,
                 int courseDays[],
                 DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < daysArray; i++) {
        this->courseDays[i] = courseDays[i];
    }
    this->degreeProgram = degreeProgram;
};
//a.  an accessor (i.e., getter) for each instance variable from part D1
std::string Student::GetStudentID() {return this->studentID;}
std::string Student::GetFirstName() {return this->firstName;}
std::string Student::GetLastName() {return this->lastName;}
std::string Student::GetEmailAddress() {return this->emailAddress;}
int Student::GetAge() {return this->age;}
const int* Student::GetCourseDays() {return this->courseDays;}
DegreeProgram Student::GetDegreeProgram() {return degreeProgram;}

//b.  a mutator (i.e., setter) for each instance variable from part D1
void Student::SetStudentID(std::string studentID) {this->studentID = studentID;}
void Student::SetFirstName(std::string firstName) {this->firstName = firstName;}
void Student::SetLastName(std::string lastName){this-> lastName = lastName;}
void Student::SetEmailAddress(std::string emailAddress) {this-> emailAddress = emailAddress;}
void Student::SetAge(int age) {this-> age = age;}
void Student::SetCourseDays(const int courseDays[]) {
    for (int i = 0; i < daysArray; i++) this->courseDays[i] = courseDays[i];
};
void Student::SetDegreeProgram(DegreeProgram dProgram) {this->degreeProgram = dProgram;}

//e.  print() to print specific student data
void Student::print(){
    cout << "| Student ID :\t" << this->studentID << " |" << '\t';
    cout << "First & Last Name :\t" << this->firstName << '\t';
    cout << this->lastName << " |" << '\t';
    cout << "Email Address :\t" << this->emailAddress << " |" << '\t';
    cout << "Age :\t" << this->age << " |" << '\t';
    cout << "Days in Course :\t" << this->courseDays[0] << "," << '\t';
    cout << this->courseDays[1] << "," << '\t';
    cout << this->courseDays[2] << " |" << '\t';
    cout << "Degree Program :\t" << degreeProgramString[(int)this->degreeProgram]<< " |" << '\t' << endl;
};

//destructor
Student::~Student(){};
