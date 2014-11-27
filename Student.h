#include <iostream>
#include <vector>

using namespace std;

#ifndef _STUDENT_H_
#define _STUDENT_H_

class Student {
	public:
		int studentId;
		string name;
		vector<Course> courses;
		vector<Assignment*> assignments;
		Student();
		~Student();
	private:	
		
}

#endif
