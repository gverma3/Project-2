#ifndef TESTER_H
#define TESTER_H

#include <vector>
#include <memory>

#include "TestBase.h"

namespace sict{
	class Tester
	{
		std::vector<std::unique_ptr<TestBase>> tests;
	public:
		void runTests();

		template <typename T>
		void addTest(T* test);

		Tester() {};
		virtual ~Tester() {};
	};

	template <typename T>
	void Tester::addTest(T* test) {
		tests.push_back(std::unique_ptr<TestBase>(test));
	};

}

#endif