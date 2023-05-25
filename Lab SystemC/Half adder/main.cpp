#include <systemc.h>
#include "adder.h"

SC_MODULE(Try)
{
    sc_out<bool> a,b;
    sc_in<bool> sum, carry;

    void test()
    {
        a.write(0);
        b.write(0);

        wait(3, SC_NS);

        a.write(0);
        b.write(1);

        wait(3, SC_NS);



        a.write(1);
        b.write(0);

        wait(3, SC_NS);

        a.write(1);
        b.write(0);

        wait(3, SC_NS);

        
        a.write(1);
        b.write(1);

        wait(3, SC_NS);

        sc_stop();
    }

    SC_CTOR(Try){
        SC_THREAD(test);
    }
};

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
    
    // Init test simulation
    a = 1;
    b = 0;
    sc_start(1, SC_NS);
    cout << "SUM = " << sum << ", CARRY = " << carry << endl;

    return 0; 
}