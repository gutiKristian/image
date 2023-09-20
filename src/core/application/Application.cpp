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
    
    void Application::OnEvent(int event)
    {
        if (event == EVENT_CLOSE)
        {
            mIsRunning = false;
            return;
        }

        pLayer->OnEvent(event);
    }

}
