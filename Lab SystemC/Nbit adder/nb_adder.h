#include <systemc.h>
#include "../Full adder/full_adder.h"

#define N 8   // Number of bit of Nbit Adder

SC_MODULE(NBitAdder) {
  sc_in<bool> a[N], b[N];        // Input Nbit Adder
  sc_out<bool> sum[N];          // Output SUM Nbit Adder
  sc_out<bool> carry;          // Output CARRY
  sc_out<bool> tmp;           // Tempory CARRY

  FullAdder *full_adders[N];    // All Full Adder
  sc_signal<bool> carry_signals[N];  // Tempory Carry Signals

  SC_CTOR(NBitAdder);
};