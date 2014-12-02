#ifndef _COURSE_H_
#define _COURSE_H_

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Course {
	public:		
		Course();
		Course(string courseName,int year, string semester,queue<string> columnName);	
		~Course();
		
		string getCourseName();
		int getYear();
		string getSemester();
		queue<string> getColumnNameQueue();
		
	private:
	
		string courseName;
		string semester;
		int year;		
		queue<string> columnName;
};
#endif
