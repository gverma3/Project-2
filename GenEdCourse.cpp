// OOP244 Milestone 4: 
// File: GenEdCourse.cpp
// Version: 1.0
// Date: 8/15/2016
// Author: Gaurav Verma 
/////////////////////////////////////////////

#include "GenEdCourse.h"
#include <cstring>
#include <iostream>
#include <iomanip>

namespace sict {

	// No argument constructor
	GenEdCourse::GenEdCourse() {
		langLevel_ = 0;
	}

	// Five argument constructor
	GenEdCourse::GenEdCourse(const char* code_,const char* title_, int credit_, int sLoad_, int level) : Course(code_, title_, credit_, sLoad_) {
		if (level != 0) {
			langLevel_ = level;
		}
		else {
			langLevel_ = 0;
		}
	}

	// Getter function
	int GenEdCourse::getLangLevel() const {
		return langLevel_;
	}

	// Setter function
	void GenEdCourse::setLangLevel(int value) {
		langLevel_ = value;
	}

	// Store function to store data into a file.
	std::fstream& GenEdCourse::store(std::fstream& fileStream, bool addNewLine = true) const {
		fileStream << TYPE_GEN << ',';
		Course::store(fileStream, false);
		fileStream << ',' << getLangLevel();
		if (addNewLine == true) {
			fileStream << "\n";
		}
		return fileStream;
	}

	// Load function to load data from a file.
	std::fstream& GenEdCourse::load(std::fstream& fileStream) {
		
		int lang_ = 0;

		Course::load(fileStream);	

		fileStream >> lang_;
		fileStream.ignore();		
		setLangLevel(lang_);
		
		return fileStream;
	}

	// Display function to print details on the screen.
	std::ostream& GenEdCourse::display(std::ostream& os) const {
		Course::display(os);
		os << std::right << std::setw(9) << std::setfill(' ') << '|';
		os << std::right << std::setw(12) << std::setfill(' ') << langLevel_ << '|';
		return os;
	}
	
	// Read function to get data from console.
	std::istream& GenEdCourse::read(std::istream& istr) {
		
		int lang_ = 0;
		
		if (istr.fail() == false) {

			Course::read(istr);

			std::cout << "Language Requirement : ";
			istr >> lang_;
			this->setLangLevel(lang_);
		}
		return istr;
	}

	//Overloaded ostream operator
	std::ostream& operator<<(std::ostream& os, const GenEdCourse & tp) {
		tp.display(os);
		return os;
	}
}