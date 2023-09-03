module;

#include <string>
#include <memory>
#include <concepts>
#include <functional>

export module core:display;

#define CallbackFn std::function<void()>

export namespace core
{
    // Interface
    struct Implementation
    {
    // Data members
        int mWidth;
        int mHeight;
        std::string mName;
        CallbackFn callback;
    // Member methods
    public:
        // Window calls this, Implementation classes are friends of Window
        virtual void CreateWindow() = 0;
    protected:
            Implementation(int width, int height, std::string name) : mWidth(width), mHeight(height), mName(std::move(name)) {}
    };

    class Window
    {
    protected:
        std::unique_ptr<Implementation> pImpl;
        
    public:
        Window(int width, int height, std::string name)
        {
            pImpl = std::make_unique<Implementation>(width, height, std::move(name));
            pImpl->CreateWindow();
        }

        ~Window() = default;

        // Utilities
        inline int GetWidth() { return pImpl->mWidth; }
        inline int GetHeight() { return pImpl->mHeight; }
        inline const std::string& GetName() { return pImpl->mName; }
        void SetEventCallback(CallbackFn func) { pImpl->callback = func; }
    };


}
