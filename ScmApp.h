// OOP244 Milestone 4: 
// File: ScmApp.h
// Version: 1.0
// Date: 8/15/2016
// Author: Gaurav Verma 
/////////////////////////////////////////////


#ifndef SICT_SCMAPP_H__
#define SICT_SCMAPP_H__

#include <iostream>
#include <fstream>
#include "general.h"
#include "Course.h"
#include "GenEdCourse.h"
#include "ICTCourse.h"


namespace sict {
	class ScmApp {
		char filename_[256];
		std::fstream dataFile_;
		Course* courseList_[MAX_NO_RECS];
		int noOfCourses_;				
		ScmApp(const ScmApp&) = delete;
		ScmApp& operator=(const ScmApp) = delete;
		void pause() const;
		int menu();
		void listCourses()const;
		int searchACourse(const char* courseCode)const;
		void changeStudyLoad(const char* courseCode);
		void addACourse(int);
		void loadRecs();
		void saveRecs();
	public:
		ScmApp();
		ScmApp(const char*);
		~ScmApp();
		int run();
		friend class ScmAppTester;
	};
		
}

#endif
