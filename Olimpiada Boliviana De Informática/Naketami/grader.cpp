#include "naketami.h"
#include <cassert>
#include <cstdio>
#include <iostream>

const int MAX_N = 300000;
const int MAX_K = 1000000;
const int MAX_H = 1000000;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int N;
  cin >> N;
  assert(N >= 1 && N <= MAX_N);

  int K;
  cin >> K;
  assert(K >= 0 && K <= MAX_K);

  vector<int> accesibilidad(N);
  for (auto &v:accesibilidad) {
    int a;
    cin >> a;
    assert(1 <= a && a <= MAX_H);
    v = a;
  }

  auto result = portales_accesibles(N, K, accesibilidad);


  for (int i = 0; i < (int)result.size(); i++) {
    if (i) {
      cout << " ";
    }
    cout << result[i];
  }

  return 0;
}
