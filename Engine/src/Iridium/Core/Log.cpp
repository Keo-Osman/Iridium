#include "Log.h"
#include <iostream>
namespace Ird {


	//---------CORE LOGGER USED IN ENGINE-----------------------------------
	Logger* g_coreLogger;
	//---------CORE LOGGER USED IN ENGINE-----------------------------------

	//---------CLIENT LOGGER USED IN APPLICATIONS-----------------------------------
	Logger* g_clientLogger;
	//---------CLIENT LOGGER USED IN APPLICATIONS-----------------------------------

	void Log::Init() {
		g_coreLogger = new Logger("Core");
		g_clientLogger = new Logger("LOLOL");
	}
	void Log::Shutdown() {
		delete g_coreLogger;
		delete g_clientLogger;
	}

	Logger::Logger(const std::string& title) {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		logger = spdlog::stdout_color_mt(title);
		logger->set_level(spdlog::level::trace);
	}
}

