#include "adder.h"

void Adder::add()
{
    SUM.write(A.read() ^ B.read()); // Computing of the sum with a XOR
    CARRY.write(A.read() & B.read() ); // Computin of the carry with a AND
}

Adder::Adder(sc_module_name name)
    : sc_module(name) {
    SC_METHOD(add); // Execute add() when A and B change
        sensitive << A << B;
}
