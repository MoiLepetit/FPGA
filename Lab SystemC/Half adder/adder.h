#include <systemc.h>

using namespace sc_core;
using namespace sc_dt;

SC_MODULE(Adder)
{
    sc_in<bool> A, B; // Two bits to add
    sc_out<bool> SUM, CARRY; // Out of the adder

    void add(); // Computing of the sum and the carry

    SC_CTOR(Adder);
};