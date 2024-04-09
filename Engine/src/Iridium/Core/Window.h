#pragma once
#include "irpch.h"
namespace Ird {
	struct WindowData{
		std::string title;
		uint32_t width, height;
		bool vsync;
		WindowData(const std::string& p_title = "Engine Iridium",
			        uint32_t p_width = 800,
			        uint32_t p_height = 800,
					bool p_vsync = false)
			: title(p_title), width(p_width), height(p_height), vsync(p_vsync)
		{
		}
	};
	class Window
	{
	public:
		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual bool IsRunning() = 0;
		static Window* IRDCreateWindow();
		// Window attributes
		//virtual void SetVSync(bool enabled) = 0;
		//virtual bool IsVSync() const = 0;
	};
}
