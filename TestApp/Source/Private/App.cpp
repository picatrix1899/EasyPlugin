#include "pch.h"

#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include <exception>
#include <windows.h>

#include "EasyPlugin/PluginManager.h"
#include "EasyPlugin/IPlugin.h"
#include "ITestAppPlugin.h"
#include "TestStd.h"

/*
std::vector<PluginInstance> getPlugins(std::vector<HINSTANCE>& modules) {

    modules.clear();

    WIN32_FIND_DATA fileData;
    HANDLE fileHandle = FindFirstFile(LR"(TestPluginA.dll)", &fileData);

    if (fileHandle == INVALID_HANDLE_VALUE) {
        DWORD error = GetLastError();

        if (error == ERROR_INVALID_HANDLE ||
            error == ERROR_FILE_NOT_FOUND) {

            std::cerr << "Error" << std::endl;
        }

        return std::vector<PluginInstance>();
    }

    std::vector<PluginInstance> ret;

    do {
        typedef EasyPlugin::IPlugin* (__cdecl* ObjProc)(void);

        HINSTANCE mod = LoadLibrary(LR"(TestPluginA.dll)");

        if (!mod) {
            for (HINSTANCE hInst : modules)
                FreeLibrary(hInst);
            throw std::runtime_error("Library wasn't loaded successfully!");
        }


        ObjProc objFunc = (ObjProc)GetProcAddress(mod, "CreatePluginObject");

        if (!objFunc)
            throw std::runtime_error("Invalid Plugin DLL: both 'getObj' must be defined.");

        EasyPlugin::IPlugin* obj = objFunc();

        PluginInstance instance {
            .plugin = obj,
            .handle = mod,
            .fileName = fileData.cFileName
        };

        ret.push_back(instance);
        modules.push_back(mod);

    } while (FindNextFile(fileHandle, &fileData));

    FindClose(fileHandle);

    return ret;
}
 */

int main() {
    TestApp::TestStd* std = static_cast<TestApp::TestStd*>(new TestApp::TestStd());

    EasyPlugin::PluginManager manager = EasyPlugin::PluginManager();
    manager.LoadPlugin("TestPluginA.dll");
    manager.GetAppObjectStore()->Add<TestApp::TestStd>(std);

    for (EasyPlugin::PluginInstance instance : manager.GetLoadedPlugins()) {
        EasyPlugin::IPlugin* rawPlugin = instance.p_Plugin;
        TestApp::ITestAppPlugin* plugin = dynamic_cast<TestApp::ITestAppPlugin*>(rawPlugin);

        EasyPlugin::SPluginInfo info = rawPlugin->GetInfo();

        std::cout << info.p_Name << std::endl;

        plugin->OnServerStart();
    }

    system("pause");

    return 0;
}