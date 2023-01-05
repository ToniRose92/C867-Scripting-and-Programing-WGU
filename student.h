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

using std::string;
using std::cout;
using std::endl;
using std::left;
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
    void SetStudentID(std::string studentID);
    void SetFirstName(std::string firstName);
    void SetLastName(std::string lastName);
    void SetEmailAddress(std::string emailAddress);
    void SetAge(int age);
    void SetCourseDays(const int courseDays[]);
    void SetDegreeProgram(DegreeProgram dProgram);
    
    //print() to print specific student data
    //static void printHeader();//to clearly lable the categories when printing.
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
