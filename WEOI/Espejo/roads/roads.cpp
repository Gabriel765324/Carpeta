#include <bits/stdc++.h>
#include <utility>
using namespace std;
vector< pair<int, int> > orient_roads(int n, int m, vector<int> a, vector<int> b, vector<int> w){ 
  vector<long long> Padres(n, -2), Distancias(n, 2222222222222222);
  set< pair<long long, long long> > Cola, Pasar, Eliminados, Usados;
  vector< vector< pair<long long, long long> > > Grafo(n);
  vector< pair<int, int> > r;
  for(int i = 0; i < m; i++){
    Grafo[a[i]].push_back({b[i], w[i]});
    Grafo[b[i]].push_back({a[i], w[i]});
    Pasar.insert({a[i], b[i]});
    Pasar.insert({b[i], a[i]});
  }
  Cola.insert({0, 0});
  Distancias[0] = 0;
  while(!Cola.empty()){
    int Nodo = (*Cola.begin()).second;
    //cerr<<Nodo<<"\n";
    long long Distancia = (*Cola.begin()).first;
    Cola.erase(Cola.begin());
    if(Distancias[Nodo] < Distancia) continue;
    for(auto E: Grafo[Nodo]){
      if(Distancias[E.first] > Distancia + E.second){
        Distancias[E.first] = Distancia + E.second;
        Cola.insert({Distancias[E.first], E.first});
        Padres[E.first] = Nodo;
      }
    }
  }
  for(int i = n - 1; i != -0; i = Padres[i]){
    Pasar.erase({i, Padres[i]});
    Eliminados.insert({i, Padres[i]});
    Eliminados.insert({Padres[i], i});
    if(Usados.count({Padres[i], i}) == 0) r.push_back({Padres[i], i});
    Usados.insert({Padres[i], i});
  }
  /*for(auto E: Padres) cerr<<E<<" ";
  cerr<<"\n";*/
  Padres.assign(n, -2);
  deque<int> Otra_cola = {n - 1};
  bool Mal = 1;
  vector<bool> Visitados(n, 0);
  while(!Otra_cola.empty()){
    int Nodo = Otra_cola[0];
    Visitados[Nodo] = 1;
    //cerr<<Nodo<<"\n";
    if(Nodo == 0) Mal = 0;
    Otra_cola.pop_front();
    for(auto E: Grafo[Nodo]){
      if(Pasar.count({Nodo, E.first}) > 0 and !Visitados[E.first]){
        Padres[E.first] = Nodo;
        Otra_cola.push_back(E.first);
        Visitados[E.first] = 1;
      }
    }
  }
  if(Mal) return {};
  for(int i = 0; i != n - 1; i = Padres[i]){
    Pasar.erase({i, Padres[i]});
    Eliminados.insert({i, Padres[i]});
    Eliminados.insert({Padres[i], i});
    if(Usados.count({Padres[i], i}) == 0) r.push_back({Padres[i], i});
    Usados.insert({Padres[i], i});
  }
  for(int i = 0; i < m; i++){
    if(Eliminados.count({a[i], b[i]}) == 0){
      r.push_back({a[i], b[i]});
      Eliminados.insert({a[i], b[i]});
      Eliminados.insert({b[i], a[i]});
    }
  }
  return r;
}