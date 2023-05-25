#include "adder.h"

void Adder::add()
{
    SUM.write(A.read() ^ B.read()); // Computing of the sum
    CARRY.write(A.read() & B.read() ); // Computin of the carry
}