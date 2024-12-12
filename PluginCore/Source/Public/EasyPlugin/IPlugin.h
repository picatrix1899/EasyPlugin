#pragma once

#include <string>

namespace EasyPlugin {

	struct SSemanticVersion {
		int p_Major;
		int p_Minor;
		int p_Hotfix;

		SSemanticVersion(int major, int minor, int hotfix) : p_Major(major), p_Minor(minor), p_Hotfix(hotfix) { }

		SSemanticVersion(int major, int minor) : p_Major(major), p_Minor(minor), p_Hotfix(0) {}

		SSemanticVersion() : p_Major(0), p_Minor(0), p_Hotfix(0) { }
	};

	struct SPluginInfo {
		std::string p_Name;
		SSemanticVersion p_Version;
	};

	class IPlugin {
	public:
		virtual ~IPlugin() = default;

	public:
		virtual SPluginInfo GetInfo() = 0;
	};

}