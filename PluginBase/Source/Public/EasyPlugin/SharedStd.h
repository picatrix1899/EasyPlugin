#pragma once

#include <iostream>

#include "SharedObjectStore.h"

namespace EasyPlugin {

	class SharedStd {
	public:
		static inline void COut(std::string text) {
			SharedObjectStore::GetStd()->COut(text);
		}
	};

}