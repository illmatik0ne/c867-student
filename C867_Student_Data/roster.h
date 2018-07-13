#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"
#include <string>

class Roster {

private:

	Student ** classRosterArray;
	int maxStudents = 0;

public:
	Roster(int maxStudents);
	~Roster();

	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeprogram);
	void remove(std::string);
	void printAverageDaysInCourse(std::string studentID);
	void printAll();
	void printByDegreeProgram(Degree degreeProgram);

};
#endif