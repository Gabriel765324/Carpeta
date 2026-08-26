#include "bits/stdc++.h"
using namespace std;
long long n;
vector< vector<long long> > Grafo;
vector<long long> Visitados;
void Init(int N_) {
  n = (long long)N_;
  Grafo.assign(n, vector<long long>());
}
void Link(int A, int B){
  long long a = (long long)A;
  long long b = (long long)B;
  Grafo[a].push_back(b);
  Grafo[b].push_back(a);
}
int Bien;
long long Ciclos;
void DFS(long long Nodo, long long Anterior){
  Visitados[Nodo] = 1;
  long long c = 0;
  for(auto E: Grafo[Nodo]){
    if(Visitados[E] == 1) c++;
    if(Visitados[E] == 1 and E != Anterior){
      Bien = 0;
    }
    if(Visitados[E] == 0){
      DFS(E, Nodo);
      c++;
    }
  }
  if(c >= 3){
    Bien = 0;
  }
}
int CountCritical(){
  int r = 0;
  vector<long long> Buenos;
  for(long long i = 0; i < n; i++){
    if(Grafo[i].size() >= 4){
      Bien = 1;
      Visitados.assign(n, 0);
      Visitados[i] = 2;
      for(long long j = 0; j < n; j++){
        if(i == j) continue;
        if(Visitados[j] == 0){
          DFS(j, -2);
        }
      }
      return Bien;
    }
  }
  bool Solo_4 = 0;
  for(long long i = 0; i < n; i++){
    if(Grafo[i].size() == 3){
      Buenos.push_back(i);
      for(auto E: Grafo[i]){
        Buenos.push_back(E);
      }
      Solo_4 = 1;
      break;
    }
  }
  if(Solo_4){
    for(auto i: Buenos){
      Bien = 1;
      Visitados.assign(n, 0);
      Visitados[i] = 2;
      for(long long j = 0; j < n; j++){
        if(i == j) continue;
        if(Visitados[j] == 0){
          DFS(j, -2);
        }
      }
      r += Bien;
    }
  } else {
    Ciclos = 0;
    Visitados.assign(n, 0);
    long long Ciclado;
    for(long long i = 0; i < n; i++){
      if(!Visitados[i]){
        Bien = 1;
        DFS(i, -2);
        if(Bien == 0) Bien = 1;
        else Bien = 0;
        Ciclos += Bien;
        if(Bien == 1) Ciclado = i;
      }
    }
    if(Ciclos > 1) return 0;
    else if(Ciclos == 1){
      set<long long> Tenemos;
      while(1){
        if(Tenemos.find(Ciclado) != Tenemos.end()) break;
        r++;
        Tenemos.insert(Ciclado);
        long long a = Grafo[Ciclado][0], b = Grafo[Ciclado][1];
        if(Tenemos.count(a) == 0) Ciclado = a;
        else Ciclado = b;
      }
    } else {
      return (int)n;
    }
  }
  return r;
}