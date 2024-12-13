#pragma once

#include "EasyPlugin/IModuleEntryPoint.h"

#include "AppObjectStore.h"

namespace EasyPlugin {

	extern EasyPlugin::IPluginFactory* CreatePluginFactory();

	class ModuleEntryPoint : public IModuleEntryPoint {
	public:
		void InitIntern(IModuleEntryPoint::SInitInternData data) {
			AppObjectStore::s_Internal = data.p_AppObjectStore;
		}

		IPluginFactory* GetPluginFactory() {
			return CreatePluginFactory();
		}
	};

	extern "C" _declspec(dllexport) EasyPlugin::IModuleEntryPoint* CreateEntryPointObject() {
		return new ModuleEntryPoint();
	}
}