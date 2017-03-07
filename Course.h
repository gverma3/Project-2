// OOP244 Milestone 4: 
// File: Course.h
// Version: 1.0
// Date: 8/15/2016
// Author: Gaurav Verma 
/////////////////////////////////////////////

#ifndef SICT_COURSE_H__
#define SICT_COURSE_H__

#include <iostream>
#include "Streamable.h"
#include "general.h"


namespace sict {
	class Course : public Streamable {
		char courseCode_[MAX_COURSECODE_LEN + 1];
		char* courseTitle_;
		int credits_;
		int studyLoad_;
		void init(const Course&);
	public:
		Course();
		Course(const char*,const char*, int, int);		
		Course(const Course&);		
		Course& operator=(const Course&);
		~Course();		
		void setCourseCode(const char * _courseCode);
		void setCourseTitle(const char * _courseTitle);
		void setCredits(const int _credits);
		void setStudyLoad(const int _studyLoad);
		const char* getCourseCode()const;
		const char* getCourseTitle()const;
		int	getCredits()const;
		int	getStudyLoad()const;
		bool isEmpty() const;
		bool operator==(const char*) const;
		int operator+=(int);		
		std::ostream& display(std::ostream& os) const;
		std::fstream& store(std::fstream& fileStream, bool addNewLine) const;
		std::fstream& load(std::fstream& fileStream);
		std::istream& read(std::istream& istr);		
		friend class CourseTester;
	};

	std::ostream& operator<<(std::ostream&, const Course &);
}

#endif



