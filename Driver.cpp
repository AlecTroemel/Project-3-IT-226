#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <cstdlib>

using namespace std;

//#include "Course.h"
//#include "Student.h"
//#include "Semester.h"


void addData() {
	string fileName, semester, courseNumber;
	int year ;

	cout << "Enter fileName (include .cvs): ";
	cin >> fileName;

	cout << "Enter Semester: ";
	cin >> semester;

	cout << "Enter Course Number: ";
	cin >> courseNumber;

	//read everything!!
	string firstline = "";
	ifstream myfile(fileName.c_str()); //file stream

	
	if(myfile.good()) {	
		int rows;
		getline(myfile, firstline, '\n');	
		cout << firstline<< "\n";
		
		
		// fill queue with lines 
		queue<string> lines;
		string line = "";
		while(getline(myfile,line,'\n')) {
			lines.push(line);
			cout << "\n" << line << "\n";		
		}
		

		//read the first line, pushing column title into a queue
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
		
		//go through a line and process it 
		while(!lines.empty()) {
			line = lines.front();
			lines.pop();
					
			int size = columnName.size();
			for(int i = 0; i <= size; i++) {
				
				//push front column to the back of the queue
				string columnTitle = columnName.front();
				columnName.pop();	
				columnName.push(columnTitle);
				
				//process the item according to its column				
			}	
		}
			
		/*
		//print out the items in the columnName Queue
		while(!columnName.empty()) {
			string temp = columnName.front();
			cout  <<  temp << "\n";	
			columnName.pop();
		}*/
	}
	else {
		cout << "file does not exist\n";
	}	
}

void saveDataForStudent() {
	cout << "this has not been implemented yet\n";
}

int main(int argc, char *argv[]) {

	while(true) {
		cin.clear();
		char choice;
		cout << "\nA: Add data \nS: Save data for a student \nE: Exit\n";
		cin >> choice;

		if(choice == 'A' || choice == 'a') { 
			addData();
			cin.clear();
		}
		else if(choice == 'S' || choice == 's') 
			saveDataForStudent();
		else if(choice == 'E' || choice == 'e')
			return 0; //end program
		else { 
			cout << "Please enter a valid choice\n";
		}
	}
	return 0;
}	



