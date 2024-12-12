#pragma once

#include "EasyPlugin/IInternalSharedObjectStore.h"

namespace EasyPlugin {

	class SharedObjectStore {
	public:
		static IInternalSharedObjectStore* internalStore;

	public:
		static inline IInternalSharedStd* GetStd() {
			return EasyPlugin::SharedObjectStore::internalStore->GetStd();
		}
	};

}