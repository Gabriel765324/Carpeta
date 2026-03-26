#include "bits/stdc++.h"
using namespace std;
int Potencia(int b, int e){
  if(e == 0) return 1;
  if(e == 1) return b;
  int a = Potencia(b, e / 2);
  a *= a * Potencia(b, e % 2);
  return a;
}
int main(){
  //vector<int> r1;
  vector<int> Primitos;
  vector<bool> Primosos(2222, 1);
  Primosos[0] = 0;
  Primosos[1] = 0;
  for(int i = 2; i < 1002; i++){
    if(Primosos[i]){
    Primitos.push_back(i);
    for(int j = i * i; j < 1002; j += i) Primosos[j] = 0;
    }
  }
  map<int, vector<int> > Divisores;
  map<int, int> Tama_os;
  //vector<int> Candidatos = {982800, 942480, 831600}
  int Probar = 1000000;
  for(int n11 = 1; n11 <= Probar; n11++){
    int n1 = n11;
    int cn1 = n1;
    unordered_map<int, int> Primos1;
    vector<int> Hay1;
    //cerr<<n<<"\n";
    for(int i1 = 0; Primitos[i1] * Primitos[i1] <= n1 and i1 < Primitos.size(); i1++){
      //cerr<<n % i<<"\n";
      while(n1 % Primitos[i1] == 0){
        //cerr<<i<<" divide a "<<n<<"\n";
        Primos1[Primitos[i1]]++;
        if(Hay1.size() == 0) Hay1.push_back(Primitos[i1]);
        else if(Hay1.back() != Primitos[i1]) Hay1.push_back(Primitos[i1]);
        n1 /= Primitos[i1];
      }
      //cerr<<"Ese era el residuo.\n";
    }
    if(n1 > 1){
      Primos1[n1]++;
      if(Hay1.size() == 0) Hay1.push_back(n1);
      else if(Hay1.back() != n1) Hay1.push_back(n1);
    }
    //cerr<<"Primoso.\n";
    n1 = Hay1.size();
    vector<int> Usos1(n1, 0);
    bool Continuar = 1;
    while(Continuar){
      int Divisor1 = 1;
      for(int i1 = 0; i1 < n1; i1++) Divisor1 *= Potencia(Hay1[i1], Usos1[i1]);
      ////cerr<<Divisor<<" "<<cn<<"\n";
      //cout<<"    Mapa["<<cn1<<"].push_back("<<Divisor1<<");\n";
      Divisores[n11].push_back(Divisor1);
      Tama_os[n11]++;
      //cout<<Divisor1<<", ";
      for(int i1 = n1 - 1; i1 > -2; i1--){
        if(i1 == -1){
          //cerr<<"Acab_.\n";
          Continuar = 0;
          break;
        }
        Usos1[i1]++;
        if(Usos1[i1] > Primos1[Hay1[i1]]) Usos1[i1] = 0;
        else break;
      }
    }
  }
  vector< pair<int, int> > Veamos;
  for(int i = 1; i <= Probar; i++){
    Veamos.push_back({Tama_os[i], i});
  }
  sort(Veamos.rbegin(), Veamos.rend());
  for(auto E: Veamos){
    if(E.first < 160) break;
    cout<<"  Divisores["<<E.second<<"] = {";
    int n1 = E.second;
    int cn1 = n1;
    vector<int> Ahora_si;
    unordered_map<int, int> Primos1;
    vector<int> Hay1;
    //cerr<<n<<"\n";
    for(int i1 = 0; Primitos[i1] * Primitos[i1] <= n1 and i1 < Primitos.size(); i1++){
      //cerr<<n % i<<"\n";
      while(n1 % Primitos[i1] == 0){
        //cerr<<i<<" divide a "<<n<<"\n";
        Primos1[Primitos[i1]]++;
        if(Hay1.size() == 0) Hay1.push_back(Primitos[i1]);
        else if(Hay1.back() != Primitos[i1]) Hay1.push_back(Primitos[i1]);
        n1 /= Primitos[i1];
      }
      //cerr<<"Ese era el residuo.\n";
    }
    if(n1 > 1){
      Primos1[n1]++;
      if(Hay1.size() == 0) Hay1.push_back(n1);
      else if(Hay1.back() != n1) Hay1.push_back(n1);
    }
    //cerr<<"Primoso.\n";
    n1 = Hay1.size();
    vector<int> Usos1(n1, 0);
    bool Continuar = 1;
    while(Continuar){
      int Divisor1 = 1;
      for(int i1 = 0; i1 < n1; i1++) Divisor1 *= Potencia(Hay1[i1], Usos1[i1]);
      ////cerr<<Divisor<<" "<<cn<<"\n";
      //cout<<"    Mapa["<<cn1<<"].push_back("<<Divisor1<<");\n";
      Ahora_si.push_back(Divisor1);
      for(int i1 = n1 - 1; i1 > -2; i1--){
        if(i1 == -1){
          //cerr<<"Acab_.\n";
          Continuar = 0;
          break;
        }
        Usos1[i1]++;
        if(Usos1[i1] > Primos1[Hay1[i1]]) Usos1[i1] = 0;
        else break;
      }
    }
    for(int i = 0; i < Ahora_si.size(); i++){
      if(i > 0) cout<<", ";
      cout<<Ahora_si[i];
    }
    //cout<<E.first<<" "<<E.second<<"\n";
    cout<<"};\n";
  }
  return 0;
}