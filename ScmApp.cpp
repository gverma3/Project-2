// OOP244 Milestone 4: 
// File: ScmApp.cpp
// Version: 1.0
// Date: 8/15/2016
// Author: Gaurav Verma 
/////////////////////////////////////////////

#include "ScmApp.h"
#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>


using namespace std;


namespace sict {	

	//No argument constructor keeping object to a safe recognizable empty state
	ScmApp::ScmApp() {
		noOfCourses_ = 0;
		for (int i = 0; i < MAX_NO_RECS; i++) {
			delete courseList_[i];
			courseList_[i] = nullptr;
		}
		filename_[0] = '\0';
	}

	// One argument constructor
	ScmApp::ScmApp(const char* filename)
	{
		if (filename) {
			strncpy(filename_, filename,256);
		}
		noOfCourses_ = 0;
		for (int i = 0; i < MAX_NO_RECS; i++) {
			courseList_[i] = nullptr;
		}		
	}

	//Deconstructor to deallocate dynamic memory
	ScmApp::~ScmApp() {
		for(int i = 0; i < MAX_NO_RECS; i++)	{
		delete courseList_[i];		
		}		
	}
	
	//Waits for user to press enter after every selection
	void ScmApp::pause() const {		
		while(getchar() != '\n') {
			cout << "Press Enter to continue..." << endl;		
				cin.ignore(1000, '\n');
		}		
	}

	//Prits out the menu
	int ScmApp::menu() {
		cout << "Seneca Course Management Tool" << endl;
		cout << "1- List courses." << endl;
		cout << "2- Display the details of a course." << endl;
		cout << "3- Add a course." << endl;
		cout << "4- Change the study load of a course." << endl;
		cout << "5- Load courses from a file." << endl;
		cout << "6- Save courses to a file." << endl;
		cout << "0- Exit Program" << endl;
		cout << ">";
		int select_;
		cin >> select_;
		cin.ignore(1000, '\n');
		if (select_ >= 0 && select_ <= 6) {			
			return select_;			
		}		
		return -1;
	}

	// Show sthe list of course added by user
	void ScmApp::listCourses()const {
		cout << endl;
		cout << ' ' << "Row | Code |               Course Title              | Credits | Study Load | System | Lang. Req. |" << endl;
		cout << "-----|------|-----------------------------------------|---------|------------|--------|------------|" << endl;
		for (int i = 0; i < noOfCourses_ && i < 10; i++) {			
			cout << right << setw(4) << setfill(' ') << i << ' ' << '|';
			cout << *courseList_[i];			
			cout <<	endl;				
		}
		cout << "----------------------------------------------------------------------------------------------------" << endl;		
	}

	//Search for a course in the array
	int ScmApp::searchACourse(const char* courseCode)const {
		for (int i = 0; i < noOfCourses_; i++) {		
			if (*courseList_[i] == courseCode) {
				return i;
			}			
		}		
		return -1;		
	}

	//Change the studyload according to user input 
	void ScmApp::changeStudyLoad(const char* courseCode) {
		int val = searchACourse(courseCode);
		if (val != -1) {
			int load_ = 0;
			std::cout << "Please enter the amount of the study load: ";
			cin >> load_;
			cout << endl;			
			*courseList_[val] += load_;
			cin.clear();
		}
		else {
			cout << "Not found!" << endl;
		}
	}

	//Add a course to the array
	void ScmApp::addACourse(int choice) {	
		cout << endl;
		
		if (choice == 1) {			
			courseList_[noOfCourses_] = new ICTCourse();
			courseList_[noOfCourses_]->read(cin);
		}
		else {				
			courseList_[noOfCourses_] = new GenEdCourse();
			courseList_[noOfCourses_]->read(cin);
		}
		noOfCourses_ += 1;
		cout << endl;		
	}

	// Load data from an external file
	void ScmApp::loadRecs()
	{
		int readIndex = 0;
		char obj_;
		
		dataFile_.open(filename_, ios::in);
		
		if (dataFile_.fail()) {
			dataFile_.clear();
			dataFile_.close();
			dataFile_.open(filename_, ios::out);
			dataFile_.close();
		}
		else {
			for (int i = 0; i < noOfCourses_; i++) {
				delete courseList_[i];
				courseList_[i] = nullptr;
			}
			while(!dataFile_.fail()) {	
				
				obj_ = dataFile_.get();				

				if (obj_ == 'G') {
					courseList_[readIndex] = new GenEdCourse();					
					dataFile_.get();
					courseList_[readIndex]->load(dataFile_);
					readIndex++;
				}
				else if (obj_ == 'I') {
					courseList_[readIndex] = new ICTCourse();					
					dataFile_.get();
					courseList_[readIndex]->load(dataFile_);
					readIndex++;
				}								   		
			}
			noOfCourses_ = readIndex;
			dataFile_.close();
		}		
		dataFile_.close();
	}

	//SaveRecs save data to an external file
	void ScmApp::saveRecs()
	{
		dataFile_.open(filename_, ios::out);
		for (int i = 0; i < noOfCourses_; ++i) {
			courseList_[i]->store(dataFile_, true);
		}
		dataFile_.close();
	}

	//Call functions according to user selection
	
	int ScmApp::run() {
		int i;		
			do {
				i = menu();
				if (i == 1) {
					listCourses();
					pause();
				}
				else if (i == 2) {
					pause();
				}
				else if (i == 3) {
					int selection;
					cout << endl;
					cout << "Please enter the course type (1-ICT or 2-GenEd): ";
					cin >> selection;
					addACourse(selection);
					pause();
				}
				else if (i == 4) {
					cout << endl ;
					char cor_[MAX_COURSECODE_LEN + 1];
					cout << "Please enter the course code : ";					
					cin >> cor_;
					char* lD_ = cor_;
					changeStudyLoad(lD_);
					pause();
				}
				else if (i == 5) {
					cout << endl;					
					loadRecs();
					//pause();
				}
				else if (i == 6) {
					cout << endl;					
					saveRecs();
					//pause();
				}
				else if (i == 0) {
				cout << endl;
				cout << "Goodbye!!" << endl;
				}
				else if (i == -1) {
					cout << "===Invalid Selection, try again.===" << endl;
					cin.clear();
					pause();
				}
			} while (i != 0);
			return 0;
			
	}



}
