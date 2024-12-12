#pragma once

#include "IPlugin.h"

namespace EasyPlugin {

	class IPluginFactory {
		virtual ~IPluginFactory() = default;

		virtual IPlugin** Create() = 0;
	};

}