module;

#include <string>
#include <memory>
#include <iostream>
#include <concepts>
#include <functional>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

export module core:display;

#define CallbackFn std::function<void()>

namespace core
{
    /*
    
        HIDDEN
    
    */

    // Abstract
    struct Implementation
    {
    
    // Data members
        int mWidth;
        int mHeight;
        std::string mName;
        CallbackFn callback;
        // Member methods
        virtual void CreateWindow() = 0;
        virtual void OnUpdate() = 0;

        virtual ~Implementation() = default;
    protected:
        Implementation(int width, int height, std::string name) : mWidth(width), mHeight(height), mName(std::move(name)) {}
    };

    /*
        Implementations
    */

    export struct GLFWImpl : public Implementation
    {

        GLFWImpl(int width = 800, int height = 600, std::string name = "GLFWWindow") 
            : Implementation(width, height, std::move(name)) 
        {
            std::cout << "Created GLFWwindow\n";
        }
        
        ~GLFWImpl()
        {
            glfwTerminate();
        }

        void CreateWindow() override
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
                std::cout << "Resize action\n";
                // Call callback for resize, set by application
                // data.callback(<resize event>)
            });


            glfwSetWindowCloseCallback(pWindow, [](GLFWwindow* window)
            {
                GLFWImpl& data = *(GLFWImpl *) glfwGetWindowUserPointer(window);
                // Callback set by application
                std::cout << "Should have closed!\n";
            });

        }

        void OnUpdate() override
        {
            glfwPollEvents();
            glfwSwapBuffers(pWindow);
        }
    private:
        GLFWwindow* pWindow;
    };

    /*
        Abstractions
    */

    export class Window
    {
    protected:
        std::unique_ptr<Implementation> pImpl;
        
    public:
        Window(std::unique_ptr<Implementation> impl) : pImpl(std::move(impl))
        {
            pImpl->CreateWindow();
        }

        ~Window() = default;

        // Utilities
        int GetWidth() { return pImpl->mWidth; }
        int GetHeight() { return pImpl->mHeight; }
        const std::string& GetName() { return pImpl->mName; }
        void SetEventCallback(CallbackFn func) { pImpl->callback = func; }
        void OnUpdate() { pImpl->OnUpdate(); }
    };


}
