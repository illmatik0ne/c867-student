#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H
#include "student.h"

// Declare the NetworkStudent class

class NetworkStudent : public Student
{
private:

	Degree degreeprogram;

public:

	NetworkStudent(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int* days);
	~NetworkStudent();

	Degree getDegreeProgram();
};

#endif