#include "GenEdCourseTests.h"
#include "GenEdCourseTester.h"
#include "TestBase.h"
#include "Test.h"

namespace sict {
	
	GenEdCourseTester::GenEdCourseTester() : Tester()
	{
		addTest(new Test<bool(void)>("isEmpty() Constructor Test", "isEmpty() should return true when an empty GenEdCourse is created.", GenEdisEmptyTest1));
		addTest(new Test<bool(void)>("isEmpty() Empty Course Code Test", "isEmpty() should return true when a GenEdCourse has an empty course code.", GenEdisEmptyTest2));
		addTest(new Test<bool(void)>("isEmpty() Course Title Test", "isEmpty() should return true when a GenEdCourse has an empty title.", GenEdisEmptyTest3));
		addTest(new Test<bool(void)>("isEmpty() Invalid Credits Test", "isEmpty() should return true when a GenEdCourse has an invalid (-1) credit.", GenEdisEmptyTest4));
		addTest(new Test<bool(void)>("isEmpty() Invalid Study Load Test", "isEmpty() should return true when a GenEdCourse has an empty course code.", GenEdisEmptyTest5));
		addTest(new Test<bool(void)>("isEmpty() Empty Computer System Test", "isEmpty() should return true when a GenEdCourse has an empty computer system.", GenEdisEmptyTest6));
		addTest(new Test<bool(void)>("Getter and Setter Test", "Your getters, setters, or your 5 arugment constructor is not functioning properly.", GenEdgettersetterTest));
		addTest(new Test<bool(void)>("Standard Initilization Test", "Your 5 argument constructor is not properly creating Course objects.", GenEdregularInitTest));
		addTest(new Test<bool(void)>("Empty Initilization Test", "Your no argument constructor is not setting your course object to a safe empty state.", GenEdemptyInitTest));
		addTest(new Test<bool(void)>("Change Study Load Test Positive Number", "Your overloaded += operator is not properly adding positive values to the courses study load.", GenEdstudyLoadTest1));
		addTest(new Test<bool(void)>("Change Study Load Test Negative Number", "Your overloaded += operator is not properly adding negative values to the courses study load.", GenEdstudyLoadTest2));
		

		
	}

	GenEdCourseTester::~GenEdCourseTester()
	{
	}


}