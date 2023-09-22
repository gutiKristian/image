#include <fstream>
#include <string>
#include "Shader.h"

namespace core
{

    Shader::Shader(const std::filesystem::path& path, GLenum type) : mPath(path), mType(type)
    {
        std::string sourceCode = LoadShader();
        // glCreateShader takes the type of the shader we want to create
        mId = glCreateShader(type);
        const char *source = sourceCode.c_str();

        // Then we link this shader with source code, we send it as a one chunk
        glShaderSource(mId, 1, &source, nullptr);

        glCompileShader(mId);

        int status;
        glGetShaderiv(mId, GL_COMPILE_STATUS, &status);

        if (status == GL_TRUE)
        {
            return;
        }

        // Fail!
        switch (type)
        {
            case GL_VERTEX_SHADER:
                std::cout << "Failed to compile Vertex shader\n";
                break;
            case GL_FRAGMENT_SHADER:
                std::cout << "Failed to compile Fragment shader\n";
                break;
            default:
                // will add another types as we are going to work with them
                std::cout << "Failed to compile shader\n";
                break;
        }

        glDeleteShader(mId);
        mId = 0;

    }

    std::string Shader::LoadShader()
    {
        std::ifstream stream(mPath);
        std::string source;

        if (!stream.is_open())
        {
            std::cout << "Couldn't open file: " <<  mPath.string() << "\n";
            return source;
        }

        std::string line;
        while(std::getline(stream, line))
        {
            source += line + '\n';
        }

        return source;
    }

    Shader::Shader()
    {
        mId = 0;
    }

    Shader::~Shader()
    {
        glDeleteShader(mId);
    }

}