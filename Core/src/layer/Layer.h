#ifndef LAYER_GUARD_H
#define LAYER_GUARD_H

#include "../events.h"

namespace core
{
    /*
     * OpenGL code is represented as a layer that is being drawn
     * on a window. Layer is managed by an application.
     */
    class Layer
    {
    protected:
        Layer() = default;
    public:
        virtual void OnAttach() = 0;
        virtual void OnUpdate(float time) = 0;
        virtual void OnDetach() = 0;
        virtual void OnEvent(Event&) = 0;
        virtual void OnResize(int, int) = 0;
    };   
}

#endif