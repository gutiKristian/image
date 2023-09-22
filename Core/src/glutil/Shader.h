#ifndef OPENGL_SHADER_GUARD_H
#define OPENGL_SHADER_GUARD_H

#include <filesystem>
#include <iostream>
#include "glad/glad.h"

namespace core
{
    struct Shader
    {
        Shader(const std::filesystem::path& shaderPath, GLenum type);
        Shader();
        ~Shader();
        inline int GetId() const { return mId;}

    private:
        std::string LoadShader();

    private:
        GLuint mId;
        GLenum mType;
        std::filesystem::path mPath{};
    };
}


#endif