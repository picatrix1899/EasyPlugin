#include "pch.h"

#include "AModuleEntryPointBase.h"

namespace EasyPlugin {

		void AModuleEntryPointBase::InitIntern(IModuleEntryPoint::SInitInternData data) {
			AppObjectStore::s_Internal = data.p_AppObjectStore;
		}

		extern "C" _declspec(dllexport) EasyPlugin::IModuleEntryPoint* CreateEntryPointObject() {
			return CreateEntryPoint();
		}
}