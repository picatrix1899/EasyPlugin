#pragma once

#include "EasyPlugin/IPlugin.h"
#include "EasyPlugin/IPluginFactory.h"

namespace EasyPlugin {

	class IPluginBase : public IPlugin {
	public:
		virtual ~IPluginBase() = default;
	};

}