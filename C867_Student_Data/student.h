#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "securityStudent.h"

// Declare the Student class

class Student
{
	private:
		int g_studentID;
		char g_firstName;
		char g_lastName;
		char g_emailAddress;
		int g_age;
		int g_degreeNumDays[3];
		char g_degreeType;

	public:
		Student(int studentID, char firstName, char lastName, char emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, char degreeType);  // default constructor
			
		int getStudentID() const;
		char getFirstName() const;
		char getLastName() const;
		char getEmailAddress() const;
		int getAge() const;
		int getDegreeNumDays() const;
		char getDegreeType() const;


		void setStudentID(int studentID);
		void setFirstName(char firstName);
		void setLastName(char lastName);
		void setEmailAddress(char emailAddress);
		void setAge(int age);
		void setDegreeNumDays(int daysInCourse1, int daysInCourse2, int daysInCourse3);
		void setDegreeType(char degreeType);

};

#endif