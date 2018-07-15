#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H
#include "student.h"
// Declare the SoftwareStudent class

class SoftwareStudent : public Student
{
private:

	Degree degreeprogram;

public:

	SoftwareStudent(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int* days);
	~SoftwareStudent();

	Degree getDegreeProgram();
};

#endif