module;

#include "../stb.h"
#include <filesystem>

export module image;

export struct Image
{
    
    unsigned char *data;
    int mWidth, mHeight, mChannels;

    Image(const std::filesystem::path path)
    {
        stbi_load(path.generic_string().data(), &mWidth, &mHeight, &mChannels, 0);
        mStbiLoad = true;
    }

    Image(int width, int height) : mWidth(width), mHeight(height)
    {
        data = new unsigned char[width * height];
    }

    ~Image()
    {
        if (mStbiLoad)
            stbi_image_free(data);
        else
            delete[] data;
    }

private:
    bool mStbiLoad = false;

}