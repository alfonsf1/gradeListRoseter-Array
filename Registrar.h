#pragma once
#include <string>
#include <stdexcept>
#include "Student.h"

using namespace std;

class Registrar {

private:
	Student* studentPtr; // dynamic pointer
	int ptrSize; //size of dynamic

public:

	void readTextfile(string filename); // Load information from a text file with the given filename: THIS IS COMPLETE
	void addLine(string courseName, string cwid, char grade); // process a line from the text file
	Student& getStudent(string cwid) const; // return the Student object corresponding to a given CWID

	Registrar(); //constructor
	Registrar(const Registrar &reg); //constuctor with parameters
	Registrar& operator=(const Registrar &reg); // assignment operator
};