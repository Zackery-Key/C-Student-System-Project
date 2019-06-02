#include "Roster.h"
using std::cout;
using std::cerr;

Roster::Roster()
{
	this->classRosterArray = nullptr;
}

void Roster::parseAndAdd(string datarow)
{
	//Find ID
	int rhs = datarow.find(",");
	string sID = datarow.substr(0, rhs);

	//Find First Name
	int lhs = rhs + 1;
	rhs = datarow.find(",", lhs);
	string sFirstName = datarow.substr(lhs, rhs - lhs);

	//Find Last Name
	lhs = rhs + 1;
	rhs = datarow.find(",", lhs);
	string sLastName = datarow.substr(lhs, rhs - lhs);

	//Find Email
	lhs = rhs + 1;
	rhs = datarow.find(",", lhs);
	string sEmail = datarow.substr(lhs, rhs - lhs);

	//Find Age
	lhs = rhs + 1;
	rhs = datarow.find(",", lhs);
	int sAge = stod(datarow.substr(lhs, rhs - lhs));

	//Find Days in Course 1
	lhs = rhs + 1;
	rhs = datarow.find(",", lhs);
	int days1 = stod(datarow.substr(lhs, rhs - lhs));

	//Find Days in Course 2
	lhs = rhs + 1;
	rhs = datarow.find(",", lhs);
	int days2 = stod(datarow.substr(lhs, rhs - lhs));

	//Find Days in Course 3
	lhs = rhs + 1;
	rhs = datarow.find(",", lhs);
	int days3 = stod(datarow.substr(lhs, rhs - lhs));

	//Find Degree
	lhs = rhs + 1;
	rhs = datarow.find(",", lhs);
	string degreeString = datarow.substr(lhs, rhs - lhs);
	switch (degreeString)
		case "SECURITY"

	add(sID, sFirstName, sLastName, sEmail, sAge, days1, days2, days3)

}

void Roster::add(string studentId, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree)
{
}

void Roster::remove(string studentId)
{
}

void Roster::printAll()
{
}

void Roster::printDaysInCourse(string studentId)
{
}

void Roster::printInvalidEmails()
{
}

void Roster::printByDegreeProgram(int degreeProgram)
{
}

Roster::~Roster()
{
}

int main()
{
	int numStudents = 5;
	const string studentData[5] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Zackery,Key,zkey1@wgu.edu,25,14,30,28,SOFTWARE"
	};

	Roster* classRoster = new Roster(numStudents);
	for (int i = 0; i < numStudents; i++)
	{
		classRoster->parseAndAdd(studentData[i]);
	}
	return 0;
}