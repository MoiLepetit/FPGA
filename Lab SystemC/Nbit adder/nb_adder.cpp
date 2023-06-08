#include "nb_adder.h"

NBitAdder::NBitAdder(sc_module_name name)
    : sc_module(name) {
        for (int i = 0; i < N; i++) {
        full_adders[i] = new FullAdder(("FullAdder_" + std::to_string(i)).c_str());
        full_adders[i]->A(a[i]);
        full_adders[i]->B(b[i]);

        if (i == 0) {
            full_adders[i]->C(tmp); // For the first Full Adderwe simulate a Half Adder with a carry equal to zero
        } else {
            full_adders[i]->C(carry_signals[i - 1]); // Full Adder as usual
        }

        full_adders[i]->SUM(sum[i]);

        if (i == N - 1) {
            full_adders[i]->CARRY(carry); // For the last we inject the last carry for the result
        } else {
            full_adders[i]->CARRY(carry_signals[i]); // Full Adder as usual
        }
        }
}