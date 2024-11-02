#include "ricehub.h"
#include "bits/stdc++.h"
using namespace std;
int besthub(int R, int L, int X[], long long B){
  long long n = R;
  if(n == 1) return 1;
  vector<long long> a(n);
  for(long long i = 0; i < n; i++){
     a[i] = X[i];
  }
  long long Mayor = 1;
  vector<long long> Distancias(n, 0);
  for(long long i = 0; i < n; i++){
    Distancias[i] = 0;
    for(long long j = i - 1; j > -1; j--){
      Distancias[j] = a[i] - a[j] + Distancias[j + 1];
    }
    for(long long j = i + 1; j < n; j++){
      Distancias[j] = a[j] - a[i] + Distancias[j - 1];
    }
    for(long long j = i; j > -1; j--){
      if(Distancias[j] > B) break;
      long long Tenemos = i - j + 1, Aun_hay = B - Distancias[j];
      long long Izquierda = i, Derecha = n - 1, Mejor = i;
      while(1){
        if(Izquierda >= (Derecha + 1)) break;
        long long Promedio = (Izquierda + Derecha) / 2;
        if(Distancias[Promedio] <= Aun_hay){
          Izquierda = Promedio + 1;
          Mejor = Promedio;
        } else Derecha = Promedio - 1;
      }
      Tenemos += Mejor - i;
      Mayor = max(Mayor, Tenemos);
    }
    for(long long j = i + 1; j < n; j++){
      if(Distancias[j] > B) break;
      long long Tenemos = j - i, Aun_hay = B - Distancias[j];
      long long Izquierda = 0, Derecha = i, Mejor = i;
      while(1){
        if(Izquierda >= (Derecha + 1)) break;
        long long Promedio = (Izquierda + Derecha) / 2;
        if(Distancias[Promedio] <= Aun_hay){
          Derecha = Promedio - 1;
          Mejor = Promedio;
        } else Izquierda = Promedio + 1;
      }
      Tenemos += i - Mejor + 1;
      Mayor = max(Mayor, Tenemos);
    }
  }
  return Mayor;
}