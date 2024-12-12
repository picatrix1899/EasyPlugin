#pragma once

#include "IInternalSharedStd.h"

namespace EasyPlugin {

	class IInternalSharedObjectStore {
	public:
		virtual ~IInternalSharedObjectStore() = default;

	public:
		virtual IInternalSharedStd* GetStd() = 0;

	};

}