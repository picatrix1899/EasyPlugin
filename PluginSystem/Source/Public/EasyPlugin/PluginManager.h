#pragma once

#include <string>
#include <vector>

#include <EasyPlugin/IPlugin.h>

namespace EasyPlugin {

	struct PluginInstance {
		EasyPlugin::IPlugin* plugin;
		HINSTANCE handle;
	};

	class PluginManager {
	private:
		std::vector<PluginInstance> plugins;

	public:
		virtual ~PluginManager();

		void LoadPlugin(std::string path);

		void UnloadAll();

		inline std::vector<PluginInstance> GetPlugins() const {
			return this->plugins;
		}
	};

}