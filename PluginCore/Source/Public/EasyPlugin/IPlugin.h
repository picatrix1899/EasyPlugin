#pragma once

#include <string>

#include "IInternalSharedObjectStore.h"

namespace EasyPlugin {

	struct SPluginInfo {
		std::string p_Name;
	};

	class IPlugin {
	public:
		virtual ~IPlugin() = default;

		virtual void GetInfo(SPluginInfo* info) = 0;

		virtual void InitSharedObject(IInternalSharedObjectStore* objects) = 0;
	};

	extern "C" _declspec(dllexport) IPlugin* CreatePluginObject();

}