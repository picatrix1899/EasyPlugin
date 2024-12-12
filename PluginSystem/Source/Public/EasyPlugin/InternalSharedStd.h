#pragma once

#include <iostream>

#include "EasyPlugin/IInternalSharedStd.h"

namespace EasyPlugin {

	class InternalSharedStd : public IInternalSharedStd {
		virtual ~InternalSharedStd() = default;

		void COut(std::string text) {
			std::cout << text;
		}

	};
}