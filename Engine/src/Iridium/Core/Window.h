#pragma once
#include <memory>
namespace Ird {
	class Window
	{
	public:
		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual bool IsRunning() = 0;
		static std::unique_ptr<Window> IRDCreateWindow();
		// Window attributes
		//virtual void SetVSync(bool enabled) = 0;
		//virtual bool IsVSync() const = 0;
	};
}
