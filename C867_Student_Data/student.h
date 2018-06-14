#ifndef STUDENT_H
#define STUDENT_H

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

	public:
		Student(int studentID, char firstName, char lastName, char emailAddress, int age, int degreeNumDays1, int degreeNumDays2, int degreeNumDays3);  // default constructor
			
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
		
		int* getDegreeNumDays();
		void setDegreeNumDays(int degreeNumDays1, int degreeNumDays2, int degreeNumDays3);


};

#endif