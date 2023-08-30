module;

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../imgui/imgui.h"


export module Basics;

namespace vis::basics
{ 
    // We work with bit depth equal to 8, values exceeding 255 are automatically
    // clamped by sf

    /*
     Point transforms
    */
    export sf::Image brightness(const sf::Image& src, int b)
    {
        sf::Image dst;
        dst.copy(src, 0, 0);

        sf::Color c(b, 0, 0);

        auto size = dst.getSize();
        for (int i = 0; i < size.y; ++i)
        {
            for (int j = 0; j < size.x; ++j)
            {
                dst.setPixel(j, i, src.getPixel(j, i) + c);
            }
        }
        
        return dst;
    }

    export sf::Image contrast(const sf::Image& src, int c)
    {
        sf::Image dst;
        dst.copy(src, 0, 0);

        sf::Color k(b, 0, 0);

        auto size = dst.getSize();
        for (int i = 0; i < size.y; ++i)
        {
            for (int j = 0; j < size.x; ++j)
            {
                dst.setPixel(j, i, src.getPixel(j, i) * k);
            }
        }
        
        return dst;
    }

    export sf::Image gradient(const sf::Image& src)
    {
        sf::Image dst;
        dst.copy(src, 0, 0);

        // TODO implement
        return sf::Image();
    }

    export sf::Image convolution(const sf::Image& src, sf::Image kernel)
    {
        // TODO implement
        return sf::Image();
    }

    export sf::Image gradient(const sf::Image& src)
    {
        // TODO implement
        return sf::Image();
    }

    export sf::Image gradient_magnitude(const sf::Image& src)
    {
        // TODO implement
        return sf::Image();
    }

}