#include <systemc.h>
#include "adder.h"

int sc_main(int argc, char *args[])
{
    // Init signal in and out
    sc_signal<bool> a, b, sum, carry;
    // Init adder
    Adder adder("add");
    adder.A(a);
    adder.B(b);
    adder.SUM(sum);
    adder.CARRY(carry);
    
    // Simulation
    sc_trace_file* tracefile = sc_create_vcd_trace_file("tracefile");
    sc_trace(tracefile, a, "a");
    sc_trace(tracefile, b, "b");
    sc_trace(tracefile, sum, "sum");
    sc_trace(tracefile, carry, "carry");

    // Run simulation for all input combinations
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            a = i;
            b = j;

            sc_start(1, SC_NS);

            cout << "a =   " << a << endl;
            cout << "b =   " << b << endl;
            cout << "+------" << endl;
            cout << "s = " << carry << " " << sum << endl;
            cout << endl;

            // Assertions
            assert(sum == (i ^ j));
            assert(carry == (i && j));
        }
    }

    // Cleanup
    sc_close_vcd_trace_file(tracefile);

    return 0; 
}