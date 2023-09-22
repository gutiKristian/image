#ifndef IMPLEMENTATION_GUARD_H
#define IMPLEMENTATION_GUARD_H

#include <functional>
#include <string>
#include "../events.h"

namespace core
{
    class Implementation
    {
    public:
        int mWidth;
        int mHeight;
        std::string mName;
        std::function<void(Event&)> callback;
        // Member methods
        virtual void CreateWindow() = 0;
        virtual void OnUpdate() = 0;

        virtual ~Implementation() = default;
    protected:
        Implementation(int width, int height, std::string name) : mWidth(width), mHeight(height), mName(std::move(name)) {}
    };
}

#endif
