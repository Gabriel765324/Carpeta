#include "magic.h"
#include "bits/stdc++.h"
using namespace std;
int Izquierda, Derecha;
bool En(int i){
  return i >= Izquierda and i < Derecha;
}
vector<int> Alicia(vector<int> p){
  int n = p.size();
  Izquierda = n * 3 / 8, Derecha = Izquierda + n / 4;
  vector< deque<int> > Crecientes(n), Decrecientes(n);
  vector<bool> V_lido(n, 0);
  int Mejor_crecientes = 0, Posici_n_crecientes = 0, Mejor_decrecientes = 0, Posici_n_decrecientes = 0;
  for(int i = 0; i < n; i++){
    if(En(i)) continue;
    Crecientes[i].push_back(i);
    int Mejor = -2, Posici_n = -2;
    for(int j = 0; j < i; j++){
      if(En(j)) continue;
      if(Crecientes[j].size() > Mejor and p[j] < p[i]){
        Posici_n = j;
        Mejor = Crecientes[j].size();
      }
    }
    for(int j = Mejor - 1; j > -1; j--){
      Crecientes[i].push_front(Crecientes[Posici_n][j]);
    }
    if(Mejor_crecientes < Crecientes[i].size()){
      Mejor_crecientes = Crecientes[i].size();
      Posici_n_crecientes = i;
    }
    if(Crecientes[i].size() == 16){
      for(auto E: Crecientes[i]) p[E] = -1;
      return p;
    }
  }
  for(int i = 0; i < n; i++){
    if(En(i)) V_lido[i] = 1;
    if(i < Derecha){
      Decrecientes[i].push_front(i);
      int Mejor = -2, Posici_n = -2;
      for(int j = 0; j < i; j++){
        if(p[j] > p[i] and Decrecientes[j].size() > Mejor){
          Mejor = Decrecientes[j].size();
          Posici_n = j;
        }
      }
      for(int j = Mejor - 1; j > -1; j--){
        Decrecientes[i].push_front(Decrecientes[Posici_n][j]);
      }
    } else {
      int Mejor = -2, Posici_n = -2;
      for(int j = Izquierda; j < i; j++){
        if(V_lido[j] and p[j] > p[i] and Decrecientes[j].size() > Mejor){
          Mejor = Decrecientes[j].size();
          Posici_n = j;
        }
      }
      if(Mejor != -2){
        V_lido[i] = 1;
        Decrecientes[i].push_front(i);
      }
      for(int j = Mejor - 1; j > -1; j--){
        Decrecientes[i].push_front(Decrecientes[Posici_n][j]);
      }
    }
    if(Decrecientes[i].size() >= 16 and V_lido[i]){
      for(auto E: Decrecientes[i]) p[E] = -1;
      return p;
    }
    if(V_lido[i] and Decrecientes[i].size() > Mejor_decrecientes){
      Mejor_decrecientes = Decrecientes[i].size();
      Posici_n_decrecientes = i;
    }
  }
  if(Mejor_crecientes > Mejor_decrecientes){
    for(auto E: Crecientes[Mejor_crecientes]) p[E] = -1;
    return p;
  } else {
    for(auto E: Decrecientes[Mejor_decrecientes]) p[E] = -1;
    return p;
  }
}
vector<int> Beatriz(vector<int> p){
  int n = p.size();
  set<int> Hay;
  bool Creciente = 1;
  for(int i = 0; i < n; i++) Hay.insert(1 + i);
  for(int i = 0; i < n; i++){
    Hay.erase(p[i]);
    if(En(i) and p[i] == -1) Creciente = 0;
  }
  if(Creciente){
    for(int i = 0; i < n; i++){
      if(p[i] == -1){
        p[i] = *Hay.begin();
        Hay.erase(Hay.begin());
      }
    }
    return p;
  } else {
    for(int i = 0; i < n; i++){
      if(p[i] == -1){
        auto E = Hay.end();
        E--;
        p[i] = *E;
        Hay.erase(E);
      }
    }
    return p;
  }
}