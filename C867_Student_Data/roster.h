#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"
#include <string>

class Roster {

private:

	Student ** classRosterArray;

public:

	void add(std::string, std::string, std::string, std::string, int, int, int, int, Degree);
	void remove(std::string);
	void printDaysInCourse(std::string);
	void printAll();

};
#endif