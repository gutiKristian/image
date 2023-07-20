//
// Created by krist on 19. 7. 2023.
//
module;

#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"


export module graphics:primitives;

using Point = sf::Vector2i;
using Image = sf::Image;
using Color = sf::Color;

namespace graphics
{
    /**
     * Writes a line into the provided image.
     * @param p1 Starting position
     * @param p2 Ending position
     * @param img Where the line will be drawn
     * @param color Color of the drawn line
     */
    export void draw_line_bresenham(Point p1, Point p2, Image& img, const Color& color)
    {
        // TODO IMPLEMENT

    }
}