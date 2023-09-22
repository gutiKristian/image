#include "ShaderProgram.h"

namespace core
{
    ShaderProgram::ShaderProgram(const std::filesystem::path& vertexShader, const std::filesystem::path& fragmentShader)
        :ShaderProgram(Shader(vertexShader, GL_VERTEX_SHADER),
                       Shader(fragmentShader, GL_FRAGMENT_SHADER))
    {
    }

    ShaderProgram::ShaderProgram(Shader vertex, Shader fragment)
        :ShaderProgram()
    {
        if (!mProgram)
        {
            std::cout << "Error while creating ShaderProgram, invalid mProgram!!!\n";
        }

        mShaders.push_back(vertex);
        mShaders.push_back(fragment);

        // Check if GetId returns non-zero, then proceed? -- we already log such thing inside Shader

        glAttachShader(mProgram, vertex.GetId());
        glAttachShader(mProgram, fragment.GetId());

        glLinkProgram(mProgram);
        int link;
        glGetProgramiv(mProgram, GL_LINK_STATUS, &link);

        if (link == GL_FALSE)
        {
            mStatus = false;
        }
        else
        {
            mStatus = true;
        }

    }

    ShaderProgram::ShaderProgram()
    {
        mProgram = glCreateProgram();
        mStatus = false;
    }

    void ShaderProgram::Use() const
    {
        if (!IsValid())
        {
            std::cout << "Cannot use invalid mProgram.\n";
        }
        else
        {
            glUseProgram(mProgram);
        }
    }

}