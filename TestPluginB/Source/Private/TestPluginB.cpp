#include "pch.h"

#include "TestPluginB.h"
#include "EasyPlugin/IPluginFactory.h"
#include "EasyPlugin/DefaultPluginFactory.h"
#include "TestStd.h"

namespace TestPluginB {

	void TestPluginB::OnServerStart() {
		TestStd::cout("Hello God");
	}	

}