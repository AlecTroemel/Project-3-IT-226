#include <iostream>
#include <string>
#include <sstream>
#include "Student.h"
#include "Assignment.h"

using namespace std;

Student::Student() {
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
}

Student::Student(string id, string firstName, string lastName)
{
	this->studentId = id;
	this->firstName = firstName;
	this->lastName = lastName;

}

Student::~Student()
{

}

string Student::getId()
{
	return studentId;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

void Student::setId(string id)
{
	this->studentId = id;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::addGradebook(Gradebook* book)
{
	gradebooks.push_back(book);
}

vector<Gradebook*>* Student::getGradebooks()
{
	return &gradebooks;
}

string Student::toString()
{
	stringstream ss; //allows read and write to string 
	ss << studentId << ",";
	for (int i = 0; i < gradebooks.size(); i++) {
		ss << gradebooks[i]->toString();
	}
	return ss.str();
}
