#pragma once

#include "EasyPlugin/IPluginBase.h"
#include "ITestAppPlugin.h"

namespace TestPluginA {

	class TestPluginA : public EasyPlugin::IPluginBase, public TestApp::ITestAppPlugin {
	private:
		EasyPlugin::SPluginInfo pluginInfo{ "TestPluginA", {1, 0, 0} };

	public:
		TestPluginA() {};

		virtual ~TestPluginA() = default;

		EasyPlugin::SPluginInfo GetInfo() { return this->pluginInfo; }

		void OnServerStart();
	};

}