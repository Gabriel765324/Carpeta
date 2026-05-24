#include "bits/stdc++.h"
using namespace std;
struct Entero{
    vector<int> v;
    int n;
    Entero(vector<int>& s){
        v = s;
        n = int(s.size());
    }
    void Suma(const Entero& a){
        int Extra = 0;
        for(int i = 0; i < n; i++){
            if(i < a.n) Extra += a.v[i];
            v[i] += Extra;
            Extra = v[i] / 10;
            v[i] %= 10;
            if(Extra == 0 and i >= a.n) break;
        }
        while(Extra > 0){
            v.push_back(Extra % 10);
            Extra /= 10;
        }
        n = int(v.size());
    }
    void Multiplicar(const int& a){
        int Extra = 0;
        for(int i = 0; i < n; i++){
            v[i] *= a;
            v[i] += Extra;
            Extra = v[i] / 10;
            v[i] %= 10;
        }
        while(Extra > 0){
            v.push_back(Extra % 10);
            Extra /= 10;
        }
        n = int(v.size());
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    vector<int> Uno = {1};
    Entero Respuesta = Entero(Uno), Caminos = Entero(Uno);
    for(auto E: s){
        if(E == 'P') continue;
        if(E == 'L' or E == 'R'){
            Respuesta.Multiplicar(2);
            if(E == 'R') Respuesta.Suma(Caminos);
        } else {
            Respuesta.Multiplicar(5);
            Respuesta.Suma(Caminos);
            Caminos.Multiplicar(3);
        }
        //for(int i = Respuesta.n - 1; i > -1; i--) cout<<Respuesta.v[i];
    }
    for(int i = Respuesta.n - 1; i > -1; i--) cout<<Respuesta.v[i];
    return 0;
}