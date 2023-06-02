#include <systemc.h>
#include "grey_scale.h"

int sc_main(int argc, char* argv[]) {
    // Déclaration des signaux
    sc_clock CLK("CLK", 10, SC_NS);
    sc_signal<sc_uint<8>> R, G, B;
    sc_signal<sc_uint<8>> GR, GG, GB;

    // Instanciation du module ClockedImageGreyScaler
    ClockedImageGreyScaler greyScaler("greyScaler");
    greyScaler.CLK(CLK);
    greyScaler.R(R);
    greyScaler.G(G);
    greyScaler.B(B);
    greyScaler.GR(GR);
    greyScaler.GG(GG);
    greyScaler.GB(GB);

    // Simulation
    sc_start(100, SC_NS);

    return 0;
}
