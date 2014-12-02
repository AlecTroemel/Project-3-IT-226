#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <cstdlib>
#include <locale>
#include <sstream>
#include <fstream>
using namespace std;

//#include "Course.h"
//#include "Student.h"
//#include "Semester.h"
enum parser_code {  FIRSTNAME,
		    LASTNAME,
		    FULLNAME,
		    ID,
		    ASSIGNMENT_GRADE,
		    ASSIGNMENT_COMMENT,
		    TOTAL,
		    LETTER_GRADE,
		    ERROR	};


parser_code chooseCode(const string str) {
	string temp = str;
	//convert the string to all lowercase	
	for(int i = 0; i < temp.length(); i++) {
		char c;
		string s;
		stringstream ss;
		c = temp[i];
		if(c == ' ' ) {} 
		else {
			c = tolower(c);
			ss << c;
			ss >> s;
			temp.replace(i, 1, s);
		}
	}
	
	cout << temp << "\n";
	//depending on what the string is, return the correct enum 
	if (  temp.find("id") != -1) 					return ID;
	if ( (temp.find("first") !=-1) && (temp.find("name") !=-1) ) 	return FIRSTNAME;
	if ( (temp.find("last") !=-1) && (temp.find("name") !=-1) ) 	return LASTNAME;	
	if (  temp.find("name") !=-1 ) 					return FULLNAME;
	if (  temp.find("comment") !=-1) 				return ASSIGNMENT_COMMENT;
	if ( (temp.find("assignment") !=-1) || 
	     (temp.find("paper") !=-1) || 
	     (temp.find("exam") !=-1) || 
	     (temp.find("project") !=-1) || 
	     (temp.find("sprint") !=-1)) 				return ASSIGNMENT_GRADE;
	if (  temp.find("total") !=-1) 					return TOTAL;
	if (  temp.find("grade") !=-1) 					return LETTER_GRADE;   
									
									return ERROR;	
}


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
			int size = columnName.size();

			for(int i = 0; i < size; i++) {
				//push front column to the back of the queue
				string columnTitle = columnName.front();
				columnName.pop();	
				columnName.push(columnTitle);			//put it in the back of the queue
	
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
				
				//put the data where it needs to go!
				parser_code code = chooseCode(columnTitle);
				
				switch (code) {
					case FIRSTNAME:
						cout << "first name";
						break;
					case LASTNAME:
						cout << "last name";
						break;
				case FULLNAME:
						cout << "full name";
						break;
					case ID:
						cout << "id";
						break;
					case ASSIGNMENT_GRADE:
						cout << "assignment grade";
						break;
					case ASSIGNMENT_COMMENT:
						cout << "assignment comment";
						break;
					case TOTAL:
						cout << "total";
						break;
					case LETTER_GRADE:
						cout << "grade";
						break;
					case ERROR:
						cout << "error";
						break;
				}
				cout << "\n";	
				
				
				//print out the column title and its data
				//cout << data << "\n";												
			}	
		}
	}
	else {
		cout << "file does not exist\n";
	}	
}

void saveDataForStudent() {
	
	std::ofstream outfile;
	//opens a new .csv file	
	outfile.open("savedData.csv",std::ofstream::out | std::ofstream::app);
	//if the new file is open	
	if(outfile.is_open()){
		
		

		outfile<< "TEST" << endl;
	}


	outfile.close();
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
		else if(choice == 't') 
			parser_code temp = chooseCode("TEST STRING:");
		else { 
			cout << "Please enter a valid choice\n";
		}
	}
	return 0;
}	



