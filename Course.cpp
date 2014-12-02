/*
	string courseName;
	string semester
	int year;		
	Queue<string> columnName;
*/

#include "Course.h"
#include "Student.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Course::Course(){
	this->number = 0;
	this->courseName = "";
	this->semester = "";
	this->year = 0;
	this->columnName;
}

Course::Course(string courseName,int year, string semester,Queue<string> columnName) {
	this->courseName = courseName;
	this->year = year;
	this->semester = semester;
	this->columnName = columnName;
}

Course::~Course(){
}

string Course::getCourseName(){
	return this->courseName;
}

int Course::getYear() {
	return this->year;
}

string Course::getSemester() {
	return this->semester;
}

Queue<string> Course::getColumnNameQueue() {
	return columnName;
}
