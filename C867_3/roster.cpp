#pragma once

#include <sstream>
#include <string>
#include <iostream>

#include "roster.h"
#include "student.h"
#include "degree.h"

//Roster constructor
//makes the array of pointers
//each pointer in the array points to a Student object
Roster::Roster() { classRosterArray = new Student * [5]; };

//Roster destructor
Roster::~Roster() { delete[] classRosterArray; };

//prints string version of degreeprogram value (using cout)
//int dp is a placeholder for the number version of the enum DegreeProgram
void Roster::printDegreeString(int dp) {
	switch (dp) {
	case 0:
		std::cout << "SECURITY";
		break;
	case 1:
		std::cout << "NETWORK";
		break;
	case 2:
		std::cout << "SOFTWARE";
		break;
	default:
		std::cout << "ERROR";
		break;
	}
}

//index is a parameter for which index of classRosterArray to add the student to
//paramaters a - h and x are for variable data to be added to a Student object
void Roster::addStudent(int index, std::string a, std::string b, std::string c, std::string d, std::string e, int f, int g, int h, DegreeProgram x) {
	//converts the int index into a constant so it can be used for index parameter
	const int indexConst = index;
	//creates a student object to overlay on classRosterArray[x]
	Student* xstudent = new Student();

	//sets vars of student object from parsed data
	xstudent->setID(a);
	xstudent->setFirstName(b);
	xstudent->setLastName(c);
	xstudent->setEmailAddress(d);
	xstudent->setAge(e);
	xstudent->setDays(f, g, h);
	xstudent->setDegreeProgram(x);

	//overlays xstudent on classRosterArray[x]
	classRosterArray[indexConst] = xstudent;
}

//removeStudent sets every var in a Student object to blank
//also sets studentID to NUL so that print functions won't print it
void Roster::removeStudent(std::string stID) {
	//did the function find the student?
	bool indexFound = false;
	//if the function found the student, what index is the student at?
	int indexNum = 0;

	std::cout << "Searching for student by ID: " << stID;

	for (int i = 0; i < 5; i++) {
		//if the value passed in is equal to one of the ID values, the function found the student
		if (this->classRosterArray[i]->getID() == stID) {
			indexNum = i;
			indexFound = true;
			std::cout << ".";
			break;
		}
		//if the value passed in is not equal to one of the ID values, the function did not find the student
		else {
			indexFound = false;
			std::cout << ".";
			continue;
		}
	}
	std::cout << std::endl;

	//if the student is found, clear the data at that index
	if (indexFound) {
		std::cout << "Student found.  Removing student from roster.";
		const int indexConst = indexNum;
		//creates a student object
		Student* xstudent = new Student();

		//sets vars of student object

		//sets id to NUL so print function won't print the data if the student is removed
		xstudent->setID("NUL");
		std::cout << ".";
		xstudent->setFirstName("");
		std::cout << ".";
		xstudent->setLastName("");
		std::cout << ".";
		xstudent->setEmailAddress("");
		std::cout << ".";
		xstudent->setAge("");
		std::cout << ".";
		xstudent->setDays(0, 0, 0);
		std::cout << ".";
		xstudent->setDegreeProgram(DEF);
		std::cout << ".";

		//overlays new student object on old one so it is cleared
		classRosterArray[indexConst] = xstudent;

		std::cout << "DONE";
	}

	else {
		//output if the function does not find the student
		std::cout << "Student " << stID << " not found.";
	}
	std::cout << std::endl;
}

void Roster::parseArray(int rosterIndex) {

	/*
		DECLARING VARIABLES TO HOLD PARSED DATA
	*/

	//grabs string from studentData to parse
	std::string studentDataString = studentData[rosterIndex];
	//makes length of the given string more accessible / readable
	int stringLength = studentDataString.length();

	//these variables hold data values that is parsed by the function
	std::string studentID = "";
	std::string firstName = "";
	std::string lastName = "";
	std::string email = "";
	std::string age = "";
	std::string stringdays0 = ""; //string version of daysincourse
	std::string stringdays1 = ""; //to be converted to int values
	std::string stringdays2 = ""; //
	int days0 = 0; //int values of stringdays0-2
	int days1 = 0; //
	int days2 = 0; //
	std::string degreeProgramString = "";	//string degreeProgram is the string version of degree enum value
	DegreeProgram studentDegree; //actual enum value of degreeprogram

	/*
		LOGIC TO PARSE DATA INTO VARIABLES
	*/

	//char # in parsing loop (what character of this string are we parsing?)
	int i = 0;

	//when commasSkipped increments, input goes to the next variable on the list
	//in order studentID, firstName, lastName, etc...
	int commasSkipped = 0;

	//parses string one char at a time and adds the chars to each string variable
	for (i = 0; i < stringLength; i++) {
		char s = studentDataString.at(i);
		if (s != ',') {
			switch (commasSkipped) {
			case 0:
				studentID.push_back(s);
				break;
			case 1:
				firstName.push_back(s);
				break;
			case 2:
				lastName.push_back(s);
				break;
			case 3:
				email.push_back(s);
				break;
			case 4:
				age.push_back(s);
				break;
			case 5:
				stringdays0.push_back(s);
				break;
			case 6:
				stringdays1.push_back(s);
				break;
			case 7:
				stringdays2.push_back(s);
				break;
			case 8:
				degreeProgramString.push_back(s);
				break;
			default:
				break;
			}
		}

		else {
			//start putting data into the next var
			commasSkipped = commasSkipped + 1;
		}
	}

	/*
		TYPE CONVERSION
	*/

	//converting string data to int data that can be passed into a Student object
	std::stringstream daysConvert0(stringdays0);
	std::stringstream daysConvert1(stringdays1);
	std::stringstream daysConvert2(stringdays2);
	daysConvert0 >> days0;
	daysConvert1 >> days1;
	daysConvert2 >> days2;

	//logic to change degreeProgramString string into an enum
	//basically the reverse of printDegreeString

	if (degreeProgramString == "SECURITY") {
		studentDegree = SECURITY;
	}
	else if (degreeProgramString == "NETWORK") {
		studentDegree = NETWORK;
	}
	else if (degreeProgramString == "SOFTWARE") {
		studentDegree = SOFTWARE;
	}
	else {
		studentDegree = DEF;
	}

	//adding data to the array of objects from parsed and converted values
	addStudent(rosterIndex, studentID, firstName, lastName, email, age, days0, days1, days2, studentDegree);
}

//printAll prints all 5 of the student vars in a list, calling the print() function
void Roster::printAll() {
	for (int i = 0; i < 5; i++) {
		//checks if student exists or not before trying to print data
		if (classRosterArray[i]->getID() != "NUL") {
			classRosterArray[i]->print(0);
			std::cout << "	";
			std::cout << "First name: ";
			classRosterArray[i]->print(1);
			std::cout << "	";
			std::cout << "Last name:";
			classRosterArray[i]->print(2);
			std::cout << "	";
			std::cout << "Age: ";
			classRosterArray[i]->print(4);
			std::cout << "	";
			std::cout << "Days In Course: {";
			classRosterArray[i]->print(5);
			std::cout << ",";
			classRosterArray[i]->print(6);
			std::cout << ",";
			classRosterArray[i]->print(7);
			std::cout << "}";
			std::cout << "Degree program: ";

			//prints degree string
			printDegreeString(classRosterArray[i]->getDegreeProgram());
			std::cout << std::endl;
		}
	}
std::cout << std::endl;
}

//printAverageDaysInCourse searches for the studentID in the roster
//then it averages the daysincourse array vals if the studentID is found
void Roster::printAverageDaysInCourse(std::string stID) {
	int average;
	int daysA;
	int daysB;
	int daysC;

	//searching for student using string studentID

	//does this student exist?
	bool indexFound = false;
	//if the student exists, what index is the student located at?
	int indexNum = 0;

	//searching for student
	for (int i = 0; i <= 5; i++) {
		if (this->classRosterArray[i]->getID() == stID) {
			indexNum = i;
			indexFound = true;
			break;
		}
		else {
			indexFound = false;
			continue;
		}
	}

	//if the student is found, calculate the average using getDays ints
	if (indexFound) {
		daysA = this->classRosterArray[indexNum]->getDays(0);
		daysB = this->classRosterArray[indexNum]->getDays(1);
		daysC = this->classRosterArray[indexNum]->getDays(2);

		average = ((daysA + daysB + daysC) / 3);

		std::cout << "Average of days in course for student " << stID << ": " << average;
		std::cout << std::endl;

	}
	
	//if the student is not found, output that the student was not found
	else {
		std::cout << "Student " << stID << " was not found.";
		std::cout << std::endl;
	}
}

//printInvalidEmails has basic logic that will find which emails are invalid
//based on if they have an @ symbol and a .
//and if the string does not contain a space
void Roster::printInvalidEmails() {
	std::cout << "Printing invalid emails: " << std::endl;

	//logic to check if email is valid

	for (int i = 0; i < 5; i++) {
		std::string emailStr = classRosterArray[i]->getEmailAddress();
		//does the email have an '@' symbol as well as a '.'
		if ((emailStr.find('@') != std::string::npos) && emailStr.find('.') != std::string::npos) {
			//does the email contain a space
			if (emailStr.find(' ') != std::string::npos) {
				std::cout << emailStr;
				std::cout << std::endl;
			}
		}
		else {
			std::cout << emailStr;
			std::cout << std::endl;
		}
	}
std::cout << std::endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram) {
	
	//does the same thing as printAll, but only prints the ones with matching degreeprogram

	std::cout << "Printing students by degree program ";
	printDegreeString(degreeprogram);
	std::cout << ":" << std::endl;
	for (int i = 0; i < 5; i++) {

		if (classRosterArray[i]->getDegreeProgram() == degreeprogram) {
			if (classRosterArray[i]->getID() != "NUL") {
				classRosterArray[i]->print(0);
				std::cout << "	";
				std::cout << "First name: ";
				classRosterArray[i]->print(1);
				std::cout << "	";
				std::cout << "Last name:";
				classRosterArray[i]->print(2);
				std::cout << "	";
				std::cout << "Age: ";
				classRosterArray[i]->print(4);
				std::cout << "	";
				std::cout << "Days In Course: {";
				classRosterArray[i]->print(5);
				std::cout << ",";
				classRosterArray[i]->print(6);
				std::cout << ",";
				classRosterArray[i]->print(7);
				std::cout << "}";
				std::cout << "Degree program: ";

				//prints string version of degree program
				printDegreeString(classRosterArray[i]->getDegreeProgram());
				std::cout << std::endl;
			}
		}
	}
}
