#pragma once

#include "EasyPlugin/IPluginBase.h"
#include "ITestAppPlugin.h"

namespace TestPluginB {

	class TestPluginB : public EasyPlugin::IPluginBase, public TestApp::ITestAppPlugin {
	private:
		EasyPlugin::SPluginInfo pluginInfo{ "TestPluginB", {1, 0, 0} };

	public:
		TestPluginB() {};

		virtual ~TestPluginB() = default;

		EasyPlugin::SPluginInfo GetInfo() { return this->pluginInfo; }

		void OnServerStart();
	};

}