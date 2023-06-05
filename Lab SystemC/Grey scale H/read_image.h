#include <systemc.h>
#include "image.h"

SC_MODULE(ReadImage) {
    sc_out<sc_uint<8>> out_R, out_G, out_B;

    void send_data(){
        std::cerr << "Read data" << std::endl;
        const char* filename = "img/cat.bmp";
        Image image;

        if (!read_image(filename, image)) {
            std::cerr << "Impossible to read the image file." << std::endl;
        }   

        for (int y = 0; y < image.height; y++) {
            for (int x = 0; x < image.width * 3 ; x = x + 3) {
                out_R.write(image.pixels[y][x]);
                out_G.write(image.pixels[y][x+1]);
                out_B.write(image.pixels[y][x+2]);
                //std::cerr << "Send data" << std::endl;
                wait(1, SC_NS);
            }
        }
        std::cerr << "Finish send data" << std::endl;
    }

    SC_CTOR(ReadImage){
        SC_THREAD(send_data);
    }
};