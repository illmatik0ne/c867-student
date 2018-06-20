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