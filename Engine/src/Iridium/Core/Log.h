#pragma once
#include <memory>

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#pragma warning(pop)


namespace Ird {
	class Logger {
	public:
		Logger(const std::string& title);
		std::shared_ptr<spdlog::logger> logger;
		
	};
	namespace Log {
		void Init();
		void Shutdown();
	}
	//---------CORE LOGGER USED IN ENGINE-----------------------------------
	extern Logger* g_coreLogger;
	//---------CORE LOGGER USED IN ENGINE-----------------------------------

	//---------CLIENT LOGGER USED IN APPLICATIONS-----------------------------------
	extern Logger* g_clientLogger;
	//---------CLIENT LOGGER USED IN APPLICATIONS-----------------------------------
}
#ifdef IRD_DIST   
#define IRD_CORE_TRACE(...)			
#define IRD_CORE_WARN(...)			
#define IRD_CORE_ERROR(...)			
#define IRD_CORE_CRITICAL(...)		
#define IRD_CORE_INFO(...)			
#else
#define IRD_CORE_TRACE(...)			Ird::g_coreLogger->logger->trace(__VA_ARGS__)
#define IRD_CORE_WARN(...)			Ird::g_coreLogger->logger->warn(__VA_ARGS__)
#define IRD_CORE_ERROR(...)			Ird::g_coreLogger->logger->error(__VA_ARGS__)
#define IRD_CORE_CRITICAL(...)		Ird::g_coreLogger->logger->critical(__VA_ARGS__)
#define IRD_CORE_INFO(...)			Ird::g_coreLogger->logger->info(__VA_ARGS__)
#endif

#ifdef IRD_APP_LOG   
#define IRD_TRACE(...)			Ird::g_clientLogger->logger->trace(__VA_ARGS__)
#define IRD_WARN(...)			Ird::g_clientLogger->logger->warn(__VA_ARGS__)
#define IRD_ERROR(...)			Ird::g_clientLogger->logger->error(__VA_ARGS__)
#define IRD_CRITICAL(...)		Ird::g_clientLogger->logger->critical(__VA_ARGS__)
#define IRD_INFO(...)			Ird::g_clientLogger->logger->info(__VA_ARGS__)
#else
#define IRD_TRACE(...)			
#define IRD_WARN(...)			
#define IRD_ERROR(...)			
#define IRD_CRITICAL(...)		
#define IRD_INFO(...)			
#endif