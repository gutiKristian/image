#include <iostream>
#include <filesystem>

#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

import graphics;
import vision;

/**
 * Object of global buffer, helps us abstract the variables that are
 * used to draw images that are being created onto the screen.
 * I didn't put sf::Image there so it is easier to work with multiple
 * images and by just calling write_image we display what we want.
 */
struct GlobalBuffer
{

    std::unique_ptr<sf::Texture> p_texture = std::make_unique<sf::Texture>();
    std::unique_ptr<sf::Sprite> p_sprite = std::make_unique<sf::Sprite>();

    static GlobalBuffer& GetInstance()
    {
        static GlobalBuffer instance;
        return instance;
    }

    /**
     * When working with images, we do the operations on them (they are stored in RAM)
     * and then, show them, update is expensive since the
     * data has to be moved to the GPU VRAM --- (not that it matters here, but this is a sidenote)
     * @param img Image that is being moved to GPU and displayed
     */
    void write_image(const sf::Image& img)
    {
        p_texture->loadFromImage(img);
        p_sprite->setTexture(*p_texture);
    }

    /**
     * Prefer buffer.draw() to *buffer.p_sprite
     * @return Constant reference to sprite object
     */
    sf::Sprite const& draw() const
    {
        return *p_sprite;
    }

    GlobalBuffer(const GlobalBuffer&) = delete;
    void operator=(const GlobalBuffer&)  = delete;

private:
    GlobalBuffer() = default;

};


void OnImgui()
{
    // graphics::primitives::OnImGui();
}

int main()
{
    GlobalBuffer& buffer = GlobalBuffer::GetInstance();


    const int WIDTH = 1280;
    const int HEIGHT = 720;


    std::filesystem::path path_to_imgs = std::filesystem::current_path() / "../images/";
    std::string image_path = (path_to_imgs / "erika.png").string();

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML", sf::Style::Close);
    ImGui::SFML::Init(window);   

    // Canvas for graphics, this is a buffer that is modified and written on
    sf::Image canvas;
    canvas.create(WIDTH, HEIGHT, sf::Color::Black);

     // Image for vision -- ignored for now
    if (!(canvas.loadFromFile(image_path)))
    {
        std::cout << "Cannot load image";   //Load Image
    }
    
    sf::Image new_image = vis::basics::contrast(canvas, 1);
    sf::Texture new_tex;
    new_tex.loadFromImage(new_image);
    sf::Sprite new_sprite(new_tex);


    // Display the buffer
    buffer.write_image(canvas);

    // Main loop
    sf::Clock delta_clock;
    while (window.isOpen())
    {

        sf::Event event;

        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        
        ImGui::SFML::Update(window, delta_clock.restart());
        ImGui::Begin("Image");
        OnImgui();
        ImGui::End();
        // if (graphics::primitives::parametric::redraw)
        // {
        //     // Reset canvas
        //     canvas.create(canvas.getSize().x, canvas.getSize().y, sf::Color::Black);
        //     // Redraw parametric line
        //     graphics::primitives::draw_line_parametric(canvas);
        //     // Update buffer
        //     buffer.write_image(canvas);
        //     graphics::primitives::parametric::redraw = false;
        // }


        window.clear();
        window.draw(buffer.draw()); // Render buffer(image that has been modified)
        new_sprite.setPosition(buffer.p_texture->getSize().x + 10, 0);
        window.draw(new_sprite);
        ImGui::SFML::Render(window); // Render UI
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}
