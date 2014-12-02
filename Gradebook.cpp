#include "Gradebook.h"
using namespace std;

Gradebook::Assignment() {
	this->total = 0;
	this->letterGrade = ' ';
	this->assignments;
	this->course;
}

Gradebook::Gradebook(string courseName,int year, string semester,Queue<string> columnName) {
	this->total = 0;
	this->letterGrade = ' ';
	this->assignments;
	course = new Course(string courseName,int year, string semester,Queue<string> columnName);
}

Gradebook::~Assignment() {
	for(int i = 0; i < assignment.size(); i ++) {
		delete assignment[i];
	}
}

void Gradebook::addAssignment(double grade, string comment, string name) {
	Assignment temp;
	temp.setComment(comment);
	temp.setGrade(grade);
	temp.setAssignmentName(name);
}

double Gradebook::getAssignmentGrade(string name) {
	for(int i = 0; i < assignments.size(); i ++) {
		if(!assignments[i].getAssignmentName().compare(name)) {
			return assignments[i].getGrade();
		}
	}
}

string Gradebook::getAssignmentComment(string name) {
	for(int i = 0; i < assignments.size(); i ++) {
		if(!assignments[i].getAssignmentName().compare(name)) {
			return assignments[i].getComment();
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

char Gradebook::getLettergrade() {
	return letterGrade;
}

string Gradebook::toString() {
	stringstream ss; //allows read and write to string 
	
	//print out assignments grades and comments with , and " 
	for(int i = 0; i < assignments.size(); i ++) {
		ss <<  assignments[i].getGrade(); << ",";
		if(assignments[i].getComment().compare("")) {
			ss << "\"" << assignments[i].getComment() << "\","; 
		}
	}
	
	
	ss << total << ",";
	ss << letterGrade << ",";	
	return ss.str();
}

queue<string> Gradebook::getColumnNameQueue() {
	return course->getColumnNameQueue();
}
