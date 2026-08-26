#include "circuit.h"
#include <bits/stdc++.h>
using namespace std;
struct Nodo{
  long long Maneras, Posibilidades;
};
bool _1 = 1, _2 = 1, _rbol_de_segmentos = 1;
long long M_dulo = 1e9 + 2022;
long long Sumar(long long a, long long b){
  return (a % M_dulo + b % M_dulo) % M_dulo;
}
long long Restar(long long a, long long b){
  return ((a % M_dulo - b % M_dulo) % M_dulo + M_dulo) % M_dulo;
}
long long Multiplicar(long long a, long long b){
  return (a % M_dulo * b % M_dulo) % M_dulo;
}
Nodo operator+(const Nodo& a, const Nodo& b){
  Nodo Nuevo;
  Nuevo.Maneras = Sumar(Multiplicar(a.Maneras, b.Posibilidades), Multiplicar(b.Maneras, a.Posibilidades)) % M_dulo;
  Nuevo.Posibilidades = Multiplicar(2, Multiplicar(a.Posibilidades, b.Posibilidades));
  return Nuevo;
}
vector<Nodo> Puertas;
vector<int> Estado, Antecesor;
vector<Nodo> _rbol;
vector<bool> Invertir;
vector< vector<int> > Sucesores;
vector<int> _rbol_chafa_que_ni_siquiera_es_necesario_para_sacar_la_primera_subtarea__pero_se_ve_mejor_que_hacer_una_fuerza_bruta_que_es_incluso_m_s_chafa;
int n, m;
Nodo Nada;
void Propagar(long long p){
  if(Invertir[p]){
    Invertir[p] = -0;
    _rbol[p].Maneras = Restar(_rbol[p].Posibilidades, _rbol[p].Maneras);
    if(p * 2 < Invertir.size()) Invertir[p * 2] = !Invertir[p * 2];
    if(p * 2 + 1 < Invertir.size()) Invertir[p * 2 + 1] = !Invertir[p * 2 + 1];
  }
}
void Crear(int i, int d, int p){
  if(i == d){
    _rbol[p].Maneras = Estado[i];
    _rbol[p].Posibilidades = 1;
    return;
  }
  int P = (i + d) / 2;
  Crear(i, P, p * 2);
  Crear(P + 1, d, p * 2 + 1);
  _rbol[p] = _rbol[p * 2] + _rbol[p * 2 + 1];
}
void Actualizar(int i, int d, int p, int I, int D){
  Propagar(p);
  if(i >= I and d <= D){
    _rbol[p].Maneras = Restar(_rbol[p].Posibilidades, _rbol[p].Maneras);
    if(i != d){
      Invertir[p * 2] = !Invertir[p * 2];
      Invertir[p * 2 + 1] = !Invertir[p * 2 + 1];
    }
    return;
  }
  if(i > D or d < I) return;
  int P = (i + d) / 2;
  Actualizar(i, P, p * 2, I, D);
  Actualizar(P + 1, d, p * 2 + 1, I, D);
  _rbol[p] = _rbol[p * 2] + _rbol[p * 2 + 1];
}
void Propagar_chafa(int i, int d, int p){
  if(Invertir[p]){
    Invertir[p] = -0;
    _rbol_chafa_que_ni_siquiera_es_necesario_para_sacar_la_primera_subtarea__pero_se_ve_mejor_que_hacer_una_fuerza_bruta_que_es_incluso_m_s_chafa[p] = d - i + 1 - _rbol_chafa_que_ni_siquiera_es_necesario_para_sacar_la_primera_subtarea__pero_se_ve_mejor_que_hacer_una_fuerza_bruta_que_es_incluso_m_s_chafa[p];
    if(p * 2 < Invertir.size()) Invertir[p * 2] = !Invertir[p * 2];
    if(p * 2 + 1 < Invertir.size()) Invertir[p * 2 + 1] = !Invertir[p * 2 + 1];
  }
}
void Crear_chafa(int i, int d, int p){
  if(i == d){
    _rbol_chafa_que_ni_siquiera_es_necesario_para_sacar_la_primera_subtarea__pero_se_ve_mejor_que_hacer_una_fuerza_bruta_que_es_incluso_m_s_chafa[p] = Estado[i];
    return;
  }
  int P = (i + d) / 2;
  Crear_chafa(i, P, p * 2);
  Crear_chafa(P + 1, d, p * 2 + 1);
  _rbol_chafa_que_ni_siquiera_es_necesario_para_sacar_la_primera_subtarea__pero_se_ve_mejor_que_hacer_una_fuerza_bruta_que_es_incluso_m_s_chafa[p] = _rbol_chafa_que_ni_siquiera_es_necesario_para_sacar_la_primera_subtarea__pero_se_ve_mejor_que_hacer_una_fuerza_bruta_que_es_incluso_m_s_chafa[p * 2] + _rbol_chafa_que_ni_siquiera_es_necesario_para_sacar_la_primera_subtarea__pero_se_ve_mejor_que_hacer_una_fuerza_bruta_que_es_incluso_m_s_chafa[p * 2 + 1];
}
void Actualizar_chafa(int i, int d, int p, int I, int D){
  Propagar_chafa(i, d, p);
  if(i >= I and d <= D){
    _rbol_chafa_que_ni_siquiera_es_necesario_para_sacar_la_primera_subtarea__pero_se_ve_mejor_que_hacer_una_fuerza_bruta_que_es_incluso_m_s_chafa[p] = d - i + 1 - _rbol_chafa_que_ni_siquiera_es_necesario_para_sacar_la_primera_subtarea__pero_se_ve_mejor_que_hacer_una_fuerza_bruta_que_es_incluso_m_s_chafa[p];
    if(i != d){
      Invertir[p * 2] = !Invertir[p * 2];
      Invertir[p * 2 + 1] = !Invertir[p * 2 + 1];
    }
    return;
  }
  if(i > D or d < I) return;
  int P = (i + d) / 2;
  Actualizar_chafa(i, P, p * 2, I, D);
  Actualizar_chafa(P + 1, d, p * 2 + 1, I, D);
  _rbol_chafa_que_ni_siquiera_es_necesario_para_sacar_la_primera_subtarea__pero_se_ve_mejor_que_hacer_una_fuerza_bruta_que_es_incluso_m_s_chafa[p] = _rbol_chafa_que_ni_siquiera_es_necesario_para_sacar_la_primera_subtarea__pero_se_ve_mejor_que_hacer_una_fuerza_bruta_que_es_incluso_m_s_chafa[p * 2] + _rbol_chafa_que_ni_siquiera_es_necesario_para_sacar_la_primera_subtarea__pero_se_ve_mejor_que_hacer_una_fuerza_bruta_que_es_incluso_m_s_chafa[p * 2 + 1];
}
void Actualizar2(int p, int o){
  if(p == -1) return;
  if(p == o) Puertas[p].Maneras = Restar(Puertas[p].Posibilidades, Puertas[p].Maneras);
  else Puertas[p] = Puertas[Sucesores[p][0]] + Puertas[Sucesores[p][1]];
  Actualizar2(Antecesor[p], o);
}
void init(int N, int M, vector<int> P, vector<int> A){
  n = N;
  m = M;
  if(n > 1022 or m > 1022) _2 = 0;
  Estado = A;
  Sucesores.assign(n + m, {});
  if(n > 1) _1 = 0;
  for(int i = 1; i < n + m; i++){
    if(P[i] != (i - 1) / 2) _rbol_de_segmentos = 0;
  }
  vector<int> Grado(n + m, 0);
  Nada.Maneras = 0;
  Nada.Posibilidades = 1;
  Puertas.assign(n + m, Nada);
  for(int i = 0; i < n + m; i++){
    Antecesor.push_back(P[i]);
    if(i > 0){
      Grado[P[i]]++;
      if(Grado[P[i]] > 2){
        _2 = 0;
        _rbol_de_segmentos = 0;
        break;
      }
      Sucesores[P[i]].push_back(i);
    }
    if(i >= n){
      Puertas[i].Maneras = 1 - A[i - n];
      Puertas[i].Posibilidades = 1;
    }
  }
  Invertir.assign(m * 4 + 22, 0);
  if(_1){
    _rbol_chafa_que_ni_siquiera_es_necesario_para_sacar_la_primera_subtarea__pero_se_ve_mejor_que_hacer_una_fuerza_bruta_que_es_incluso_m_s_chafa.assign(n * 4 + 22, 0);
    Crear_chafa(0, m - 1, 1);
    return;
  }
  if(_rbol_de_segmentos){
    _rbol.assign(m * 4 + 22, Nada);
    Crear(0, m - 1, 1);
    return;
  }
  if(_2){
    for(int i = 0; i < m; i++) Actualizar2(i + n, i + n);
    return;
  }
}
int q = 0;
int count_ways(int l, int r){
  if(_1){
    l--;
    r--;
    Actualizar_chafa(0, m - 1, 1, l, r);
    return (int)_rbol_chafa_que_ni_siquiera_es_necesario_para_sacar_la_primera_subtarea__pero_se_ve_mejor_que_hacer_una_fuerza_bruta_que_es_incluso_m_s_chafa[1] % M_dulo;
  }
  if(_rbol_de_segmentos){
    l -= n;
    r -= n;
    Actualizar(0, m - 1, 1, l, r);
    return (int)_rbol[1].Maneras % M_dulo;
  }
  if(_2){
    q++;
    if(q > 7) _2 = 0;
    for(; l <= r; l++) Actualizar2(l, l);
    return (int)Puertas[0].Maneras % M_dulo;
  }
  return 0;
}