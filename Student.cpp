#include "Student.h"
#include <iostream>

Student::Student() //default construtor sets data to 0 or empty
{
	CWID = "";
	classNumber = 0;
}

Student::Student(const string &cwid)  //consutuctor allowing parameters
{
	this->CWID = cwid;
	classNumber = 0;
}

string Student::getCWID()  //returns value of cwid
{
	return CWID;
}

void Student::addCourseGrade(const string &courseName, char grade) //adds course grade and name and increases the pointer
{
	this->className[classNumber] = courseName;
	this->classGrade[classNumber] = grade;
	classNumber++; 
}

double Student::getGPA() {
	int cumulativeGPA;
	for (int i = cumulativeGPA = 0; i < classNumber; i++)
	{
		if (classGrade[i] >= 'A' && classGrade[i] <= 'E')
			cumulativeGPA += 4 - (classGrade[i] - 'A');
		else if (classGrade[i] >= 'a' && classGrade[i] <= 'e')
			cumulativeGPA += 4 - (classGrade[i] - 'a');
	}
	if (classNumber == 0) // if number is 0, it will not divide by zero, it will return 0
		return 0.0;
	return (double)cumulativeGPA / classNumber;
}


void Student::printTranscript() 
{
	int cumulativeGrade;
	cout << "TRANSCRIPT FOR CWID=" << CWID << "\n";
	for (int i = cumulativeGrade = 0; i < classNumber; i++) {
		cout << className[i] << " " << classGrade[i] << "\n";
		cumulativeGrade += 4 - (classGrade[i] - 'A');
	}
	cout << "GPA = " << getGPA() << "\n";
}
