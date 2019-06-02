#include "Roster.h"
using std::cout;
using std::cerr;

Roster::Roster()
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student*[capacity];
}

Student* Roster::getStudentAt(int index)
{
	return classRosterArray[index];
}

void Roster::parseAndAdd(string datarow)
{
	if (lastIndex < capacity) {
		lastIndex++;
	}
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

	Degree degreeProgram;
	
	if (degreeString == "SECURITY") degreeProgram = SECURITY;
	else if (degreeString == "NETWORK") degreeProgram = NETWORK;
	else if (degreeString == "SOFTWARE") degreeProgram = SOFTWARE;

	

	add(sID, sFirstName, sLastName, sEmail, sAge, days1, days2, days3, degreeProgram);

}

void Roster::add(string studentId, string firstName, string lastName, string emailaddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreetype)
{
	int daysInCourse[Student::daysArraySize];
	daysInCourse[0] = daysInCourse1;
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;

	switch (degreetype) {
	case SECURITY:
		classRosterArray[lastIndex] = new SecurityStudent(studentId, firstName, lastName, emailaddress, age, daysInCourse, degreetype);
		break;
	case NETWORK:
		classRosterArray[lastIndex] = new NetworkStudent(studentId, firstName, lastName, emailaddress, age, daysInCourse, degreetype);
		break;
	case SOFTWARE:
		classRosterArray[lastIndex] = new SoftwareStudent(studentId, firstName, lastName, emailaddress, age, daysInCourse, degreetype);
		break;
	}
}

void Roster::remove(string studentId) {
	cout << "Removing student with ID " << studentId;
	for (int i = 0; i < lastIndex; ++i) {
		if (classRosterArray[i] == nullptr) {
			cout << "ERROR: Student with this ID not found" << endl;
			break;
		}
		else if (studentId == classRosterArray[i]->getStudent_ID()) {
			classRosterArray[i] = nullptr;
			cout << "Student removed" << endl;
		}
	}
};

void Roster::printAll()
{
	for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray[i])->print();
}

void Roster::printDaysInCourse(string studentId)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getStudent_ID() == studentId)
		{
			found = true;
			int* p = classRosterArray[i]->getNumDays();
			cout << studentId << " has an average of " << (((float)p[0] + (float)p[1] + (float)p[2]) / 3) << "days left in each course" << endl;
		}
	}
}

void Roster::printInvalidEmails()
{
	bool any = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		any = false;
		string email = classRosterArray[i]->getEmail_Address();
		size_t emailLength = email.size();
		size_t j = 0;
		while (email[j] != ' ' && email[j] != '@' && j < emailLength) {
			++j;
			if (email[j] == '@' && j < emailLength) {
				++j;
				while (email[j] != ' ' && email[j] != '@' && email[j] != '.' && j < emailLength) {
					++j;
					if (email[j] == '.' && j < emailLength) {
						++j;
						while (email[j] != ' ' && email[j] != '@' && email[j] != '.' && j < emailLength) {
							++j;
							if (j == emailLength) {
								any = true;
							}
						}
					}
				}
			}
		}
		if (any == false) {
			std::cout << email << std::endl;
		}
	}
}

void Roster::printByDegreeProgram(int degreeProgram)
{
	for (int i = 0; i <= lastIndex; i++) {
		if (this -> classRosterArray[i]->getDegreeProgram() == degreeProgram) this->classRosterArray[i]->print();
	}
}

Roster::~Roster()
{
	for (int i = 0; i <= lastIndex; i++)
	{
		delete this->classRosterArray[i];
	}
	delete classRosterArray;
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

	cout << "Scripting and Programming - Applications C867 in C++" << endl;
	cout << "Written by (001049442) Zackery Key \n" << endl;

	Roster * classRoster = new Roster(numStudents);
	cout << "Creating Class Roster:";
	for (int i = 0; i < numStudents; i++)
	{
		classRoster->parseAndAdd(studentData[i]);
	}
	cout << "Done. \n" << endl;
	cout << "Dispalying all Students:" << endl;
	classRoster->printAll();
	cout << endl << endl;

	cout << "Invalid Emails?" << endl;
	classRoster->printInvalidEmails();

	cout << endl << endl;
	cout << "Printing average days in course for each student:\n";
	for (int i = 0; i < numStudents; i++) {
		classRoster->printDaysInCourse(classRoster->getStudentAt(i)->getStudent_ID());
	}

	cout << endl << endl;
	cout << "Print by Degree Program: Software\n";
	classRoster->printByDegreeProgram(SOFTWARE);

	cout << endl << endl;
	classRoster->remove("A3");
	classRoster->remove("A3");
	
	classRoster->~Roster();

	return 0;
}