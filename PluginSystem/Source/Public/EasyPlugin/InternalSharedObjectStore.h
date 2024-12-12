#pragma once

#include "EasyPlugin/IInternalSharedObjectStore.h"
#include "EasyPlugin/IInternalSharedStd.h"

namespace EasyPlugin {

	class InternalSharedObjectStore : public IInternalSharedObjectStore {
	public:
		IInternalSharedStd* sharedStd;

	public:
		IInternalSharedStd* GetStd() {
			return sharedStd;
		}
	};
}