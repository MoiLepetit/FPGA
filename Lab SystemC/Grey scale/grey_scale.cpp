#include "grey_scale.h"

void ClockedImageGreyScaler::greyScaleProcess() {
    while (true) {
        wait(); // Attente d'un front d'horloge positif

        // Conversion en niveaux de gris (formule simple : moyenne des composantes R, G et B)
        sc_uint<8> grey = (R.read() + G.read() + B.read()) / 3;

        // Affectation des niveaux de gris à chaque composante
        GR.write(grey);
        GG.write(grey);
        GB.write(grey);
    }
}

ClockedImageGreyScaler::ClockedImageGreyScaler(sc_module_name name)
    : sc_module(name) {
    SC_THREAD(greyScaleProcess);
    sensitive << CLK.pos();
}
