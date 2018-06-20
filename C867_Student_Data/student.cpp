#include "stdafx.h"
#include "student.h"

// Student constructor

Student::Student(int studentID, char firstName, char lastName, char emailAddress, int age, std::vector<int> degreeNumDays)
{
	this->g_studentID = studentID;
	this->g_firstName = firstName;
	this->g_lastName = lastName;
	this->g_emailAddress = emailAddress;
	this->g_age = age;
	this->g_degreeNumDays = degreeNumDays;
}

// Accessors

int Student::getStudentID()
{ 
	return g_studentID; 
}

char Student::getFirstName()
{
	return g_firstName;
}

char Student::getLastName()
{
	return g_lastName;
}

char Student::getEmailAddress()
{
	return g_emailAddress;
}

int Student::getAge()
{
	return g_age;
}

std::vector<int> Student::getDegreeNumDays()
{
	return g_degreeNumDays;
}

// Mutators

void Student::setStudentID(int studentID)
{ 
	this->g_studentID = studentID;
}

void Student::setFirstName(char firstName)
{
	this->g_firstName = firstName;
}

void Student::setLastName(char lastName)
{
	this->g_lastName = lastName;
}

void Student::setEmailAddress(char emailAddress)
{
	this->g_emailAddress = emailAddress;
}

void Student::setAge(int age)
{
	this->g_age = age;
}

void Student::setDegreeNumDays(std::vector<int> degreeNumDays)
{
	this->g_degreeNumDays = degreeNumDays;
}