#pragma once

#include <string>
#include "student.h"

//A. Modify the “studentData Table” to include your personal information as the last item.
const std::string studentData[5] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Sven,Fulenchek,sfulenc@wgu.edu,21,10,20,30,SOFTWARE"
};

class Roster {
public:
    //constructor
    Roster();
    //destructor
    ~Roster();

    //array of students as objects containing student data. double pointer lets it link to main and roster .cpp
    Student** classRosterArray;

    //adds a student to array index from parsed data. each var parameter is a placeholder for the value parsed
    void addStudent(int index, std::string a, std::string b, std::string c, std::string d, std::string e, int f, int g, int h, DegreeProgram x);

    //removes student data from the roster
    void removeStudent(std::string stID);

    //takes data from studentData string and adds to classRoster as an object
    void parseArray(int rosterIndex);

    //prints all student data seperated by tabs, format may vary between systems
    void printAll();

    //prints average days in course
    void printAverageDaysInCourse(std::string stID);

    //prints all invalid emails using find() and basic logic
    void printInvalidEmails();

    //prints students of a particular degree program
    void printByDegreeProgram(DegreeProgram degreeprogram);

private:
    //takes in an int value from DegreeProgram and outputs the string version of DegreeProgram rather than the int
    void printDegreeString(int dp);
};

