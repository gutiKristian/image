module;

#include <string>

export module core:display;

export namespace core
{
    class Implementation
    {
        struct Data
        {
            int mWidth;
            int mHeight;
            std::string mName;
            
        };

    protected:
    //TODO:  Try to get rid off Data, pass this to the glfwSetPointer then we will cast it to impl calss and update members
        Data mData; 
        Implementation(int width, int height, std::string name)
        {
            mData.mWidth = width;
            mData.mHeight = height;
            mData.mName = std::move(name);
        }

        virtual void CreateWindow() = 0;

    public:
        inline const Data& GetData() { return mData; }
    };

    class Window
    {
    protected:
        Implementation * pImpl;
        
        virtual void SetEventCallback() = 0;
    public:
        Window(Implementation * windowImplementation) : pImpl(windowImplementation) {}
        virtual ~Window() { delete pImpl; }

        // Utilities
        inline int GetWidth() { return pImpl->GetData().mWidth; }
        inline int GetHeight() { return pImpl->GetData().mHeight; }
        inline std::string GetName() { return pImpl->GetData().mName; }
        
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
    private:
        Window * pWindow;
    public:
        virtual void OnAttach() = 0;
        virtual void OnUpadte() = 0;
        virtual void OnDestroy() = 0;
        virtual void OnUiRender() = 0;
        virtual ~Application() {}
    };

}
