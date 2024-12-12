#pragma once

#include "EasyPlugin/IPluginBase.h"

class TestPlugin : public EasyPlugin::IPluginBase {
public:
	virtual ~TestPlugin() = default;

	void GetInfo(EasyPlugin::SPluginInfo* info);
};