#include "full_adder.h"

void FullAdder::full_add()
{
    // Compute of SUM
    bool xor_tmp1 = A.read() ^ B.read(); //XOR
    bool xor_tmp2 = xor_tmp1 ^ C.read(); //XOR
    SUM.write(xor_tmp2);
    // Compute of the CARRY
    bool and_tmp1 = xor_tmp1 & C.read(); //AND
    bool and_tmp2 = A.read() & B.read(); //AND
    bool or_tmp1 = and_tmp1 | and_tmp2; //OR
    CARRY.write(or_tmp1); 
}

FullAdder::FullAdder(sc_module_name name)
    : sc_module(name) {
    SC_METHOD(full_add); // Execute add() when A, B and C change
        sensitive << A << B << C;
}