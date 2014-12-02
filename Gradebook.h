#include <iostream>
#include <vector>
#include "Assignment.h"
#include <string>
#include <queue>
#include "Course.h"

using namespace std;

#ifndef _GRADEBOOK_H_
#define _GRADEBOOK_H_

class Gradebook {
	public:
	Gradebook();
	Gradebook(string courseName,int year, string semester,queue<string> columnName);
	~Gradebook();
	string getAssignmentName(int index);
	void addAssignment(double grade, string name);
	void addAssignmentComment(string comment, int index);
	double getAssignmentGrade(string name);
	string getAssignmentComment(string name);
	void setTotal(double total);
	double getTotal();
	void setLetterGrade(char lg);
	char getLetterGrade();
	string toString();
	string courseToString();
	queue<string> getColumnNameQueue();
	int getAmountOfAssignments();
	 
	
	private:
	Course *course;
	double total;
	char letterGrade;
	vector<Assignment*> assignments;
};

#endif
