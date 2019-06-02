#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

/*Constructor and Destructor*/
Student::Student() {
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysArraySize; i++) this->daysInCourse[i] = 0;
}
Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[]) {
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this-> emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
}

/*Getter*/
string Student::getStudent_ID() {	return studentId;}

string Student::getFirst_Name() {	return firstName;}

string Student::getLast_Name() {	return lastName;}

string Student::getEmail_Address() {	return emailAddress;}

int Student::getAge() {	return age;}

int* Student::getNumDays()
{
	return daysInCourse;
}

/*Setter*/
void Student::setStudent_ID(string studentId) { this->studentId = studentId; }

void Student::setFirst_Name(string firstName) { this->firstName = firstName; }

void Student::setLast_Name(string lastName) { this->lastName = lastName; }

void Student::setEmail_Address(string emailAddress) { this->emailAddress = emailAddress; }

void Student::setAge(int age) { this->age = age; }

void Student::setNumDays(int daysInCourse[])
{
	for (int i = 0; i < daysArraySize; i++)
		this->daysInCourse[i] = daysInCourse[i];
}

/*Print*/
void Student::print() {
	cout << getStudent_ID();
	cout << "First Name: " << getFirst_Name();
	cout << "Last Name: " << getLast_Name();
	cout << "Age: " << getAge();
	cout << "Days in Course: " << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2];
}

Student::~Student()
{
}
