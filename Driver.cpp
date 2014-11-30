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
			//cout << "\n" << line << "\n";		
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
			//cout << "\n" << line << "\n";
			int size = columnName.size();
			//cout << size;
			for(int i = 0; i < size; i++) {
				//push front column to the back of the queue
				string columnTitle = columnName.front();
				columnName.pop();	
				columnName.push(columnTitle);			//put it in the back of the queue
				//cout << "\n" << i << "\n" << line << "\n";		
				//check to see if the next item is surounded by double quotes						
				char delimiter;	
				int index;
				if(!line.substr(0,1).compare("\"") ) {		//check for " 		
					delimiter = '"';	
					index = line.find(delimiter, 1); 	//find the second double quote
					
					//handle inner quotes ""
					while(!line.substr(index+1, 1).compare("\"")) {	
						//find the matching ""  
						index = line.find(delimiter,index+2);
						index = index+1;				
						index = line.find(delimiter,index+1);
					}
					//line.substr(0,2).compare("\"\"")
					
				} else {
					delimiter = ',';
					index = line.find(delimiter, 0); 	//find the next comma 
				}
				
				//grab that column of the data based on the delimiter
				string data;
				if(index == -1) {				//its the last item in the row
					data = line;	
				}
				else {
					if(delimiter == '"') {
						data = line.substr(1,index-1);	
						line = line.substr(index+2);	//remove the quote and the comma
					}
					else {
						data = line.substr(0,index);
						line = line.substr(index+1);			
					}
					
					
				}
				
				//print out the column title and its data
				//cout << "\n" << columnTitle << "\t" << data;
				cout << data << "\n";
				
								
			}	
		}
			
		/*
		
		//cout << line.substr(0,2) << "\n";
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



