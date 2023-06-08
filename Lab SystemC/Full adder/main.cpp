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

    // TraceFile
    sc_trace_file* tracefile = sc_create_vcd_trace_file("tracefile");
    sc_trace(tracefile, a, "a");
    sc_trace(tracefile, b, "b");
    sc_trace(tracefile, c, "c");
    sc_trace(tracefile, sum, "sum");
    sc_trace(tracefile, carry, "carry");
    
    // Simulation
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            for (int k = 0; k <= 1; k++) {
                // Init test simulation
                a = i;
                b = j;
                c = k;
                sc_start(1, SC_NS);
                cout << "c =   " << c << endl;
                cout << "a =   " << a << endl;
                cout << "b =   " << b << endl;
                cout << "+------" << endl;
                cout << "s = " << carry << " " << sum << endl;
                cout << endl;
            }
        }
    }
    
    // Cleanup
    sc_close_vcd_trace_file(tracefile);

    return 0; 
}