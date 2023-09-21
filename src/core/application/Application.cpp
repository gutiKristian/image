#include "Application.h"

namespace core
{
    
    Application::Application(std::unique_ptr<Window> window, std::unique_ptr<Layer> layer)
        : pWindow(std::move(window)), pLayer(std::move(layer))
    {
        pWindow->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
    }


    void Application::Run()
    {  
        pLayer->OnAttach();
        while (mIsRunning)
        {
            pLayer->OnUpdate();
        }
        pLayer->OnDetach();
    }
    
    void Application::OnEvent(Event& event)
    {
        EventDispatcher dispatcher(event);

        dispatcher.Dispatch<WindowCloseEvent>([&isRunning = mIsRunning](WindowCloseEvent &e){ isRunning = false; });

        pLayer->OnEvent(event);
    }

}
