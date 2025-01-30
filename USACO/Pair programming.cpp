#include "bits/stdc++.h"
using namespace std;
long long m = 1e9 + 7;
long long n;
string s, t;
vector<string> Crear(long long i, long long j){
    if(i == n and j == i) return {""};
    vector<string> Retorno, Retorno_extra;
    if(i == n and j != n){
        Retorno = Crear(i, j + 1);
        for(long long k = 0; k < Retorno.size(); k++){
            Retorno[k] += t[j];
        }
    } else if(i != j and j == n){
        Retorno = Crear(i + 1, j);
        for(long long k = 0; k < Retorno.size(); k++){
            Retorno[k] += s[i];
        }
    } else {
        Retorno = Crear(i + 1, j);
        Retorno_extra = Crear(i, j + 1);
        for(long long k = 0; k < Retorno.size(); k++){
            Retorno[k] += s[i];
        }
        for(long long k = 0; k < Retorno_extra.size(); k++){
            Retorno_extra[k] += t[j];
            Retorno.push_back(Retorno_extra[k]);
        }
    }
    return Retorno;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long T;
    cin>>T;
    while(T--){
        cin>>n>>s>>t;
        //cout<<n<<" "<<s<<" "<<t<<"\n";
        char Caracter = 'a';
        for(long long i = 0; i < n; i++){
            if(s[i] == '+'){
                s[i] = Caracter;
                Caracter++;
            }
        }
        for(long long i = 0; i < n; i++){
            if(t[i] == '+'){
                t[i] = Caracter;
                Caracter++;
            }
        }
        vector<string> Posibilidades = Crear(0, 0);
        for(long long i = 0; i < Posibilidades.size(); i++){
            long long N = Posibilidades[i].size();
            for(long long j = 0; j < N / 2; j++){
                swap(Posibilidades[i][j], Posibilidades[i][N - j - 1]);
            }
        }
        set< map<char, long long> > Se_puede_crear;
        n *= 2;
        for(long long Posibilidad = 0; Posibilidad < Posibilidades.size(); Posibilidad++){
            map<char, long long> Suma;
            for(long long i = 0; i < n; i++){
                if(Posibilidades[Posibilidad][i] < '0' or Posibilidades[Posibilidad][i] > '9'){
                    Suma[Posibilidades[Posibilidad][i]]++;
                } else {
                    long long Multiplicar = Posibilidades[Posibilidad][i] - '0';
                    for(long long j = i; j > -1; j--){
                        if(Posibilidades[Posibilidad][j] < '0' or Posibilidades[Posibilidad][j] > '9') Suma[Posibilidades[Posibilidad][j]] *= Multiplicar;
                    }
                }
            }
            Se_puede_crear.insert(Suma);
        }
        cout<<Se_puede_crear.size() % m<<"\n";
        //cout<<Posibilidades.size();
        //for(auto E: Posibilidades) cout<<E<<"\n";
    }
    return 0;
}