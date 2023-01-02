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
#include <string>
#include "student.h"

using namespace std;

class Roster{
public:
    //Constructors
    Roster();
    Student** getStudents();
    //Destructor
    ~Roster();
    
    //Uses the data from studentData and adds it to the classRoster as an object
    void parseArray(std::string studentData);
    
    //2.  Create a student object for each student in the data table and populate classRosterArray.
    //a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.
    void add(std::string studentID,
                    std::string firstName,
                    std::string lastName,
                    std::string emailAddress,
                    int age,
                    int daysInCourse1,
                    int daysInCourse2,
                    int daysInCourse3,
                    DegreeProgram degreeProgram);
    //c. public void printAll() that prints a complete tab-separated list of student data.
    void printAll();
    
    //b.  public void remove(string studentID)  that removes students from the roster by student ID.
    void removeStudent(string studentID);
    
    //d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
    void printAverageDaysInCourse(std::string studentID);
    
    //e.  public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.
    void printInvalidEmails();
    
    //f.  public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type.
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
    int studentIndex = -1;
    const static int totalStudentCount = 5;
    //1.  Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
    //Student** classRosterArray[totalStudentCount];
    Student* classRosterArray[totalStudentCount] = {nullptr, nullptr, nullptr, nullptr, nullptr};

};
#endif /* roster_h */
