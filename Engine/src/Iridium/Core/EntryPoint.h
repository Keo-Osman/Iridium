#pragma once
#include "Iridium/Core/Application.h"
#include "Iridium/Core/Log.h"
#include "Iridium/Core/Time.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
extern Ird::Application* Ird::CreateApp();
int main() {
	Ird::log::Init();
	Ird::Application* app = Ird::CreateApp();
	if (!app) {
		std::cout << "App failed to load!\n";
		return -1;
	}
	app->Run();

	delete app;
	IRD_CORE_INFO("Count was: {}", Ird::g_tickCount);
	std::cin.get();


	return 0;
}