#include "irpch.h"
#include "Log.h"
namespace Ird {
	namespace log{
		//---------CORE LOGGER USED IN ENGINE-----------------------------------
		Logger* g_coreLogger = nullptr;
	//---------CORE LOGGER USED IN ENGINE-----------------------------------

	//---------CLIENT LOGGER USED IN APPLICATIONS-----------------------------------
	Logger* g_clientLogger = nullptr;
	//---------CLIENT LOGGER USED IN APPLICATIONS-----------------------------------
	}
	void log::Init() {
		g_coreLogger = new Logger("Core");
		g_clientLogger = new Logger("LOLOL");
	}
	void log::Shutdown() {
		delete g_coreLogger;
		delete g_clientLogger;
	}

	Logger::Logger(const std::string& title) {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		logger = spdlog::stdout_color_mt(title);
		logger->set_level(spdlog::level::trace);
	}
	void Verify(bool condition){
		if(!condition){
			std::string result = "Condition failed at ";
			result += IRD_AT;
			IRD_CORE_CRITICAL(result);
			__debugbreak();
		}
	}
}

