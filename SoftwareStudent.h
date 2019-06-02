#pragma once
#include "Student.h"
#include "degree.h"
class SoftwareStudent : 
	public Student
{

public:
	SoftwareStudent();
	SoftwareStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degreetype);
	

	Degree getDegreeProgram();
	void print();

	~SoftwareStudent();
};

