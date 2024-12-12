#include "pch.h"

#include "TestStd.h"

#include <iostream>
#include <string>

namespace TestApp {

	void TestStd::cout(std::string text) {
		std::cout << text << std::endl;
	}

}