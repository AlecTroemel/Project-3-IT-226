#include <iostream>
#include <vector>

using namespace std;

#ifndef _ASSIGNMENT_H_
#define _ASSIGNMENT_H_

class Assignment {
	public:		
		Assignment();
		~Assignment();
	private:
		string assignmentName;
		string comment;
		double grade;
}

#endif
