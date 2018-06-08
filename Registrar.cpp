#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Registrar.h"

using namespace std;

void Registrar::readTextfile(string filename) //reads text file and collects data
{
	ifstream myfile(filename);

	if (myfile.is_open()) { //if file opens, collect data
		cout << "Successfully opened file " << filename << endl;
		string courseName;
		string cwid;
		char grade;
		while (myfile >> courseName >> cwid >> grade) {
			addLine(courseName, cwid, grade);
		}
		myfile.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);
}

// return Student object corresponding to a given CWID
// getStudent must throw an exception if cwid is invalid
Student& Registrar::getStudent(string cwid) const 
{
	for (int i = 0; i < ptrSize; i++) {
		if (studentPtr[i].getCWID() == cwid)
			return studentPtr[i];
	}
	throw out_of_range("CWID provided is invalid: " + cwid); // if CWID is invalid return invalid CWID
}

// process a line from the text file
void Registrar::addLine(string courseName, string cwid, char grade) 
{
	try { //if CWID exists, it will proceed to add course grade
		Student &s = getStudent(cwid);
		s.addCourseGrade(courseName, grade);
	}
	catch (exception &e) { //else, it eill be created 
		studentPtr[ptrSize] = Student(cwid);
		studentPtr[ptrSize].addCourseGrade(courseName, grade);
		ptrSize++; 
	}
}

Registrar::Registrar()  // constructor
{
	studentPtr = new Student[50];
	ptrSize = 0;
}

Registrar::Registrar(const Registrar &reg)
{
	studentPtr = new Student[50]; //new memory allocation
	ptrSize = reg.ptrSize;
	for (int i = 0; i < ptrSize; i++) {
		studentPtr[i] = reg.studentPtr[i];
	}
}

Registrar& Registrar::operator=(const Registrar &reg)
{
	delete[] studentPtr; //deletes old dynamic to prevent memory leaks
	studentPtr = new Student[50]; //new memory allocation
	ptrSize = reg.ptrSize;
	for (int i = 0; i < ptrSize; i++) {
		studentPtr[i] = reg.studentPtr[i];
	}
	return *this; //returns class information
}
