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
        export bool redraw = false;
        float t = .001f;
        int x0 = 100;
        int y0 = 100;
        int x1 = 1000;
        int y1 = 700;
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
    export void draw_line_parametric(Image& img, const Color& color = sf::Color::White)
    {
        using namespace parametric;

        int v = x1 - x0;
        int u = y1 - y0;

        for (float _t = 0.0f; _t <= 1.0f; _t+=t)
        {
            int x = x0 + _t * v;
            int y = y0 + _t * u;

            img.setPixel(x, y, color);
        }

        redraw = true;
    }

    export void OnImGui()
    {
        ImGui::Button("Primitives");
        parametric::redraw = ImGui::SliderFloat("Parametric line t", &parametric::t, 0.001f, 0.1f, "%.3f") |
                ImGui::SliderInt("X0", &parametric::x0, 0, 1279) | ImGui::SliderInt("Y0", &parametric::y0, 0, 719);
    }

}