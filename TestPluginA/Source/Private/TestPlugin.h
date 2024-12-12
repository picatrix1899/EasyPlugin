#pragma once

#include "EasyPlugin/IPluginBase.h"
#include "ITestAppPlugin.h"

namespace TestPluginA {

	class TestPlugin : public EasyPlugin::IPluginBase, public TestApp::ITestAppPlugin {
	private:
		EasyPlugin::SPluginInfo pluginInfo{ "TestPlugin", {1, 0, 0} };

	public:
		TestPlugin() {};

		virtual ~TestPlugin() = default;

		EasyPlugin::SPluginInfo GetInfo() { return this->pluginInfo; }

		void OnServerStart();
	};

}