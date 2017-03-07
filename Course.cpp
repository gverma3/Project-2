// OOP244 Milestone 4: 
// File: Course.cpp
// Version: 1.0
// Date: 8/15/2016
// Author: Gaurav Verma 
/////////////////////////////////////////////

#include "Course.h"
#include <cstring>
#include <string.h>
#include <iostream>
#include <iomanip>


namespace sict {

	//No argument constructor keeping object to a safe recognizable empty state
	Course::Course()
	{
		courseCode_[0] = '\0';
		courseTitle_ = nullptr;
		credits_ = 0;
		studyLoad_ = 0;
	}

	//Four argument constructor to initialize object
	Course::Course(const char* cCode_,const char* cTitle_, int cred_, int sLoad_) {
		setCourseCode(cCode_);
		setCourseTitle(cTitle_);
		setCredits(cred_);
		setStudyLoad(sLoad_);		
	}

	//Localization to prevent code duplication
	void Course::init(const Course& src) {

		// shallow copy
		credits_ = src.credits_;
		studyLoad_ = src.studyLoad_;

		// allocate dynamic memory for courseTitle_ string
		if (src.courseCode_ && src.courseTitle_) {
			strncpy(courseCode_, src.courseCode_, MAX_COURSECODE_LEN);
			courseTitle_ = new char[strlen(src.courseTitle_) + 1];
			// copy data from the original resource
			// to newly allocated resource
			strcpy(courseTitle_, src.courseTitle_);
		}
		else
			courseTitle_ = nullptr;
	}

	//Copy constructor
	Course::Course(const Course& src) {
		init(src);
	}	

	//Overloaded assignment opertaor
	Course& Course::operator=(const Course& source) {

		// check for self-assignment
		if (this != &source) {			
			// deallocate previously allocated dynamic memory 
			delete[] courseTitle_;			
			init(source);
		}
		return *this;
	}

	//Deconstructor for preventing memory leak
	Course::~Course() {		
			delete[] courseTitle_;			
	}

	//Setter to assign cousre code
	void Course::setCourseCode(const char* _courseCode) {
	if(courseCode_)
	strcpy(courseCode_, _courseCode);	
	}  

	//Setter to assign course title
	void Course::setCourseTitle(const char* _courseTitle) {
		if (_courseTitle) {			
			courseTitle_ = new char[strlen(_courseTitle) + 1];
			strcpy(courseTitle_, _courseTitle);
		}
	}

	//Setter to assign course credits
	void Course::setCredits(const int _credits) {
	credits_ = _credits;
	}

	//Setter to assign course studyload
	void Course::setStudyLoad(const int _studyLoad) {
	studyLoad_ = _studyLoad;
	}

	//Getter to read course code
	const char* Course::getCourseCode() const{
		return courseCode_;
	}

	//Getter to read course title
	const char* Course::getCourseTitle() const{
		return courseTitle_;
	}

	//Getter to read course credit
	int	Course::getCredits() const{
		return credits_;
	}

	//Getter to read course studyload
	int	Course::getStudyLoad() const{
		return studyLoad_;
	}

	//Bool to check object safe empty state
	bool Course::isEmpty() const{
		if (courseTitle_ == nullptr || courseTitle_[0] == '\0' || courseCode_[0] == '\0' || credits_ == -1 || credits_ == 0 || studyLoad_ == 0 || studyLoad_ == -1) {
			return true;
			}
		else{
		return false;
		}
	}

	//bool overloaded comparison operator
	bool Course::operator==(const char* other) const{
		return(strcmp(this->courseCode_,other) == 0);
	}

	//Overloaded operator to  change studyload
	int Course::operator+=(int val) {
		if (val < 0) {
			this->studyLoad_ += val;
			return this->studyLoad_;
		}
		else {
			this->studyLoad_ += val;
			return this->studyLoad_;
		}		
	}	

	// Display function to print details on the screen.
		std::ostream& Course::display(std::ostream& os) const {
		os << std::left << std::setw(6) << std::setfill(' ') << courseCode_ << '|' << std::left << std::setw(41) << std::setfill(' ')
			<< courseTitle_ << '|' << std::right << std::setw(9) << std::setfill(' ') << credits_ << '|' << std::right << std::setw(12)
			<< std::setfill(' ') << studyLoad_ << '|';
		return os;
	}

	// Store function to store data into a file.
	std::fstream& Course::store(std::fstream& fileStream, bool addNewLine) const
	{
		fileStream << getCourseCode() << ',' << getCourseTitle() << ',' << getCredits() << ',' << getStudyLoad();
		if (addNewLine == true) {
			fileStream << '\n';
		}
		return fileStream;
	}

	// Load function to load data from a file. 
	std::fstream & Course::load(std::fstream& fileStream)
	{
		char c[MAX_COURSECODE_LEN + 1];
		char title[99];
		int cre_ = 0;
		int ld_ = 0;		

		fileStream.get(c, MAX_COURSECODE_LEN + 1, ',');		
		fileStream.ignore();		

		fileStream.get(title, 99, ',');		
		fileStream.ignore();

		fileStream >> cre_;
		fileStream.ignore();
		
		fileStream >> ld_;
		fileStream.ignore();		

		this->setCourseCode(c);
		this->setCourseTitle(title);
		this->setCredits(cre_);
		this->setStudyLoad(ld_);

		return fileStream;
	}

	// Read function to get data from console.
	std::istream & Course::read(std::istream & istr)
	{
		char c[MAX_COURSECODE_LEN + 1];
		char title[99];
		int cre_ = 0;
		int ld_ = 0;		
		if (istr.fail() == false) {
			std::cout << "Course Code: ";
			istr >> c;
			istr.ignore(1000, '\n');
			char* code_ = c;
			this->setCourseCode(code_);

			std::cout << "Course Title: ";
			istr.getline(title, 98, '\n');
			char* title_ = title;
			this->setCourseTitle(title_);

			std::cout << "Course Credit: ";
			istr >> cre_;
			this->setCredits(cre_);

			std::cout << "Study Load: ";
			istr >> ld_;
			this->setStudyLoad(ld_);
		}		
		return istr;
	}	

	//Overloaded ostream operator
	std::ostream& operator<<(std::ostream& os, const Course & tp) {
	    tp.display(os);
		return os;
	}

}



