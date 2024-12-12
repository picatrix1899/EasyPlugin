#pragma once

#include <functional>

#include "EasyPlugin/IPluginFactory.h"

namespace EasyPlugin {

	class DefaultPluginFactory : public IPluginFactory {
	private: 
		std::function<EasyPlugin::IPlugin* ()> m_Producer;

	public: 
		DefaultPluginFactory(std::function<EasyPlugin::IPlugin* ()> producer);

	public:
		std::vector<IPlugin*> Create() override;
	};

}