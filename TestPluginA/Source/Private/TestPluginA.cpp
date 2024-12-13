#include "pch.h"

#include "TestPluginA.h"
#include "EasyPlugin/IPluginFactory.h"
#include "EasyPlugin/DefaultPluginFactory.h"
#include "TestStd.h"

namespace TestPluginA {

	void TestPluginA::OnServerStart() {
		TestStd::cout("Hello Devil");
	}	

}