#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Lilac {
	class LILAC_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define LL_CORE_TRACE(...)    ::Lilac::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LL_CORE_INFO(...)     ::Lilac::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LL_CORE_WARN(...)     ::Lilac::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LL_CORE_ERROR(...)    ::Lilac::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LL_CORE_FATAL(...)    ::Lilac::Log::GetCoreLogger()->fatal(__VA_ARGS__)


// Client log macros
#define LL_TRACE(...)         ::Lilac::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LL_INFO(...)          ::Lilac::Log::GetClientLogger()->info(__VA_ARGS__)
#define LL_WARN(...)          ::Lilac::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LL_ERROR(...)         ::Lilac::Log::GetClientLogger()->error(__VA_ARGS__)
#define LL_FATAL(...)         ::Lilac::Log::GetClientLogger()->fatal(__VA_ARGS__)
