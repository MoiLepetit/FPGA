#include <systemc.h>
#include "image.h"

SC_MODULE(SaveImage) {
    sc_in<sc_uint<8>> in_gr, in_gg, in_gb;
    sc_out<bool> end;

    void save_data(){
        std::cerr << "Save data" << std::endl;
        const char* filename = "img/cat.bmp";
        Image image;
        read_image(filename, image);

        std::vector<std::vector<int>> grayscale_image;
        grayscale_image.resize(image.height, std::vector<int>(image.width * 3));

        while (true) {
            for (int y = 0; y < image.height; y++) {
                for (int x = 0; x < image.width * 3 ; x = x + 3) {
                    grayscale_image[y][x] = in_gr.read();
                    grayscale_image[y][x+1] = in_gg.read();
                    grayscale_image[y][x+2] = in_gb.read();
                    wait(1, SC_NS);
                }
            }

            end.write(true);
            const char* new_filename = "img/grey.bmp";
            image.pixels = grayscale_image;
            if (!save_image(new_filename, image)) {
                std::cerr << "Impossible to save the image file." << std::endl;
            }
        }
        std::cerr << "Finish save data" << std::endl;
    }

    SC_CTOR(SaveImage){
        SC_THREAD(save_data);
    }
};