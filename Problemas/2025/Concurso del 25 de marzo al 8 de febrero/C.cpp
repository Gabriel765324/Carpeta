#include "bits/stdc++.h"
using namespace std;
struct Cuarto{
    long long Cortes, Valor_quitado_tras_otro_corte, Valor, Suma;
};
map< pair<long long, long long>, long long> Memorizaci_n;
vector<long long> Criba;
long long Menor(long long Valor, long long Cortes, long long Suma){
    if(Memorizaci_n.count({Suma, Cortes}) == 1) return Memorizaci_n[{Suma, Cortes}];
    long long Posible = Valor * (Valor + 1) / 2 * (Cortes - 1) + (Suma % Cortes + Valor) * (Suma % Cortes + Valor + 1) / 2;
    if(Cortes == 1) return Posible;
    for(long long Otro_valor = max(Valor - 2, 1LL); Otro_valor <= Valor + 2; Otro_valor++){
        if(Suma < Otro_valor) continue;
        long long Residuo = Suma - Otro_valor * (Cortes - 1), Otro_posible = (Otro_valor) * (Otro_valor + 1) / 2 * (Cortes - 1) + Residuo * (Residuo + 1) / 2;
        Posible = min(Posible, Otro_posible);
    }
    if(__gcd(Suma, Cortes) == 1){
        return Memorizaci_n[{Suma, Cortes}] = Posible;
    } else {
        for(long long i = Cortes; i > 1; i /= Criba[i]){
            if(Suma % Criba[i] == 0) Posible = min(Posible, Criba[i] * Menor(Valor, Cortes / Criba[i], Suma / Criba[i]));
        }
        return Memorizaci_n[{Suma, Cortes}] = Posible;
    }
}
Cuarto operator+(const Cuarto &a, const long long &b){
    Cuarto Retorno;
    Retorno.Suma = a.Suma;
    Retorno.Cortes = a.Cortes + b;
    long long Valor = a.Suma / Retorno.Cortes;
    Retorno.Valor = Menor(Valor, Retorno.Cortes, a.Suma);
    if(Retorno.Cortes == Retorno.Suma){
        Retorno.Valor_quitado_tras_otro_corte = 0;
        return Retorno;
    }
    Retorno.Cortes++;
    Valor = a.Suma / Retorno.Cortes;
    Retorno.Valor_quitado_tras_otro_corte = Retorno.Valor - Menor(Valor, Retorno.Cortes, a.Suma);
    Retorno.Cortes--;
    return Retorno;
}
bool operator<(const Cuarto &a, const Cuarto &b){
    return a.Valor_quitado_tras_otro_corte > b.Valor_quitado_tras_otro_corte;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(long long i = 0; i < 1000222; i++){
        Criba.push_back(i);
    }
    for(long long i = 2; i < 1000222; i++){
        if(Criba[i] == i){
            for(long long j = i * i; j < 1000222; j += i){
                Criba[j] = i;
            }
        }
    }
    long long n, m, k;
    cin>>n>>m>>k;
    set<long long> Hay;
    map<long long, long long> Llegada;
    for(long long i = 0; i < n; i++){
        long long a;
        cin>>a;
        Llegada[a]++;
        Hay.insert(a);
    }
    //cout<<"Escaneado.\n";
    vector<Cuarto> s;
    for(auto E: Hay){
        Cuarto Nuevo;
        Nuevo.Cortes = 1;
        Nuevo.Suma = Llegada[E];
        Nuevo.Valor = 0;
        Nuevo.Valor_quitado_tras_otro_corte = 0;
        //cout<<"Seguro aquí falla.\n";
        Nuevo = Nuevo + 0LL;
        //cout<<"No.\n";
        s.push_back(Nuevo);
    }
    //cout<<"Creado.\n";
    /*while(k--){
        Cuarto Actual = *s.begin();
        s.erase(s.find(Actual));
        //cout<<Actual.Cortes<<" "<<Actual.Suma<<" "<<Actual.Valor<<" "<<Actual.Valor_quitado_tras_otro_corte<<"\n";
        if(Actual.Valor_quitado_tras_otro_corte == 0){
            s.insert(Actual);
            break;
        }
        Actual = Actual + 1LL;
        s.insert(Actual);
    }*/
    vector< vector<long long> > PD(s.size() + 2, vector<long long>(k + 2, 2222222222222222));
    PD[s.size()][0] = 0;
    for(long long i = s.size() - 1; i > -1; i--){
        for(long long j = 0; j <= k; j++){
            for(long long ii = 0; ii <= j; ii++){
                PD[i][j] = min(PD[i][j], PD[i + 1][j - ii] + (s[i] + ii).Valor);
            }
        }
    }
    /*for(auto E: PD){
        for(auto e: E){
            cout<<e<<" ";
        }
        cout<<"\n";
    }*/
    /*long long Valor = 0;
    for(auto E: s) Valor += E.Valor;
    cout<<Valor;*/
    cout<<PD[0][k];
    return 0;
}