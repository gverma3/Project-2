// OOP244 Milestone 4: 
// File: GenEdCourse.h
// Version: 1.0
// Date: 8/15/2016
// Author: Gaurav Verma 
/////////////////////////////////////////////

#ifndef SICT_GENEDCOURSE_H__
#define SICT_GENEDCOURSE_H__

#include <iostream>
#include "Streamable.h"
#include "Course.h"
#include "general.h"


namespace sict {

	class GenEdCourse : public Course {
		int langLevel_;		
	public:
		GenEdCourse();
		GenEdCourse(const char*,const char*, int, int, int);
		int getLangLevel() const;
		void setLangLevel(int value);		
		std::fstream& store(std::fstream& fileStream, bool addNewLine) const;
		std::fstream& load(std::fstream& fileStream);
		std::ostream& display(std::ostream& os) const;
		std::istream& read(std::istream& istr);
		friend class GenEdCourseTester;
	};

	std::ostream& operator<<(std::ostream&, const GenEdCourse &);

}

#endif

