#include "nile.h"
#include "bits/stdc++.h"
using namespace std;
struct Artefacto{
  long long Peso, a, b;
};
bool operator<(const Artefacto& a, const Artefacto& b){
  if(a.Peso < b.Peso) return 1;
  else if(a.Peso > b.Peso) return 0;
  else return a.a - a.b > b.a - b.b;
}
vector<Artefacto> Artefactos;
vector<long long> Representantes, Tama_os;
long long Respuesta_actual = 0;
void Crear(long long n){
  for(long long i = 0; i < n; i++){
    Representantes.push_back(i);
    Tama_os.push_back(1);
  }
}
long long Buscar(long long a){
  if(Representantes[a] == a) return a;
  Representantes[a] = Buscar(Representantes[a]);
  Tama_os[a] = Tama_os[Representantes[a]];
  return Representantes[a];
}
void Unir(long long a, long long b){
  a = Buscar(a);
  b = Buscar(b);
  if(a != b){
    long long ta = Tama_os[a], tb = Tama_os[b];
    Tama_os[a] += Tama_os[b];
    Representantes[b] = a;
    Tama_os[b] = Tama_os[a];
    if(ta % 2 == 1) ta++;
    if(tb % 2 == 1) tb++;
    Respuesta_actual -= ta;
    Respuesta_actual -= tb;
    Respuesta_actual += Tama_os[a] + (long long)(Tama_os[a] % 2 == 1);
  }
}
vector<long long> calculate_costs(vector<int> w, vector<int> a, vector<int> b, vector<int> e) {
  int n = a.size(), q = e.size();
  for(long long i = 0; i < n; i++){
    Artefacto Nuevo;
    Nuevo.Peso = w[i];
    Nuevo.a = a[i];
    Nuevo.b = b[i];
    Artefactos.push_back(Nuevo);
    Respuesta_actual += a[i];
  }
  sort(Artefactos.begin(), Artefactos.end());
  if(q <= 5){
    vector<long long> Retorno;
    for(auto E: e){
      vector< vector<long long> > PD(n + 1, vector<long long>(3, 2222222222222222));
      PD[n][0] = 0;
      for(long long i = n - 1; i > -1; i--){
        for(long long j = 0; j < 3; j++){
          if(j == 0) PD[i][j] = min(PD[i + 1][0] + Artefactos[i].a, PD[i + 1][1] + Artefactos[i].b);
          if(j == 1){
            if(i - j > -1 and abs(Artefactos[i].Peso - Artefactos[i - j].Peso) <= E) PD[i][j] = min(PD[i + 1][j + 1] + Artefactos[i].a, PD[i + 1][0] + Artefactos[i].b);
            else PD[i][j] = 2222222222222222;
          }
          if(j == 2){
            if(i - j > -1 and abs(Artefactos[i].Peso - Artefactos[i - j].Peso) <= E) PD[i][j] = PD[i + 1][0] + Artefactos[i].b;
            else PD[i][j] = 2222222222222222;
          }
        }
      }
      Retorno.push_back(PD[0][0]);
    }
    return Retorno;
  }
  vector< pair<long long, long long> > Consultas(q);
  vector< pair< long long, pair<long long, long long> > > Emparejador(n - 1);
  for(long long i = 0; i < q; i++) Consultas[i] = {e[i], i};
  for(long long i = 0; i < n - 1; i++) Emparejador[i] = {abs(Artefactos[i].Peso - Artefactos[i + 1].Peso), {i, i + 1}};
  Crear(n);
  vector<long long> Respuestas(q);
  sort(Consultas.begin(), Consultas.end());
  sort(Emparejador.begin(), Emparejador.end());
  long long i = 0;
  for(auto E: Consultas){
    while(i < Emparejador.size() and Emparejador[i].first <= E.first){
      Unir(Emparejador[i].second.first, Emparejador[i].second.second);
      i++;
    }
    Respuestas[E.second] = Respuesta_actual;
  }
  return Respuestas;
}