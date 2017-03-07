// OOP244 Milestone 4: 
// File: ICTCourse.cpp
// Version: 1.0
// Date: 8/15/2016
// Author: Gaurav Verma 
/////////////////////////////////////////////

#include "ICTCourse.h"
#include <cstring>
#include <iostream>
#include <iomanip>


namespace sict {

	//No argument constructor keeping object to a safe recognizable empty state
	ICTCourse::ICTCourse() {		
		computerSystem_[0] = '\0';
	}

	//Five argument constructor to initialize object
	ICTCourse::ICTCourse(const char* code_,const char* title_ , int credit_ , int sLoad_,const char* system_ ) : Course(code_, title_, credit_, sLoad_) {
		if (system_ && system_[0]) {
			strncpy(computerSystem_, system_,MAX_COURSECODE_LEN);
		}
		else {
			ICTCourse();
		}
	}

	// Getter function
	const char* ICTCourse::getComputerSystem() const {		
		return computerSystem_;
	}

	//Setter function
	void ICTCourse::setComputerSystem(const char* value) {
		if (value) {
			strcpy(computerSystem_, value);
		}
		else {
			ICTCourse();
		}
	}

	// Display function to print details on the screen.
	std::ostream& ICTCourse::display(std::ostream& os) const {
		Course::display(os);
		os << std::left << std::setw(8) << std::setfill(' ') << getComputerSystem() << '|';
		os << std::right << std::setw(13) << std::setfill(' ') << '|';
		return os;
	}	

	// Read function to get data from console.
	std::istream& ICTCourse::read(std::istream& istr){
		
		char sys[MAX_COURSECODE_LEN + 1];

		if (istr.fail() == false) {

			Course::read(istr);

			std::cout << "Computer System : ";
			istr >> sys;			
			char* sys_ = sys;
			this->setComputerSystem(sys_);
		}
		return istr;
	}

	//Overloaded ostream operator
	std::ostream& operator<<(std::ostream& os, const ICTCourse & tp) {
		tp.display(os);
		return os;
	}

	// Store function to store data into a file.
	std::fstream& ICTCourse::store(std::fstream& fileStream, bool addNewLine) const {

		fileStream << TYPE_ICT << ',';

		Course::store(fileStream,false);

		fileStream << ',' << getComputerSystem();
		if (addNewLine == true) {
			fileStream << "\n";
		}
		return fileStream;
	}

	// Load function to load data from a file. 
	std::fstream& ICTCourse::load(std::fstream& fileStream) {
		
		char sys[MAX_COURSECODE_LEN + 1];	

		Course::load(fileStream);

		fileStream.get(sys, MAX_COURSECODE_LEN + 1, '\n');				
		this->setComputerSystem(sys);		

			return fileStream;
	}
	
}