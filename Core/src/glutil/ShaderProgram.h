#ifndef OPENGL_SHADER_PROGRAM_GUARD_H
#define OPENGL_SHADER_PROGRAM_GUARD_H

#include <filesystem>
#include <iostream>
#include "Shader.h"

namespace core
{
    struct ShaderProgram
    {

        /**
         * Initializes the ShaderProgram using paths. Shader objects are constructed and ShaderProgram(Shader, Shader)
         * ctor is called.
         *
         * @param vertexShader      Path to this file.
         * @param fragmentShader    Path to this file.
         */
        ShaderProgram(const std::filesystem::path& vertexShader, const std::filesystem::path& fragmentShader);

        /**
         * Initializes ShaderProgram with provided Shaders.
         * @param vertex
         * @param fragment
         */
        ShaderProgram(Shader vertex, Shader fragment);

        /**
         * Getter for mProgram ID.
         * @return Id of the mProgram.
         */
        inline GLuint GetId() const { return mProgram; }

        /**
         * Whether there was an error while creating a mProgram.
         * @return True if the mProgram is valid, False otherwise.
         */
        inline GLuint IsValid() const { return mStatus; }

        /**
         * This activates the mProgram in OpenGL.
         */
        void Use() const;

    private:
        /**
         * Initializes the mProgram, it's always called when we create ShaderProgram, therefore
         * OpenGL context must be initialized.
         */
        ShaderProgram();

        /**
         * ID of the mProgram.
         */
        GLuint mProgram;

        /**
         * Status of the mProgram.
         */
        bool mStatus;

        /**
         * In the future we might use more than two default shaders (e.g. Tesselation, Geometry).
         */
        std::vector<Shader> mShaders;

    };


}

#endif