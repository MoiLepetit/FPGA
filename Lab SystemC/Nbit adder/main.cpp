#include <systemc.h>
#include <random>
#include <string>
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

  // TraceFile
  sc_trace_file* tracefile = sc_create_vcd_trace_file("tracefile");
  for (int i = 0; i < N; i++){
    sc_trace(tracefile, a[i], "a"+std::to_string(i));
    sc_trace(tracefile, b[i], "b"+std::to_string(i));
    sc_trace(tracefile, sum[i], "sum"+std::to_string(i));
  }
  sc_trace(tracefile, carry, "carry");

  // Simulation of random test
  bool a_tmp[N];
  bool b_tmp[N];
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dis(0, 1);

  for (int i = 0; i < N; i++) {
    a_tmp[i] = dis(gen);
    b_tmp[i] = dis(gen);
  }

  for (int i = 0; i < N; i++){
    a[(N-1)-i].write(a_tmp[i]);
    b[(N-1)-i].write(b_tmp[i]);
  }

  sc_start(1, SC_NS);

  // Assertion
  bool expected_sum[N];
  bool expected_carry;

  // First bit and carry
  expected_sum[0] = a[0] ^ b[0];
  expected_carry = a[0] & b[0];

  for (int i = 1; i < N; i++) {
    expected_sum[i] = a[i] ^ b[i] ^ expected_carry;
    expected_carry = (a[i] & b[i]) | (expected_carry & (a[i] ^ b[i])); 
  }

  // Check the assertion
  for (int i = 0; i < N; i++) {
    sc_assert(sum[i] == expected_sum[i]);
  }
  sc_assert(carry == expected_carry);

  sc_close_vcd_trace_file(tracefile);

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