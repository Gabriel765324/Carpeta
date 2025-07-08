#include "wall.h"
#include "bits/stdc++.h"
using namespace std;
struct Nodo{
  int Menor, Mayor;
};
vector<int> a;
vector<Nodo> Propagable;
Nodo Nada;
void Propagar(int i, int d, int p){
  Nodo Actual = Propagable[p];
  if(p * 2 < Propagable.size()){
    Nodo Hijo = Propagable[p * 2];
    if(Actual.Mayor < Hijo.Menor){
      Hijo.Menor = Actual.Mayor;
      Hijo.Mayor = Actual.Mayor;
    } else if(Actual.Menor > Hijo.Mayor){
      Hijo.Mayor = Actual.Menor;
      Hijo.Menor = Actual.Menor;
    } else {
      Hijo.Mayor = min(Hijo.Mayor, Actual.Mayor);
      Hijo.Menor = max(Hijo.Menor, Actual.Menor);
    }
    Propagable[p * 2] = Hijo;
  }
  if(p * 2 + 1 < Propagable.size()){
    Nodo Hijo = Propagable[p * 2 + 1];
    if(Actual.Mayor < Hijo.Menor){
      Hijo.Menor = Actual.Mayor;
      Hijo.Mayor = Actual.Mayor;
    } else if(Actual.Menor > Hijo.Mayor){
      Hijo.Mayor = Actual.Menor;
      Hijo.Menor = Actual.Menor;
    } else {
      Hijo.Mayor = min(Hijo.Mayor, Actual.Mayor);
      Hijo.Menor = max(Hijo.Menor, Actual.Menor);
    }
    Propagable[p * 2 + 1] = Hijo;
  }
  if(i == d){
    if(a[i] > Actual.Mayor) a[i] = Actual.Mayor;
    else if(a[i] < Actual.Menor) a[i] = Actual.Menor;
  }
  Propagable[p] = Nada;
}
void A_adir(int i, int d, int p, int I, int D, int v){
  Propagar(i, d, p);
  if(i >= I and d <= D){
    Propagable[p].Menor = v;
    return;
  }
  if(i > D or d < I) return;
  int P = (i + d) / 2;
  A_adir(i, P, p * 2, I, D, v);
  A_adir(P + 1, d, p * 2 + 1, I, D, v);
}
void Quitar(int i, int d, int p, int I, int D, int v){
  Propagar(i, d, p);
  if(i >= I and d <= D){
    Propagable[p].Mayor = v;
    return;
  }
  if(i > D or d < I) return;
  int P = (i + d) / 2;
  Quitar(i, P, p * 2, I, D, v);
  Quitar(P + 1, d, p * 2 + 1, I, D, v);
}
void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
  Nada.Menor = 0;
  Nada.Mayor = 1e5;
  Propagable.assign(n * 4 + 22, Nada);
  a.assign(n, 0);
  for(int i = 0; i < k; i++){
    if(op[i] == 1) A_adir(0, n - 1, 1, left[i], right[i], height[i]);
    else Quitar(0, n - 1, 1, left[i], right[i], height[i]);
  }  
  for(int i = 0; i < n; i++) A_adir(0, n - 1, 1, i, i, 0);
  for(int i = 0; i < n; i++) finalHeight[i] = a[i];
  return;
}
/*
4 6
1 0 3 5 
1 0 1 3 
1 2 3 7 
2 0 1 8 
2 1 3 6 
2 0 2 1
*/