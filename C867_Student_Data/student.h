#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "degree.h"

class Student {

private:
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age, daysInCourse1, daysInCourse2, daysInCourse3;
	int days[3];

public:

	Student();
	~Student();

	Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int* days);

	std::string get_studentID();
	std::string get_firstName();
	std::string get_lastName();
	std::string get_emailAddress();
	int get_age();
	int get_days(int i);
	virtual Degree getDegreeProgram() = 0;

	std::string set_studentID(std::string);
	std::string set_firstName(std::string);
	std::string set_lastName(std::string);
	std::string set_emailAddress(std::string);
	int set_age(int);
	int* set_days(int v_daysInCourse1, int v_daysInCourse2, int v_daysInCourse3);
	
	void printStudent();

};
#endif