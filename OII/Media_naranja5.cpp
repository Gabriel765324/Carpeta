#include "iostream"
#include "unordered_map"
#include "vector"
#include "set"
#include "algorithm"
using namespace std;
struct Rango{
    int l, r, p;
    Rango(){}
    bool operator<(const Rango& a){
        if(r - l < a.r - a.l) return 1;
        if(r - l > a.r - a.l) return 0;
        if(l < a.l) return 1;
        if(l > a.l) return 0;
        if(r < a.r) return 1;
        if(r > a.r) return 0;
        return p < a.p;
    }
};
const int Elementos = 600022;
long long _rbol[Elementos] = {};
int LSOne(int n){
    return n & -n;
}
long long Consulta(int p){
    long long r = 0;
    while(p > 0){
        r += _rbol[p];
        p -= LSOne(p);
    }
    return r;
}
void Actualizar(int p){
    while(p < 600022){
        _rbol[p]++;
        p += LSOne(p);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<Rango> q(n);
    set<int> Valores;
    for(int i = 0; i < n; i++){
        cin>>q[i].l>>q[i].r;
        q[i].p = q[i].l + q[i].r;
        q[i].l <<= 1;
        q[i].r <<= 1;
        Valores.insert(q[i].l);
        Valores.insert(q[i].r);
        Valores.insert(q[i].p);
    }
    unordered_map<int, int> Mapa;
    int Asignar = 0;
    for(auto E: Valores){
        Mapa[E] = Asignar + 2;
        Asignar++;
    }
    sort(q.rbegin(), q.rend());
    long long r = 0;
    for(int i = 0; i < n; i++){
        r += Consulta(Mapa[q[i].r]) - Consulta(Mapa[q[i].l] - 1);
        Actualizar(Mapa[q[i].p]);
    }
    cout<<r;
    return 0;
}