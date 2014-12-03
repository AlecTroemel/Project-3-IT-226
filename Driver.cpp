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


vector<Student*> students; 

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
	if (  temp.find("user id") != -1 || temp.find("student id") != -1)	return ID;
	if ( (temp.find("first") !=-1) && (temp.find("name") !=-1) ) 		return FIRSTNAME;
	if ( (temp.find("last") !=-1) && (temp.find("name") !=-1) ) 		return LASTNAME;	
	if (  temp.find("name") !=-1 ) 						return FULLNAME;
	if (  temp.find("comment") !=-1) 					return ASSIGNMENT_COMMENT;
	if ( (temp.find("assignment") !=-1) || 
	     (temp.find("paper") !=-1) || 
	     (temp.find("exam") !=-1) || 
	     (temp.find("project") !=-1) || 
	     (temp.find("sprint") !=-1)) 					return ASSIGNMENT_GRADE;
	if (  temp.find("total") !=-1) 						return TOTAL;
	if (  temp.find("grade") !=-1) 						return LETTER_GRADE; 
	  
										return ERROR;	
}


void addData() {
	string fileName, semester, courseName;
	int year;

	cout << "Enter fileName: ";
	cin >> fileName;
	fileName = fileName + ".csv";
	
	//make sure entered year is an nt
	bool switcher = true;
	while(switcher) {
		cout << "Enter year: ";
		string temp;
		cin >> temp;
		
		bool isDigit = true;
		std::string::const_iterator it = temp.begin();
		while (it != temp.end()) {
			if(!std::isdigit(*it)) {
				isDigit = false;
			}
			it++;
		}
		
		if(isDigit) {
			stringstream ss;
			ss << temp;
			ss >> year;
			switcher = false;
		}
		else {
			cout << "not a valid number, enter again\n";
		}
	}
		
	
	cout << "Enter Semester: ";
	cin >> semester;
	
	cout << "Enter Course Name: ";
	cin >> courseName;
	
	/*
	switcher = true;
	while(switcher) {
		cout << "Enter Course Name: ";
		std::getline(cin,courseName);
		
		if (courseName.find(" ",0) != -1) {
			cout << "please enter a name with no spaces\n";
		}
		else {
			switcher = false;
		}
	}	
	*/
	//read everything!!
	string firstline = "";
	ifstream myfile(fileName.c_str()); //file stream

	
	if(myfile.good()) {	
		int rows;
		getline(myfile, firstline, '\n');			
		
		// fill queue with lines 
		queue<string> lines;
		string line = "";
		while(getline(myfile,line,'\n')) {
			lines.push(line);	
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
		Gradebook* tempGradebook = new Gradebook(courseName, year, semester,columnName);		
		//temp classes that will be added 
		Student* tempStudent;
		
		//go through a line and process it 
		while(!lines.empty()) {
			tempStudent = new Student;
			line = lines.front();
			lines.pop();
			
			int size = columnName.size();
			int gradeIndex = 0;	
			//go through single line (single student)
			for(int i = 0; i < size; i++) {
				//push front column to the back of the queue
				string columnTitle = columnName.front();
				columnName.pop();	
				columnName.push(columnTitle);			//put it in the back of the queue
				
				//check to see if the next item is std::cin.ignore();
				//surounded by double quotes						
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
						tempStudent->setFirstName(data);
						break;
					case LASTNAME:
						tempStudent->setLastName(data);
						break;
					case FULLNAME:
					{
						//split up full name into lastname, firstname
						int d = data.find(',', 1);
						tempStudent->setLastName(data.substr(0,d));
						tempStudent->setFirstName(data.substr(d+1));
						break;
					}
					case ASSIGNMENT_GRADE:
					{
						double i;
						std::istringstream(data) >> i;
						tempGradebook->addAssignment(i, columnTitle);
						break;
					}
					case ASSIGNMENT_COMMENT:
						tempGradebook->addAssignmentComment(data, gradeIndex);
						gradeIndex++;
						break;
					case TOTAL:
					{	
						double i;
						std::istringstream(data) >> i;
						tempGradebook->setTotal(i);
						break;
					}
					case LETTER_GRADE:
					{
						tempGradebook->setLetterGrade(data[0]);
						break;
					}
					case ID:
						tempStudent->setId(data);
						break;
					case ERROR:
						cout << "error";
						break;
				}									
			}
			
			//add student into student vector
			
			//check to see if student already exists 
			bool studentExists = false; 
			for(int k = 0; k < students.size(); k++) {	
				if(!students.at(k)->getId().compare(tempStudent->getId())) {	
					//a match has been found 
					//add gradebook into student 
					students.at(k)->addGradebook(tempGradebook);
					studentExists = true;
				}
			}
			
			if(studentExists == false) {
				//add gradebook to tempstudetn
				tempStudent->addGradebook(tempGradebook);	
				students.push_back(tempStudent);
			}									
		}	
		cout << "file parsed and added successfully\n";	
	}
	else {
		cout << "file does not exist\n";
	}	
}

void saveDataForStudent() {	
	string studentID, filename;
	int studentIndex = -1;
	bool studentExists = false;
	
				
	cout << "Enter student ID: \n";
	cin >> studentID;
	
	for(int i =0; i < students.size();i++){
		if(!students.at(i)->getId().compare(studentID))
		{
			//match
			studentExists = true;
			studentIndex = i;
		}		
	}

	if(studentExists) {
		cout << "Student ID found\n";
		cout << "Enter name of file" <<endl;			
		cin >> filename;			 
		filename = filename + ".csv";		
		//opens a new .csv file	
		std::ofstream outfile;
		outfile.open(filename.c_str(),std::ofstream::out | std::ofstream::app);
		
		//if the new file is open	
		if(outfile.is_open()){
		
			//print out first line
			string firstline = studentID + ",";
			vector<Gradebook*>* studentGradebooks = students.at(studentIndex)->getGradebooks();	
			//iterate through all gradebooks of the student
			
			cout << "\n" << studentGradebooks->size() << "\n";
			for(int j = 0; j < studentGradebooks->size(); j++) {
								
				//iterate through all the assignments of a given gradebook
				for(int k = 0; k < studentGradebooks->at(j)->getAmountOfAssignments(); k++) {					
					firstline = firstline + studentGradebooks->at(j)->courseToString();
					firstline = firstline + studentGradebooks->at(j)->getAssignmentName(k) + ",";
				}
				firstline = firstline + studentGradebooks->at(j)->courseToString() + "Letter grade" + ",";	
			}	
			firstline.resize(firstline.length()-1);
			outfile<<firstline << "\n";

			//print out second line (the data)
			string s = students.at(studentIndex)->toString();
			s.resize(s.length()-1);
			outfile << s;	
		}
		
		cout << "student successfully saved to file " << filename;
		outfile.close();	
	}
	else {
		cout << "Stdent ID does not exist\n";
	}		
}

int main(int argc, char *argv[]) {

	while(true) {
		cin.clear();
		char choice;
		cout << "\nA: Add data ('A' or 'a') \nS: Save data for a student ('S' or 's') \nE: Exit ('E' or 'e')\n";
		cin >> choice;

		if(choice == 'A' || choice == 'a') { 
			addData();
			cin.clear();
		}
		else if(choice == 'S' || choice == 's'){	
			saveDataForStudent();
		}
		else if(choice == 'E' || choice == 'e') {
			//delete student vector 
			
			while(!students.empty()) {
				delete students.back(), students.pop_back();
			}
			return 0; //end program
		}
		else { 
			cout << "Please enter a valid choice\n";
		}
	}
	return 0;
}	



