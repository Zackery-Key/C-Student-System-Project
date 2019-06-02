#include "NetworkStudent.h"
#include <iostream>
using std::cout;

NetworkStudent::NetworkStudent() :Student()
{
	dtype = NETWORK;
}
NetworkStudent::NetworkStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degreetype)
	: Student(studentId, firstName, lastName, emailAddress, age, daysInCourse)
{
	dtype = NETWORK;
}

Degree NetworkStudent::getDegreeProgram()
{
	return NETWORK;
}

void NetworkStudent::print()
{
	this->Student::print();
	cout << "NETWORK" << "\n";
}

NetworkStudent::~NetworkStudent()
{
}

