#include <iostream>
#include <vector>
#include "Course.h"
#include <string>
using namespace std;

#ifndef _SEMESTER_H_
#define _SEMESTER_H_

class Semester {
	public:		
		Semester();
		~Semester();
		
		void setYear(int x);
		void setSemester(string str);
		int getYear();
		string getSemester();
		Course* getCourse(string courseName);
		void addCourse(Course* course);
	private:
		int year;
		string semester;
		vector<Course*> courses;
};
#endif
