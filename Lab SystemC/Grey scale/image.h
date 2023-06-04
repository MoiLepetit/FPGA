#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <fstream>
#include <vector>

// Structure personnalisée pour représenter une image
struct Image {
    int width;
    int height;
    std::vector<std::vector<int>> pixels;
    std::vector<char> header;
};

// Fonction pour lire une image BMP à partir d'un fichier
bool read_image(const char* filename, Image& image);

// Fonction pour enregistrer une image dans un fichier BMP
bool save_image(const char* filename, const Image& image);

#endif // IMAGE_H
