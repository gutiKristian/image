#include <memory>
#include "../impl/Implementation.h"

namespace core
{
    class Window
    {
    protected:
        std::unique_ptr<Implementation> pImpl;
        
    public:
        Window(std::unique_ptr<Implementation>);

        ~Window() = default;

        int GetWidth();
        int GetHeight();
        const std::string& GetName();
        void SetEventCallback(CallbackFn func);
        void OnUpdate();
    };
}