#include "quesitos.h"
#include <cassert>
#include <cstdio>
#include <iostream>

using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;
const int MAX_K = 1000;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int N;
  cin >> N;
  assert(N >= 1 && N <= MAX_N);

  int M;
  cin >> M;
  assert(M >= 1 && M <= MAX_M);

  vector<int> accesibilidad(N);
  vector<vector<int>> C(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
        int k;
        cin >> k;
        assert(0 <= k && k <= MAX_K);
        C[i][j] = k;
    }
  }

  int result = max_quesitos(N, M, C);


  cout << result << '\n';

  return 0;
}
