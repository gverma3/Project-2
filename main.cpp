#include <iostream>

#include "CourseTester.h"
#include "ICTCourseTester.h"
#include "GenEdCourseTester.h"
#include "ScmAppTester.h"

using namespace sict;
using std::cout;
using std::endl;
int main() {

	cout << "OOP244 Summer Milestone Tester" << endl << endl;

	cout << "\nRunning tests on your Course class." << endl;	
	cout << "-----------------------------------" << endl;	
	sict::CourseTester courseTester;
	courseTester.runTests();
	
	cout << "\nRunning tests on your ScmApp class." << endl;	
	cout << "-----------------------------------" << endl;	
	sict::ScmAppTester scmAppTester;
	scmAppTester.runTests();

	cout << "\nRunning tests on your ICTCourse class." << endl;	
	cout << "--------------------------------------" << endl;	

	sict::ICTCourseTester ICTcourseTester;
	ICTcourseTester.runTests();
	

	cout << "\nRunning tests on your GenEdCourse class." << endl;	
	cout << "--------------------------------------" << endl;	
	sict::GenEdCourseTester GenEdcourseTester;
	GenEdcourseTester.runTests();



}
