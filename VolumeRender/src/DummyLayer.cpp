#include "DummyLayer.h"

void DummyLayer::OnAttach()
{
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);

    std::filesystem::path shadersDir = R"(C:\dev\graphics\image\VolumeRender\shaders)";

    // Just compiled shaders
    auto vertexShader = core::Shader(shadersDir / "default.vert", GL_VERTEX_SHADER);
    auto fragmentShader = core::Shader(shadersDir / "default.frag", GL_FRAGMENT_SHADER);
    // Now create Shader Program
    pProgram = std::make_unique<core::ShaderProgram>(vertexShader, fragmentShader);
    pProgram->Use();


    glCreateBuffers(1, &mVbo);
    glNamedBufferData(mVbo, sizeof(float) * 9, data, GL_STATIC_DRAW);
    

    glCreateVertexArrays(1, &mVao);
    glVertexArrayVertexBuffer(mVao, 0, mVbo, 0, 3 * sizeof(float));
    glEnableVertexArrayAttrib(mVao, 0);
    glVertexArrayAttribFormat(mVao, 0, 3, GL_FLOAT, GL_FALSE, 0);
    
}

void DummyLayer::OnUpdate()
{
    // Eventhough we have only one VAO and only one ShaderProgram we use it just to keep it clear
    glClear(GL_COLOR_BUFFER_BIT);
    pProgram->Use();
    glBindVertexArray(mVao);
    glDrawArrays(GL_TRIANGLES, 0, 3);

}

void DummyLayer::OnDetach()
{
}

void DummyLayer::OnEvent(core::Event &e)
{
    core::EventDispatcher dispatcher(e);

    dispatcher.Dispatch<core::WindowResizeEvent>([](core::WindowResizeEvent &e) 
        { 
            std::cout << e.w << " , " << e.h << "\n";
            glViewport(0, 0, e.w, e.h); 
        }
    );
}

void DummyLayer::OnResize(int w, int h)
{
}
