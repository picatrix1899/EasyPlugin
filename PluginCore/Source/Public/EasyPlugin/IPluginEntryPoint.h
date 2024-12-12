#pragma once

#include "AppObjectStoreIntern.h"

#include "IPluginFactory.h"

namespace EasyPlugin {

	class IPluginEntryPoint {
	public:
		virtual ~IPluginEntryPoint() = default;

		struct SInitInternData {
			AppObjectStoreIntern* p_AppObjectStore;
		};

		virtual void InitIntern(IPluginEntryPoint::SInitInternData data) = 0;

		virtual IPluginFactory* GetPluginFactory() = 0;
	};

	extern IPluginEntryPoint* CreatePluginEntryPoint();

	extern "C" _declspec(dllexport) IPluginEntryPoint* CreatePluginEntryPointObject() {
		return CreatePluginEntryPoint();
	}

}