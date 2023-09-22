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

import image;

#define CallbackFn std::function<void(int8_t)>

namespace core
{

    /*
        Abstractions
    */




    export struct VisionApplication
    {
        VisionApplication(std::string &&name, std::unique_ptr<Window> window, Image&& img) : mName(name), pWindow(std::move(window)), mImg(img)
        {
            pWindow->SetEventCallback(std::bind(&VisionApplication::OnEvent, this, std::placeholders::_1));
        }

        // VisionApplication(std::string &&name, std::unique_ptr<Window> window) : mName(name), pWindow(std::move(window))
        // {
        //     pWindow->SetEventCallback(std::bind(&VisionApplication::OnEvent, this, std::placeholders::_1));
        // }
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
            //case EVENT_RELOAD_IMAGE
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

            Image mImg;

            std::string mName;
            std::unique_ptr<Window> pWindow;
    };

    


    /*
     *  Application that manages window and layer.
    */
    export class OpenGLApplication
    {
    private:
        bool mIsRunning = true;
    protected:
        std::unique_ptr<Window> pWindow;
        std::unique_ptr<Layer> pLayer;
    public:

        explicit OpenGLApplication(std::unique_ptr<Window> window) : pWindow(std::move(window))
        {
            // Common
            pWindow->SetEventCallback(std::bind(&OpenGLApplication::OnEvent, this, std::placeholders::_1));
        }

        void Run()
        {
            while(mIsRunning)
            {
                pLayer->OnUpdate();
                pWindow->OnUpdate();
            }
        }

        void OnClose()
        {
            pLayer->OnDetach();
            mIsRunning = false;
        }

        void OnEvent(int8_t e)
        {
            switch (e)
            {
                case EVENT_CLOSE:
                    OnClose();
                    break;
                case EVENT_RESIZE:
                    pLayer->OnResize(pWindow->GetWidth(), pWindow->GetHeight());
                    break;
                default:
                    pLayer->OnEvent(e);
                    break;
            }

        }

    };
}
