#include "impl/GlfwImpl.h"
#include "application/Application.h"
#include "SimpleShaderLayer.h"

int main()
{
    auto windowImpl = std::make_unique<core::GLFWImpl>(800, 600, "SimpleShader");
    auto window = std::make_unique<core::Window>(std::move(windowImpl));
    auto app = std::make_unique<core::Application>(
        std::move(window),
        std::make_unique<SimpleShaderLayer>()
    );

    app->Run();
    return 0;
}