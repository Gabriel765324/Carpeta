#include "mosaic.h"
#include <bits/stdc++.h>
using namespace std;
vector< vector<long long> > s;
long long Consulta(int i, int j, int k, int l){
  if(i > k) swap(i, k);
  if(j > l) swap(j, l);
  return s[k][l] - s[i - 1][l] - s[k][j - 1] + s[i - 1][j - 1];
}
vector<long long> mosaic(vector<int> x, vector<int> y, vector<int> t, vector<int> b, vector<int> l, vector<int> r){
  int n = x.size(), q = t.size();
  vector<long long> Respuesta(q);
  bool Cero = 1, Acumulada = 1;
  for(int i = 0; i < n; i++){
    if(x[i] != 0 or y[i] != 0){
      Cero = 0;
      break;
    }
  }
  for(int i = 0; i < n; i++){
    if(t[i] != 0 or b[i] != 0){
      Acumulada = 0;
      break;
    }
  }
  if(n <= 5022){
    s.assign(n + 1, vector<long long>(n + 1, 0));
    vector< vector<bool> > Colores(n + 1, vector<bool>(n + 1, 0));
    for(int i = 0; i < n; i++){
      Colores[1][i + 1] = x[i] == 1;
      Colores[i + 1][1] = y[i] == 1;
      s[1][i + 1] = x[i] + s[0][i + 1] + s[1][i] - s[0][i];
      s[i + 1][1] = y[i] + s[i][1] + s[i + 1][0] - s[i][0];
    }
    for(int i = 2; i <= n; i++){
      for(int j = 2; j <= n; j++){
        Colores[i][j] = Colores[i - 1][j] == 0 and Colores[i][j - 1] == 0;
        s[i][j] = (long long)Colores[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
      }
    }
    for(int i = 0; i < q; i++){
      Respuesta[i] = Consulta(t[i] + 1, l[i] + 1, b[i] + 1, r[i] + 1);
    }
    return Respuesta;
  }
  if(Cero){
    for(int i = 0; i < q; i++){
      if(t[i] == 0) t[i]++;
      if(l[i] == 0) l[i]++;
      if(t[i] > b[i] or l[i] > r[i]){
        Respuesta[i] = -0;
        continue;
      }
      long long Temporal = ((r[i] - l[i] + 1LL) * (b[i] - t[i] + 1LL)) / 2LL;
      if(((r[i] - l[i] + 1LL) * (b[i] - t[i] + 1LL)) % 2LL == 1LL and t[i] % 2LL == l[i] % 2LL) Temporal++;
      Respuesta[i] = Temporal;
    }
    return Respuesta;
  }
  if(Acumulada){
    vector<long long> Suma(n, 0);
    for(int i = 0; i < n; i++){
      Suma[i] = x[i];
      if(i > 0) Suma[i] += Suma[i - 1];
    }
    for(int i = 0; i < q; i++){
      Respuesta[i] = Suma[r[i]];
      if(l[i] - 1 > -1) Respuesta[i] -= Suma[l[i] - 1];
    }
    return Respuesta;
  }
}