#include "stdafx.h"
#include "softwareStudent.h"

SoftwareStudent::SoftwareStudent(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int* days) :
	Student(studentID, firstName, lastName, emailAddress, age, days)
{
	degreeprogram = SOFTWARE;
}


Degree SoftwareStudent::getDegreeProgram()
{
	return degreeprogram;
}