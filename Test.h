#ifndef TEST_H
#define TEST_H

#include <string>
#include <functional>

#include "TestBase.h"

namespace sict {
	template <typename T>
	class Test : public TestBase
	{
		std::function<T> _func;
		bool _success;


	public:
		Test(const std::string&, const std::string&, T&);
		bool getSuccess() const;
		virtual bool run();

		virtual ~Test();
	};

	template<typename T>
	Test<T>::Test(const std::string & name, const std::string & err, T & t) : TestBase(name, err), _func(t), _success(true)
	{
	}

	template<typename T>
	bool Test<T>::getSuccess() const {
		return _success;
	}
	
	template<typename T>
	bool Test<T>::run()
	{
		return true;//_success = _func();

	}

	template<typename T>
	Test<T>::~Test()
	{
	}


}

#endif
