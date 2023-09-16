module;

#include "../stb.h"
#include <filesystem>

export module image;

using DataPtr = unsigned char *;

template<typename T>
export struct Image
{
    
    T *data;
    int mWidth, mHeight, mChannels;

    Image(const std::filesystem::path path)
    {
        mLoaddata = stbi_load(path.generic_string().data(), &mWidth, &mHeight, &mChannels, 0);
        for (size_t i = 0; i < mWidth * mHeight; ++i)
        {
            data[i] = static_cast<T>(mLoaddata[i]);
        }
        // Release the old data
        stbi_image_free(mLoaddata);

    }

    Image(int width, int height, T initialValue) : mWidth(width), mHeight(height)
    {
        data = new T[width * height];
        SetValue(initialValue);
    }

    ~Image()
    {
        delete[] data;
    }

    T& operator()(int x, int y)
    {
        if (x < 0 || x >= mWidth || y >= mHeight || y < 0)
        {
            throw std::exception();
        }

        return *(data + mWidth * y + x);
    }

    void SetVaule(T val)
    {
        for (size_t i = 0; i < mWidth * mHeight; ++i)
        {
            data[i] = val;
        }
    }

private:
    DataPtr *mLoaddata;
}