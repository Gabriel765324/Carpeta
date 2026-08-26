#include "bitstrings.h"
#include "bits/stdc++.h"
using namespace std;
int count_duplicated(string S){
  set<string> r;
  int n = S.size();
  //cerr<<n<<"\n";
  for(int i = 0; i < n; i++){
    string s = "";
    for(int j = i; j < n; j++){
      s += S[j];
      int m = s.size();
      if(m % 2 == 0){
        bool Bien = 1;
        for(int k = 0; k + m / 2 < m; k++){
          if(s[k] != s[k + m / 2]){
            Bien = 0;
            break;
          }
        }
        if(Bien) r.insert(s);
      }
    }
  }
  //for(auto E: r) cerr<<E<<"\n";
  return r.size();
}
string find_weakest(){
  string r;
  while(r.size() < 100){
    string cr = r + '0';
    if(count_duplicated(cr) > 3){
      cr = r + '1';
    }
  }
}
string find_strongest(){
  return string(100, '0');
}