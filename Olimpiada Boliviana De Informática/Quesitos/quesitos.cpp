#include "quesitos.h"
#include "bits/stdc++.h"
using namespace std;
int max_quesitos(int n, int m, vector< vector<int> > c) {
  vector< vector<int> > Memoria(n + 1, vector<int>(m + 1, -2222));
  Memoria[n][m - 1] = 0;
  for(int i = n - 1; i > -1; i--){
    for(int j = m - 1; j > -1; j--){
      Memoria[i][j] = max(Memoria[i + 1][j], Memoria[i][j + 1]) + c[i][j];
    }
  }
  return Memoria[0][0];
}