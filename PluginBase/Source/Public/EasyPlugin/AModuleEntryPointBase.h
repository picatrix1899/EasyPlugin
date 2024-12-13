#pragma once

#include "EasyPlugin/IModuleEntryPoint.h"

#include "AppObjectStore.h"

namespace EasyPlugin {

	class AModuleEntryPointBase : public IModuleEntryPoint {
	public:
		void InitIntern(IModuleEntryPoint::SInitInternData data) override;

		virtual IPluginFactory* GetPluginFactory() = 0;
	};

	extern EasyPlugin::IModuleEntryPoint* CreateEntryPoint();
}