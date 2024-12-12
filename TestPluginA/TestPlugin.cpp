#include "pch.h"

#include "TestPlugin.h"
#include "EasyPlugin/SharedStd.h"

void TestPlugin::GetInfo(EasyPlugin::SPluginInfo* info) {
	info->p_Name = "Hello Home!";

	EasyPlugin::SharedStd::COut("Test shared");
	std::cout << "Test non shared" << std::endl;
}

extern EasyPlugin::IPlugin* EasyPlugin::CreatePlugin() {
	return new TestPlugin();
}