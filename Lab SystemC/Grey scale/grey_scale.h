#include <systemc.h>

SC_MODULE(GreyScaler) {
    sc_signal<bool> CLK;
    sc_in<sc_uint<8>> R, G, B;
    sc_out<sc_uint<8>> GR, GG, GB;

    void clock();
    void greyScaleProcess();

    SC_CTOR(GreyScaler);
};