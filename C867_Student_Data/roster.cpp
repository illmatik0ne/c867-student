// C867_Student_Data.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "roster.h"
#include "softwareStudent.h"
#include "securityStudent.h"
#include "networkStudent.h"

#include <iostream>
#include <string>

const std::string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,J,A,j.a@wgu.edu,39,30,25,45,SOFTWARE" };

struct studentFields {
	int start;
	int length;

};


Roster::Roster(int maxStudents)
{
	this->maxStudents = maxStudents;
	this->classRosterArray = new Student *[maxStudents];
	memset(classRosterArray, 0, sizeof(classRosterArray) * maxStudents);
	//for (int i = 0; i < maxStudents; i++)
	//{
	//	if (classRosterArray[i] == NULL)
	//	{
	//		std::cout << "i is NULL" << '\n';  // Just testing memset to verify NULL
	//	}
	//}
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
		std::cout << "Removing student " << studentID << " from the roster." << '\n';
		delete classRosterArray[i];
		classRosterArray[i] = NULL;
	}
	else std::cout << "A student with ID " << studentID << " could not be found." << '\n';
	
}

void Roster::printAverageDaysInCourse(std::string studentID)
{
	for (int i = 0; i < maxStudents; i++)
	{
		if (classRosterArray[i]->get_studentID() == studentID)
		{
			int avgDaysInCourse = 
				((classRosterArray[i]->get_days(0)) + 
				(classRosterArray[i]->get_days(1)) + 
				(classRosterArray[i]->get_days(2))) / 3;
			std::cout << "Average Days in Course for student " << studentID << " : " << 
				avgDaysInCourse << '\n';
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
	for (int i = 0; i < maxStudents; i++)
	{
		if (classRosterArray[i] != NULL) 
		{
			classRosterArray[i]->printStudent();
		}
	}
}

int main() {

	const int numStudents = sizeof(studentData) / sizeof(studentData[0]);  //source data size

	Roster * classRoster = new Roster(numStudents);
	
	classRoster->add("A1", "John", "Smith", "John1989@gm ail.com", 20, 30, 35, 40, SECURITY);
	classRoster->add("A2", "Suzan", "Erickson", "Erickson_1990@gmailcom", 19, 50, 30, 40, NETWORK);
	classRoster->add("A3", "Jack", "Napoli", "The_lawyer99yahoo.com", 19, 20, 40, 33, SOFTWARE);
	classRoster->add("A4", "Erin", "Black", "Erin.black@comcast.net", 22, 50, 58, 40, SECURITY);
	classRoster->add("A5", "J", "A", "j.a@wgu.edu", 39, 30, 25, 45, SOFTWARE);
	
	classRoster->printAll();
	
	classRoster->printAverageDaysInCourse("A1");
	classRoster->printAverageDaysInCourse("A2");
	classRoster->printAverageDaysInCourse("A3");
	classRoster->printAverageDaysInCourse("A4");
	classRoster->printAverageDaysInCourse("A5");

	classRoster->printByDegreeProgram(SECURITY);
	classRoster->printByDegreeProgram(NETWORK);
	classRoster->printByDegreeProgram(SOFTWARE);

	classRoster->remove("A1");
	classRoster->remove("A1");
	classRoster->remove("A2");
	classRoster->remove("A2");
	classRoster->remove("A3");
	classRoster->remove("A3");
	classRoster->remove("A4");
	classRoster->remove("A4");
	classRoster->remove("A5");
	classRoster->remove("A5");

	classRoster->printAll();

	classRoster->add("A5", "J", "A", "j.a@wgu.edu", 39, 30, 25, 45, SOFTWARE);
	classRoster->add("A4", "Erin", "Black", "Erin.black@comcast.net", 22, 50, 58, 40, SECURITY);
	classRoster->add("A3", "Jack", "Napoli", "The_lawyer99yahoo.com", 19, 20, 40, 33, SOFTWARE);
	classRoster->add("A2", "Suzan", "Erickson", "Erickson_1990@gmailcom", 19, 50, 30, 40, NETWORK);
	classRoster->add("A1", "John", "Smith", "John1989@gm ail.com", 20, 30, 35, 40, SECURITY);

	classRoster->printAll();

	studentFields line[9];

	for (int student = 0; student < numStudents; student++) // Loop through the array until finished
	{
		std::cout << "Parsing: " << studentData[student] << std::endl;  // Output each student string to the console
		std::string delimiter = ",";
		int fieldNum = 0;
		int strSize = studentData[student].size();
		std::size_t substrStartPos = 0;
		std::size_t substrEndPos = 0;

		for (fieldNum = 0; fieldNum < 9; fieldNum++)
		{
			substrEndPos = studentData[student].find(delimiter, substrStartPos);
			line[fieldNum].start = substrStartPos;
			line[fieldNum].length = (substrEndPos - substrStartPos);
			substrStartPos = substrEndPos + delimiter.length();
			std::cout << "(" << line[fieldNum].start << "," << line[fieldNum].length << ")" << '\n';
		}
		
	}

	delete classRoster;

	return 0;
}

/*
// Provided Student Data for Assignment - Comments to help me remember the substring details when I'm ready for this step

const std::string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40" };

const int numStudents = sizeof(studentData) / sizeof(studentData[0]); // Determine the number of students in studentData[]

int main()
{
	for (int student = 0; student < numStudents; student++) // Loop through the array until finished
	{
		std::cout << "Parsing: " << studentData[student] << std::endl;  // Output each student string to the console
		std::string delimiter = ",";

		std::size_t substrStartPos = 0;
		std::size_t substrEndPos = studentData[student].find(delimiter);

		while (substrEndPos != std::string::npos)  // loop until no matches found
		{
			std::cout << studentData[student].substr(substrStartPos, substrEndPos - substrStartPos) << std::endl;  // output substring
			substrStartPos = substrEndPos + delimiter.length();  // update the starting
			substrEndPos = studentData[student].find(delimiter, substrStartPos); // find the next delimiter position
		}

		std::cout << studentData[student].substr(substrStartPos, substrEndPos) << std::endl; // output the last substring which is always degree program
	}
	
	return 0;
}
*/

//for (int student = 0; student < numStudents; student++) // Loop through the array until finished
//{
//	std::cout << "Parsing: " << studentData[student] << std::endl;  // Output each student string to the console
//	std::string delimiter = ",";
//	int fieldNum = 0;
//
//	std::size_t substrStartPos = 0;
//	std::size_t substrEndPos = studentData[student].find(delimiter);
//	line[fieldNum].start = substrStartPos;
//	line[fieldNum].length = (substrEndPos - substrStartPos);
//	fieldNum++;
//
//	while (substrEndPos != std::string::npos)  // loop until no matches found
//	{
//		std::cout << studentData[student].substr(substrStartPos, substrEndPos - substrStartPos) << std::endl;  // output substring
//		substrStartPos = substrEndPos + delimiter.length();  // update the starting
//		substrEndPos = studentData[student].find(delimiter, substrStartPos); // find the next delimiter position
//		line[fieldNum].start = substrStartPos;
//		line[fieldNum].length = (substrEndPos - substrStartPos);
//		fieldNum++;
//	}
//
//	std::cout << studentData[student].substr(substrStartPos, substrEndPos) << std::endl; // output the last substring which is always degree program
//	line[fieldNum].start = substrStartPos;
//	line[fieldNum].length = ((studentData[student].size()) - substrStartPos);
//	std::cout << "substrStartPos: " << substrStartPos << '\n';
//	std::cout << "substrLength: " << ((studentData[student].size()) - substrStartPos) << '\n';
//
//	for (int i = 0; i < 9; i++)
//	{
//		std::cout << "(" << line[i].start << "," << line[i].length << ")" << '\n';
//	}
//}