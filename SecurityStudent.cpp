#include "SecurityStudent.h"
#include <iostream>
using std::cout;

SecurityStudent::SecurityStudent() :Student()
{
	dtype = SECURITY;
}
SecurityStudent::SecurityStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degreetype)
	: Student(studentId, firstName, lastName, emailAddress, age, daysInCourse)
{
	dtype = SECURITY;
}

Degree SecurityStudent::getDegreeProgram()
{
	return SECURITY;
}

void SecurityStudent::print()
{
	this->Student::print();
	cout << "SECURITY" << "\n";
}

SecurityStudent::~SecurityStudent()
{
}