#pragma once
#include "Iridium/Core/Application.h"
#include "Iridium/Core/Log.h"
extern Ird::Application* Ird::CreateApp();
int main() {

	Ird::Application* app = Ird::CreateApp();
	if (!app) {
		std::cout << "App failed to load!\n";
		return -1;
	}
	app->Run();
	delete app;


	return 0;
}