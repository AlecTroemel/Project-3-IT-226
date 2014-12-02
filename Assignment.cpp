#include <sstream>
#include <iostream>
#include "Assignment.h"

using namespace std;


//default constructor, initiates to blank strings and 0
Assignment::Assignment() {
	this->assignmentName = "";
	this->comment = "";
	this->grade = 0;	
}

//empty deconsrtuctor
Assignment::~Assignment() {}

void Assignment::setAssignmentName(string name) {
	this->assignmentName = name;
}

string Assignment::getAssignmentName() {
	return this->assignmentName;
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



