//
// Created by krist on 19. 7. 2023.
//
module;

#include <iostream>

#include "../imgui/imgui.h"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"


export module graphics:primitives;

using Point = sf::Vector2i;
using Image = sf::Image;
using Color = sf::Color;

// C++17
namespace graphics::primitives
{
    export void primitives()
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
    export void draw_line_bresenham(Point p1, Point p2, Image& img, const Color& color)
    {
        // TODO IMPLEMENT

    }


    namespace parametric
    {
        float t = .001f;
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
    export void draw_line_parametric(Point p1, Point p2, Image& img, const Color& color = sf::Color::White)
    {
        // Unpack start s_[x|y] and end e_[x|y]
        const auto [x0, y0] = p1;
        const auto [x1, y1] = p2;

        int v = x1 - x0;
        int u = y1 - y0;

        for (float t = 0.0f; t <= 1.0f; t+=parametric::t)
        {
            int x = x0 + t * v;
            int y = y0 + t * u;

            // Make one pixel of size 3x3
            for (int i = -1; i <= 1; ++i)
            {
                for (int j = -1; j <= 1; ++j)
                {
                    img.setPixel(x - i, y - j, color);
                }
            }
        }

    }

    export void OnImGui()
    {
        ImGui::Button("Primitives");
        ImGui::SliderFloat("Parametric line t", &parametric::t, 0.001f, 0.1f, "%.3f");
    }

}