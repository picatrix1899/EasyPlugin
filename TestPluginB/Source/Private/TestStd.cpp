#include "pch.h"

#include "TestStd.h"
#include "EasyPlugin/AppObjectStore.h"

namespace TestPluginB {

	TestApp::ITestStd* TestStd::s_Internal = nullptr;

	void TestStd::Init() {
		if (s_Internal) return;

		s_Internal = EasyPlugin::AppObjectStore::Get<TestApp::ITestStd>();
	}

	void TestStd::cout(std::string text) {
		Init();

		s_Internal->cout(text);
	}

}