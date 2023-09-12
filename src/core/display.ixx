module;

#include <string>
#include <memory>
#include <concepts>
#include <functional>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

export module core:display;

#define CallbackFn std::function<void()>

namespace core
{
    // Abstract
    struct Implementation
    {
    
    // Data members
        int mWidth;
        int mHeight;
        std::string mName;
        CallbackFn callback;

    // Member methods
    public:
        virtual void CreateWindow() = 0;
    protected:
        Implementation(int width, int height, std::string name) : mWidth(width), mHeight(height), mName(std::move(name)) {}
    };

    struct GLFWImpl : public Implementation
    {

        GLFWImpl(int width = 800, int height = 600, std::string name = "GLFWWindow") 
            : Implementation(width, height, std::move(name)) {}

        void CreateWindow() override
        {

        }
    };


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
    };


}
