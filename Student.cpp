#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Student.h"

using namespace std;

Student::Student() {
    
}

bool Student::login(string username, string password) {
    vector<string> studentInfo = matchUser("students.txt", username, password);
}

vector<string> Student::matchUser(string filename, string username, string password) {
    vector<string> userInfo;
    
    string line;
    bool matchFound = false;
    
    ifstream file(filename);

    if(file.is_open()) {
	while(getline(file, line)) {
	    if(username.compare(line.substr(0, line.find("\t"))) == 0) {
		matchFound = true;
		break;
	    }
	}
	
	file.close();
    }

    else
	cout << "Error opening students.txt" << endl;

    if(matchFound) {
	int firstTabLoc = line.find("\t");
	int secondTabLoc = line.find("\t", firstTabLoc+1);
	
	if(password.compare(line.substr(firstTabLoc+1, (secondTabLoc-firstTabLoc)-1)) == 0) {
	    unsigned int current = line.find("\t");
	    unsigned int prev = 0;

	    while(current != string::npos) {
		userInfo.push_back(line.substr(prev, (current - prev)-1));
		prev = current + 1;
		current = line.find("\t", prev);
	    }
	}

	for(unsigned int i = 0; i < userInfo.size(); i++)
	    cout << userInfo.at(i) << endl;
    }

    return userInfo;
}
