#include <iostream>
#include <vector>

using namespace std;

#ifndef _ASSIGNMENT_H_
#define _ASSIGNMENT_H_

class Assignment {
	public:	
		Assignment();
		~Assignment();
		void setAssignmentName(string);
		string getAssignmentName();
		void setComment(string);
		string getComment();
		void setGrade(double);
		double getGrade();			
		
	private:
		string assignmentName;
		string comment;
		double grade;
}

#endif
