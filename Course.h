#ifndef _COURSE_H_
#define _COURSE_H_

#include <iostream>
#include <vector>
#include "Student.h"
using namespace std;

class Course {
	public:		
		Course();
		Course(string courseName);	
		~Course();
		
		void setCourseName(string str);
		string getCourseName();
	private:
	
		string courseName;
		int number;	
		vector<Student*> students;
};
#endif
