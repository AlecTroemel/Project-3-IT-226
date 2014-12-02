#include <iostream>
#include <string>
using namespace std;
#include "Student.h"
#include "Assignment.h"

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
	return gradebooks;
}

string Student::toString()
{

}
