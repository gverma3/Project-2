#ifndef SCMAPPTESTER_H
#define SCMAPPTESTER_H

#include "Tester.h"
#include "ScmApp.h"

namespace sict{
	

	class ScmAppTester :
		public Tester
	{
		

	public:
		ScmAppTester();
		virtual ~ScmAppTester();

		bool scmAppListCourses();
		bool scmAppArrayNull();
		bool scmAppMenuOutput();
		bool scmAppMenuTester1();
		bool scmAppMenuTester2();
		bool scmAppMenuTester3();
		bool scmAppMenuTester4();
		bool scmAppMenuTester0();
		bool scmAppSearchForCourse0();
		bool scmAppSearchForCourse1();
		bool scmAppSearchForCourse2();
		bool scmAppSearchForCourse3();
		bool testLoadRecs();
		bool testSaveRecs();
		void emptyCourses(ScmApp&);
		void createTestFile();
		void initCourses(ScmApp&);

		void runTests();

	};

}

#endif