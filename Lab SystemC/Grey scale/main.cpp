#include <systemc.h>
#include <iostream>
#include <fstream>
#include <vector>

#include "grey_scale.h"
#include "image.h"

int sc_main(int argc, char* argv[]) {
    // Déclaration des signaux
    //sc_clock CLK("CLK", 1, SC_NS);
    //sc_signal<bool> CLK;
    sc_signal<sc_uint<8>> R, G, B;
    sc_signal<sc_uint<8>> GR, GG, GB;

    // Instanciation du module GreyScaler
    GreyScaler greyScaler("greyScaler");
    greyScaler.R(R);
    greyScaler.G(G);
    greyScaler.B(B);
    greyScaler.GR(GR);
    greyScaler.GG(GG);
    greyScaler.GB(GB);

    // Lire une image depuis un fichier
    cout << "Read image : " << endl;
    const char* filename = "img/what.bmp";
    Image image;
    if (!read_image(filename, image)) {
        std::cerr << "Impossible to read the image file." << std::endl;
        return 1;
    }

    // Convert the image to grayscale
    cout << "Convert the image" << endl;
    cout << "Height : " << image.height << endl;
    cout << "Width : " << image.width << endl;
    std::vector<std::vector<int>> grayscale_image;
    grayscale_image.resize(image.height, std::vector<int>(image.width * 3));
    int counter = 0;
    for (int y = 0; y < image.height; y++) {
        for (int x = 0; x < image.width * 3 ; x = x + 3) {
            R.write(image.pixels[y][x]);
            G.write(image.pixels[y][x+1]);
            B.write(image.pixels[y][x+2]);
            sc_start(1, SC_NS);  // Wait 1 unit of time
            grayscale_image[y][x] = GR.read();
            grayscale_image[y][x+1] = GG.read();
            grayscale_image[y][x+2] = GB.read();
            //cout << "Tour : " << counter << endl;
            //cout << "Red : " << image.pixels[y][x] << endl;
            //cout << "Green : " << image.pixels[y][x+1] << endl;
            //cout << "Blue : " << image.pixels[y][x+2] << endl;
            //cout << "Grey : " << GR.read() << endl;
            //cout << endl;
            //counter++;
        }
    }
    cout << "Counter : " << counter << endl;

    // Enregistrer l'image dans un fichier BMP
    cout << "Save image color: " << endl;
    const char* new_filename = "img/copy.bmp";
    if (!save_image(new_filename, image)) {
        std::cerr << "Impossible to save the image file." << std::endl;
        return 1;
    }

    // Enregistrer l'image dans un fichier BMP
    cout << "Save image grey: " << endl;
    new_filename = "img/grey.bmp";
    image.pixels = grayscale_image;
    if (!save_image(new_filename, image)) {
        std::cerr << "Impossible to save the image file." << std::endl;
        return 1;
    }

    return 0;
}
