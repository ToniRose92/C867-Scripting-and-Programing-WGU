//
//  student.h
//  C867 - JYM1 TASK 1 - CLASS ROSTER
//
//  Created by Toni Work on 12/19/22.
//
/*
 D.  For the Student class, do the following:
 */
#ifndef student_h
#define student_h
#include "degree.h"
#include <string>

using namespace std;

class Student {
public:
    const static int daysArray = 3;
    //constructor using all of the input parameters provided in the table
    Student();//default values constructor
    Student(std::string studentID,
            std::string firstName,
            std::string lastName,
            std::string emailAddress,
            int age,
            int courseDays[],
            DegreeProgram degreeProgram);
    // deconstructor
    ~Student();
    
    //an accessor (i.e., getter) for each instance variable from part D1
    std::string GetStudentID();
    std::string GetFirstName();
    std::string GetLastName();
    std::string GetEmailAddress();
    int  GetAge();
    const int* GetCourseDays();
    DegreeProgram GetDegreeProgram();
    
    //a mutator (i.e., setter) for each instance variable from part D1
    void SetStudentID(std::string newStudentID);
    void SetFirstName(std::string newFirstName);
    void SetLastName(std::string newLastName);
    void SetEmailAddress(std::string newEmailAddress);
    void SetAge(int newAge);
    void SetCourseDays(const int newCourseDays[]);
    void SetDegreeProgram(DegreeProgram degreeProgram);
    
    //print() to print specific student data
    static void printHeader();//to clearly lable the categories when printing.
    void print();
    
    //Create the class Student  in the files student.h and student.cpp
private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int courseDays[daysArray];
    DegreeProgram degreeProgram;
};

#endif /* student_h */
