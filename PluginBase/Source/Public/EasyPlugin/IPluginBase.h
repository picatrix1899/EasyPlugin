#pragma once

#include "EasyPlugin/IPlugin.h"

#include "SharedObjectStore.h"

namespace EasyPlugin {

	class IPluginBase : public IPlugin {
	public:
		virtual ~IPluginBase() = default;

		void InitSharedObject(IInternalSharedObjectStore* objects) {
			objects->GetStd()->COut("Test");

			EasyPlugin::SharedObjectStore::internalStore = objects;
		}
	};

	extern IPlugin* CreatePlugin();

	extern "C" _declspec(dllexport) IPlugin* CreatePluginObject() {
		return CreatePlugin();
	}

}