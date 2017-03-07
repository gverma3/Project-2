// OOP244 Milestone 4: 
// File: Streamable.h
// Version: 1.0
// Date: 8/15/2016
// Author: Gaurav Verma 
/////////////////////////////////////////////

#ifndef SICT_STREAMABLE_H__
#define SICT_STREAMABLE_H__

#include <fstream>
#include <iostream>

namespace sict {

	class Streamable {
	public:
		virtual std::fstream& store(std::fstream& file, bool addNewLine = true) const = 0;
		virtual std::fstream& load(std::fstream& file) = 0;
		virtual std::ostream& display(std::ostream& os) const = 0;
		virtual std::istream& read(std::istream& is) = 0;

	};

	

}

#endif