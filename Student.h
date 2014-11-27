#include <iostream>
#include <vector>

using namespace std;

#ifndef _STUDENT_H_
#define _STUDENT_H_

class Student {
	public:
		
		Student();
		~Student();
	private:	
		string studentId;
		string firstName;
		string lastName;
		double finalPercent;
		string finalLeterGrade;		
		vector<Assignment*> assignments;
}

#endif
