#include "Window.h"

namespace core
{
    Window::Window(std::unique_ptr<Implementation> impl) : pImpl(std::move(impl))
    {
        pImpl->CreateWindow();
    }

    inline int Window::GetWidth()
    {
        return pImpl->mWidth;
    }

    inline int Window::GetHeight()
    {
        return pImpl->mHeight;
    }

    inline const std::string& Window::GetName()
    {
        return pImpl->mName;
    }

    inline void Window::SetEventCallback(const std::function<void(Event&)>& func)
    {
        pImpl->callback = func;
    }

    inline void Window::OnUpdate()
    {
        pImpl->OnUpdate();
    }
}