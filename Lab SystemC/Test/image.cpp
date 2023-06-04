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
        for (int y = image.height - 1; y >= 0; y--) {
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
        for (int y = image.height - 1; y >= 0; y--) {
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

bool save_image_grey(const char* filename, const Image& image){
    // Ouvrir un fichier de sortie en mode binaire
    // Calculer la taille du fichier de sortie
    int file_size = image.header.size() + image.width * image.height;

    // Modifier les champs du header nécessaires pour une image en nuance de gris
    *(int*)&image.header[28] = 1; // bitsPerPixel = 1
    *(int*)&image.header[30] = 0; // pas de compression
    *(int*)&image.header[34] = file_size & 0xFF;
    *(int*)&image.header[35] = (file_size >> 8) & 0xFF;
    *(int*)&image.header[36] = (file_size >> 16) & 0xFF;
    *(int*)&image.header[37] = (file_size >> 24) & 0xFF;
    *(int*)&image.header[38] = 0; // xResolution
    *(int*)&image.header[39] = 0; // xResolution
    *(int*)&image.header[40] = 0; // yResolution
    *(int*)&image.header[41] = 0; // yResolution
    *(int*)&image.header[42] = 0; // colorsUsed
    *(int*)&image.header[43] = 0; // colorsUsed
    *(int*)&image.header[44] = 0; // colorsImportant
    *(int*)&image.header[45] = 0; // colorsImportant
    
    std::ofstream output_file(filename, std::ios::out | std::ios::binary);
    if(!output_file){
        std::cerr << "Erreur : impossible d'ouvrir le fichier " << filename << std::endl;
        return false;
    }

    // Écrire le header et les pixels de l'image
    output_file.write(image.header.data(), image.header.size());
    for(int i = 0 ; i < image.height ; i++){
        for(int j = 0 ; j < image.width * 3 ; j = j + 3){
            // Convertir chaque pixel couleur en nuance de gris
            int pixel_grey = 0.3 * image.pixels[i][j] + 0.59 * image.pixels[i][j+1] + 0.11 * image.pixels[i][j+2];
            // Écrire le pixel gris dans le fichier de sortie
            output_file.write(reinterpret_cast<const char*>(&pixel_grey), 1);
        }
    }

    // Fermer le fichier de sortie
    output_file.close();
    return true;
}


int main() {
    // Lire une image depuis un fichier
    const char* filename = "cat.bmp";
    Image image;
    if (!read_image(filename, image)) {
        std::cerr << "Impossible de lire le fichier image." << std::endl;
        return 1;
    }

    // Enregistrer l'image dans un fichier BMP
    const char* new_filename = "result.bmp";
    if (!save_image(new_filename, image)) {
        std::cerr << "Impossible d'enregistrer l'image." << std::endl;
        return 1;
    }

    return 0;
}
