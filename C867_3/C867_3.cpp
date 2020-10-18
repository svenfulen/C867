#include <iostream>
#include <string>

#include "roster.h"

//i am using namespace std here to make main more readable
using namespace std;

int main() {
    //F1. output course title, programming language, student id, name
    cout << "WGU C867: Scripting and Programming Applications" << endl;
    cout << "Language used: C++" << endl;
    cout << "Written by Sven Fulenchek" << endl;
    cout << "Student ID: 001366569";
    cout << "\n------------------------------------------------";
    cout << endl << endl << endl;

    //F2. creates an instance of roster class
    Roster* classRoster = new Roster();

    //F3. adds each student to classRoster
    for (int i = 0; i <= 5; i++) {classRoster->parseArray(i);}

    //F4. program functionality
    
    cout << "Printing all students: ";
    cout << endl;
    classRoster->printAll();
    classRoster->printInvalidEmails();

    cout << "Printing average days in course for each student:" << endl;

    for (int i = 0; i < 5; i++) {
        classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->getID());
    }

    cout << endl;
    classRoster->printByDegreeProgram(SOFTWARE);

    cout << endl;
    classRoster->removeStudent("A3");

    cout << endl;
    cout << "Printing all students:\n";
    classRoster->printAll();
    classRoster->removeStudent("A3");

    /*
    When main returns 0, the destructor is called automatically.

    roster.h
    Roster::~Roster();
    
    this is the destructor, it deallocates roster from memory

    if you try to read from Roster after deallocating it, there will be an error.
    */
    return 0;
}