#include "pch.h"

#include "EasyPlugin/DefaultPluginFactory.h"
#include "TestPlugin.h"

#include "EasyPlugin/AModuleEntryPointBase.h"

namespace TestPluginA {

	class ModuleEntryPoint : public EasyPlugin::AModuleEntryPointBase {

		EasyPlugin::IPluginFactory* GetPluginFactory() {
			return new EasyPlugin::DefaultPluginFactory([]() { return static_cast<EasyPlugin::IPlugin*>(new TestPluginA::TestPlugin()); });
		}

	};	
}

extern EasyPlugin::IModuleEntryPoint* EasyPlugin::CreateEntryPoint() {
	return new TestPluginA::ModuleEntryPoint();
}