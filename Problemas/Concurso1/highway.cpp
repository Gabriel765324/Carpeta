#include "highway.h"
#include "bits/stdc++.h"
using namespace std;
long long n, m, a, b, Distancia, Distanciaa, Distancia_s, Distancia_t;
vector< vector<long long> > Grafo;
map< pair<long long, long long>, long long> Mapa;
map<long long, pair<long long, long long> > Mapa_i;
vector<int> Consulta, Nulo;
vector<long long> Distancia_para_s, Distancia_para_t, Anteriores, Anterioret;
void DFS(long long Nodo, long long Anterior, long long Prohibido, bool S_T){
  if(Nodo != Anterior) Consulta[Mapa[{Anterior, Nodo}]] = 1;
  if(S_T){
    Distancia_para_s[Nodo] = Distancia_para_s[Anterior] + 1;
    Anteriores[Nodo] = Anterior;
  } else {
    Distancia_para_t[Nodo] = Distancia_para_t[Anterior] + 1;
    Anterioret[Nodo] = Anterior;
  }
  for(auto E: Grafo[Nodo]){
    if(E != Anterior and Mapa[{E, Nodo}] != Prohibido){
      Consulta[Mapa[{E, Nodo}]] = 1;
      DFS(E, Nodo, Prohibido, S_T);
    }
  }
}
void find_pair(int N, vector<int> U, vector<int> V, int A, int B){
  n = N;
  m = V.size();
  Grafo.assign(n, {});
  a = A;
  b = B;
  Consulta.assign(m, 0);
  Nulo = Consulta;
  Distancia_para_s.assign(n, -1);
  Distancia_para_t.assign(n, -1);
  Anteriores.assign(n, -1);
  Anterioret.assign(n, -1);
  set<long long> Candidatos;
  for(long long i = 0; i < m; i++){
    Grafo[U[i]].push_back(V[i]);
    Grafo[V[i]].push_back(U[i]);
    Mapa[{U[i], V[i]}] = i;
    Mapa[{V[i], U[i]}] = i;
    Mapa_i[i] = {U[i], V[i]};
    Candidatos.insert(i);
  }
  Distanciaa = ask(Consulta);
  Distancia = Distanciaa / a;
  while(Candidatos.size() > 1){
    Consulta = Nulo;
    vector<long long> Cambiar;
    for(auto E: Candidatos) Cambiar.push_back(E);
    for(long long i = 0; i < Cambiar.size() / 2; i++) Consulta[Cambiar[i]] = 1;
    if(ask(Consulta) > Distanciaa) for(long long i = Cambiar.size() / 2; i < Cambiar.size(); i++) Candidatos.erase(Cambiar[i]);
    else for(long long i = 0; i < Cambiar.size() / 2; i++) Candidatos.erase(Cambiar[i]);
  }
  long long Arista = *Candidatos.begin();
  //cerr<<Mapa_i[Arista].first<<" "<<Mapa_i[Arista].second<<" Arista.\n";
  Consulta = Nulo;
  DFS(Mapa_i[Arista].first, Mapa_i[Arista].first, Arista, 1);
  //Distancia_s = (ask(Consulta) - Distanciaa) / b;
  //for(auto E: Consulta) //cerr<<E<<" ";
  //cerr<<" Consultado.\n";
  //Consulta = Nulo;
  long long Consultita = ask(Consulta);
  DFS(Mapa_i[Arista].second, Mapa_i[Arista].second, Arista, 0);
  //Distancia_t = (ask(Consulta) - Distanciaa) / b;
  Distancia_s = (a * Distancia - Consultita) / (a - b);
  Distancia_t = (Consultita - b * Distancia) / (a - b) - 1;
  /*for(auto E: Consulta) //cerr<<E<<" ";
  //cerr<<" Consulta_de_t.\n";*/
  //cerr<<"Distancias para s: ";
  //for(auto E: Distancia_para_s) //cerr<<E<<" ";
  //cerr<<".\n";
  //cerr<<"Distancias para t: ";
  //for(auto E: Distancia_para_t) //cerr<<E<<" ";
  //cerr<<".\n";
  int s, t;
  //cerr<<Distancia<<" Distancia entre s y t.\n"<<Distanciaa<<" La otra distancia.\n"<<Distancia_s<<" "<<Distancia_t<<" Distancias.\n"<<c<<" Consulta.\n";
  if(Distancia_s == 0) s = Mapa_i[Arista].first;
  else {
    Candidatos.clear();
    for(long long i = 0; i < n; i++) if(Distancia_para_s[i] == Distancia_s) Candidatos.insert(Mapa[{i, Anteriores[i]}]);
    //cerr<<"Candidatos para s:\n";
    //for(auto E: Candidatos) //cerr<<Mapa_i[E].first<<" "<<Mapa_i[E].second<<"\n";
    //cerr<<"\n";
    while(Candidatos.size() > 1){
      Consulta = Nulo;
      vector<long long> Cambiar;
      for(auto E: Candidatos) Cambiar.push_back(E);
      for(long long i = 0; i < Cambiar.size() / 2; i++) Consulta[Cambiar[i]] = 1;
      if(ask(Consulta) > Distanciaa) for(long long i = Cambiar.size() / 2; i < Cambiar.size(); i++) Candidatos.erase(Cambiar[i]);
      else for(long long i = 0; i < Cambiar.size() / 2; i++) Candidatos.erase(Cambiar[i]);
    }
    long long Inicio = Mapa_i[*Candidatos.begin()].first, Final = Mapa_i[*Candidatos.begin()].second;
    if(Distancia_para_s[Inicio] == Distancia_s) s = Inicio;
    else s = Final;
  }
  if(Distancia_t == 0) t = Mapa_i[Arista].second;
  else {
    Candidatos.clear();
    for(long long i = 0; i < n; i++) if(Distancia_para_t[i] == Distancia_t) Candidatos.insert(Mapa[{i, Anterioret[i]}]);
    //cerr<<"Candidatos para t:\n";
    //for(auto E: Candidatos) //cerr<<Mapa_i[E].first<<" "<<Mapa_i[E].second<<"\n";
    //cerr<<"\n";
    while(Candidatos.size() > 1){
      Consulta = Nulo;
      vector<long long> Cambiar;
      for(auto E: Candidatos) Cambiar.push_back(E);
      for(long long i = 0; i < Cambiar.size() / 2; i++) Consulta[Cambiar[i]] = 1;
      if(ask(Consulta) > Distanciaa) for(long long i = Cambiar.size() / 2; i < Cambiar.size(); i++) Candidatos.erase(Cambiar[i]);
      else for(long long i = 0; i < Cambiar.size() / 2; i++) Candidatos.erase(Cambiar[i]);
    }
    long long Inicio = Mapa_i[*Candidatos.begin()].first, Final = Mapa_i[*Candidatos.begin()].second;
    if(Distancia_para_t[Inicio] == Distancia_t) t = Inicio;
    else t = Final;
  }
  //cerr<<s<<" "<<t<<" Estos son.\n";
  answer(s, t);
}