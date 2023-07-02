#include <iostream>
#include <filesystem>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"


 int main()
 {

    std::filesystem::path path_to_imgs = std::filesystem::current_path() / "../../images/";
    std::string image_path = (path_to_imgs / "erika.png").string();
    


    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML ");
        
    sf::Image image;
    if (!(image.loadFromFile(image_path)))
    {
        std::cout << "Cannot load image";   //Load Image
    }
    
    sf::Texture texture;
    texture.loadFromImage(image);

    sf::Sprite sprite;
    sprite.setTexture(texture);    


    while (window.isOpen())
    {
            
            sf::Event event;
            
            while (window.pollEvent(event))
            {
                    if (event.type == sf::Event::Closed)
                    {
                        window.close();
                    }
            }
                    
                window.clear();
                window.draw(sprite);
                window.display();
            }

    return 0;
 }