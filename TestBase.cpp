#include "TestBase.h"

namespace sict{
	const std::string& TestBase::getName() const {
		return _name;
	}

	const std::string& TestBase::getError() const {
		return _error;
	}

	TestBase::TestBase(const std::string & n, const std::string & err) : _name(n), _error(err)
	{
	}

	bool TestBase::run()
	{
		return false;
	}

	bool TestBase::getSuccess() const
	{
		return false;
	}


}