#include <iostream>
#include <filesystem>

#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"


 int main()
 {

    std::filesystem::path path_to_imgs = std::filesystem::current_path() / "../../images/";
    std::string image_path = (path_to_imgs / "erika.png").string();
    


    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML", sf::Style::Close);
    ImGui::SFML::Init(window);


    sf::Image image;
    if (!(image.loadFromFile(image_path)))
    {
        std::cout << "Cannot load image";   //Load Image
    }
    
    sf::Texture texture;
    texture.loadFromImage(image);

    sf::Sprite sprite;
    sprite.setTexture(texture);    

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
        ImGui::Text("Text!");
        ImGui::End();

        window.clear();
        window.draw(sprite);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
 }