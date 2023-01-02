//
//  main.cpp
//  C867 - JYM1 TASK 1 - CLASS ROSTER
//
//  Created by Toni Work on 12/19/22.
//
/*
 F.  Demonstrate the program’s required functionality by adding a main() function in main.cpp, which will contain the required function calls to achieve the following results:
 */
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include "roster.h"

using namespace std;

int main() {
    //A.  Modify the “studentData Table” to include your personal information as the last item.
    const int studentTotal = 5;
    const string studentData[5] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Toni,Stewart,mste902@wgu.edu,30,2,14,17,SOFTWARE"
    };
    // 1.  Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
    cout << "Scripting and Programming Applications - C867" << endl;
    cout << "Language: C++" << endl;
    cout << "WGU Student ID: 010807298" << endl;
    cout << "Programmer: Melodee Stewart" << endl << endl;
      
    //2.  Create an instance of the Roster class called classRoster.
    Roster* classRoster = new Roster(studentTotal);
    
    //3.  Add each student to classRoster.
    for (int i = 0; i <= studentTotal; i++) {
        classRoster->parseArray(studentData[i]);
    }
    
    //4.  Convert the following pseudo code to complete the rest of the  main() function:

    cout << "All students: ";
    cout << endl;
    classRoster->printAll();
    classRoster->printInvalidEmails();
    
    //loop through
   cout << "Average days in a course (each student): " << endl;
    for (int i = 0; i <=5; i++) {
        classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->GetStudentID());
    }

    cout << "Software Degrees: " << endl;
    classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
    
    cout << "Removing student A3" << endl;
    classRoster->removeStudent("A3");
    
    cout << "All students: " << endl;
    classRoster->printAll();
    classRoster->removeStudent("A3");
    //expected: the above line should print a message saying such a student with this ID was not found.
    
    //5.  Implement the destructor to release the memory that was allocated dynamically in Roster.
    
    char exitSign = 'a';
        while (exitSign != 'q') {


            cout << endl << "enter 'q' to quit...";
            cin >> exitSign;
            cout << endl << endl;
        }
    
    return 0;
}
