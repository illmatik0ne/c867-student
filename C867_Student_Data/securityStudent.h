#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H
#include "student.h"

// Declare the SecurityStudent class

class SecurityStudent : public Student
{
private:

	Degree degreeprogram;

public:

	SecurityStudent(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int* days);
	~SecurityStudent();

	Degree getDegreeProgram();
	void print();
};

#endif
