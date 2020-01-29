#include <iostream>
#include <string>
#include <fstream>

#include "Student.h"

using namespace std;

Student::Student() {
    
}

bool Student::login(string username, string password) {
    string line;
    bool matchFound = false;
    
    ifstream studentFile("students.txt");

    if(studentFile.is_open()) {
	while(getline(studentFile, line, '\t') && !matchFound) {
	    if(username.compare(line) == 0)
		matchFound = true;

	    else
		studentFile.ignore(256, '\n');

	    cout << line << endl;
	}
	
	studentFile.close();
    }

    else
	cout << "Error opening students.txt" << endl;

    if(matchFound)
	cout << "Username found" << endl;
    else
	cout << "Username not found" << endl;
    
    return true;
}

