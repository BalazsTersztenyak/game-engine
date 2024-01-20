#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Lilac {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			LL_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput)) {
			LL_TRACE(e);
		}

		while (true);
	}
}