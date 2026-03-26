#include "bits/stdc++.h"
#include "ternurios.h"
using namespace std;
vector< vector<int> > Memoria;
vector<int> a;
int n;
int Resolver(int i, int j){
  if(i == n) return 0;
  if(Memoria[i][j] != -2) return Memoria[i][j];
  if(j == 0) return Memoria[i][j] = max(Resolver(i + 1, 0), Resolver(i + 1, 1) + a[i]);
  else return Memoria[i][j] = Resolver(i + 1, 0);
}
int max_ternurios(int N, vector<int> t){
  n = N;
  Memoria.assign(n, vector<int>(2, -2));
  for(long long i = 0; i < n; i++) a.push_back(t[i]);
  return Resolver(0, 0);
}