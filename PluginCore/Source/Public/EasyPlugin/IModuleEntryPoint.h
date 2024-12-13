#pragma once

#include "AppObjectStoreIntern.h"

#include "IPluginFactory.h"

namespace EasyPlugin {

	class IModuleEntryPoint {
	public:
		virtual ~IModuleEntryPoint() = default;

		struct SInitInternData {
			AppObjectStoreIntern* p_AppObjectStore;
		};

		virtual void InitIntern(IModuleEntryPoint::SInitInternData data) = 0;

		virtual IPluginFactory* GetPluginFactory() = 0;
	};

	extern "C" _declspec(dllexport) EasyPlugin::IModuleEntryPoint* CreateEntryPointObject();
}