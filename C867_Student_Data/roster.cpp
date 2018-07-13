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

//Roster::Roster() {
//	this->classRosterArray = new Student *[5];
//
//}

Roster::Roster(int maxStudents) {
	this->classRosterArray = new Student *[maxStudents];
}

Roster::~Roster() {

	for (int i = 0; i < numStudents; i++)
	{
		std::cout << "Destroy Student " << i << '\n';
		delete classRosterArray[i];
	}
	std::cout << "Destroy classRosterArray "<< '\n';
	delete classRosterArray;
};

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeprogram)
{
	std::cout << "Size of Roster Array: " << sizeof(classRosterArray) / sizeof(*classRosterArray) << '\n';
	std::cout << "Number of Students in Roster: " << numStudents << '\n';
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
		classRosterArray[numStudents++] = s;
	}
}

void Roster::remove(std::string studentID)
{
	int match = 0;
	for (int i = 0; i < numStudents; i++)
	{
		if (classRosterArray[i]->get_studentID() == studentID) {
			std::cout << "Removing student " << studentID << " from the roster." << '\n';
			delete classRosterArray[i];
			match++;
		}
	}
		if (match == 0) {
				std::cout << "A student with ID " << studentID << " could not be found." << '\n';
		}
}

//void Roster::remove(std::string studentID)
//{
//	for (int i = 0; i < numStudents; i++)
//	{
//		if (classRosterArray[i]->get_studentID() == studentID) {
//			std::cout << "Removing student " << studentID << " from the roster." << '\n';
//			delete classRosterArray[i];
//		}
//	}
//}

void Roster::printDaysInCourse(std::string studentID)
{
	for (int i = 0; i < numStudents; i++)
	{
		if (classRosterArray[i]->get_studentID() == studentID) {
			int avgDaysInCourse = ((classRosterArray[i]->get_days(0)) + (classRosterArray[i]->get_days(1)) + (classRosterArray[i]->get_days(2))) / 3;
			std::cout << "Average Days in Course for student " << studentID << " : " << avgDaysInCourse << '\n';
		}
	}
}

void Roster::printAll()
{
	for (int i = 0; i < numStudents; i++)
	{
		classRosterArray[i]->printStudent();
	}
}

int main() {

	Roster * classRoster = new Roster(5);
	
	classRoster->add("A1", "John", "Smith", "John1989@gm ail.com", 20, 30, 35, 40, SECURITY);
	classRoster->add("A2", "Suzan", "Erickson", "Erickson_1990@gmailcom", 19, 50, 30, 40, NETWORK);
	classRoster->add("A3", "Jack", "Napoli", "The_lawyer99yahoo.com", 19, 20, 40, 33, SOFTWARE);
	classRoster->add("A4", "Erin", "Black", "Erin.black@comcast.net", 22, 50, 58, 40, SECURITY);
	classRoster->add("A5", "J", "A", "j.a@wgu.edu", 39, 30, 25, 45, SOFTWARE);
	classRoster->printAll();
	classRoster->printDaysInCourse("A1");
	classRoster->printDaysInCourse("A2");
	classRoster->printDaysInCourse("A3");
	classRoster->printDaysInCourse("A4");
	classRoster->printDaysInCourse("A5");

	classRoster->remove("A5");
	classRoster->remove("A5");

	classRoster->printAll();

	delete classRoster;

	return 0;
}



// Creating array of pointers to hold Student Objects and adding each student object
//typedef Student* StudentPtr; 
//StudentPtr * classRosterArray = new StudentPtr[3];  // Saw this typedef aliasing and wondered why this over below.  Ask instructor?



/*
Student ** classRosterArray = new Student*[4];
for (int i = 0; i < 4; ++i) {
classRosterArray[i] = new Student();  // future spot for iteration through student substring data
}

// Testing creating student object and populating data statically through mutators
classRosterArray[0]->set_studentID("A1");
classRosterArray[0]->set_firstName("John");
classRosterArray[0]->set_lastName("Smith");
classRosterArray[0]->set_emailAddress("John1989@gm ail.com");
classRosterArray[0]->set_age(20);
classRosterArray[0]->set_days(30,35,40);
classRosterArray[0]->set_degreeProgram("SECURITY");

classRosterArray[1]->set_studentID("A2");
classRosterArray[1]->set_firstName("Suzan");
classRosterArray[1]->set_lastName("Erickson");
classRosterArray[1]->set_emailAddress("Erickson_1990@gmailcom");
classRosterArray[1]->set_age(19);
classRosterArray[1]->set_days(50,30,40);
classRosterArray[1]->set_degreeProgram("NETWORK");

classRosterArray[2]->set_studentID("A3");
classRosterArray[2]->set_firstName("Jack");
classRosterArray[2]->set_lastName("Napoli");
classRosterArray[2]->set_emailAddress("The_lawyer99yahoo.com");
classRosterArray[2]->set_age(19);
classRosterArray[2]->set_days(20,40,33);
classRosterArray[2]->set_degreeProgram("SOFTWARE");

classRosterArray[3]->set_studentID("A4");
classRosterArray[3]->set_firstName("Erin");
classRosterArray[3]->set_lastName("Black");
classRosterArray[3]->set_emailAddress("Erin.black@comcast.net");
classRosterArray[3]->set_age(22);
classRosterArray[3]->set_days(50,58,40);
//classRosterArray[3]->set_degreeProgram("SECURITY");

/*
Testing creating student object with paramaterized constructor.
Should be removed but used as a learning tool to help me understand constructors and accessor/mutators.
Found it interesting that the IDE formats accessor/mutator object.printstudent() with -> but when creating the object
using paramaterized constructor it formats object.printstude() it without the ->.  Ask instructor?  Seems to behave the same.

//Student student2("A2", "J", "A", "ja@wgu.edu", 39, 30, 40, 50, "SOFTWARE");
//student2.printStudent();

*/

/*
// Provided Student Data for Assignment

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

		std::cout << studentData[student].substr(substrStartPos, substrEndPos) << std::endl; // output the last substring
	}
	
	return 0;
}
*/