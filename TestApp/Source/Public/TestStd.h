#pragma once

#include "ITestStd.h"

namespace TestApp {

	class TestStd : public ITestStd {
	public:
		virtual ~TestStd() = default;

		void cout(std::string text);
	};

}