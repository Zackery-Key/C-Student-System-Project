#include "SoftwareStudent.h"
#include <iostream>
using std::cout;

SoftwareStudent::SoftwareStudent() :Student()
{
	dtype = SOFTWARE;
}
SoftwareStudent::SoftwareStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse [], Degree degreetype)
	: Student(studentId, firstName, lastName, emailAddress, age, daysInCourse)
{
	dtype = SOFTWARE;
}

Degree SoftwareStudent::getDegreeProgram()
{
	return SOFTWARE;
}

void SoftwareStudent::print()
{
	this->Student::print();
	cout << "SOFTWARE" << "\n";
}

SoftwareStudent::~SoftwareStudent()
{
}