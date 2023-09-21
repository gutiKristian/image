#include <memory>
#include <functional>
#include "../window/Window.h"
#include "../layer/Layer.h"
#include "../events.h"

namespace core
{
    class Application
    {
    private:
        bool mIsRunning = true;
        std::unique_ptr<Window> pWindow;
        std::unique_ptr<Layer> pLayer;
    public:
        Application(std::unique_ptr<Window>, std::unique_ptr<Layer>);
        void Run();
        void OnEvent(Event&);
    };
}