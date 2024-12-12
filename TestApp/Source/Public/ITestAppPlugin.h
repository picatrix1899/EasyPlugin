#pragma once

namespace TestApp {

	class ITestAppPlugin {
	public:
		virtual ~ITestAppPlugin() = default;

		virtual void OnServerStart() = 0;
	};

}