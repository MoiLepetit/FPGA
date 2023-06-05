#include "grey_scale.h"

void GreyScaler::greyScaleProcess() {
    // Conversion en niveaux de gris (formule simple : moyenne des composantes R, G et B)
    ////std::cerr << "Convert data" << std::endl;
    sc_uint<8> grey = (R.read() + G.read() + B.read()) / 3;

    // Affectation des niveaux de gris à chaque composante
    GR.write(grey);
    GG.write(grey);
    GB.write(grey);
}

void GreyScaler::clock() {
    while (true) {
        CLK.write(!CLK.read());
        wait(1, SC_NS) ;
    }
}

GreyScaler::GreyScaler(sc_module_name name)
    : sc_module(name) {
    SC_THREAD(clock);
    SC_METHOD(greyScaleProcess);
        sensitive << CLK;
    CLK.write(0);
}
