#ifndef COURSETESTS_H
#define COURSETESTS_H

#include <string>
#include "Course.h"

namespace sict {
	bool isEmptyTest0() {
		// empty test
		sict::Course c0;
		return c0.isEmpty();
	}

	bool isEmptyTest1() {
		// empty test
		sict::Course c0("", "title", 3, 3);
		return c0.isEmpty();
	}

	bool isEmptyTest2() {
		// empty test
		sict::Course c0("code", "", 3, 3);
		return c0.isEmpty();
	}

	bool isEmptyTest3() {
		// empty test
		sict::Course c0("code", "title", -1, 3);
		return c0.isEmpty();
	}

	bool isEmptyTest4() {
		// empty test
		sict::Course c0("code", "title", 3, -1);
		return c0.isEmpty();
	}

	bool regularInitTest() {
		// regular
		sict::Course c5("OOP244", "Object-Oriented Programming in C++", 1, 4);
		return (!c5.isEmpty()
			&& std::string(c5.getCourseCode()) == "OOP244"
			&& std::string(c5.getCourseTitle()) == "Object-Oriented Programming in C++"
			&& c5.getCredits() == 1
			&& c5.getStudyLoad() == 4
			);
	}

	bool emptyInitTest() {
		// regular
		sict::Course c5;
		return (std::string(c5.getCourseCode()) == ""
			&& (c5.getCredits() == 0 || c5.getCredits() == -1)
			&& (c5.getStudyLoad() == 0 || c5.getStudyLoad() == -1)
			&& (c5.getCourseTitle() == nullptr || (c5.getCourseTitle() != nullptr && std::string(c5.getCourseTitle()) == ""))
			//&& std::string(c5.getCourseTitle()) == ""
			);
	}


	bool equalTest() {
		// regular
		sict::Course c5("OOP244", "Object-Oriented Programming in C++", 1, 4);
		return (c5 == "OOP244");
	}

	bool inequalityTest() {
		// regular
		sict::Course c5("OOP244", "Object-Oriented Programming in C++", 1, 4);
		return !(c5 == "xxx244");
	}
	bool studyLoadTest1() {

		sict::Course c5("OOP244", "Object-Oriented Programming in C++", 1, 4);
		int a = c5 += 6;
		return (a == 10) && (c5.getStudyLoad() == 10);
	}

	bool studyLoadTest2() {

		sict::Course c5("OOP244", "Object-Oriented Programming in C++", 1, 4);
		int a = c5 += -3;
		return (a == 1) && (c5.getStudyLoad() == 1);
	}

	bool gettersetterTest() {

		sict::Course c;
		c.setCourseTitle("Object-Oriented Programming in C++");
		c.setCourseCode("OOP244");
		c.setCredits(4);
		c.setStudyLoad(4);


		return (std::string(c.getCourseCode()) == "OOP244"
			&& std::string(c.getCourseTitle()) == "Object-Oriented Programming in C++"
			&& c.getCredits() == 4
			&& c.getStudyLoad() == 4
			);
	}
}

#endif
