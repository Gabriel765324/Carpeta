#include "bits/stdc++.h"
using namespace std;
//¿Para qué le puse también suma al árbol de segmentos?
mt19937_64 Aleatorio(16);
vector<long long> a, Llevo, Propagar;
struct Nodo{
    long long Suma, Menor;
};
long long Mucho = 2222222222222222;
vector<Nodo> _rbol;
Nodo Nada;
Nodo operator+(const Nodo &a, const Nodo &b){
    Nodo Retorno;
    Retorno.Menor = min(a.Menor, b.Menor);
    Retorno.Suma = a.Suma + b.Suma;
    return Retorno;
}
void Crear(long long i, long long d, long long p){
    if(i == d){
        _rbol[p].Menor = Llevo[i];
        _rbol[p].Suma = Llevo[i];
        return;
    }
    long long P = (i + d) / 2;
    Crear(i, P, p * 2);
    Crear(P + 1, d, p * 2 + 1);
    _rbol[p] = _rbol[p * 2] + _rbol[p * 2 + 1];
}
Nodo Consulta(long long i, long long d, long long p, long long I, long long D){
    if(Propagar[p] != Mucho){
        _rbol[p].Menor += Propagar[p];
        _rbol[p].Suma += (d - i + 1) * Propagar[p];
        if(i != d){
            if(Propagar[p * 2] != Mucho) Propagar[p * 2] += Propagar[p];
            else Propagar[p * 2] = Propagar[p];
            if(Propagar[p * 2 + 1] != Mucho) Propagar[p * 2 + 1] += Propagar[p];
            else Propagar[p * 2 + 1] = Propagar[p];
        }
        Propagar[p] = Mucho;
    }
    if(i >= I and d <= D) return _rbol[p];
    if(i > D or d < I) return Nada;
    long long P = (i + d) / 2;
    return Consulta(i, P, p * 2, I, D) + Consulta(P + 1, d, p * 2 + 1, I, D);
}
void Actualizar(long long i, long long d, long long p, long long I, long long D, long long v){
    if(Propagar[p] != Mucho){
        _rbol[p].Menor += Propagar[p];
        _rbol[p].Suma += (d - i + 1) * Propagar[p];
        if(i != d){
            if(Propagar[p * 2] != Mucho) Propagar[p * 2] += Propagar[p];
            else Propagar[p * 2] = Propagar[p];
            if(Propagar[p * 2 + 1] != Mucho) Propagar[p * 2 + 1] += Propagar[p];
            else Propagar[p * 2 + 1] = Propagar[p];
        }
        Propagar[p] = Mucho;
    }
    if(i >= I and d <= D){
        _rbol[p].Menor += v;
        _rbol[p].Suma += (d - i + 1) * v;
        if(i != d){
            if(Propagar[p * 2] != Mucho) Propagar[p * 2] += v;
            else Propagar[p * 2] = v;
            if(Propagar[p * 2 + 1] != Mucho) Propagar[p * 2 + 1] += v;
            else Propagar[p * 2 + 1] = v;
        }
        return;
    }
    if(i > D or d < I) return;
    long long P = (i + d) / 2;
    Actualizar(i, P, p * 2, I, D, v);
    Actualizar(P + 1, d, p * 2 + 1, I, D, v);
    _rbol[p] = _rbol[p * 2] + _rbol[p * 2 + 1];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    a.assign(n, 0);
    Llevo = a;
    Nada.Menor = Mucho;
    Nada.Suma = 0;
    _rbol.assign(n * 4, Nada);
    Propagar.assign(n * 4, Mucho);
    vector< pair<long long, long long> > Valores_negativos;
    long long r = 0;
    for(long long i = 0; i < n; i++){
        cin>>a[i];
        if(i > 0) Llevo[i] += Llevo[i - 1];
        Llevo[i] += max(0LL, a[i]);
        r += (a[i] >= 0) ? 1 : 0;
        if(a[i] < 0) Valores_negativos.push_back({a[i], i});
    }
    Crear(0, n - 1, 1);
    sort(Valores_negativos.rbegin(), Valores_negativos.rend());
    for(long long i = 0; i < Valores_negativos.size(); i++){
        vector<long long> Reponer;
        long long Peque_o = Consulta(0, n - 1, 1, Valores_negativos[i].second, n - 1).Menor;
        if(Peque_o + Valores_negativos[i].first >= 0){
            r++;
            Actualizar(0, n - 1, 1, Valores_negativos[i].second, n - 1, Valores_negativos[i].first);
        }
    }
    cout<<r;
    return 0;
}
/*
Caso fallido:
5
1 -6 -5 -1 -7
Da: 3
Debería dar: 2
*/
    /*uniform_int_distribution<long long> Tama_o(4, 8), Valores(-12, 12);
    long long Caso = 0;
    while(1){
        Caso++;
        if(Caso % 222 == 0) cerr<<Caso<<"\n";
        long long n = 12;
        vector<long long> a(n), Llevo(n, 0);
        vector< pair<long long, long long> > Valores_negativos;
        long long r = 0;
        for(long long i = 0; i < n; i++){
            a[i] = Valores(Aleatorio);
            if(i > 0) Llevo[i] += Llevo[i - 1];
            Llevo[i] += max(0LL, a[i]);
            r += (a[i] >= 0) ? 1 : 0;
            if(a[i] < 0) Valores_negativos.push_back({a[i], i});
        }
        sort(Valores_negativos.rbegin(), Valores_negativos.rend());
        for(long long i = 0; i < Valores_negativos.size(); i++){
            vector<long long> Reponer;
            bool Mal = 0;
            for(long long j = Valores_negativos[i].second; j < n; j++){
                Reponer.push_back(Llevo[j]);
                Llevo[j] += Valores_negativos[i].first;
                if(Llevo[j] < 0){
                    Mal = 1;
                    break;
                }
            }
            if(Mal){
                for(long long j = 0; j < Reponer.size(); j++){
                    Llevo[Valores_negativos[i].second + j] = Llevo[j];
                }
            } else {
                r++;
            }
        }
        long long Mejor = 0;
        for(long long Intento = 0; Intento < (1LL<<n); Intento++){
            vector<bool> Tomo(n, 0);
            long long Tomados = 0;
            for(long long i = 0; i < n; i++){
                if((Intento & (1LL<<i)) > 0){
                    Tomo[i] = 1;
                    Tomados++;
                }
                //cout<<Tomo[i]<<" ";
            }
            //cout<<"\n";
            bool Bien = 1;
            long long Vida = 0;
            for(long long i = 0; i < n; i++){
                Vida += a[i] * Tomo[i];
                if(Vida < 0){
                    Bien = 0;
                    break;
                }
            }
            if(Bien) Mejor = max(Mejor, Tomados);
        }
        if(Mejor > r){
            cout<<"Mal.\n";
            cout<<r<<" "<<Mejor<<"\n";
            for(auto E: a) cout<<E<<" ";
            return 0;
        } 
    }*/