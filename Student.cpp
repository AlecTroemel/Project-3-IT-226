#include <iostream>
#include <string>
using namespace std;
#include "Student.h"
#include "Assignment.h"

Student::Student(string id, string firstName, string lastName, double finalPercentage, char finalLetterGrade)
{
	this->studentId = id;
	this->firstName = firstName;
	this->lastName = lastName;
	this->finalPercentage = finalPercentage;
	this->finalLetterGrade = finalLetterGrade;
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

double Student::getFinalPercentage()
{
	return finalPercentage;
}

char Student::getFinalLetterGrade()
{
	return finalLetterGrade;
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

void Student::setFinalPercentage(double finalPercentage)
{
	this->finalPercentage = finalPercentage;
}

void Student::setFinalLetterGrade(char finalLetterGrade)
{
	this->finalLetterGrade = finalLetterGrade;
}

string Student::toString()
{

}
