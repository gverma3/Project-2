// OOP244 Milestone 4: 
// File: ICTCourse.h
// Version: 1.0
// Date: 8/15/2016
// Author: Gaurav Verma 
/////////////////////////////////////////////

#ifndef SICT_ICTCOURSE_H__
#define SICT_ICTCOURSE_H__

#include <iostream>
#include "Streamable.h"
#include "Course.h"
#include "general.h"


namespace sict {
	
	class ICTCourse : public Course {
		char computerSystem_[MAX_COURSECODE_LEN + 1];		
	public:
		ICTCourse();
		ICTCourse(const char*,const char*, int, int,const char*);
		const char* getComputerSystem() const;
		void setComputerSystem(const char* value);		
		std::fstream& store(std::fstream& fileStream, bool addNewLine) const;
		std::fstream& load(std::fstream& fileStream);
		std::ostream& display(std::ostream& os) const;
		std::istream& read(std::istream& istr);
		friend class ICTCourseTester;
	};

	std::ostream& operator<<(std::ostream&, const ICTCourse &);

}

#endif
