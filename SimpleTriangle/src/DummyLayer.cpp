#include "DummyLayer.h"

void DummyLayer::OnAttach()
{
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);

    std::filesystem::path shadersDir = R"(C:\dev\graphics\image\SimpleTriangle\shaders)";

    // Just compiled shaders
    auto vertexShader = core::Shader(shadersDir / "default.vert", GL_VERTEX_SHADER);
    auto fragmentShader = core::Shader(shadersDir / "default.frag", GL_FRAGMENT_SHADER);
    // Now create Shader Program
    pProgram = std::make_unique<core::ShaderProgram>(vertexShader, fragmentShader);
    pProgram->Use();


    glCreateBuffers(1, &mVbo);
    glNamedBufferData(mVbo, sizeof(float) * 9, data, GL_STATIC_DRAW);


    glCreateVertexArrays(1, &mVao);
    // Enabling attribute
    glEnableVertexArrayAttrib(mVao, 0);
    // Set format, how this data are stored in the buffer
    glVertexArrayAttribFormat(mVao, /*attributeIndex=*/0, /*size=*/3, /*type=*/GL_FLOAT, GL_FALSE, 0);
    // Binding buffer (mVBO) from which the data for this attribute will be taken -- here it is 0
    glVertexArrayVertexBuffer(mVao, 0, mVbo, 0, 3 * sizeof(float));
}

void DummyLayer::OnUpdate(float time)
{
    // Eventhough we have only one VAO and only one ShaderProgram we use it just to keep it clear
    glClear(GL_COLOR_BUFFER_BIT);
    pProgram->Use();
    glBindVertexArray(mVao);
    //glDrawArrays(mode, starting index in enabled array, number of indices to be rendered)
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void DummyLayer::OnDetach()
{
    glDeleteVertexArrays(1, &mVao);
    glDeleteBuffers(1, &mVbo);
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
