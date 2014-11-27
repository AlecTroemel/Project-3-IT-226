#include <iostream>
#include <vector>

using namespace std;

#ifndef _SEMESTER_H_
#define _SEMESTER_H_

class Semester {
	public:
		int year;
		string semester;
		vector<Course*> courses;
		Course();
		~Course();
	private:
	
}
#endif
