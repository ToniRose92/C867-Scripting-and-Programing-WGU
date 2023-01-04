//
//  roster.h
//  C867 - JYM1 TASK 1 - CLASS ROSTER
//
//  Created by Toni Work on 12/19/22.
//
/*
 E.  Create a Roster class (roster.cpp) by doing the following:
 */
#ifndef roster_h
#define roster_h
#include <stdio.h>
#include <vector>
#include <cstring>
#include <string.h>
#include <sstream>
#include <string>
#include "student.h"

using std::string;
using std::cout;
using std::endl;
using namespace std;

class Roster{
public:
    //Constructors
    Roster();
    
    //Destructor
    ~Roster();
    
    Student** getStudent();
    
    //Uses the data from studentData and adds it to the classRoster as an object
    void parseArray(const std::string studentData[]);
    
    //a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.
    void add(std::string studentID,
            std::string firstName,
            std::string lastName,
            std::string emailAddress,
            int age,
            int courseDays1,
            int courseDays2,
            int courseDays3,
            DegreeProgram degreeProgram);
    //c. public void printAll()
    void printAll();
    //d.  public void printAverageDaysInCourse(string studentID)
    void printAverageDaysInCourse(std::string studentID);
    //e.  public void printInvalidEmails()
    void printInvalidEmails();
    //f.  public void printByDegreeProgram(DegreeProgram degreeProgram) 
    void printByDegreeProgram(DegreeProgram degreeProgram);
    //b.  public void remove(string studentID)
    void removeStudent(string studentID);
    
    //2.  Create a student object for each student in the data table and populate classRosterArray.
    const static int totalStudents = 5;
    Student* classRosterArray[totalStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };
private:
    int studentIndex = -1;
    //1.  Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
    
};
#endif /* roster_h */
