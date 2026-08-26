#include "bits/stdc++.h"
using namespace std;
vector<long long> Menores, a;
struct Nodo{
    long long Valor, Pendiente;
};
vector<Nodo> Mayores;
void Crear_menores(long long i, long long f, long long p){
    if(i == f) Menores[p] = a[i];
    else {
        long long P = (i + f) / 2;
        Crear_menores(i, P, p * 2);
        Crear_menores(P + 1, f, p * 2 + 1);
        Menores[p] = min(Menores[p * 2], Menores[p * 2 + 1]);
    }
}
long long Consulta_menor(long long i, long long f, long long p, long long c, long long t){
    if(i >= c and f <= t) return Menores[p];
    if(i > t or f < c) return 2222222222222222;
    long long P = (i + f) / 2;
    return min(Consulta_menor(i, P, p * 2, c, t), Consulta_menor(P + 1, f, p * 2 + 1, c, t));
}
long long Consulta_mayor(long long i, long long f, long long p, long long A){
    Mayores[p].Valor = max(Mayores[p].Valor, Mayores[p].Pendiente);
    if((p * 2) < Mayores.size()){
        Mayores[p * 2].Pendiente = max(Mayores[p].Pendiente, Mayores[p * 2].Pendiente);
    }
    if((p * 2 + 1) < Mayores.size()){
        Mayores[p * 2 + 1].Pendiente = max(Mayores[p].Pendiente, Mayores[p * 2 + 1].Pendiente);
    }
    Mayores[p].Pendiente = 0;
    if(i == f and f == A) return Mayores[p].Valor;
    if(i > A or f < A) return -2222222222222222;
    long long P = (i + f) / 2;
    return max(Consulta_mayor(i, P, p * 2, A), Consulta_mayor(P + 1, f, p * 2 + 1, A));
}
void Actualizar_mayor(long long i, long long f, long long p, long long c, long long t, long long m){
    Mayores[p].Valor = max(Mayores[p].Valor, Mayores[p].Pendiente);
    if((p * 2) < Mayores.size()){
        Mayores[p * 2].Pendiente = max(Mayores[p].Pendiente, Mayores[p * 2].Pendiente);
    }
    if((p * 2 + 1) < Mayores.size()){
        Mayores[p * 2 + 1].Pendiente = max(Mayores[p].Pendiente, Mayores[p * 2 + 1].Pendiente);
    }
    Mayores[p].Pendiente = 0;
    if(i >= c and f <= t){
        if((p * 2) < Mayores.size()){
            Mayores[p * 2].Pendiente = max(m, Mayores[p * 2].Pendiente);
        }
        if((p * 2 + 1) < Mayores.size()){
            Mayores[p * 2 + 1].Pendiente = max(m, Mayores[p * 2 + 1].Pendiente);
        }
        Mayores[p].Valor = max(Mayores[p].Valor, m);
        return;
    }
    if(i > t or f < c) return;
    long long P = (i + f) / 2;
    Actualizar_mayor(i, P, p * 2, c, t, m);
    Actualizar_mayor(P + 1, f, p * 2 + 1, c, t, m);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    Menores.assign(n * 4, 0);
    Nodo E;
    E.Valor = 0;
    E.Pendiente = 0;
    Mayores.assign(n * 4, E);
    a.assign(n, 0);
    set< pair<long long, long long> > Posiciones; 
    for(long long i = 0; i < n; i++){
        cin>>a[i];
        Posiciones.insert(make_pair(a[i], i));
    }
    vector< pair<long long, long long> > Consultas(n);
    n--;
    //Crear_menores(0, n, 1);
    set<long long> Barreras, Otras_barreras;
    Barreras.insert(n + 1);
    Barreras.insert(-1);
    Otras_barreras.insert(- n - 1);
    Otras_barreras.insert(1);
    while(!Posiciones.empty()){
        vector<long long> Cola;
        long long Actual = (*Posiciones.begin()).first;
        while(!Posiciones.empty() and (*Posiciones.begin()).first == Actual){
            Cola.push_back((*Posiciones.begin()).second);
            Posiciones.erase(Posiciones.begin());
        }
        for(long long j = 0; j < Cola.size(); j++){
            pair<long long, long long> Nuevo;
            Nuevo.first = -(*Otras_barreras.lower_bound(-Cola[j])) + 1;
            Nuevo.second = (*Barreras.lower_bound(Cola[j])) - 1;
            /*cout<<Cola[j]<<" ";
            if(Cola[j] > n or Cola[j] < 0) cout<<"Fuera del límite\n";
            else cout<<"Bien\n";*/
            Consultas[Cola[j]] = Nuevo;
        }
        while(!Cola.empty()){
            Barreras.insert(Cola.back());
            Otras_barreras.insert(-Cola.back());
            Cola.pop_back();
        }
    }
    //for(long long i = 0; i <= n; i++) cout<<Consultas[i].first<<" "<<Consultas[i].second<<"\n";
    for(long long i = 0; i <= n; i++){
        /*long long I = i, D = n, M1 = i;
        while(1){
            if(I >= D + 1) break;
            long long P = (I + D) / 2;
            if(Consulta_menor(0, n, 1, i, P) == a[i]){
                I = P + 1;
                M1 = P;
            } else D = P - 1;
        }
        I = 0, D = i;
        long long M2 = i;
        while(1){
            if(I >= D + 1) break;
            long long P = (I + D) / 2;
            if(Consulta_menor(0, n, 1, P, i) == a[i]){
                D = P - 1;
                M2 = P;
            } else I = P + 1;
        }*/
        long long M1 = Consultas[i].second;
        long long M2 = Consultas[i].first;
        long long Rango = M1 - M2;
        //cout<<Rango<<" ";
        Actualizar_mayor(0, n, 1, 0, Rango, a[i]);
    }
    //cout<<"\n";
    for(long long i = 0; i <= n; i++){
        //cout<<i<<" ";
        cout<<Consulta_mayor(0, n, 1, i)<<" ";
        //cout<<"\n";
    }
    //cout<<"\n";
    return 0;
}