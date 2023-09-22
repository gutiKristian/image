#include "layer/Layer.h"
#include "events.h"
#include "glad/glad.h"
#include "glutil/ShaderProgram.h"

class DummyLayer : public core::Layer
{
    // Data are provided in NDC -- normalized device coordinates
    float data[9] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };
    
    GLuint mVbo{};
    GLuint mVao{};
    std::unique_ptr<core::ShaderProgram> pProgram;

public:
    virtual void OnAttach() override;
    virtual void OnUpdate() override;
    virtual void OnDetach() override;
    virtual void OnEvent(core::Event&) override;
    virtual void OnResize(int, int) override;
};