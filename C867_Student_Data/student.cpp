#include "stdafx.h"
#include "student.h"

// Student constructor

Student::Student(int studentID, char firstName, char lastName, char emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, char degreeType)
{
	this->g_studentID = studentID;
	this->g_firstName = firstName;
	this->g_lastName = lastName;
	this->g_emailAddress = emailAddress;
	this->g_age = age;
	this->setDegreeNumDays(daysInCourse1, daysInCourse2, daysInCourse3);
	this->g_degreeType = degreeType;
}


// Accessors


int Student::getStudentID() const { 
	return g_studentID; 
}

char Student::getFirstName() const {
	return g_firstName;
}

char Student::getLastName() const {
	return g_lastName;
}

char Student::getEmailAddress() const {
	return g_emailAddress;
}

int Student::getAge() const {
	return g_age;
}

int Student::getDegreeNumDays() const {
	return g_degreeNumDays[3];
}

char Student::getDegreeType() const {
	return g_degreeType;
}


// Mutators


void Student::setStudentID(int studentID) { 
	this->g_studentID = studentID;
}

void Student::setFirstName(char firstName) {
	this->g_firstName = firstName;
}

void Student::setLastName(char lastName) {
	this->g_lastName = lastName;
}

void Student::setEmailAddress(char emailAddress) {
	this->g_emailAddress = emailAddress;
}

void Student::setAge(int age) {
	this->g_age = age;
}

void Student::setDegreeNumDays(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
	g_degreeNumDays[0] = daysInCourse1;
	g_degreeNumDays[1] = daysInCourse2;
	g_degreeNumDays[2] = daysInCourse3;
}

void Student::setDegreeType(char degreeType) {
	g_degreeType = degreeType;
}

