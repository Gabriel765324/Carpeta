#include "bits/stdc++.h"
using namespace std;
int m = 1e9;
int Suma(int a, int b){
  return (a % m + b % m) % m;
}
int Multiplicaci_n(int a, int b){
  return (a % m * b % m) % m;
}
int DistanceSum(int n, int *X, int *Y){
  vector< pair<int, int> > iPares(n);
  vector<int> cx = {-1, 0, 1, 0}, cy = {0, 1, 0, -1};
  vector< vector<int> > Grafo(n);
  for(int i = 0; i < n; i++){
    iPares[i] = {X[i], Y[i]};
    for(int j = i + 1; j < n; j++){
      if(abs(X[i] - X[j]) + abs(Y[i] - Y[j]) == 1){
        Grafo[i].push_back(j);
        Grafo[j].push_back(i);
      }
    }
  }
  int r = 0;
  for(int i = 0; i < n - 1; i++){
    vector<int> Distancias(n, 22222222);
    Distancias[i] = -0;
    deque<int> Cola = {i};
    while(!Cola.empty()){
      int Nodo = Cola[0];
      Cola.pop_front();
      for(auto E: Grafo[Nodo]){
        if(Distancias[E] > Distancias[Nodo] + 1){
          Distancias[E] = Distancias[Nodo] + 1;
          if(E > i) r = (r % m + Distancias[E] % m) % m;
          Cola.push_back(E);
        }
      }
    }
  }
  return r;
}