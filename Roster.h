#pragma once
#include <string>
#include <iostream>
#include "degree.h"
#include "Student.h"
#include "SoftwareStudent.h"
#include "NetworkStudent.h"
#include "SecurityStudent.h"

class Roster
{
private:
	int capacity;
	int lastIndex;
	Student** classRosterArray; //array of pointers to Students
	
public:

	Roster();
	Roster(int capacity);

	Student* getStudentAt(int index);
	void parseAndAdd(string datarow);
	void add(string studentId, string firstName, string lastName, string email, int age,
		int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreetype);
	void remove(string studentId);
	void printAll();
	void printDaysInCourse(string studentId);
	void printInvalidEmails();
	void printByDegreeProgram(int degreeProgram);

	~Roster();
};

