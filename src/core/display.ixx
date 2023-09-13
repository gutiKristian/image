module;

#include <string>
#include <memory>
#include <iostream>
#include <concepts>
#include <functional>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "events.h"

export module core:display;

#define CallbackFn std::function<void(int8_t)>

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
                // Call callback for resize, set by application
                data.callback(EVENT_RESIZE);
            });


            glfwSetWindowCloseCallback(pWindow, [](GLFWwindow* window)
            {
                GLFWImpl& data = *(GLFWImpl *) glfwGetWindowUserPointer(window);
                data.callback(EVENT_CLOSE);                
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



    export struct VisionApplication
    {
        VisionApplication(std::string &&name, std::unique_ptr<Window> window) : mName(name), pWindow(std::move(window))
        {
            pWindow->SetEventCallback(std::bind(&VisionApplication::OnEvent, this, std::placeholders::_1));
        }
        ~VisionApplication() = default;

        void Run()
        {
            while (mIsRunning)
            {
                pWindow->OnUpdate();
            }
        }
        
        void OnEvent(int8_t event)
        {
            switch (event)
            {
            case EVENT_CLOSE:
                mIsRunning = false;
                break;
            case EVENT_RESIZE:
                OnResize();
                break;
            default:
                std::cout << "Unknown event\n";
                break;
            }
        }

    private:
        void OnClose()
        {
            std::cout << "----- Vision OnClose -----\n";
        }

        void OnResize()
        {
            // Recalculating viewports ?
            std::cout << "----- Vision OnResize -----\n";
            std::cout << "Current res: " << pWindow->GetWidth() << ", " <<  pWindow->GetHeight() << "\n";
        }

        private:
            bool mIsRunning = true;
            std::string mName;
            std::unique_ptr<Window> pWindow;
    };

}
