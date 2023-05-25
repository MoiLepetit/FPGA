#include <systemc.h>
#include "full_adder.h"

int sc_main(int argc, char *args[])
{
    // Init signal in and out
    sc_signal<bool> a, b, c, sum, carry;
    // Init adder
    FullAdder full_adder("add");
    full_adder.A(a);
    full_adder.B(b);
    full_adder.C(c);
    full_adder.SUM(sum);
    full_adder.CARRY(carry);
    
    // Init test simulation
    a = 1;
    b = 1;
    c = 1;
    sc_start(1, SC_NS);
    cout << "SUM = " << sum << ", CARRY = " << carry << endl;

    return 0; 
}