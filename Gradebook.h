#include <iostream>
#include <vector>
#include "Assignment.h"
#include <string>
#include <queue>
#include <Course.h>
using namespace std;

#ifndef _GRADEBOOK_H_
#define _GRADEBOOK_H_

class Gradebook {
	public:
	Gradebook();
	Gradebook(string courseName,int year, string semester,Queue<string> columnName);
	~Gradebook();
	void addAssignment(double grade, string name);
	void addAssignmentComment(string comment, int index);
	
	double getAssignmentGrade(string name);
	string getAssignmentComment(string name);
	void setTotal(double total);
	double getTotal();
	void setLetterGrade(char lg);
	char getLettergrade();
	string toString();
	queue<string> getColumnNameQueue();
	
	 
	
	private:
	Course *course;
	double total;
	char letterGrade;
	vector<Assignments*> assignments;
}
