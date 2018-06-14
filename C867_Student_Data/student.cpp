#include "stdafx.h"
#include "student.h"

// Student constructor

Student::Student(int studentID, char firstName, char lastName, char emailAddress, int age, int degreeNumDays1, int degreeNumDays2, int degreeNumDays3)
{
	this->g_studentID = studentID;
	this->g_firstName = firstName;

}

// Student function

int Student::getStudentID()
{ 
	return g_studentID; 
}

void Student::setStudentID(int studentID)
{ 
	g_studentID = studentID; 
}

char Student::getFirstName()
{ 
	return g_firstName;
}

void Student::setFirstName(char firstName)
{
	g_firstName = firstName;
}

char Student::getLastName()
{ 
	return g_lastName;
}

void Student::setLastName(char lastName)
{
	g_lastName = lastName;
}

char Student::getEmailAddress()
{
	return g_emailAddress;
}

void Student::setEmailAddress(char emailAddress)
{
	g_emailAddress = emailAddress;
}

int Student::getAge()
{
	return g_age;
}

void Student::setAge(int age)
{
	g_age = age;
}

int* Student::getDegreeNumDays()
{
	return g_degreeNumDays;
}

void Student::setDegreeNumDays(int degreeNumDays1, int degreeNumDays2, int degreeNumDays3)
{
	g_degreeNumDays[0] = degreeNumDays1;
	g_degreeNumDays[1] = degreeNumDays2;
	g_degreeNumDays[2] = degreeNumDays3;
}