#ifndef _COURSE_H_
#define _COURSE_H_

#include <iostream>
#include <vector>
#include "Student.h"
using namespace std;

class Course {
	public:		
		Course();
		Course(string courseName,int year, string semester,Queue<string> columnName);	
		~Course();
		
		string getCourseName();
		int getYear();
		string getSemester();
		Queue<string> getColumnNameQueue();
		
	private:
	
		string courseName;
		string semester
		int year;		
		Queue<string> columnName;
};
#endif
