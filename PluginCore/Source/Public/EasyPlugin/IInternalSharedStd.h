#pragma once

#include <iostream>

namespace EasyPlugin {

	class IInternalSharedStd {
	public:
		virtual ~IInternalSharedStd() = default;

		virtual void COut(std::string text) = 0;
	};

}