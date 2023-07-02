#include <iostream>
#include <filesystem>

#include "stb.h"

 int main()
 {
    std::cout << "Image\n";
    std::string imgage_path = (std::filesystem::current_path() / std::filesystem::path("images/erika.png")).string();
    
    const char *img = imgage_path.c_str();
    
    int w;
    int h;
    int comp;
    stbi_info(img, &w, &h, &comp);
    // unsigned char* image = stbi_load(img, &w, &h, &comp, STBI_grey);

    std::cout << "Width: " << w 
            << "\nHeight: " << h 
            << "\nComp: " << comp 
            << "\n";

    return 0;
 }