#ifndef GLFWIMPL_GUARD_H
#define GLFWIMPL_GUARD_H


#include "Implementation.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace core
{
    class GLFWImpl : public Implementation
    {
    public:
        GLFWImpl(int, int, std::string);
        ~GLFWImpl();

        void CreateWindow() override;
        void OnUpdate() override;
        
    private:
        GLFWwindow* pWindow = nullptr;
    };
}

#endif