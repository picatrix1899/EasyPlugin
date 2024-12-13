# EasyPlugin

This is a small personal project that provides an easy to implement and flexible plugin/addin/addon/mod system. It works currently only for Windows.
It allows to load and undload dlls with a respective entry point. Each dll may contain more than on plugin/addin/addon/mod.


It is still in development and is not tested outside of the solution yet.

# Implementation (Not tested yet)

1. Compile the Project. You need the PluginBase.lib and the PluginSystem.lib
2. Gather the Header files from the Source/Public folders of the projects PluginCore and PluginBase for the Plugin
3. Gather the Header files from the Source/Public folders of the projects PluginCore and PluginSystem for the main App
4. Create DLL project for the plugin and use the PluginBase.lib and the gathered Headers for the Plugin.
5. Add a cpp File i.e. "ModuleEntryPoint.cpp" to the plugin project:
```c++
  #include "EasyPlugin/ModuleEntryPoint.h"
  
  extern EasyPlugin::IPluginFactory* EasyPlugin::CreatePluginFactory() {
  	return ...
  }
```

Be careful with the include of `EasyPlugin/ModuleEntryPoint.h`. it contains the actual Entry Point.

You can implement your own plugin factory or you can use the default one `DefaultPluginFactory` from `EasyPlugin/DefaultPluginFactory.h` which provides a single plugin.
For using the default factory create a new instance and give it a lambda for creation of the plugin:

```c++
  extern EasyPlugin::IPluginFactory* EasyPlugin::CreatePluginFactory() {
  	return new EasyPlugin::DefaultPluginFactory([]() { return static_cast<EasyPlugin::IPlugin*>(new ...); });
  }
```

7. In your main App use the PluginSystem.lib and the gathered Headers for the main App.
