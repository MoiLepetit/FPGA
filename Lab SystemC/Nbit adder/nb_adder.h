#include <systemc.h>
#include "../Full adder/full_adder.h"

#define N 8   // Nombre de bits dans l'additionneur N-bit

SC_MODULE(NBitAdder) {
  sc_in<bool> a[N], b[N];        // Entrées N-bit
  sc_out<bool> sum[N];          // Sortie SUM N-bit
  sc_out<bool> carry;           // Sortie CARRY
  sc_out<bool> tmp;           // Sortie CARRY

  FullAdder *full_adders[N];    // Tableau de pointeurs vers Full Adder instances
  sc_signal<bool> carry_signals[N];  // Signaux temporaires pour les Carry-Out

  SC_CTOR(NBitAdder) {
    for (int i = 0; i < N; i++) {
      full_adders[i] = new FullAdder(("FullAdder_" + std::to_string(i)).c_str());
      full_adders[i]->A(a[i]);
      full_adders[i]->B(b[i]);

      if (i == 0) {
        full_adders[i]->C(tmp);
      } else {
        full_adders[i]->C(carry_signals[i - 1]);
      }

      full_adders[i]->SUM(sum[i]);

      if (i == N - 1) {
        full_adders[i]->CARRY(carry); // Connecter le Carry-Out du dernier Full Adder à la sortie carry
      } else {
        full_adders[i]->CARRY(carry_signals[i]); // Connecter le Carry-Out du Full Adder i au Carry-In du Full Adder suivant
      }
    }
  }

  ~NBitAdder() {
    for (int i = 0; i < N; i++) {
      delete full_adders[i];
    }
  }
};