#include "SimpleShaderLayer.h"

void SimpleShaderLayer::OnAttach()
{
    std::filesystem::path shadersDir = R"(C:\dev\graphics\image\SimpleShader\shaders)";

    // Just compiled shaders
    auto vertexShader = core::Shader(shadersDir / "default.vert", GL_VERTEX_SHADER);
    auto fragmentShader = core::Shader(shadersDir / "default.frag", GL_FRAGMENT_SHADER);
    // Now create Shader Program
    pProgram = std::make_unique<core::ShaderProgram>(vertexShader, fragmentShader);
    pProgram->Use();

    glCreateBuffers(1, &mVbo);
    glNamedBufferData(mVbo, sizeof(float) * 9, data, GL_STATIC_DRAW);

    glCreateVertexArrays(1, &mVao);
    glEnableVertexArrayAttrib(mVao, 0);
    glVertexArrayAttribFormat(mVao, 0, 3, GL_FLOAT, GL_FALSE, 0);
    glVertexArrayVertexBuffer(mVao, 0, mVbo, 0, sizeof(float) * 3);

}

void SimpleShaderLayer::OnUpdate(float time)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    addTim += time;

    float val = (std::sin(addTim) / 2.0f) + 0.5f;
    // Retrieve unifrom location
    int uniformColorLoc = glGetUniformLocation(pProgram->GetId(), "triangleColor");
    pProgram->Use();
    
    // Set the uniform
    glUniform4f(uniformColorLoc, 0.5f, val, 0.3f, 1.0f);

    glBindVertexArray(mVao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void SimpleShaderLayer::OnDetach()
{
}

void SimpleShaderLayer::OnEvent(core::Event &)
{
}

void SimpleShaderLayer::OnResize(int, int)
{
}
