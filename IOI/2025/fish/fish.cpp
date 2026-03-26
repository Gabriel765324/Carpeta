#include "fish.h"
#include <bits/stdc++.h>
using namespace std;
int Capas, Mayor;
struct Pez{
  int x, y;
  long long Valor;
};
vector< vector<Pez> > Puntos;
vector< map< long long, unordered_map<long long, long long> > > PD;
set< pair< pair<long long, long long>, long long> > Hay;
long long Resolver(int i, int Altura_anterior, int Altura_actual){
  int n = Puntos[i].size();
  if(i == Capas) return 0;
  if(Hay.count({{i, Altura_anterior}, Altura_actual}) != 0) return PD[i][Altura_anterior][Altura_actual];
  int x = Puntos[i][0].x, Izquierda = 0, Derecha = n - 1, Mejor_actual = n, Mejor_ambos = n;
  while(1){
    int Promedio = (Izquierda + Derecha) / 2;
    if(Altura_actual >= Puntos[i].back().y) break;
    if(Altura_actual < Puntos[i][Promedio].y){
      Mejor_actual = Promedio;
      Derecha = Promedio - 1;
    } else Izquierda = Promedio + 1;
    if(Izquierda >= Derecha + 1) break;
  }
  Izquierda = 0, Derecha = n - 1;
  while(1){
    int Promedio = (Izquierda + Derecha) / 2;
    if(max(Altura_actual, Altura_anterior) >= Puntos[i].back().y) break;
    if(max(Altura_actual, Altura_anterior) < Puntos[i][Promedio].y){
      Mejor_ambos = Promedio;
      Derecha = Promedio - 1;
    } else Izquierda = Promedio + 1;
    if(Izquierda >= Derecha + 1) break;
  }
  if(i == Capas - 1){
    if(x < Mayor){
      long long Suma = 0;
      for(; Mejor_ambos < n; Mejor_ambos++) Suma += Puntos[i][Mejor_ambos].Valor;
      Hay.insert({{i, Altura_anterior}, Altura_actual});
      //cerr<<i<<" "<<Altura_anterior<<" "<<Altura_actual<<"\n"<<Suma<<"\n";
      return PD[i][Altura_anterior][Altura_actual] = Suma;
    } else {
      Hay.insert({{i, Altura_anterior}, Altura_actual});
      //cerr<<i<<" "<<Altura_anterior<<" "<<Altura_actual<<"\n"<<0<<"\n";
      return PD[i][Altura_anterior][Altura_actual] = 0;
    }
  } else {
    if(i + 2 < Capas){
      if(Puntos[i + 1][0].x == x + 2){
        int m = Puntos[i + 1].size();
        long long Suma = 0, Mayor = 0;
        vector<int> Opciones = {-1};
        for(int j = 0; j < n; j++) Opciones.push_back(Puntos[i][j].y);
        for(int j = 0; j < m; j++) Opciones.push_back(Puntos[i + 1][j].y);
        sort(Opciones.begin(), Opciones.end());
        int j = 0, k = 0;
        for(auto E: Opciones){
          if(j < n and E >= Puntos[i][j].y){
            if(Puntos[i][j].y > max(Altura_actual, Altura_anterior)) Suma += Puntos[i][j].Valor;
            j++;
          }
          if(k < m and E >= Puntos[i + 1][k].y){
            Suma += Puntos[i + 1][k].Valor;
            k++;
          }
          Mayor = max(Mayor, Resolver(i + 1, E, -1) + Suma);
        }
        Hay.insert({{i, Altura_anterior}, Altura_actual});
        //cerr<<i<<" "<<Altura_anterior<<" "<<Altura_actual<<"\n"<<Mayor<<"\n";
        return PD[i][Altura_anterior][Altura_actual] = Mayor;
      } else if(Puntos[i + 2][0].x == x + 2){
        int m = Puntos[i + 2].size(), mm = Puntos[i + 1].size();
        long long Suma = 0, Mayor = 0;
        vector<int> Opciones = {-1};
        for(int j = 0; j < n; j++) Opciones.push_back(Puntos[i][j].y);
        for(int j = 0; j < mm; j++) Opciones.push_back(Puntos[i + 1][j].y);
        for(int j = 0; j < m; j++) Opciones.push_back(Puntos[i + 2][j].y);
        sort(Opciones.begin(), Opciones.end());
        int j = 0, k = 0, l = 0;
        for(auto E: Opciones){
          if(j < n and E >= Puntos[i][j].y){
            if(Puntos[i][j].y > max(Altura_actual, Altura_anterior)) Suma += Puntos[i][j].Valor;
            j++;
          }
          if(k < m and E >= Puntos[i + 2][k].y){
            Suma += Puntos[i + 2][k].Valor;
            k++;
          }
          if(l < mm and E >= Puntos[i + 1][l].y){
            if(Puntos[i + 1][l].y <= Altura_actual) Suma -= Puntos[i + 1][l].Valor;
            l++;
          }
          Mayor = max(Mayor, Resolver(i + 1, Altura_actual, E) + Suma);
        }
        Hay.insert({{i, Altura_anterior}, Altura_actual});
        //cerr<<i<<" "<<Altura_anterior<<" "<<Altura_actual<<"\n"<<Mayor<<"\n";
        return PD[i][Altura_anterior][Altura_actual] = Mayor;
      } else if(Puntos[i + 1][0].x == x + 1){
        int m = Puntos[i + 1].size();
        long long Suma = 0, Mayor = 0;
        vector<int> Opciones = {-1};
        for(int j = 0; j < n; j++) Opciones.push_back(Puntos[i][j].y);
        for(int j = 0; j < m; j++) Opciones.push_back(Puntos[i + 1][j].y);
        sort(Opciones.begin(), Opciones.end());
        int j = 0, k = 0;
        for(auto E: Opciones){
          if(j < n and E >= Puntos[i][j].y){
            if(Puntos[i][j].y > max(Altura_actual, Altura_anterior)) Suma += Puntos[i][j].Valor;
            j++;
          }
          if(k < m and E >= Puntos[i + 1][k].y){
            if(Puntos[i + 1][k].y <= Altura_actual) Suma -= Puntos[i + 1][k].Valor;
            k++;
          }
          Mayor = max(Mayor, Resolver(i + 1, Altura_actual, E) + Suma);
        }
        Hay.insert({{i, Altura_anterior}, Altura_actual});
        //cerr<<i<<" "<<Altura_anterior<<" "<<Altura_actual<<"\n"<<Mayor<<"\n";
        return PD[i][Altura_anterior][Altura_actual] = Mayor;
      } else {
        long long Suma = 0;
        for(; Mejor_ambos < n; Mejor_ambos++) Suma += Puntos[i][Mejor_ambos].Valor;
        Hay.insert({{i, Altura_anterior}, Altura_actual});
        //cerr<<i<<" "<<Altura_anterior<<" "<<Altura_actual<<"\n"<<Mayor<<"\n";
        return PD[i][Altura_anterior][Altura_actual] = Suma + Resolver(i + 1, -1, -1);
      }
    }
    if(Puntos[i + 1][0].x == x + 2){
      int m = Puntos[i + 1].size();
      long long Suma = 0, Mayor = 0;
      vector<int> Opciones = {-1};
      for(int j = 0; j < n; j++) Opciones.push_back(Puntos[i][j].y);
      for(int j = 0; j < m; j++) Opciones.push_back(Puntos[i + 1][j].y);
      sort(Opciones.begin(), Opciones.end());
      int j = 0, k = 0;
      for(auto E: Opciones){
        if(j < n and E >= Puntos[i][j].y){
          if(Puntos[i][j].y > max(Altura_actual, Altura_anterior)) Suma += Puntos[i][j].Valor;
          j++;
        }
        if(k < m and E >= Puntos[i + 1][k].y){
          Suma += Puntos[i + 1][k].Valor;
          k++;
        }
        Mayor = max(Mayor, Resolver(i + 1, E, -1) + Suma);
      }
      Hay.insert({{i, Altura_anterior}, Altura_actual});
      //cerr<<i<<" "<<Altura_anterior<<" "<<Altura_actual<<"\n"<<Mayor<<"\n";
      return PD[i][Altura_anterior][Altura_actual] = Mayor;
    } else if(Puntos[i + 1][0].x == x + 1){
      int m = Puntos[i + 1].size();
      long long Suma = 0, Mayor = 0;
      vector<int> Opciones = {-1};
      for(int j = 0; j < n; j++) Opciones.push_back(Puntos[i][j].y);
      for(int j = 0; j < m; j++) Opciones.push_back(Puntos[i + 1][j].y);
      sort(Opciones.begin(), Opciones.end());
      int j = 0, k = 0;
      for(auto E: Opciones){
        if(j < n and E >= Puntos[i][j].y){
          if(Puntos[i][j].y > max(Altura_actual, Altura_anterior)) Suma += Puntos[i][j].Valor;
          j++;
        }
        if(k < m and E >= Puntos[i + 1][k].y){
          if(Puntos[i + 1][k].y <= Altura_actual) Suma -= Puntos[i + 1][k].Valor;
          k++;
        }
        Mayor = max(Mayor, Resolver(i + 1, Altura_actual, E) + Suma);
      }
      Hay.insert({{i, Altura_anterior}, Altura_actual});
      //cerr<<i<<" "<<Altura_anterior<<" "<<Altura_actual<<"\n"<<Mayor<<"\n";
      return PD[i][Altura_anterior][Altura_actual] = Mayor;
    } else {
      long long Suma = 0;
      for(; Mejor_ambos < n; Mejor_ambos++) Suma += Puntos[i][Mejor_ambos].Valor;
      Hay.insert({{i, Altura_anterior}, Altura_actual});
      //cerr<<i<<" "<<Altura_anterior<<" "<<Altura_actual<<"\n"<<Mayor<<"\n";
      return PD[i][Altura_anterior][Altura_actual] = Suma + Resolver(i + 1, -1, -1);
    }
  }
}
long long max_weights(int n, int m, vector<int> x, vector<int> y, vector<int> w){
  swap(n, m);
  //cerr<<n<<" "<<m<<"\n";
  if(m == 1) return 0LL;
  bool Par = 1, Menor_o_igual_a_uno = 1;
  long long Suma = 0;
  for(int i = 0; i < n; i++){
    Suma += w[i];
    if(x[i] % 2 != 0) Par = 0;
    if(x[i] > 1) Menor_o_igual_a_uno = 0;
  }
  if(Par) return Suma;
  if(Menor_o_igual_a_uno){
    vector<long long> Opciones;
    long long Suma_0 = 0, Suma_1 = 0;
    for(int i = 0; i < n; i++){
      if(x[i] == 0) Suma_0 += w[i];
      else Suma_1 += w[i];
      Opciones.push_back(y[i]);
    }
    long long r = max(Suma_0, Suma_1);
    if(m >= 3){
      vector< pair< pair<int, int>, int> > Pez_causas(n);
      for(int i = 0; i < n; i++) Pez_causas[i] = {{x[i], y[i]}, w[i]};
      sort(Pez_causas.begin(), Pez_causas.end());
      int i;
      for(i = 0; i < n and Pez_causas[i].first.first == 0; i++){}
      sort(Opciones.begin(), Opciones.end());
      int j = 0, ii = i;
      for(auto E: Opciones){
        while(i < n and Pez_causas[i].first.second <= E){
          Suma_1 -= Pez_causas[i].second;
          i++;
        }
        while(j < ii and Pez_causas[j].first.second <= E){
          Suma_1 += Pez_causas[j].second;
          j++;
        }
        r = max(r, Suma_1);
      }
    }
    return r;
  }
  Mayor = m - 1;
  vector< pair< pair<int, int>, int> > Pez_causas(n);
  for(int i = 0; i < n; i++) Pez_causas[i] = {{x[i], y[i]}, w[i]};
  sort(Pez_causas.begin(), Pez_causas.end());
  map< long long, unordered_map<long long, long long> > A;
  for(auto E: Pez_causas){
    Pez Actual;
    Actual.x = E.first.first;
    Actual.y = E.first.second;
    Actual.Valor = E.second;
    if(Puntos.size() > 0 and Puntos.back().size() > 0 and Puntos.back()[0].x == Actual.x) Puntos.back().push_back(Actual);
    else Puntos.push_back({Actual});
  }
  Capas = Puntos.size();
  PD.assign(Capas, A);
  long long Mejor = Resolver(0, -1, -1);
  if(Puntos[0][0].x > 0){
    n = Puntos[0].size();
    Suma = 0;
    for(int i = 0; i < n; i++) Suma += Puntos[0][i].Valor;
    Mejor = max(Mejor, Resolver(0, Puntos[0].back().y, -1) + Suma);
    if(Puntos.size() >= 2 and Puntos[1][0].x - Puntos[0][0].x == 0){
      n = Puntos[0].size();
      m = Puntos[1].size();
      Suma = 0;
      vector<int> Opciones = {-1};
      for(int i = 0; i < n; i++) Opciones.push_back(Puntos[0][i].y);
      for(int i = 0; i < m; i++) Opciones.push_back(Puntos[1][i].y);
      sort(Opciones.begin(), Opciones.end());
      int i = 0, j = 0;
      for(auto E: Opciones){
        if(i < n and Puntos[0][i].y >= E){
          Suma -= Puntos[0][i].Valor;
          i++;
        }
        if(j < m and Puntos[1][j].y >= E){
          Suma += Puntos[1][j].Valor;
          j++;
        }
        Mejor = max(Mejor, Resolver(0, Puntos[0].back().y, E) + Suma);
      }
    }
  } else {
    if(Puntos.size() >= 2 and Puntos[1][0].x - Puntos[0][0].x == 0){
      n = Puntos[0].size();
      m = Puntos[1].size();
      Suma = 0;
      vector<int> Opciones = {-1};
      for(int i = 0; i < n; i++) Opciones.push_back(Puntos[0][i].y);
      for(int i = 0; i < m; i++) Opciones.push_back(Puntos[1][i].y);
      sort(Opciones.begin(), Opciones.end());
      int i = 0, j = 0;
      for(auto E: Opciones){
        if(j < m and Puntos[1][j].y >= E){
          Suma += Puntos[1][j].Valor;
          j++;
        }
        Mejor = max(Mejor, Resolver(0, -1, E) + Suma);
      }
    }
  }
  return Mejor;
}