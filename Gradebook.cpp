#include "Gradebook.h"
#include <sstream>
using namespace std;

Gradebook::Gradebook() {
	this->total = 0;
	this->letterGrade = ' ';
	this->assignments;
	this->course;
}

Gradebook::Gradebook(string courseName,int year, string semester,queue<string> columnName) {
	this->total = 0;
	this->letterGrade = ' ';
	this->assignments;
	course = new Course(courseName,year,semester,columnName);
}

Gradebook::~Gradebook() {
	for(int i = 0; i < assignments.size(); i ++) {
		delete assignments[i];
	}
}

string Gradebook::getAssignmentName(int index) {
	return assignments.at(index)->getAssignmentName();
}

void Gradebook::addAssignment(double grade,string name) {
	Assignment* temp = new Assignment;
	temp->setGrade(grade);
	temp->setAssignmentName(name);
	assignments.push_back(temp);
}

void Gradebook::addAssignmentComment(string comment, int index) {	
	assignments.at(assignments.size()-1)->setComment(comment);
}

double Gradebook::getAssignmentGrade(string name) {
	for(int i = 0; i < assignments.size(); i ++) {
		if(!assignments[i]->getAssignmentName().compare(name)) {
			return assignments[i]->getGrade();
		}
	}
}

string Gradebook::getAssignmentComment(string name) {
	for(int i = 0; i < assignments.size(); i ++) {
		if(!assignments[i]->getAssignmentName().compare(name)) {
			return assignments[i]->getComment();
		}
	}
}

void Gradebook::setTotal(double total) {
	this->total = total;
}

double Gradebook::getTotal() {
	return total;
}

void Gradebook::setLetterGrade(char lg) {
	this->letterGrade = lg;
}

char Gradebook::getLetterGrade() {
	return letterGrade;
}

string Gradebook::toString() {
	stringstream ss; //allows read and write to string 
	
	//print out assignments grades and comments with , and " 
	for(int i = 0; i < assignments.size(); i ++) {
		ss <<  assignments[i]->getGrade() << ",";
	}
	ss << letterGrade << ",";	
	return ss.str();
}

string Gradebook::courseToString() {
	stringstream ss;
	ss << course->getCourseName();
	
	//string temp = course->getSemester()
	char c = course->getSemester()[0];
	c = toupper(c);
	ss << "-" << c << "-" << course->getYear() << "-";
	return ss.str();	
}

queue<string> Gradebook::getColumnNameQueue() {
	return course->getColumnNameQueue();
}

int Gradebook::getAmountOfAssignments() {
	return assignments.size();
}
