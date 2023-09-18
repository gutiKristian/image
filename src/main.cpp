#include <iostream>
#include <filesystem>

import core;
import image;


int main()
{
    auto window = std::make_unique<core::Window>(std::make_unique<core::GLFWImpl>());
    auto app = std::make_unique<core::VisionApplication>("Vision", std::move(window), Image(50, 50));
    
    app->Run();

    return 0;
}
