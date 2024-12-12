#pragma once

#include <string>

namespace TestApp {

	class ITestStd {
	public:
		virtual ~ITestStd() = default;

		virtual void cout(std::string text) = 0;
	};

}