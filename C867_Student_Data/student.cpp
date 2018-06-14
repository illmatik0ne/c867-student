#include "stdafx.h"
#include "student.h"

// Student constructor

Student::Student(int studentID, char firstName, char lastName, char emailAddress, int age, int degreeNumDays1, int degreeNumDays2, int degreeNumDays3)
{
	this->g_studentID = studentID;
	this->g_firstName = firstName;
	this->g_lastName = lastName;
	this->g_emailAddress = emailAddress;
	this->g_age = age;
	this->setDegreeNumDays(degreeNumDays1, degreeNumDays2, degreeNumDays3);
}

// Student function

int Student::getStudentID()
{ 
	return g_studentID; 
}

void Student::setStudentID(int studentID)
{ 
	this->g_studentID = studentID;
}

char Student::getFirstName()
{ 
	return g_firstName;
}

void Student::setFirstName(char firstName)
{
	this->g_firstName = firstName;
}

char Student::getLastName()
{ 
	return g_lastName;
}

void Student::setLastName(char lastName)
{
	this->g_lastName = lastName;
}

char Student::getEmailAddress()
{
	return g_emailAddress;
}

void Student::setEmailAddress(char emailAddress)
{
	this->g_emailAddress = emailAddress;
}

int Student::getAge()
{
	return g_age;
}

void Student::setAge(int age)
{
	this->g_age = age;
}

int* Student::getDegreeNumDays()
{
	return g_degreeNumDays;
}

void Student::setDegreeNumDays(int degreeNumDays1, int degreeNumDays2, int degreeNumDays3)
{
	this->g_degreeNumDays[0] = degreeNumDays1;
	this->g_degreeNumDays[1] = degreeNumDays2;
	this->g_degreeNumDays[2] = degreeNumDays3;
}