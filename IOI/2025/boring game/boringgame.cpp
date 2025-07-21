#include "boringgame.h"
#include "bits/stdc++.h"
using namespace std;
long long play_game(){
  long long i = 1, d = 1e18, r = 1, Pregunta = (i + d) / 2;
  vector<long long> Respuestas;
  vector< pair<long long, long long> > Pares;
  bool Primero = ask(Pregunta);
  if(Primero){
    r = Pregunta;
    i = Pregunta + 1;
  } else d = Pregunta - 1;
  while(1){
    Pares.push_back({i, d});
    Respuestas.push_back(r);
    long long p = (i + d) / 2;
    //cerr<<p<<" ";
    if(ask(p)){
      r = p;
      i = p + 1;
    } else d = p - 1;
    if(i >= d + 1){
      if(ask(Pregunta) == Primero) return r;
      else break;
    }
    if(Pares.size() == 9){
      if(ask(Pregunta) == Primero){
        Pares.clear();
        Respuestas.clear();
      } else break;
    }
  }
  i = Pares[0].first, d = Pares[0].second, r = Respuestas[0];
  while(1){
    long long p = (i + d) / 2;
    //cerr<<p<<" ";
    if(!ask(p)){
      r = p;
      i = p + 1;
    } else d = p - 1;
    if(i >= d + 1) return r;
  }
}