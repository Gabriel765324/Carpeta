#include "insects.h"
#include "bits/stdc++.h"
using namespace std;
/*void move_inside(int i);
void move_outside(int i);
int press_button();*/
vector<int> r, t;
int Buscar(int a){
  if(r[a] == a) return a;
  return r[a] = Buscar(r[a]);
}
void Unir(int a, int b){
  a = Buscar(a);
  b = Buscar(b);
  if(a != b){
    t[a] += t[b];
    r[b] = a;
  }
}
int min_cardinality(int n){
  r.assign(n, 0);
  t.assign(n, 1);
  for(int i = 0; i < n; i++) r[i] = i;
  for(int i = 0; i < n - 1; i++){
    move_inside(i);
    for(int j = i + 1; j < n; j++){
      move_inside(j);
      if(press_button() == 2) Unir(i, j);
      move_outside(j);
    }
    move_outside(i);
  }
  int r = n;
  for(int i = 0; i < n; i++){
    t[i] = t[Buscar(i)];
    r = min(r, t[i]);
  }
  return r;
}