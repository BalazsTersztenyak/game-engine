#pragma once

#include "Lilac/Core.h"
#include "Lilac/Events/Event.h"

namespace Lilac {
	class LILAC_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
