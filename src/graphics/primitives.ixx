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

export namespace graphics
{

    void primitives()
    {
        std::cout << "------------------ PRIMITIVES MODULE ------------------\n";
        std::cout << "\t Write primitives such as: lines and triangles.\n";
        std::cout << "-------------------------------------------------------\n";
    }


    /**
     * Writes a line into the provided image.
     * @param p1 Starting position
     * @param p2 Ending position
     * @param img Where the line will be drawn
     * @param color Color of the drawn line
     */
    void draw_line_bresenham(Point p1, Point p2, Image& img, const Color& color)
    {
        // TODO IMPLEMENT

    }

    /**
     * Write a line using simple paramteric line equation.
     * p(t) = P + t * v
     * x = x0 + t * (x1 - x0)
     * y = y0 + t * (y1 - y0)
     * @param p1 Starting position
     * @param p2 Ending position
     * @param img Where the line will be drawn
     * @param color Color of the drawn line
     */
    void draw_line_parametric(Point p1, Point p2, Image& img, const Color& color = sf::Color::White)
    {
        // Unpack start s_[x|y] and end e_[x|y]
        const auto [x0, y0] = p1;
        const auto [x1, y1] = p2;

        int v = x1 - x0;
        int u = y1 - y0;

        for (float t = 0.0f; t <= 1.0f; t+=.001f)
        {
            int x = x0 + t * v;
            int y = y0 + t * u;
            img.setPixel(x, y, color);
        }

    }

}