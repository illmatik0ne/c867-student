// C867_Student_Data.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "roster.h"
#include <iostream>
#include <string>

const std::string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,J,A,j.a@wgu.edu,39,30,25,45,SOFTWARE" };

struct studentFields
{
	std::size_t start;
	std::size_t length;
};

Degree degreeConvert(std::string degreeprogram) //function to convert string to Degree
{
	if (degreeprogram == "SECURITY")
	{
		return SECURITY;
	}
	else if (degreeprogram == "NETWORK")
	{
		return NETWORK;
	}
	else if (degreeprogram == "SOFTWARE")
	{
		return SOFTWARE;
	}
}

Roster::Roster(int maxStudents)
{
	this->maxStudents = maxStudents;
	this->classRosterArray = new Student *[maxStudents];
	memset(classRosterArray, 0, sizeof(classRosterArray) * maxStudents);
}

Roster::~Roster() {

	for (int i = 0; i < maxStudents; i++)
	{
		if (classRosterArray[i] != NULL)
		{
			std::cout << "Deleting Student " << i << '\n';
			delete classRosterArray[i];
		}
	}
	std::cout << "Deleting classRoster"<< '\n';
	delete classRosterArray;
};

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeprogram)
{
	Student * s = NULL;
	int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	if (degreeprogram == SECURITY)
	{
		s = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, days);
	}
	else if (degreeprogram == NETWORK)
	{
		s = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, days);
	}
	else if (degreeprogram == SOFTWARE)
	{
		s = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, days);
	}

	if (s != NULL) {
		for (int i = 0; i < maxStudents; i++)
		{
			if (classRosterArray[i] == NULL)
			{
				classRosterArray[i] = s;
				break;
			}
		}
	}
}

void Roster::remove(std::string studentID)
{
	int match = 0;
	int i;
	std::cout << "Attempting to remove student " << studentID << " from the roster." << '\n';
	for (i = 0; i < maxStudents; i++)
	{
		if (classRosterArray[i] != NULL)
		{
			if (classRosterArray[i]->get_studentID() == studentID)
			{
				match++;
				break;
			}
		}
	}
	
	if (match != 0 )
	{
		std::cout << "Student: " << studentID << " found! Removing from the roster." << '\n';
		delete classRosterArray[i];
		classRosterArray[i] = NULL;
	}
	else std::cout << "A student with ID " << studentID << " could not be found." << '\n';
	
}

void Roster::printAverageDaysInCourse()
{
	for (int i = 0; i < maxStudents; i++)
	{
		int avgDaysInCourse = 
				((classRosterArray[i]->get_days(0)) + 
				(classRosterArray[i]->get_days(1)) + 
				(classRosterArray[i]->get_days(2))) / 3;
		
		std::cout << "Average Days in Course for student " << classRosterArray[i]->get_studentID() << " : " << 
				avgDaysInCourse << '\n';
	}
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i < maxStudents; i++)
	{
		int errorFlag = 0;

		if (classRosterArray[i] != NULL)
		{
			std::string emailAddress = classRosterArray[i]->get_emailAddress();
				if (emailAddress.find(' ') != std::string::npos)
				{ 
					errorFlag++;
				}
				else if (emailAddress.find("@") == std::string::npos)
				{
					errorFlag++;
				}
				else if (emailAddress.find(".", emailAddress.find("@")) == std::string::npos)
				{
					errorFlag++;
				}
				if (errorFlag > 0)
				{
					std::cout << emailAddress << " is an invalid email address." << '\n';
				}
		}
	}
}

void Roster::printByDegreeProgram(Degree degreeProgram)
{
	for (int i = 0; i < maxStudents; i++)
	{
		if (classRosterArray[i] != NULL)
		{
			if (classRosterArray[i]->getDegreeProgram() == degreeProgram)
			{
				classRosterArray[i]->printStudent();
			}
		}

	}
}

void Roster::printAll()
{
	std::cout << "Student Information:" << '\n';
	for (int i = 0; i < maxStudents; i++)
	{
		if (classRosterArray[i] != NULL) 
		{
			classRosterArray[i]->printStudent();
		}
	}
}

int main() {

	std::cout << "C867: Scripting and Programming - Applications" << '\n' <<
		"Written in C++" << '\n' << "J A" << '\n' << "Student ID: 831181" << '\n';
	std::cout << '\n';

	const int maxStudents = sizeof(studentData) / sizeof(studentData[0]);

	Roster * classRoster = new Roster(maxStudents);

	for (int i = 0; i < maxStudents; i++)
		{
		std::string delimiter = ",";
		std::size_t strSize = studentData[i].size();
		std::size_t substrStartPos = 0;
		std::size_t substrEndPos = 0;
		studentFields line[9];
		
		for (int student = 0; student < 9; student++)
			{
				substrEndPos = studentData[i].find(delimiter, substrStartPos);
				if (substrEndPos != std::string::npos)
				{
					line[student].start = substrStartPos;
					line[student].length = (substrEndPos - substrStartPos);
				}
				else
				{
					line[student].start = substrStartPos;
					line[student].length = (strSize - substrStartPos);
				}
				substrStartPos = substrEndPos + delimiter.length();
			}
			classRoster->add(
			studentData[i].substr(line[0].start, line[0].length),
			studentData[i].substr(line[1].start, line[1].length),
			studentData[i].substr(line[2].start, line[2].length),
			studentData[i].substr(line[3].start, line[3].length),
			std::stoi(studentData[i].substr(line[4].start, line[4].length)),
			std::stoi(studentData[i].substr(line[5].start, line[5].length)),
			std::stoi(studentData[i].substr(line[6].start, line[6].length)),
			std::stoi(studentData[i].substr(line[7].start, line[7].length)),
			degreeConvert(studentData[i].substr(line[8].start, line[8].length))
		);
	}
	
	classRoster->printAll();
	std::cout << '\n';
	
	classRoster->printInvalidEmails();
	std::cout << '\n';
	
	classRoster->printAverageDaysInCourse();
	std::cout << '\n';
	
	classRoster->printByDegreeProgram(SOFTWARE);
	std::cout << '\n';
	
	classRoster->remove("A3");
	std::cout << '\n';
	
	classRoster->remove("A3");
	std::cout << '\n';
	
	delete classRoster;
	std::cout << '\n';

	return 0;
}