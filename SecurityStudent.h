#pragma once
#include "Student.h"
#include "degree.h"
class SecurityStudent :
	public Student
{
public:
	SecurityStudent();
	SecurityStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degreetype);
	
	
	Degree getDegreeProgram();
	void print();

	~SecurityStudent();
};

