#ifndef GENEDCOURSETESTS_H
#define GENEDCOURSETESTS_H

#include <string>
#include "GenEdCourse.h"

namespace sict {
	
	bool GenEdisEmptyTest1() {
		// empty test
		sict::GenEdCourse c0;
		return c0.isEmpty();
	}

	bool GenEdisEmptyTest2() {
		// empty test
		sict::GenEdCourse c0("", "title", 3, 3, 1);
		return c0.isEmpty();
	}

	bool GenEdisEmptyTest3() {
		// empty test
		sict::GenEdCourse c0("code", "", 3, 3, 1);
		return c0.isEmpty();
	}

	bool GenEdisEmptyTest4() {
		// empty test
		sict::GenEdCourse c0("code", "title", -1, 3, 1);
		return c0.isEmpty();
	}

	bool GenEdisEmptyTest5() {
		// empty test
		sict::GenEdCourse c0("code", "title", 3, -1, 1);
		return c0.isEmpty();
	}

	bool GenEdisEmptyTest6() {
		// empty test
		sict::GenEdCourse c0("code", "title", 3, -1, 0);
		return c0.isEmpty();
	}

	bool GenEdregularInitTest() {
		// regular
		sict::GenEdCourse c5("OOP244", "Object-Oriented Programming in C++", 1, 4, 2);
		return (!c5.isEmpty()
			&& std::string(c5.getCourseCode()) == "OOP244"
			&& std::string(c5.getCourseTitle()) == "Object-Oriented Programming in C++"
			&& c5.getCredits() == 1
			&& c5.getStudyLoad() == 4
			&& c5.getLangLevel() == 2
			);
	}

	bool GenEdemptyInitTest() {
		// regular
		sict::GenEdCourse c5;
		return (std::string(c5.getCourseCode()) == ""
			&& (c5.getCredits() == 0 || c5.getCredits() == -1)
			&& (c5.getStudyLoad() == 0 || c5.getStudyLoad() == -1)
			&& (c5.getCourseTitle() == nullptr || (c5.getCourseTitle() != nullptr && std::string(c5.getCourseTitle()) == ""))
			//&&std::string(c5.getCourseTitle()) == ""
			&& c5.getLangLevel() == 0
			);
	}


	
	bool GenEdstudyLoadTest1() {

		sict::GenEdCourse c5("OOP244", "Object-Oriented Programming in C++", 1, 4, 2);
		int a = c5 += 6;
		return (a == 10) && (c5.getStudyLoad() == 10);
	}

	bool GenEdstudyLoadTest2() {

		sict::GenEdCourse c5("OOP244", "Object-Oriented Programming in C++", 1, 4, 2);
		int a = c5 += -3;
		return (a == 1) && (c5.getStudyLoad() == 1);
	}

	bool GenEdgettersetterTest() {

		sict::GenEdCourse c;
		c.setCourseTitle("Object-Oriented Programming in C++");
		c.setCourseCode("OOP244");
		c.setCredits(4);
		c.setStudyLoad(4);
		c.setLangLevel(5);


		return (std::string(c.getCourseCode()) == "OOP244"
			&& std::string(c.getCourseTitle()) == "Object-Oriented Programming in C++"
			&& c.getCredits() == 4
			&& c.getStudyLoad() == 4
			&& c.getLangLevel() == 5
			);
	}
}

#endif
