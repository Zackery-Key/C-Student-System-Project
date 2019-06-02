#pragma once
#include "Student.h"
#include "degree.h"
class NetworkStudent :
	public Student
{
public:
	NetworkStudent();
	NetworkStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degreetype);


	Degree getDegreeProgram();
	void print();

	~NetworkStudent();
};

