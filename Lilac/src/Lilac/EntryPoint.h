#pragma once


#ifdef LL_PLATFORM_WINDOWS

extern Lilac::Application* Lilac::CreateApplication();

int main(int argc, char** argv) {
	Lilac::Log::Init();
	LL_CORE_WARN("Initialized Log!");
	int a = 5;
	LL_INFO("Hello! Var={0}", a);


	auto app = Lilac::CreateApplication();
	app->Run();
	delete app;
}

#endif
