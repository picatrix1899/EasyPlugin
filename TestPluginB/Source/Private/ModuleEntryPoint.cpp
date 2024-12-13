#include "pch.h"

#include "EasyPlugin/DefaultPluginFactory.h"
#include "TestPluginB.h"

#include "EasyPlugin/ModuleEntryPoint.h"

extern EasyPlugin::IPluginFactory* EasyPlugin::CreatePluginFactory() {
	return new EasyPlugin::DefaultPluginFactory([]() { return static_cast<EasyPlugin::IPlugin*>(new TestPluginB::TestPluginB()); });
}