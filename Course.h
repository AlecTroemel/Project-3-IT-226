#include <iostream>
#include <vector>

using namespace std;

#ifndef _STUDENT_H_
#define _STUDENT_H_

class Course {
	public:		
		Course();	
		~Course();
	private:
		int number;	
		vector<Student*> students;
}
