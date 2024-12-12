#pragma once

#include <string>
#include <vector>

#include <EasyPlugin/IPlugin.h>
#include <EasyPlugin/AppObjectStoreIntern.h>

namespace EasyPlugin {

	struct PluginFile;

	struct PluginInstance {
		IPlugin* p_Plugin;
		PluginFile* p_File;
	};

	struct PluginFile {
		std::string p_Path;
		std::vector<PluginInstance> p_Instances;
		HMODULE p_Handle;
	};

	class PluginManager {
	private:
		std::vector<PluginInstance> m_PluginInstances;
		std::vector<PluginFile> m_PluginFiles;
		AppObjectStoreIntern* m_AppObjectStore;

	public:
		PluginManager();

		virtual ~PluginManager();

		void LoadPlugin(std::string path);

		void UnloadAll();

		inline std::vector<PluginInstance> GetLoadedPlugins() const {
			return this->m_PluginInstances;
		}

		inline std::vector<PluginFile> GetLoadedPluginFiles() const {
			return this->m_PluginFiles;
		}

		inline AppObjectStoreIntern* GetAppObjectStore() const {
			return this->m_AppObjectStore;
		}
	};

}