#pragma once

#include "ITestStd.h"

namespace TestPluginA {

	class TestStd {
	private:
		static TestApp::ITestStd* s_Internal;
	public:
		static void cout(std::string text);
	private:
		static inline void Init();
	};

}