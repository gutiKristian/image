#include "Implementation.h"
#include <GLFW/glfw3.h>

namespace core
{
    class GLFWImpl : public Implementation
    {
    public:
        GLFWImpl(int, int, std::string);
        ~GLFWImpl() override;

        void CreateWindow() override;
        void OnUpdate() override;
        
    private:
        GLFWwindow* pWindow = nullptr;
    };
}