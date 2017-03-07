#include "Tester.h"

#include <iostream>



namespace sict{

	void Tester::runTests() {
		for (const auto& t : tests)
		{
			std::cout << t->getName() << " has " << (t->run() ? "Passed\n" : "Failed - ");
			if (!t->getSuccess()){
				
				std::cout << t->getError() << "\n";
			}
		}
	};
}