#pragma once
#include <memory>
#include <iostream>

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#pragma warning(pop)

#pragma region goofy macro magic
#define IRD_STRINGIFY(x) #x
#define IRD_TOSTRING(x) IRD_STRINGIFY(x)
#define IRD_AT __FILE__ ":" IRD_TOSTRING(__LINE__)

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

#ifdef IRD_DEBUG
#define IRD_VERIFY(...)
#endif
#pragma endregion 
namespace Ird {
	class Logger {
	public:
		Logger(const std::string& title);
		std::shared_ptr<spdlog::logger> logger;
		void Test(){
			std::cout << "Logger Test" <<std::endl;
		}
		
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

	void Verify(bool condition);
}
