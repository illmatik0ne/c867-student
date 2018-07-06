#include "stdafx.h"
#include "NetworkStudent.h"

NetworkStudent::NetworkStudent(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int* days) :
	Student(studentID, firstName, lastName, emailAddress, age, days)
{
	degreeprogram = NETWORK;
}

Degree NetworkStudent::getDegreeProgram()
{
	return degreeprogram;
}