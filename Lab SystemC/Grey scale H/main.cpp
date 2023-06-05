#include <systemc.h>

#include "grey_scale.h"
#include "read_image.h"
#include "save_image.h"

int sc_main(int argc, char* argv[]) {
    // Déclaration des signaux
    sc_signal<sc_uint<8>> R, G, B;
    sc_signal<sc_uint<8>> GR, GG, GB;
    sc_signal<bool> end;

    // Instanciation du module GreyScaler
    GreyScaler greyScaler("greyScaler");
    ReadImage readImage("readImage");
    SaveImage saveImage("saveImage");

    // Output Read Image
    readImage.out_R(R);
    readImage.out_G(G);
    readImage.out_B(B);
    // Input Grey Scale
    greyScaler.R(R);
    greyScaler.G(G);
    greyScaler.B(B);
    // Output Grey Scale
    greyScaler.GR(GR);
    greyScaler.GG(GG);
    greyScaler.GB(GB);
    // Input Save Image
    saveImage.in_gr(GR);
    saveImage.in_gg(GG);
    saveImage.in_gb(GB);
    saveImage.end(end);

    end.write(false);

    while (!end)    {
        sc_start(1, SC_NS);
    }

    return 1;
}
