#include "stdafx.h"
#include "student.h"
#include <iostream>

using namespace std;

Student::Student() {};
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int* days) {};

//Student::Student(std::string v_studentID, std::string v_firstName, std::string v_lastName, std::string v_emailAddress,
//	int v_age, int* days, std::string v_degreeProgram) {
//	studentID = v_studentID;
//	firstName = v_firstName;
//	lastName = v_lastName;
//	emailAddress = v_emailAddress;
//	age = v_age;
//	days = v_days;
//	degreeProgram = v_degreeProgram;
//}


std::string Student::get_studentID()
{
	return studentID;
}

std::string Student::get_firstName()
{
	return firstName;
}

std::string Student::get_lastName()
{
	return lastName;
}

std::string Student::get_emailAddress()
{
	return emailAddress;
}

int Student::get_age()
{
	return age;
}

int Student::get_days(int i)
{
	return days[i];
}



std::string Student::set_studentID(std::string v_studentID)
{
	studentID = v_studentID;
	return studentID;
}

std::string Student::set_firstName(std::string v_firstName)
{
	firstName = v_firstName;
	return firstName;
}

std::string Student::set_lastName(std::string v_lastName)
{
	lastName = v_lastName;
	return lastName;
}

std::string Student::set_emailAddress(std::string v_emailAddress)
{
	emailAddress = v_emailAddress;
	return emailAddress;
}

int Student::set_age(int v_age)
{
	age = v_age;
	return age;
}

int* Student::set_days(int v_daysInCourse1, int v_daysInCourse2, int v_daysInCourse3)
{
	days[0] = v_daysInCourse1;
	days[1] = v_daysInCourse2;
	days[2] = v_daysInCourse3;
	return days;
}

void Student::printStudent()
{
	std::cout << "Student Information:" << '\n' <<
		'\t' << "StudentID: " << get_studentID() << '\n' <<
		'\t' << "First Name: " << get_firstName() << '\n' <<
		'\t' << "Last Name: " << get_lastName() << '\n' <<
		'\t' << "Email Address: " << get_emailAddress() << '\n' <<
		'\t' << "Age: " << get_age() << '\n' <<
		'\t' << "Days In Course: " << "{" << get_days(0) << ", " << get_days(1) << ", " << get_days(2) << "}" << '\n';

}