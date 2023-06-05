#include <systemc.h>

using namespace sc_core;
using namespace sc_dt;

SC_MODULE(FullAdder)
{
    sc_in<bool> A, B, C;
    sc_out<bool> SUM; 
    sc_out<bool>CARRY;

    void full_add(); // Computing of the sum and the carry

    SC_CTOR(FullAdder);
};