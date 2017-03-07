#include "ICTCourseTests.h"
#include "ICTCourseTester.h"
#include "TestBase.h"
#include "Test.h"

namespace sict {
	ICTCourseTester::ICTCourseTester() : Tester()
	{
		addTest(new Test<bool(void)>("isEmpty() Constructor Test", "isEmpty() should return true when an empty ICTCourse is created.", ICTisEmptyTest1));
		addTest(new Test<bool(void)>("isEmpty() Empty Course Code Test", "isEmpty() should return true when a ICTCourse has an empty course code.", ICTisEmptyTest2));
		addTest(new Test<bool(void)>("isEmpty() Course Title Test", "isEmpty() should return true when a ICTCourse has an empty title.", ICTisEmptyTest3));
		addTest(new Test<bool(void)>("isEmpty() Invalid Credits Test", "isEmpty() should return true when a ICTCourse has an invalid (-1) credit.", ICTisEmptyTest4));
		addTest(new Test<bool(void)>("isEmpty() Invalid Study Load Test", "isEmpty() should return true when a ICTCourse has an empty course code.", ICTisEmptyTest5));
		addTest(new Test<bool(void)>("isEmpty() Empty Computer System Test", "isEmpty() should return true when a ICTCourse has an invalid (-1) language level.", ICTisEmptyTest6));
		addTest(new Test<bool(void)>("Getter and Setter Test", "our getters, setters, or your 5 arugment constructor is not functioning properly.", ICTgettersetterTest));
		addTest(new Test<bool(void)>("Standard Initilization Test", "Your constructor is not properly creating Course objects.", ICTregularInitTest));
		addTest(new Test<bool(void)>("Empty Initilization Test", "Your no argument constructor is not setting your course object to a safe empty state.", ICTemptyInitTest));
		addTest(new Test<bool(void)>("Change Study Load Test Positive Number", "Your overloaded += operator is not properly adding positive values to the courses study load.", ICTstudyLoadTest1));
		addTest(new Test<bool(void)>("Change Study Load Test Negative Number", "Your overloaded += operator is not properly adding negative values to the courses study load.", ICTstudyLoadTest2));
	}

	ICTCourseTester::~ICTCourseTester()
	{
	}


}