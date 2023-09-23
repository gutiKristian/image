#ifndef WINDOW_GUARD_H
#define WINDOW_GUARD_H

#include <memory>
#include "../impl/Implementation.h"

namespace core
{
    class Window
    {
    protected:
        std::unique_ptr<Implementation> pImpl;
        
    public:
        Window(std::unique_ptr<Implementation>);

        ~Window() = default;

        int GetWidth();
        int GetHeight();
        const std::string& GetName();
        void SetEventCallback(const std::function<void(Event&)>& func);
        void OnUpdate();
        float GetTime();
    };
}

#endif