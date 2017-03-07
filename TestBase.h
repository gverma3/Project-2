#ifndef TESTBASE_H
#define TESTBASE_H

#include <string>

namespace sict{
	class TestBase {
		std::string _name;
		std::string _error;

	public:
		const std::string& getName() const;
		const std::string& getError() const;
		
		TestBase(const std::string&, const std::string&);
		virtual bool getSuccess() const;
		virtual bool run();
	};
}

#endif