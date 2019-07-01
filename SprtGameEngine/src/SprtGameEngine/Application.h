#pragma once

#include "Core.h"

namespace Sprt {

	class SPRT_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}