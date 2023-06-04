#include "image.h"

// Fonction pour lire une image BMP à partir d'un fichier
bool read_image(const char* filename, Image& image) {
    std::ifstream file(filename, std::ios::binary);
    if (file) {
        // Lire l'en-tête du fichier BMP (54 octets)
        image.header.resize(54);
        file.read(image.header.data(), 54);

        // Extraire la largeur et la hauteur de l'image à partir de l'en-tête
        image.width = *(int*)&image.header[18];
        image.height = *(int*)&image.header[22];

        // Calculer la taille des données de l'image (chaque pixel utilise 3 octets)
        int dataSize = image.width * image.height * 3;

        // Allouer un tampon pour stocker les données de l'image
        std::vector<char> buffer(dataSize);

        // Lire les données de l'image
        file.read(buffer.data(), dataSize);

        // Convertir les données brutes en une structure de pixels
        image.pixels.resize(image.height, std::vector<int>(image.width * 3));
        int index = 0;
        for (int y = 0; y < image.height; y++) {
            for (int x = 0; x < image.width * 3; x++) {
                image.pixels[y][x] = static_cast<unsigned char>(buffer[index++]);
            }
        }

        file.close();
        return true;
    } else {
        std::cerr << "Impossible to open the image file." << std::endl;
        return false;
    }
}

// Fonction pour enregistrer une image dans un fichier BMP
bool save_image(const char* filename, const Image& image) {
    std::ofstream file(filename, std::ios::binary);
    if (file) {
        // Écrire l'en-tête du fichier BMP
        file.write(image.header.data(), 54);

        // Écrire les données de l'image (en inversant l'ordre des pixels pour chaque ligne)
        for (int y = 0; y < image.height; y++) {
            for (int x = 0; x < image.width * 3; x++) {
                file.write(reinterpret_cast<const char*>(&image.pixels[y][x]), sizeof(unsigned char));
            }
        }

        file.close();
        return true;
    } else {
        std::cerr << "Impossible to save the image file." << std::endl;
        return false;
    }
}