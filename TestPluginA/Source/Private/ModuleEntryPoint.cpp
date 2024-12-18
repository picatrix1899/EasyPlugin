#include "pch.h"

#include "EasyPlugin/DefaultPluginFactory.h"
#include "TestPluginA.h"

#include "EasyPlugin/ModuleEntryPoint.h"

extern EasyPlugin::IPluginFactory* EasyPlugin::CreatePluginFactory() {
	return new EasyPlugin::DefaultPluginFactory([]() { return static_cast<EasyPlugin::IPlugin*>(new TestPluginA::TestPluginA()); });
}