#include <sstream>
#include <iostream>


using namespace std;
#include "Assignment.h"

//default constructor, initiates to blank strings and 0
Assignment::Assignment() {
	this->assignmentName = "";
	this->comment = "";
	this->grade = 0;	
}

//empty deconsrtuctor
Assignment::~Assignment() {}

void Assignment::setAssignmentName(string name) {
	this->AssignmentName = name;
}

string Assignment::getAssignmentName() {
	return this->AssignmentName;
}

void Assignment::setComment(string comment) {
	this->comment = comment;
}

string Assignment::getComment() {
	return this->comment;
}

void Assignment::setGrade(double grade) {
	this->grade = grade;
}

double  Assignment::getGrade() {
	return this->grade;
}


