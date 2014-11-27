#include <iostream>
#include <vector>
#include "Assignment.h"

using namespace std;

#ifndef _STUDENT_H_
#define _STUDENT_H_

class Student {
	public:
		string getId();
		string getFirstName();
		string getLastName();
		double getFinalPercentage();
		char getFinalLetterGrade();
		void setId(string id);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setFinalPercentage(double finalPercentge);
		void setFinalLetterGrade(char finalLetterGrade);
		string toString();
		Student(string id, string firstName, string lastName, double finalPercentage, char finalLetterGrade);
		~Student();
	private:	
		string studentId;
		string firstName;
		string lastName;
		double finalPercentage;
		char finalLetterGrade;		
		vector<Assignment*> assignments;
};

#endif
