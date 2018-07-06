#include "stdafx.h"
#include "securityStudent.h"

SecurityStudent::SecurityStudent(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int* days) :
	Student(studentID, firstName, lastName, emailAddress, age, days)
{
	degreeprogram = SECURITY;
}

Degree SecurityStudent::getDegreeProgram()
{
	return degreeprogram;
}