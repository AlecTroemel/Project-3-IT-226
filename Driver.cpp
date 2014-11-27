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
	else {
		cout << "file does not exist\n";
	}	
}

void saveDataForStudent() {
	cout << "this has not been implemented yet\n";
}
/*
void menu() {
	char choice;
	cout << "A: Add data \nS: Save data for a student \nE: Exit\n";
	cin >> choice;

	if(choice == 'A' || choice == 'a') 
		addData();
	else if(choice == 'S' || choice == 's') 
		saveDataForStudent();
	else if(choice == 'E' || choice == 'e')
		std::exit(0);
	else { 
		cout << "Please enter a valid choice\n";
		menu(); //loop back to menu
	}
}
*/

int main(int argc, char *argv[]) {
	char choice;
	while(true) {
		cout << "\nA: Add data \nS: Save data for a student \nE: Exit\n";
		cin >> choice;

		if(choice == 'A' || choice == 'a') 
			addData();
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



