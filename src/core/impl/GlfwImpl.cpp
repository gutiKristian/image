#include "GlfwImpl.h"
#include "../events.h"

namespace core
{
    GLFWImpl::GLFWImpl(int width = 800, int height = 600, std::string name = "GLFWImpl") 
            : Implementation(width, height, name)
    {

    }

    GLFWImpl::~GLFWImpl() override
    {
        glfwTerminate();
    }

    GLFWImpl::CreateWindow() override
    {
        if (!glfwInit())
        {
            std::cout << "GLFW failed to initialize!\n";
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);


        pWindow = glfwCreateWindow(mWidth, mHeight, mName.c_str(), nullptr, nullptr);

        if (pWindow == nullptr)
        {
            std::cout << "Failed to create GLFW window\n";
            glfwTerminate();
        }

        glfwMakeContextCurrent(pWindow);

        // init glad
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD\n";
        }

        glfwSetWindowUserPointer(pWindow, this);

        glfwSetFramebufferSizeCallback(pWindow, [](GLFWwindow *window, int width, int height)
        {
            GLFWImpl& data = *(GLFWImpl *) glfwGetWindowUserPointer(window);
            data.mWidth = width;
            data.mHeight = height;
            WindowResizeEvent e(width, height);
            data.callback(e);
        });


        glfwSetWindowCloseCallback(pWindow, [](GLFWwindow* window)
        {
            GLFWImpl& data = *(GLFWImpl *) glfwGetWindowUserPointer(window);
            WindowCloseEvent e;
            data.callback(e);                
        });
    }

    GLFWImpl::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(pWindow);
    }
    
}