#include <systemc.h>

using namespace sc_core;
using namespace sc_dt;

SC_MODULE(Adder)
{
    sc_in<bool> A, B;
    sc_out<bool> SUM; 
    sc_out<bool>CARRY;

    void add(); // Computing of the sum and the carry

    SC_CTOR(Adder){
        SC_METHOD(add);
        sensitive << A << B;
    }
};