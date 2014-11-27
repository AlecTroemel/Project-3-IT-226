#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

//#include "Course.h"
//#include "Student.h"
//#include "Semester.h"


void addData() {
	string fileName, semester, courseNumber;
	int year ;
	/*
	cout << "Enter fileName (include .cvs): ";
	cin >> fileName;
	
	cout << "Enter Semester: ";
	cin >> semester;
	
	cout << "Enter Course Number: ";
	cin >> courseNumber;
	*/
	//read everything!!
	string firstline = "467-fall-2002.txt";
	ifstream myfile("467-fall-2002.csv"); //file stream
		
	int rows;
	getline(myfile, firstline, '\n');	
	cout << firstline<< "\n";
		
	myfile.close();
	
	//read the first line, pushing an int corosponding to the type of column into a queue
	queue<string> columnName;
	int i = 0;	
	while(!firstline.empty()) {
		int temp =  firstline.find(",",0);
		if(temp == -1) {
			columnName.push(firstline.substr(0));	
			break;
		}
		else {
			columnName.push(firstline.substr(0,temp));			
			firstline = firstline.substr(temp+1);
		}

		i++;
	}
	
	while(!columnName.empty()) {
		string temp = columnName.front();
		cout  <<  temp << "\n";	
		columnName.pop();
	}	 
}



int main(int argc, char *argv[]) {
	addData();
	return 0;
}	




