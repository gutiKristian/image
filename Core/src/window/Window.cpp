#include "Window.h"

namespace core
{
    Window::Window(std::unique_ptr<Implementation> impl) : pImpl(std::move(impl))
    {
        pImpl->CreateWindow();
    }

    int Window::GetWidth()
    {
        return pImpl->mWidth;
    }

    int Window::GetHeight()
    {
        return pImpl->mHeight;
    }

    const std::string& Window::GetName()
    {
        return pImpl->mName;
    }

    void Window::SetEventCallback(const std::function<void(Event&)>& func)
    {
        pImpl->callback = func;
    }

    void Window::OnUpdate()
    {
        pImpl->OnUpdate();
    }
    
    float Window::GetTime()
    {
        pImpl->mTime;
    }
}