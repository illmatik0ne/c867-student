// C867_Student_Data.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


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
		std::cout << "Parsing: " << studentData[student] << '\n';  // Output each student string to the console
		//std::size_t delimPos = 0;
		//std::size_t substrStart = 0;
		//	while (delimPos != std::string::npos)
		//	{
		//		delimPos = studentData[student].find(",", substrStart);
		//		//std::size_t delimPos = studentData[student].find(",", substrStart);
		//		int substrLength = delimPos - substrStart;
		//		std::string substrWord = studentData[student].substr(substrStart, substrLength);
		//		std::cout << substrWord << '\n';
		//		substrStart = delimPos + (substrStart+1);
		//	}
	}
	
	return 0;
}