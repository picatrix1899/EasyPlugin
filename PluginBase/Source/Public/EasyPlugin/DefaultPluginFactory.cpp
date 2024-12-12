#include "pch.h"

#include "DefaultPluginFactory.h"

namespace EasyPlugin {

	DefaultPluginFactory::DefaultPluginFactory(std::function<EasyPlugin::IPlugin* ()> producer) : m_Producer(producer) { }

	std::vector<IPlugin*> DefaultPluginFactory::Create() {
		std::vector<IPlugin*> plugins;

		plugins.push_back(this->m_Producer());

		return plugins;
	}
}