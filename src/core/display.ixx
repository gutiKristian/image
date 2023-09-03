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
    class Implementation
    {
    // Data members
    protected:
        int mWidth;
        int mHeight;
        std::string mName;
        CallbackFn callback;
    // Member methods
    protected:
            Implementation(int width, int height, std::string name) : mWidth(width), mHeight(height), mName(std::move(name)) {}
            // Window calls this, Implementation classes are friends of Window
            virtual void CreateWindow() = 0;
    };



    template <typename T>
    concept IsDerived = std::is_base_of<Implementation, T>::value;
    
    template <IsDerived Impl>
    class Window
    {
        friend Impl;

    protected:
        std::shared_ptr<Impl> pImpl;
        
    public:
        Window(int width, int height, std::string name)
        {
            pImpl = std::make_shared(width, height, std::move(name));
            pImpl->CreateWindow();
        }

        ~Window() = default;

        // Utilities
        inline int GetWidth() { return pImpl->mWidth; }
        inline int GetHeight() { return pImpl->mHeight; }
        inline std::string GetName() { return pImpl->mName; }
        void SetEventCallback(CallbackFn func) { pImpl->callback = func; }
        
    };

    // Implementation
    class GLFWImpl : Implementation
    {
    public:
        GLFWImpl(int height, int width, std::string name) : Implementation(height, width, std::move(name))
        {}

        void CreateWindow() override
        {
            
        }
    };



    class Application
    {
    
    public:
        virtual void OnAttach() = 0;
        virtual void OnUpdate() = 0;
        virtual void OnDestroy() = 0;
        virtual void OnUiRender() = 0;
        virtual ~Application() {}
    };

}
