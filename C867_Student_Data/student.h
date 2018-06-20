#ifndef STUDENT_H
#define STUDENT_H

#include <vector>

// Declare the Student class

class Student
{
	private:
		int g_studentID;
		char g_firstName;
		char g_lastName;
		char g_emailAddress;
		int g_age;
		std::vector<int> g_degreeNumDays;

	public:
		Student(int studentID, char firstName, char lastName, char emailAddress, int age, std::vector<int> degreeNumDays);  // default constructor
			
		int getStudentID();
		void setStudentID(int studentID);

		char getFirstName();
		void setFirstName(char firstName);
				
		char getLastName();
		void setLastName(char lastName);

		char getEmailAddress();
		void setEmailAddress(char emailAddress);
		
		int getAge();
		void setAge(int age);
		
		std::vector<int> getDegreeNumDays();
		void setDegreeNumDays(std::vector<int> degreeNumDays);
};

#endif