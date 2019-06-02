#pragma once
#include <string>
#include <iostream>
#include "degree.h"
using namespace std;
class Student
{
public:
	const static int daysArraySize = 3;

protected:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[daysArraySize];
	Degree dtype;

public:

	/*Contructor*/
	Student();
	Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[]);

	/*Getters*/
	string getStudent_ID();
	string getFirst_Name();
	string getLast_Name();
	string getEmail_Address();
	int getAge();
	int* getNumDays();
	virtual Degree getDegreeProgram() = 0;

	/*Setters*/
	void setStudent_ID(string studentId);
	void setFirst_Name(string firstName);
	void setLast_Name(string lastName);
	void setEmail_Address(string emailAddress);
	void setAge(int age);
	void setNumDays(int daysInCourse[]);



	virtual void print() = 0;

	/*Destructor*/
	~Student();
};
