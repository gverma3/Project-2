#include "CourseTests.h"
#include "CourseTester.h"
#include "TestBase.h"
#include "Test.h"

namespace sict {
	CourseTester::CourseTester() : Tester()
	{
		addTest(new Test<bool(void)>("isEmpty() Constructor Test", "isEmpty() should return true when an empty Course is created.", isEmptyTest0));
		addTest(new Test<bool(void)>("isEmpty() Empty Course Code Test", "isEmpty() should return true when a Course has an empty course code.", isEmptyTest1));
		addTest(new Test<bool(void)>("isEmpty() Course Title Test", "isEmpty() should return true when a Course has an empty title.",isEmptyTest2));
		addTest(new Test<bool(void)>("isEmpty() Invalid Credits Test", "isEmpty() should return true when a Course has an invalid (-1) credit.",isEmptyTest3));
		addTest(new Test<bool(void)>("isEmpty() Invalid Study Load Test", "isEmpty() should return true when a Course has an empty course code.",isEmptyTest4));
		addTest(new Test<bool(void)>("Getter and setter Test Test", "Your getters, setters, or your 4 arugment constructor is not functioning properly.",gettersetterTest));		
		addTest(new Test<bool(void)>("Standard Initilization Test", "Your 4 argument constructor is not properly creating Course objects.",regularInitTest));
		addTest(new Test<bool(void)>("Empty Initilization Test", "Your no argument constructor is not setting your course object to a safe empty state.",emptyInitTest));
		addTest(new Test<bool(void)>("Equality Test", "Your overloaded == operator is not properly comparing the string with the courses course code.",equalTest));
		addTest(new Test<bool(void)>("Inequality Test Test", "Your overloaded == operator is not properly comparing the string with the courses course code.",inequalityTest));
		addTest(new Test<bool(void)>("Change Study Load Test Positive Number", "Your overloaded += operator is not properly adding positive values to the courses study load.",studyLoadTest1));
		addTest(new Test<bool(void)>("Change Study Load Test Negative Number", "Your overloaded += operator is not properly adding negative values to the courses study load",studyLoadTest2));
		
	}

	CourseTester::~CourseTester()
	{
	}


}




