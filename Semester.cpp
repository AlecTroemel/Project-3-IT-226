#include "Semester.h"
#include "Course.h"
#include <string>
#include <vector>

using namespace std;

Semester::Semester(){
	this->year = 0;
	this->semester;
	this->courses;
	}

Semester::~Semester(){
	for(int i = 0; 	this->courses.size();i++){
		delete this->courses.at(i);
	}
	
}

	
void Semester::setYear(int x){
	
	this->year = x;
}

void Semester::setSemester(string str){
	this->semester = str;
}

int Semester::getYear(){
	return this->year;

}

string Semester::getSemester(){
	return this->semester;
}

Course* Semester::getCourse(string courseName){
	int size = courses.size();
	int i =0;
	while(i < size){
		string temp = courses.at(i)->getCourseName();
		if(temp.compare(courseName) == 0)
		{
			//returns pointer 
			return courses.at(i);
		}
		i++;		
	}
	//course name is not in vector, returns null
	return NULL;
}
	
void Semester::addCourse(Course* course){
	//adds a course pointer to the vector
	courses.push_back(course);
}	
	
	
	
	
	
	
	
	
	
	
	
	
	