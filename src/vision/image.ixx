module;

#include <glad/glad.h>
#include "../stb.h"
#include <filesystem>

export module image;

using DataPtr = unsigned char *;

export struct Image
{
    
    float *data;
    GLuint tex;
    int mWidth, mHeight, mChannels;

    Image(const std::filesystem::path path)
    {
        // These data are send to the gpu and displayed as default image
        mLoadData = stbi_load(path.generic_string().data(), &mWidth, &mHeight, &mChannels, 0);
        // These data are edited
        data = new float[width * height];
        for (size_t i = 0; i < mWidth * mHeight; ++i)
        {
            data[i] = static_cast<float>(mLoadData[i]);
        }

        glGenTextures(1, &tex);
        glBindTexture(tex);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, mWidth, mHeight, 0, GL_RED, GL_UNSIGNED_BYTE, mLoadData);


        // Release the old data
        stbi_image_free(mLoadData);

    }

    Image(int width, int height, float initialValue = 0.0f) : mWidth(width), mHeight(height)
    {
        data = new float[width * height];
        SetValue(initialValue);
    }

    ~Image()
    {
        delete[] data;
    }

    float& operator()(int x, int y)
    {
        if (x < 0 || x >= mWidth || y >= mHeight || y < 0)
        {
            throw std::exception();
        }

        return *(data + mWidth * y + x);
    }

    void SetVaule(float val)
    {
        for (size_t i = 0; i < mWidth * mHeight; ++i)
        {
            data[i] = val;
        }
    }

private:
    DataPtr *mLoadData;
}