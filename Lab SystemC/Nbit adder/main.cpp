#include <systemc.h>
#include "nb_adder.h"

int sc_main(int argc, char* argv[]) {
  sc_signal<bool> a[N], b[N];
  sc_signal<bool> sum[N];
  sc_signal<bool> carry;
  sc_signal<bool> tmp;

  NBitAdder nba("NBitAdder");
  for (int i = 0; i < N; i++) {
    nba.a[i](a[i]);
    nba.b[i](b[i]);
    nba.sum[i](sum[i]);
  }
  nba.carry(carry);
  nba.tmp(tmp);

  // Simulation de test
  a[0].write(1);
  a[1].write(1);
  a[2].write(1);
  a[3].write(1);
  a[4].write(1);
  a[5].write(1);
  a[6].write(1);
  a[7].write(1);

  b[0].write(1);
  b[1].write(0);
  b[2].write(1);
  b[3].write(0);
  b[4].write(0);
  b[5].write(0);
  b[6].write(0);
  b[7].write(0);

  sc_start(1, SC_NS);

  cout << "a =   ";
  for (int i = N - 1; i >= 0; i--) {
    cout << a[i] << " ";
  }
  cout << endl;

  cout << "b =   ";
  for (int i = N - 1; i >= 0; i--) {
    cout << b[i] << " ";
  }
  cout << endl;

  cout << "+-----";
  for (int i=0; i<N; i++){
    cout << "--";
  }
  cout << endl;

  cout << "S = ";
  cout << carry << " ";
  for (int i = N - 1; i >= 0; i--) {
    cout << sum[i] << " ";
  }
  cout << endl;

  return 0;
}