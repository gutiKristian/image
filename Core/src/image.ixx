module;

#include <glad/glad.h>
#include "../stb.h"
#include <filesystem>
#include <iostream>

export module image;

export struct Image
{
    
    float *data;
    int mWidth, mHeight, mChannels;

    Image(const std::filesystem::path path)
    {
        // These data are send to the gpu and displayed as default image
        mLoadData = stbi_load(path.generic_string().data(), &mWidth, &mHeight, &mChannels, 0);
        // These data are edited
        data = new float[mWidth * mHeight];
        for (size_t i = 0; i < mWidth * mHeight; ++i)
        {
            data[i] = static_cast<float>(mLoadData[i]);
        }
        
    }

    Image(int width, int height, float initialValue = 0.0f) : mWidth(width), mHeight(height), mChannels(0)
    {
        data = new float[mWidth * mHeight];
        SetValue(initialValue);
    }

    ~Image()
    {
        stbi_image_free(mLoadData);
		delete[] data;
    }

    Image(const Image& other) // copy constructor
    {
		std::memcpy(data, other.data, sizeof(float) * mWidth*mHeight);
        mWidth = other.mWidth;
        mHeight = other.mHeight;
        mChannels = other.mChannels;
    }

    Image(Image&& other) noexcept // move constructor
    {
        data = std::exchange(other.data, nullptr);
    }

    Image& operator=(const Image& other) // copy assignment
    {
        return *this = Image(other);
    }

    Image& operator=(Image&& other) noexcept // move assignment
    {
        std::swap(data, other.data);
        return *this;
    }

    float& operator()(int x, int y)
    {
        if (x < 0 || x >= mWidth || y >= mHeight || y < 0)
        {
            throw std::exception();
        }

        return *(data + mWidth * y + x);
    }

    void SetValue(float val)
    {
        for (std::size_t i = 0; i < mWidth * mHeight; i++)
        {
            data[i] = val;
        }
    }
	
	const unsigned char* GetLoadedData(bool update)
	{
		if (update)
		{
			std::cout << "Casting to uchar, carefull if your image contains negative values!\n";
			for (std::size_t i = 0; i < mWidth * mHeight; ++i)
			{
				mLoadData[i] = static_cast<unsigned char>(data[i]);
			}
		
		}
		
		return mLoadData;
	}

    // It is up to user to manage textures
    static GLuint CreateTexture(const Image& img, bool updateImage = false)
    {
        GLuint tex;
        glGenTextures(1, &tex);
        glBindTexture(GL_TEXTURE_2D, tex);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, img.mWidth, img.mHeight, 0, GL_RED, GL_UNSIGNED_BYTE, img.GetLoadedData(updateImage));
        return tex;
    }

private:
    unsigned char *mLoadData = nullptr;
};
