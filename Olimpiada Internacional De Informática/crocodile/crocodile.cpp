#include "crocodile.h"
#include "bits/stdc++.h"
using namespace std;
struct Arista{
  long long Nodo, Peso;
};
struct Arista_completa{
  long long a, b, Peso;
};
struct Nodo_por_ver{
  long long Distancia, Nodo;
  //long long Padre;
};
bool operator<(const Arista &a, const Arista &b){
  if(a.Peso < b.Peso) return 1;
  if(a.Peso > b.Peso) return 0;
  return a.Nodo < b.Nodo;
}
bool operator<(const Arista_completa &a, const Arista_completa &b){
  if(a.Peso < b.Peso) return 1;
  if(a.Peso > b.Peso) return 0;
  if(a.a < b.a) return 1;
  if(a.a > b.a) return 0;
  return a.b < b.b;
}
bool operator<(const Nodo_por_ver &a, const Nodo_por_ver &b){
  if(a.Distancia < b.Distancia) return 1;
  if(a.Distancia > b.Distancia) return 0;
  /*if(a.Nodo < b.Nodo) return 1;
  if(a.Nodo > b.Nodo) return 0;
  return a.Padre < b.Padre;*/
  return a.Nodo < b.Nodo;
}
int travel_plan(int N, int M, int R[][2], int L[], int K, int P[]){
  long long n = N, m = M;
  multiset<Arista_completa> Lista_de_aristas;
  vector< vector<Arista> > Grafo(n);
  //vector<bool> Salidas(n, 0);
  for(long long i = 0; i < m; i++){
    Arista a, b;
    a.Nodo = R[i][0];
    b.Nodo = R[i][1];
    a.Peso = L[i];
    b.Peso = a.Peso;
    Arista_completa _1;
    _1.a = a.Nodo;
    _1.b = b.Nodo;
    _1.Peso = a.Peso;
    Lista_de_aristas.insert(_1);
    swap(_1.a, _1.b);
    Lista_de_aristas.insert(_1);
    Grafo[a.Nodo].push_back(b);
    Grafo[b.Nodo].push_back(a);
  }
  //for(long long i = 0; i < K; i++) Salidas[P[i]] = 1;
  vector< multiset<long long> > Distancias(n);
  multiset<Nodo_por_ver> Cola;
  for(long long i = 0; i < K; i++){
    Distancias[P[i]].insert(0);
    Nodo_por_ver a;
    a.Nodo = P[i];
    a.Distancia = 0;
    //a.Padre = P[i];
    Cola.insert(a);
  }
  while(!Cola.empty()){
    Nodo_por_ver Actual = *Cola.begin();
    //cout<<Actual.Nodo<<" "<<Actual.Distancia<<"\n";
    Cola.erase(Cola.begin());
    bool Sirve = 0;
    if(Distancias[Actual.Nodo].size() <= 1){
      Distancias[Actual.Nodo].insert(Actual.Distancia);
      if(Distancias[Actual.Nodo].size() == 2) Sirve = 1;
    } else {
      Distancias[Actual.Nodo].insert(Actual.Distancia);
      auto E = Distancias[Actual.Nodo].end();
      E--;
      if(*E != Actual.Distancia){
        Sirve = 1;
      }
      Distancias[Actual.Nodo].erase(E);
    }
    if(Actual.Nodo == 0) Sirve = 0;
    if(!Sirve) continue;
    auto e = Distancias[Actual.Nodo].end();
    e--;
    Actual.Distancia = *e;
    for(auto E: Grafo[Actual.Nodo]){
      Nodo_por_ver Siguiente;
      Siguiente.Distancia = E.Peso + Actual.Distancia;
      Siguiente.Nodo = E.Nodo;
      Cola.insert(Siguiente);
    }
  }
  /*for(auto E: Distancias){
    cout<<*E.begin()<<" ";
  }*/
  auto E = Distancias[0].end();
  E--;
  return (int)(*E);
}