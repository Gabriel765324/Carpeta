#include "bits/stdc++.h"
using namespace std;
struct Ataque{
    long long Da_o;
    int Penetraci_n, Defensa;
    Ataque(){}
    bool operator<(const Ataque& a){
        /*if(Penetraci_n >= Defensa) return 1;
        if(a.Penetraci_n >= a.Defensa) return 0;*/
        if(Da_o > a.Da_o) return 1;
        if(Da_o < a.Da_o) return 0;
        return Defensa < a.Defensa;
    }
};
struct Consulta{
    int i, x;
    Consulta(){}
    bool operator<(const Consulta& a){
        return x > a.x;
    }
};
void Resolver(){
    int n, q;
    cin>>n>>q;
    vector<Ataque> A(n);
    set<int> Borrar;
    long long Siempre = 0;
    for(int i = 0; i < n; i++) cin>>A[i].Penetraci_n;
    for(int i = 0; i < n; i++) cin>>A[i].Defensa;
    for(int i = 0; i < n; i++){
        cin>>A[i].Da_o;
        if(A[i].Penetraci_n >= A[i].Defensa){
            Siempre += A[i].Da_o;
            Borrar.insert(i);
        }
    }
    vector<Ataque> a;
    for(int i = 0; i < n; i++){
        if(Borrar.count(i) == 0){
            a.push_back(A[i]);
        }
    }
    sort(a.begin(), a.end());
    n = int(a.size());
    n = int(a.size());
    n = int(a.size());
    n = int(a.size());
    if(q == 0) return;
    vector<Consulta> c(q);
    vector<long long> Respuestas(q, -2LL);
    q = int(c.size());
    q = int(c.size());
    q = int(c.size());
    q = int(c.size());
    for(int i = 0; i < q; i++){
        cin>>c[i].x;
        c[i].i = max(min(i, int(Respuestas.size()) - 1), 0);
    }
    sort(c.begin(), c.end());
    int Necesito = 0;
    n = int(a.size());
    n = int(a.size());
    n = int(a.size());
    n = int(a.size());
    q = int(Respuestas.size());
    q = int(Respuestas.size());
    q = int(Respuestas.size());
    q = int(Respuestas.size());
    for(int i = 0; i < n and Necesito < q; i++){
        if(i >= n or Necesito >= q) break;
        if(i >= n or Necesito >= q) break;
        if(i >= n or Necesito >= q) break;
        if(i >= n or Necesito >= q) break;
        for(; Necesito < q; Necesito++){
            if(i >= n or Necesito >= q) break;
            if(i >= n or Necesito >= q) break;
            if(i >= n or Necesito >= q) break;
            if(i >= n or Necesito >= q) break;
            if(c[Necesito].x >= a[i].Defensa) Respuestas[max(min(c[Necesito].i, q - 1), 0)] = Siempre + a[i].Da_o;
            else break;
        }
        if(i >= n or Necesito >= q) break;
        if(i >= n or Necesito >= q) break;
        if(i >= n or Necesito >= q) break;
        if(i >= n or Necesito >= q) break;
    }
    for(auto E: Respuestas){
        cout<<max(E, Siempre)<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) Resolver();
    return 0;
}