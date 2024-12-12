#include "pch.h"

#include <windows.h>
#include <exception>
#include <stdexcept>

#include "PluginManager.h"
#include "InternalSharedObjectStore.h"
#include "InternalSharedStd.h"

namespace EasyPlugin {

    PluginManager::~PluginManager() {
        UnloadAll();
    }

	void PluginManager::LoadPlugin(std::string path) {
            typedef EasyPlugin::IPlugin* (__cdecl* CreatePluginObjectProc)(void);

            HINSTANCE dllHandle = LoadLibrary(LR"(TestPluginA.dll)");

            if (!dllHandle) {
                throw std::runtime_error("Library wasn't loaded successfully!");
            }

            CreatePluginObjectProc createPluginObjectFunc = (CreatePluginObjectProc)GetProcAddress(dllHandle, "CreatePluginObject");

            if (!createPluginObjectFunc) {
                throw std::runtime_error("Invalid Plugin DLL: both 'getObj' must be defined.");
            }
                
            EasyPlugin::IPlugin* obj = createPluginObjectFunc();

            InternalSharedObjectStore* store = new InternalSharedObjectStore();
            store->sharedStd = new InternalSharedStd();

            obj->InitSharedObject(store);

            PluginInstance instance;
            instance.plugin = obj;
            instance.handle = dllHandle;

            this->plugins.push_back(instance);
	}

	void PluginManager::UnloadAll() {

        for (PluginInstance plugin : this->plugins) {
            FreeLibrary(plugin.handle);
        }

        this->plugins.clear();
	}
}