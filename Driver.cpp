#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <cstdlib>
#include <locale>
#include <sstream>
#include <fstream>
#include <vector> 

using namespace std;

#include "Course.h"
#include "Student.h"

enum parser_code {  FIRSTNAME,
		    LASTNAME,
		    FULLNAME,
		    ID,
		    ASSIGNMENT_GRADE,
		    ASSIGNMENT_COMMENT,
		    TOTAL,
		    LETTER_GRADE,
		    ERROR	};


vector<Student> students; 

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
	string fileName, semester, courseName;
	int year;

	cout << "Enter fileName (include .cvs): ";
	cin >> fileName;
	
	cout << "Enter year: ";
	cin >> year;
	
	cout << "Enter Semester: ";
	cin >> semester;

	cout << "Enter Course Name: ";
	cin >> courseName;

	//create Semester and course
	/*
	temp.setYear(year);
	temp.setSemester(semester);
	Course* tempCourse = new Course(courseNumber);
	temp.addCourse(tempCourse);
*/
	

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
		
		
		//temp GradeBook which will be pointed to by the students
		Gradebook tempGradebook(courseName, year, semester,columnName);		
		//temp classes that will be added 
		Student tempStudent;
		
		//go through a line and process it 
		while(!lines.empty()) {
			line = lines.front();
			lines.pop();
			/*
			if(lines.empty) {
				cout << "the line is now empty";
			}*/
			
			int size = columnName.size();
			int gradeIndex = 0;	
			//go through single line (single student)
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
						cout << "firstname";
						tempStudent.setFirstName(data);
						break;
					case LASTNAME:
						cout << "lastname";
						tempStudent.setLastName(data);
						break;
					case FULLNAME:
					{
						cout << "fullname";
						//split up full name into lastname, firstname
						int d = data.find(',', 1);
						tempStudent.setLastName(data.substr(0,d));
						tempStudent.setFirstName(data.substr(d+1));
						break;
					}
					case ID:
						cout << "id";
						tempStudent.setId(data);
						break;
					case ASSIGNMENT_GRADE:
					{
						cout << "assignment grade";
						double i;
						std::istringstream(data) >> i;
						tempGradebook.addAssignment(i, columnTitle);
						break;
					}
					case ASSIGNMENT_COMMENT:
						cout << "assignment comment :" << data;
						
						tempGradebook.addAssignmentComment(data, gradeIndex);
						gradeIndex++;
						break;
					case TOTAL:
					{
						cout << "total";
						double i;
						std::istringstream(data) >> i;
						tempGradebook.setTotal(i);
						break;
					}
					case LETTER_GRADE:
					{
						cout << "letter grade:" << data;
						
						tempGradebook.setLetterGrade(data[0]);
						break;
					}
					case ERROR:
						cout << "error";
						break;
				}	
				cout << "\n";									
			}
			
			//add student into student vector
			
			//check to see if student already exists 
			bool studentExists = false; 
			for(int k = 0; k < students.size(); k++) {
				if(!students.at(k).getId().compare(tempStudent.getId())) {	
					//a match has been found 
					//add gradebook into student 
					students.at(k).addGradebook(&tempGradebook);
					studentExists = true;
					cout << students.at(k).toString();
				}
			}
			
			if(studentExists == false) {
				//add gradebook to tempstudetn
				tempStudent.addGradebook(&tempGradebook);	
				students.push_back(tempStudent);
				cout << tempStudent.toString();
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
		else if(choice == 'S' || choice == 's'){
			string studentID;			
			cout<<"Enter student ID: " << endl;
			cin >> studentID;
			cout << endl;
			
			bool studentExists = false;
			for(int i =0; i < students.size();i++){
				if(!students.at(i).getID().compare(studentID))
				{
					//match
					studentExists = true;
				}		
			}

			if(studentExists)
			string fileName;
			cout<<"Enter name of file" <<endl;			
			cin >> fileName;			 
			saveDataForStudent(fileName);
			saveDataForStudent();

		}
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



