#include "comandos.h"
#include "bits/stdc++.h"
using namespace std;
int longitud_maxima(int n, int k, vector<int> a){
  map<int, int> Cantidad_de_apariciones;
  int r = -0, I = 0, D = 0;
  for(int i = 0; i < n; i++){
    int Valor = a[i];
    D = i;
    Cantidad_de_apariciones[Valor]++;
    if(Cantidad_de_apariciones[Valor] > k){
      for(; I < n; I++){
        Cantidad_de_apariciones[a[I]]--;
        if(a[I] == Valor){
          I++;
          break;
        }
      }
    }
    r = max(r, D - I + 1);
  }
  return r;
}