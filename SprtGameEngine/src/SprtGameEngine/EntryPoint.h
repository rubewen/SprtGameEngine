#pragma once

#ifdef SPRT_PLATFORM_WINDOWS

extern Sprt::Application* Sprt::CreateApplication();

int main(int argc, char** argv)
{
	printf("SprtGameEngine kjører en uendelig while(true) loop...");
	auto app = Sprt::CreateApplication();
	app->Run();
	delete app;
}

#endif