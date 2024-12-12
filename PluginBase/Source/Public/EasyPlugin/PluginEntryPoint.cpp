#include "pch.h"

#include "EasyPlugin/IPluginEntryPoint.h"

#include "AppObjectStore.h"

#include "IPluginBase.h"

namespace EasyPlugin {

	class PluginEntryPoint : public IPluginEntryPoint {
	public:
		void InitIntern(IPluginEntryPoint::SInitInternData data) override {
			AppObjectStore::s_Internal = data.p_AppObjectStore;
		}

		IPluginFactory* GetPluginFactory() override {
			return CreatePluginFactory();
		}
	};

	extern IPluginEntryPoint* CreatePluginEntryPoint() {
		return new PluginEntryPoint();
	}
}