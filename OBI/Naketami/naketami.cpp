#include "naketami.h"
#include "bits/stdc++.h"
using namespace std;
vector<int> portales_accesibles(int n, int k, vector<int> a){
  vector<int> r(n, 0), c = a;
  map<int, int> Tenemos;
  vector<int> Hay;
  sort(c.begin(), c.end());
  for(int i = 0; i < n; i++){
    Tenemos[c[i]]++;
    if(Hay.size() == 0 or Hay.back() != c[i]) Hay.push_back(c[i]);
  }
  vector<int> Consultas(1000001, 0);
  for(int i = 0; i < Hay.size(); i++){
    int Valor = Tenemos[Hay[i]];
    for(int j = Hay[i]; j < 1000001 and Hay[i] > k; j += Hay[i]){
      Consultas[j] += Valor;
    }
  }
  for(int i = 0; i < n; i++){
    if(a[i] - k > 0) r[i] = Consultas[a[i] - k] - (int)(k == 0);
    if(k == a[i]) r[i] = n - (upper_bound(c.begin(), c.end(), a[i]) - c.begin());
  }
  return r;
}