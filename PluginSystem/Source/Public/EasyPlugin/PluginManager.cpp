#include "pch.h"

#include <windows.h>
#include <exception>
#include <stdexcept>

#include "PluginManager.h"
#include "EasyPlugin/AppObjectStoreIntern.h"
#include "EasyPlugin/IPluginEntryPoint.h"
#include "EasyPlugin/IPluginFactory.h"
#include "EasyPlugin/IPlugin.h"

namespace EasyPlugin {

    PluginManager::PluginManager() {
        this->m_AppObjectStore = new AppObjectStoreIntern();
    }

    PluginManager::~PluginManager() {
        UnloadAll();
    }

	void PluginManager::LoadPlugin(std::string path) {
            using CreatePluginEntryPointProc = IPluginEntryPoint* (*)();

            HMODULE dllHandle = LoadLibraryA(path.c_str());

            if (!dllHandle) {
                throw std::runtime_error("Library wasn't loaded successfully!");
            }

            FARPROC funcAddress = GetProcAddress(dllHandle, "CreatePluginEntryPointObject");
            CreatePluginEntryPointProc createPluginEntryPointFunc = reinterpret_cast<CreatePluginEntryPointProc>(funcAddress);

            if (!createPluginEntryPointFunc) {
                throw std::runtime_error("Invalid Plugin DLL: No function for entry point creation.");
            }
                
            IPluginEntryPoint* pluginEntryPoint = createPluginEntryPointFunc();

            IPluginEntryPoint::SInitInternData initInternData{};
            initInternData.p_AppObjectStore = this->m_AppObjectStore;

            pluginEntryPoint->InitIntern(initInternData);

            IPluginFactory* pluginFactory = pluginEntryPoint->GetPluginFactory();

            std::vector<IPlugin*> plugins = pluginFactory->Create();

            PluginFile pluginFile{};
            pluginFile.p_Path = path;
            pluginFile.p_Handle = dllHandle;

            for (IPlugin* plugin : plugins) {
                PluginInstance pluginInstance{};
                pluginInstance.p_File = &pluginFile;
                pluginInstance.p_Plugin = plugin;

                pluginFile.p_Instances.push_back(pluginInstance);
            }
	}

	void PluginManager::UnloadAll() {

        for (PluginFile plugin : this->m_PluginFiles) {
            FreeLibrary(plugin.p_Handle);
        }

        this->m_PluginFiles.clear();
        this->m_PluginInstances.clear();
	}
}