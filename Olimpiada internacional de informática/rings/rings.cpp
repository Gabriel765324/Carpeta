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
void DFS(long long Nodo, long long Anterior){
  Visitados[Nodo] = 1;
  long long c = 0;
  for(auto E: Grafo[Nodo]){
    if(Visitados[E] == 1) c++;
    if(Visitados[E] == 1 and E != Anterior){
      if(Bien != 0){
        //cout<<"Ciclo //"<<Nodo<<" "<<E<<" "<<Anterior<<" "<<Visitados[E]<<"// ";
      }
      Bien = 0;
    }
    if(Visitados[E] == 0){
      DFS(E, Nodo);
      c++;
    }
  }
  if(c >= 3){
    if(Bien != 0){
      //cout<<"Vecinos salgan\n";
    }
    Bien = 0;
  }
}
int CountCritical(){
  int r = 0;
  for(long long i = 0; i < n; i++){
    Bien = 1;
    Visitados.assign(n, 0);
    Visitados[i] = 2;
    for(long long j = 0; j < n; j++){
      if(i == j) continue;
      /*for(auto E: Visitados) cout<<E<<" ";
      cout<<"\n";*/
      if(Visitados[j] == 0){
        DFS(j, -2);
        //cout<<j<<" ";
      }
      //cout<<"\n\n";
      /*cout<<j<<" ";
      for(auto E: Grafo[j]) cout<<E<<" ";
      cout<<"\n";*/
    }
    r += Bien;
  }
  //cout<<"Respuesta: ";
  return r;
}