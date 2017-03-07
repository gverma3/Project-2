#ifndef ICTCOURSETESTS_H
#define ICTCOURSETESTS_H

#include <string>
#include "ICTCourse.h"

namespace sict {
	
	bool ICTisEmptyTest1() {
		// empty test
		sict::ICTCourse c0;
		return c0.isEmpty();
	}

	bool ICTisEmptyTest2() {
		// empty test
		sict::ICTCourse c0("", "title", 3, 3, "test");
		return c0.isEmpty();
	}

	bool ICTisEmptyTest3() {
		// empty test
		sict::ICTCourse c0("code", "", 3, 3, "test");
		return c0.isEmpty();
	}

	bool ICTisEmptyTest4() {
		// empty test
		sict::ICTCourse c0("code", "title", -1, 3, "test");
		return c0.isEmpty();
	}

	bool ICTisEmptyTest5() {
		// empty test
		sict::ICTCourse c0("code", "title", 3, -1, "test");
		return c0.isEmpty();
	}

	bool ICTisEmptyTest6() {
		// empty test
		sict::ICTCourse c0("code", "title", 3, -1, "");
		return c0.isEmpty();
	}

	bool ICTregularInitTest() {
		// regular
		sict::ICTCourse c5("OOP244", "Object-Oriented Programming in C++", 1, 4, "MATRIX");
		return (!c5.isEmpty()
			&& std::string(c5.getCourseCode()) == "OOP244"
			&& std::string(c5.getCourseTitle()) == "Object-Oriented Programming in C++"
			&& c5.getCredits() == 1
			&& c5.getStudyLoad() == 4
			&& std::string(c5.getComputerSystem()) == "MATRIX"
			);
	}

	bool ICTemptyInitTest() {
		// regular
		sict::ICTCourse c5;
		return (std::string(c5.getCourseCode()) == ""
			&& (c5.getCredits() == 0 || c5.getCredits() == -1)
			&& (c5.getStudyLoad() == 0 || c5.getStudyLoad() == -1)
			&& (c5.getCourseTitle() == nullptr || (c5.getCourseTitle() != nullptr && std::string(c5.getCourseTitle()) == ""))
			//&&std::string(c5.getCourseTitle()) == ""
			&& std::string(c5.getComputerSystem()) == "matrix"
			);
	}


	
	bool ICTstudyLoadTest1() {

		sict::ICTCourse c5("OOP244", "Object-Oriented Programming in C++", 1, 4, "test");
		int a = c5 += 6;
		return (a == 10) && (c5.getStudyLoad() == 10);
	}

	bool ICTstudyLoadTest2() {

		sict::ICTCourse c5("OOP244", "Object-Oriented Programming in C++", 1, 4, "test");
		int a = c5 += -3;
		return (a == 1) && (c5.getStudyLoad() == 1);
	}

	bool ICTgettersetterTest() {

		sict::ICTCourse c;
		c.setCourseTitle("Object-Oriented Programming in C++");
		c.setCourseCode("OOP244");
		c.setCredits(4);
		c.setStudyLoad(4);
		c.setComputerSystem("tester");


		return (std::string(c.getCourseCode()) == "OOP244"
			&& std::string(c.getCourseTitle()) == "Object-Oriented Programming in C++"
			&& c.getCredits() == 4
			&& c.getStudyLoad() == 4
			&& std::string(c.getComputerSystem()) == "tester"
			);
	}
}

#endif
