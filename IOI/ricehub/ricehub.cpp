#include "ricehub.h"
#include "bits/stdc++.h"
using namespace std;
int besthub(int R, int L, int X[], long long B){
  long long n = R;
  vector<long long> a, Suma;
  for(long long i = 0; i <= n; i++){
    a.push_back(X[i]);
    Suma.push_back(a.back());
    if(i > 0) Suma.back() += Suma[i - 1];
  }
  int Mejor = -2;
  long long Resta = 0;
  for(long long i = 0; i < n; i++){
    long long Izquierda = i, Derecha = n - 1, Tentativo = i;
    Resta += a[i];
    while(1){
      if(Izquierda >= (Derecha + 1)) break;
      long long Promedio = (Izquierda + Derecha) / 2;
      long long zd = (Promedio + i) / 2;
      long long Distancia = 0;
      Distancia += Suma[Promedio] - Suma[zd] - a[zd] * (Promedio - zd);
      if(zd > 0) Distancia -= Suma[zd - 1];
      if(i > 0) Distancia += Suma[i - 1];
      Distancia += a[zd] * (zd - i);
      //Distancia -= a[zd] * (Promedio - i + 1);
      if(Distancia <= B){
        Izquierda = Promedio + 1;
        Tentativo = Promedio;
      } else Derecha = Promedio - 1;
      //cout<<i<<" "<<Promedio<<" "<<Distancia<<"\n";
    }
    Mejor = max(Mejor, (int)(Tentativo - i + 1));
  }
  return Mejor;
}