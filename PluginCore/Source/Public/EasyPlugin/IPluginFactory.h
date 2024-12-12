#pragma once

#include <vector>

#include "IPlugin.h"

namespace EasyPlugin {

	class IPluginFactory {
	public:
		virtual ~IPluginFactory() = default;

	public:
		virtual std::vector<IPlugin*> Create() = 0;
	};

}