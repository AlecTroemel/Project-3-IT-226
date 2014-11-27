#include "Course.h"
#include "Student.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Course::Course(){
	this->number = 0;
	this->students;
	this->courseName;
}

Course::Course(string courseName){
	this->courseName = courseName;
	this->students;
	this->courseName;

}

Course::~Course(){
}



void Course::setCourseName(string str){

	this->courseName = str;
}


string Course::getCourseName(){
	
	return this->courseName;
}

