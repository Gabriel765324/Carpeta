#include "crocodile.h"
#include "bits/stdc++.h"
using namespace std;
struct Arista{
  long long Nodo, Peso;
};
struct Nodo_por_ver{
  long long Distancia, Nodo;
};
bool operator<(const Arista &a, const Arista &b){
  if(a.Peso < b.Peso) return 1;
  if(a.Peso > b.Peso) return 0;
  return a.Nodo < b.Nodo;
}
bool operator<(const Nodo_por_ver &a, const Nodo_por_ver &b){
  if(a.Distancia < b.Distancia) return 1;
  if(a.Distancia > b.Distancia) return 0;
  return a.Nodo < b.Nodo;
}
int travel_plan(int N, int M, int R[][2], int L[], int K, int P[]){
  long long n = N, m = M;
  vector< vector<Arista> > Grafo(n);
  for(long long i = 0; i < m; i++){
    Arista a, b;
    a.Nodo = R[i][0];
    b.Nodo = R[i][1];
    a.Peso = L[i];
    b.Peso = a.Peso;
    Grafo[a.Nodo].push_back(b);
    Grafo[b.Nodo].push_back(a);
  }
  vector< pair<long long, long long> > Distancias(n, make_pair(-2, -2));
  multiset<Nodo_por_ver> Cola;
  vector<bool> Visitados(n, 0);
  for(long long i = 0; i < K; i++){
    Distancias[P[i]].first = 0;
    Nodo_por_ver a;
    a.Nodo = P[i];
    a.Distancia = 0;
    Cola.insert(a);
  }
  while(!Cola.empty()){
    Nodo_por_ver Actual = *Cola.begin();
    Cola.erase(Cola.begin());
    bool Sirve = 0;
    long long Caminos_que_sirven = 0;
    if(Distancias[Actual.Nodo].first > Distancias[Actual.Nodo].second) swap(Distancias[Actual.Nodo].first, Distancias[Actual.Nodo].second);
    if(Distancias[Actual.Nodo].first == -2) swap(Distancias[Actual.Nodo].first, Distancias[Actual.Nodo].second);
    if(Distancias[Actual.Nodo].first != -2) Caminos_que_sirven++;
    if(Distancias[Actual.Nodo].second != -2) Caminos_que_sirven++;
    if(Caminos_que_sirven == 0) Distancias[Actual.Nodo].first = Actual.Distancia;
    else if(Caminos_que_sirven == 1){
      Sirve = 1;
      Distancias[Actual.Nodo].second = Actual.Distancia;
    } else {
      if(Actual.Distancia <= Distancias[Actual.Nodo].second){
        Sirve = 1;
        Distancias[Actual.Nodo].second = Actual.Distancia;
        if(Distancias[Actual.Nodo].first > Distancias[Actual.Nodo].second) swap(Distancias[Actual.Nodo].first, Distancias[Actual.Nodo].second);
      }
    }
    if(Visitados[Actual.Nodo]) Sirve = 0;
    if(Actual.Nodo == 0) Sirve = 0;
    if(!Sirve) continue;
    Actual.Distancia = Distancias[Actual.Nodo].second;
    Visitados[Actual.Nodo] = 1;
    for(auto E: Grafo[Actual.Nodo]){
      Nodo_por_ver Nuevo;
      Nuevo.Distancia = Actual.Distancia + E.Peso;
      Nuevo.Nodo = E.Nodo;
      if(!Visitados[E.Nodo]) Cola.insert(Nuevo);
    }
  }
  return (int)max(Distancias[0].first, Distancias[0].second);
}