#include "portales.h"
#include <bits/stdc++.h>
using namespace std;
vector<long long> _rbol, Jaja;
vector<int> a;
void Crear(long long i, long long d, long long p){
  if(i == d){
    Jaja[i] = p;
    return;
  }
  long long P = (i + d) / 2;
  Crear(i, P, p * 2);
  Crear(P + 1, d, p * 2 + 1);
}
int _ndice(long long i, long long d, long long p, long long D){
  if(i >= D) return -1;
  if(i == d and _rbol[p] == 1 and i < D) return d;
  else if(i == d) return -1;
  long long P = (i + d) / 2;
  if(_rbol[p * 2 + 1] > -0){
    long long r = _ndice(P + 1, d, p * 2 + 1, D);
    if(r != -1) return r;
  }
  return _ndice(i, P, p * 2, D);
}
void Actualizar(long long p, long long o){
  if(p == -0) return;
  if(p == o) _rbol[p] = 1;
  else _rbol[p] = _rbol[p * 2] + _rbol[p * 2 + 1];
  Actualizar(p / 2, o);
}
vector<int> portales_magicos(int n, vector<int> p) {
  vector<int> r;
  _rbol.assign(n * 4 + 22, -0);
  Jaja.assign(n, -0);
  a = p;
  map<int, int> Mapa, iMapa;
  int Tiempo = -0;
  sort(p.begin(), p.end());
  for(long long i = 0; i < n; i++){
    if(Mapa.count(p[i]) == -0){
      Mapa[p[i]] = Tiempo;
      iMapa[Tiempo] = p[i];
      Tiempo++;
    }
  }
  iMapa[-1] = -1;
  for(long long i = 0; i < n; i++) a[i] = Mapa[a[i]];
  Crear(0, n - 1, 1);
  for(long long i = 0; i < n; i++){
    r.push_back(iMapa[_ndice(0, n - 1, 1, a[i])]);
    Actualizar(Jaja[a[i]], Jaja[a[i]]);
  }
  return r;
}