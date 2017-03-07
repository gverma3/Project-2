#include "ScmAppTester.h"

#include "Course.h"
#include "ICTCourse.h"
#include "GenEdCourse.h"
#include "Test.h"

#include <sstream>
#include <string>
#include <memory>
#include <fstream>
#include <iostream>

namespace sict{
	
	void ScmAppTester::runTests(){

		std::cout << "courseList_ elements initiated to nullptr has ";
		if (!scmAppArrayNull()){
			std::cout << "Failed - You are not initializing your courseList_ elements to nullptr\n";
		} else{
			std::cout << "Passed\n";
		}
		std::cout << "searchForACourse function - first element has ";
		if (!scmAppSearchForCourse0()){
			std::cout << "Failed - Your course search is not functioning correctly\n";
		} else{
			std::cout << "Passed\n";
		}
		std::cout << "searchForACourse function- last element has ";
		if (!scmAppSearchForCourse1()){
			std::cout << "Failed - Your course search is not functioning correctly\n";
		} else{
			std::cout << "Passed\n";
		}
		std::cout << "searchForACourse function- middle element has ";
		if (!scmAppSearchForCourse2()){
			std::cout << "Failed - Your course search is not functioning correctly\n";
		} else{
			std::cout << "Passed\n";
		}
		std::cout << "searchForACourse function- not found has ";
		if (!scmAppSearchForCourse3()){
			std::cout << "Failed - Your course search is not functioning correctly\n";
		} else{
			std::cout << "Passed\n";
		}
		/*
		std::cout << "listCourses output formatting  has ";
		if (!scmAppListCourses()){
			std::cout << "Failed - Your courses are not formatted properly\n";
		} else{
			std::cout << "Passed\n";
		}
		
		std::cout << "Menu ouput and format test has ";
		if (!scmAppMenuOutput()){
			std::cout << "Failed - The output of menu function is not properly formatted\n";
		} else{
			std::cout << "Passed\n";
		}
		std::cout << "Menu input test - 1 has ";
		if (!scmAppMenuTester1()){
			std::cout << "Failed - Your menu function is not returning the value 1 after taking 1 as input\n";
		} else{
			std::cout << "Passed\n";
		}
		std::cout << "Menu input test - 2 has ";
		if (!scmAppMenuTester2()){
			std::cout << "Failed - Your menu function is not returning the value 2 after taking 2 as input\n";
		} else{
			std::cout << "Passed\n";
		}
		std::cout << "Menu input test - 3 has ";
		if (!scmAppMenuTester3()){
			std::cout << "Failed - Your menu function is not returning the value 3 after taking 3 as input\n";
		} else{
			std::cout << "Passed\n";
		}
		std::cout << "Menu input test - 4 has ";
		if (!scmAppMenuTester4()){
			std::cout << "Failed - Your menu function is not returning the value 4 after taking 4 as input\n";
		} else{
			std::cout << "Passed\n";
		}
		std::cout << "Menu input test - 0 has ";
		if (!scmAppMenuTester0()){
			std::cout << "Failed - Your menu function is not returning the value 0 after taking 0 as input\n";
		} else{
			std::cout << "Passed\n";
		}
		*/
		std::cout << "Testing saving records \n";
		if (!testSaveRecs()){
			std::cout << "Failed - Your saveRec function is not functioning correctly.\n";
		} else{
			std::cout << "Passed\n";
		}
		std::cout << "Record Loading Test \n";
		if (!testLoadRecs()){
			std::cout << "Failed - Your loadRec function is not functioning correctly.\n";
		} else{
			std::cout << "Passed\n";
		}

	}

	ScmAppTester::ScmAppTester()
	{
		/*
		addTest(new Test<bool(void)>("courseList_ elements initiated to nullptr ", "You are not initializing your courseList_ elements to nullptr", [&](){ return this->scmAppArrayNull();}));
        addTest(new Test<bool(void)>("searchForACourse function - first element", "Your course search is not functioning correctly", [&](){ return this->scmAppSearchForCourse0();}));
        addTest(new Test<bool(void)>("searchForACourse function- last element", "Your course search is not functioning correctly", [&](){ return this->scmAppSearchForCourse1();}));
        addTest(new Test<bool(void)>("searchForACourse function- middle element", "Your course search is not functioning correctly", [&](){ return this->scmAppSearchForCourse2();}));
        addTest(new Test<bool(void)>("searchForACourse function- not found", "Your course search is not functioning correctly",[&](){ return this->scmAppSearchForCourse3();}));
        addTest(new Test<bool(void)>("listCourses output formatting ", "Your course search is not functioning correctly", [&](){ return this->scmAppListCourses();}));
        addTest(new Test<bool(void)>("Menu ouput and format test", "The output of menu function is not properly formatted", [&](){ return this->scmAppMenuOutput();}));
        addTest(new Test<bool(void)>("Menu input test - 1", "Your menu function is not returning the value 1 after taking 1 as input", [&](){ return this->scmAppMenuTester1();}));
        addTest(new Test<bool(void)>("Menu input test - 2", "Your menu function is not returning the value 2 after taking 2 as input", [&](){ return this->scmAppMenuTester2();}));
        addTest(new Test<bool(void)>("Menu input test - 3", "Your menu function is not returning the value 3 after taking 3 as input", [&](){ return this->scmAppMenuTester3();}));
        addTest(new Test<bool(void)>("Menu input test - 4", "Your menu function is not returning the value 4 after taking 4 as input", [&](){ return this->scmAppMenuTester4();}));
        addTest(new Test<bool(void)>("Menu input test - 0", "Your menu function is not returning the value 0 after taking 0 as input", [&](){ return this->scmAppMenuTester0();}));
        addTest(new Test<bool(void)>("Record Loading Test", "Your menu function is not returning the value 0 after taking 0 as input", [&](){ return this->testSaveRecs();}));
        addTest(new Test<bool(void)>("Record Saving Test", "Your menu function is not returning the value 0 after taking 0 as input", [&](){ return this->testLoadRecs();}));
        */
        
	}


	ScmAppTester::~ScmAppTester()
	{

	}

	bool ScmAppTester::scmAppListCourses(){
		ScmApp app("testFile.txt");
		std::ostringstream oss;
		auto cout_buf = std::cout.rdbuf();
		std::cout.rdbuf(oss.rdbuf());

		app.listCourses();		
		
		std::cout.rdbuf(cout_buf);
		
		return oss && oss.str() == " Row | Code |               Course Title              | Credits | Study Load | System | Lang. Req. |\n-----|------|-----------------------------------------|---------|------------|--------|------------|\n   0 |OOP244|Object-Oriented Programming in C++       |        1|           4|\n   1 |BTP200|The Object-Oriented Paradigm Using C++   |        1|           4|\n   2 |IPC144|Introduction to Programming Using C      |        1|           4|\n   3 |BTP100|Programming Fundamentals Using C         |        1|           4|\n   4 |EAC150|College English                          |        1|           4|\n   5 |BTP140|Critical Thinking and Writing            |        1|           4|\n   6 |COM480|The Art of Storytelling                  |        1|           3|\n   7 |CUL485|Movies and Morality                      |        1|           3|\n   8 |PHL105|Introduction to Philosophy               |        1|           3|\n----------------------------------------------------------------------------------------------------\n\n";

	}

	bool ScmAppTester::scmAppMenuOutput(){
		ScmApp app("testFile.txt");
		std::ostringstream oss;
		auto cout_buf = std::cout.rdbuf();
		std::cout.rdbuf(oss.rdbuf());

		std::istringstream iss("1");
		auto cin_buf = std::cin.rdbuf();
		std::cin.rdbuf(iss.rdbuf());


		app.menu();
		
		std::cin.rdbuf(cin_buf);
		std::cout.rdbuf(cout_buf);
		
		return oss && oss.str() == "Seneca Course Management Tool\n1- List courses.\n2- Display the details of a course.\n3- Add a course.\n4- Change the study load of a course.\n0- Exit Program\n";

	}

	bool ScmAppTester::scmAppMenuTester1(){
		ScmApp app("testFile.txt");
		std::istringstream iss("1");
		auto cin_buf = std::cin.rdbuf();
		std::cin.rdbuf(iss.rdbuf());

		std::ostringstream oss;
		auto cout_buf = std::cout.rdbuf();
		std::cout.rdbuf(oss.rdbuf());

		int test = app.menu();

		std::cout.rdbuf(cout_buf);
		std::cin.rdbuf(cin_buf);		
		return test == 1;

	}

	bool ScmAppTester::scmAppMenuTester2(){
		ScmApp app("testFile.txt");
		std::istringstream iss("2");
		auto cin_buf = std::cin.rdbuf();
		std::cin.rdbuf(iss.rdbuf());

		std::ostringstream oss;
		auto cout_buf = std::cout.rdbuf();
		std::cout.rdbuf(oss.rdbuf());

		int test = app.menu();

		std::cout.rdbuf(cout_buf);
		std::cin.rdbuf(cin_buf);		
		return test == 2;
	}	

	bool ScmAppTester::scmAppMenuTester3(){
		ScmApp app("testFile.txt");
		std::istringstream iss("3");
		auto cin_buf = std::cin.rdbuf();
		std::cin.rdbuf(iss.rdbuf());

		std::ostringstream oss;
		auto cout_buf = std::cout.rdbuf();
		std::cout.rdbuf(oss.rdbuf());

		int test = app.menu();

		std::cout.rdbuf(cout_buf);
		std::cin.rdbuf(cin_buf);		
		return test == 3;

	}	

	bool ScmAppTester::scmAppMenuTester4(){
		ScmApp app("testFile.txt");
		std::istringstream iss("4");	
		auto cin_buf = std::cin.rdbuf();
		std::cin.rdbuf(iss.rdbuf());

		std::ostringstream oss;
		auto cout_buf = std::cout.rdbuf();
		std::cout.rdbuf(oss.rdbuf());

		int test = app.menu();

		std::cout.rdbuf(cout_buf);
		std::cin.rdbuf(cin_buf);		

		return test == 4;

	}	

	bool ScmAppTester::scmAppMenuTester0(){
		ScmApp app("testFile.txt");
		std::istringstream iss("0");
		auto cin_buf = std::cin.rdbuf();
		std::cin.rdbuf(iss.rdbuf());

		std::ostringstream oss;
		auto cout_buf = std::cout.rdbuf();
		std::cout.rdbuf(oss.rdbuf());

		int test = app.menu();

		std::cout.rdbuf(cout_buf);
		std::cin.rdbuf(cin_buf);		

		return test == 0;

	}		

	bool ScmAppTester::scmAppArrayNull(){
		ScmApp app("testFile.txt");
		return app.courseList_[0] == nullptr && app.courseList_[1999] == nullptr;
	}
		
	bool ScmAppTester::scmAppSearchForCourse0(){
		ScmApp app("testFile.txt");
		
		initCourses(app);
		int i = app.searchACourse("OOP244");
		return i == 0;
		
	}

	bool ScmAppTester::scmAppSearchForCourse1(){
		ScmApp app("testFile.txt");
		
		initCourses(app);
		int i = app.searchACourse("PHL105");
		return i == 8;		
	}

	bool ScmAppTester::scmAppSearchForCourse2(){
		ScmApp app("testFile.txt");
		
		initCourses(app);
		int i = app.searchACourse("EAC150");
		return i == 4;
	}

	bool ScmAppTester::scmAppSearchForCourse3(){
		ScmApp app("testFile.txt");
		
		initCourses(app);
		int i = app.searchACourse("xxx141");
		return i == -1;
	
	}

	bool ScmAppTester::testLoadRecs(){
		ScmApp app("testFile.txt");
		

		createTestFile();
		app.loadRecs();

		if (app.dataFile_.is_open()){
			std::cout << "File is not closed after read\n";
			return false;
		}

		if (app.noOfCourses_ != 12){
			std::cout << "Number of files read is incorrect\n";
			return false;
		}
		
		if (
			std::string(app.courseList_[0]->getCourseCode()) != "OOP244"
			|| std::string(app.courseList_[0]->getCourseTitle()) != "Object-Oriented Programming in C++"
			|| app.courseList_[0]->getCredits() != 1
			|| app.courseList_[0]->getStudyLoad() != 4
			|| std::string(((ICTCourse*)app.courseList_[0])->getComputerSystem()) != "Window"){
			std::cout << "loadRecs() is not properly reading the course records from the file\n";
			return false;
		}
		
		if (
			std::string(app.courseList_[3]->getCourseCode()) != "BTP100"
			|| std::string(app.courseList_[3]->getCourseTitle()) != "Programming Fundamentals Using C"
			|| app.courseList_[3]->getCredits() != 1
			|| app.courseList_[3]->getStudyLoad() != 4
			|| std::string(((ICTCourse*)app.courseList_[3])->getComputerSystem()) != "AS400"){
			std::cout << "loadRecs() is not properly reading the course records from the file\n";
			return false;
		}

		if (
			std::string(app.courseList_[4]->getCourseCode()) != "EAC150"
			|| std::string(app.courseList_[4]->getCourseTitle()) != "College English"
			|| app.courseList_[4]->getCredits() != 1
			|| app.courseList_[4]->getStudyLoad() != 4
			|| ((GenEdCourse*)app.courseList_[4])->getLangLevel() != 2){
			std::cout << "loadRecs() is not properly reading the course records from the file\n";
			return false;
		}

		if (
			std::string(app.courseList_[11]->getCourseCode()) != "SOC600"
			|| std::string(app.courseList_[11]->getCourseTitle()) != "Introduction to Sociology"
			|| app.courseList_[11]->getCredits() != 1
			|| app.courseList_[11]->getStudyLoad() != 3
			|| ((GenEdCourse*)app.courseList_[11])->getLangLevel() != 6){
			std::cout << "loadRecs() is not properly reading the course records from the file\n";
			return false;
		}

		return true;
	}

	bool ScmAppTester::testSaveRecs(){
		ScmApp app("testFile.txt");
		

		std::remove("testFile.txt");

		initCourses(app);

		app.saveRecs();
		

		if (app.dataFile_.is_open()){
			std::cout << "File is not closed after save\n";
			return false;
		}

		std::fstream file("testFile.txt", std::ios::in);
		if (!file.is_open()){
			std::cout << "Error opening file\n" ;
		}
		std::string courseType = "empty";
		std::vector<Course*> courseList;
		int numCourse = 0;
		
		while (getline(file, courseType, ',')){
			Course* c;
			if (courseType == TYPE_ICT){
				c = new ICTCourse;
			}else if (courseType == TYPE_GEN) {
				c = new GenEdCourse;
			}


			std::string input;
			int num;
			getline(file, input, ',');
			c->setCourseCode(input.c_str());
			getline(file, input, ',');
			c->setCourseTitle(input.c_str());
			file >> num;
			c->setCredits(num);
			std::string garbage;
			getline(file, garbage, ',');
			file >> num;
			c->setStudyLoad(num);
			getline(file, garbage, ',');
			
			if (courseType == TYPE_ICT){
				file >> input;
				((ICTCourse*)c)->setComputerSystem(input.c_str());				
			}else if (courseType == TYPE_GEN) {
				file >> num;
				((GenEdCourse*)c)->setLangLevel(num);			
			}
			file.ignore(256,'\n');
			courseList.push_back(c);
			numCourse++;
			


		}
		file.close();
		


		std::vector<Course*> courses{new ICTCourse("OOP244", "Object-Oriented Programming in C++" ,1, 4, "Window"),
									new ICTCourse("BTP200", "The Object-Oriented Paradigm Using C++", 1, 4, "Linux"),
									new ICTCourse("IPC144", "Introduction to Programming Using C", 1, 4, "Matrix"),
									new ICTCourse("BTP100", "Programming Fundamentals Using C", 1, 4, "AS400"),
									new GenEdCourse("EAC150", "College English", 1, 4, 2),
									new GenEdCourse("BTP140", "Critical Thinking and Writing", 1, 4, 4),
									new GenEdCourse("COM480", "The Art of Storytelling", 1, 3, 3),
									new GenEdCourse("CUL485", "Movies and Moraltiy", 1, 3, 5),
									new GenEdCourse("PHL105", "Introduction to Philosophy", 1, 3, 4),
									new GenEdCourse("PSY141", "Social Psychology", 1, 3, 3),
									new GenEdCourse("HIS201", "World War II", 1, 3, 5),
									new GenEdCourse("SOC600", "Introduction to Sociology", 1, 3, 6)};

		
		return courseList.size() == courses.size()
			&& std::string(courseList[0]->getCourseCode()) == std::string(courses[0]->getCourseCode())
			&& std::string(courseList[0]->getCourseTitle()) == std::string(courses[0]->getCourseTitle())
			&& courseList[0]->getCredits() == courses[0]->getCredits()
			&& courseList[0]->getStudyLoad() == courses[0]->getStudyLoad()
			&& std::string(courseList[11]->getCourseCode()) == std::string(courses[11]->getCourseCode())
			&& std::string(courseList[11]->getCourseTitle()) == std::string(courses[11]->getCourseTitle())
			&& courseList[11]->getCredits() == courses[11]->getCredits()
			&& courseList[11]->getStudyLoad() == courses[11]->getStudyLoad()
			&& std::string(courseList[5]->getCourseCode()) == std::string(courses[5]->getCourseCode())
			&& std::string(courseList[5]->getCourseTitle()) == std::string(courses[5]->getCourseTitle())
			&& courseList[5]->getCredits() == courses[5]->getCredits()
			&& courseList[5]->getStudyLoad() == courses[5]->getStudyLoad();





		
	}





	void ScmAppTester::initCourses(ScmApp& app){
		
		app.courseList_[app.noOfCourses_++] = new ICTCourse("OOP244", "Object-Oriented Programming in C++", 1, 4, "Window");
		app.courseList_[app.noOfCourses_++] = new ICTCourse("BTP200", "The Object-Oriented Paradigm Using C++", 1, 4, "Linux");
		app.courseList_[app.noOfCourses_++] = new ICTCourse("IPC144", "Introduction to Programming Using C", 1, 4, "Matrix");
		app.courseList_[app.noOfCourses_++] = new ICTCourse("BTP100", "Programming Fundamentals Using C", 1, 4, "AS400");
		app.courseList_[app.noOfCourses_++] = new GenEdCourse("EAC150", "College English", 1, 4, 2);
		app.courseList_[app.noOfCourses_++] = new GenEdCourse("BTP140", "Critical Thinking and Writing", 1, 4, 4);
		app.courseList_[app.noOfCourses_++] = new GenEdCourse("COM480", "The Art of Storytelling", 1, 3, 3);
		app.courseList_[app.noOfCourses_++] = new GenEdCourse("CUL485", "Movies and Moraltiy", 1, 3, 5);
		app.courseList_[app.noOfCourses_++] = new GenEdCourse("PHL105", "Introduction to Philosophy", 1, 3, 4);
		app.courseList_[app.noOfCourses_++] = new GenEdCourse("PSY141", "Social Psychology", 1, 3, 3);
		app.courseList_[app.noOfCourses_++] = new GenEdCourse("HIS201", "World War II", 1, 3, 5);
		app.courseList_[app.noOfCourses_++] = new GenEdCourse("SOC600", "Introduction to Sociology", 1, 3, 6);

	}


	void ScmAppTester::createTestFile(){
		
		
		std::fstream file("testFile.txt", std::ios::out);
		
		if (!file.is_open())	
		{
			std::cout << "Error opening file";
			
		}

		std::vector<std::string> courses{ "I,OOP244,Object-Oriented Programming in C++,1,4,Window\n","I,BTP200,The Object-Oriented Paradigm Using C++,1,4,Linux\n","I,IPC144,Introduction to Programming Using C,1,4,Matrix\n","I,BTP100,Programming Fundamentals Using C,1,4,AS400\n","G,EAC150,College English,1,4,2\n","G,BTP140,Critical Thinking and Writing,1,4,4\n","G,COM480,The Art of Storytelling,1,3,3\n","G,CUL485,Movies and Moraltiy,1,3,5\n","G,PHL105,Introduction to Philosophy,1,3,4\n","G,PSY141,Social Psychology,1,3,3\n","G,HIS201,World War II,1,3,5\n","G,SOC600,Introduction to Sociology,1,3,6\n"};

		for (const auto& c : courses)
		{
			file << c;
		}

		file.close();
	}


}
