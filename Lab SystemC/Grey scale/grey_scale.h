#ifndef CLOCKED_IMAGE_GREY_SCALER_H
#define CLOCKED_IMAGE_GREY_SCALER_H

#include <systemc.h>

SC_MODULE(ClockedImageGreyScaler) {
    sc_in<bool> CLK;
    sc_in<sc_uint<8>> R, G, B;
    sc_out<sc_uint<8>> GR, GG, GB;

    void greyScaleProcess();

    SC_CTOR(ClockedImageGreyScaler);
};

#endif  // CLOCKED_IMAGE_GREY_SCALER_H