#include <iostream>
#include <filesystem>

import core;


int main()
{
    auto window = std::make_unique<core::Window>(std::make_unique<core::GLFWImpl>());
    auto app = std::make_unique<core::VisionApplication>("Vision", std::move(window));
    
    app->Run();

    return 0;
}
