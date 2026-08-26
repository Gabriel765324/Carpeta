#include "elephants.h"
#include "bits/stdc++.h"
using namespace std;
int n, l;
vector<int> Posiciones;
vector< pair<int, int> > a;
void init(int N, int L, int X[]){
  n = N;
  l = L;
  for(int i = 0; i < n; i++){
    a.push_back({X[i], i});
    Posiciones.push_back(i);
  }
}
int update(int i, int y){
  a[Posiciones[i]].first = y;
  //cerr<<Posiciones[i]<<"\n";
  for(int j = Posiciones[i]; j < n - 1; j++){
    //cerr<<a[j].first<<" "<<a[j + 1].first<<"\n";
    if(a[j].first <= a[j + 1].first){
      //cerr<<"Roto.\n";
      break;
    } else {
      Posiciones[i]++;
      Posiciones[a[j + 1].second]--;
      swap(a[j], a[j + 1]);
    }
  }
  //cerr<<Posiciones[i]<<"\n";
  for(int j = Posiciones[i]; j > 0; j--){
    //cerr<<a[j - 1].first<<" "<<a[j].first<<"\n";
    if(a[j - 1].first <= a[j].first){
      //cerr<<"Roto.\n";
      break;
    } else {
      Posiciones[i]--;
      Posiciones[a[j - 1].second]++;
      swap(a[j], a[j - 1]);
    }
  }
  int r = 0, p = -2;
  for(auto E: a){
    //cerr<<E.first<<" ";
    if(p == -2){
      r++;
      p = E.first;
    } else if(E.first > p + l){
      r++;
      p = E.first;
    }
  }
  /*cerr<<"\n";
  for(auto E: a) cerr<<E.second<<" ";
  cerr<<"\n\n";*/
  return r;
}