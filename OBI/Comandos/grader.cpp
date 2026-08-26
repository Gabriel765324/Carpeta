#include "comandos.h"
#include <cassert>
#include <cstdio>
#include <iostream>

using namespace std;

const int MAX_N = 100000;
const int MAX_K = 1000000000;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int N;
  cin >> N;
  assert(N >= 1 && N <= MAX_N);

  int K;
  cin >> K;
  assert(K >= 1 && K <= N);

  vector<int> comandos(N);
  for (int i = 0; i < N; i++) {
    int k;
    cin >> k;
    assert(-MAX_K <= k && k <= MAX_K);
    comandos[i] = k;
  }

  int result = longitud_maxima(N, K, comandos);


  cout << result << "\n";

  return 0;
}
