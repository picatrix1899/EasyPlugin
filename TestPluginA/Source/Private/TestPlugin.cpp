#include "pch.h"

#include "TestPlugin.h"
#include "EasyPlugin/IPluginFactory.h"
#include "EasyPlugin/DefaultPluginFactory.h"
#include "TestStd.h"

namespace TestPluginA {
	void TestPlugin::OnServerStart() {
		TestStd::cout("Hello Devil");
	}	
}

extern EasyPlugin::IPluginFactory* EasyPlugin::CreatePluginFactory() {
	return new DefaultPluginFactory([]() { return static_cast<EasyPlugin::IPlugin*>(new TestPluginA::TestPlugin()); });
}