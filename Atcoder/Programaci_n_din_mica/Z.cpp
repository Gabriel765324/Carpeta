#include "bits/stdc++.h"
using namespace std;
struct Recta{
    __int128 Pendiente, Desplazamiento;
    bool Vac_o;
    Recta(__int128 p, __int128 d, bool v){
        Pendiente = p;
        Desplazamiento = d;
        Vac_o = v;
    }
    __int128 Evaluar(__int128 x){
        return x * Pendiente + Desplazamiento;
    }
};
vector<Recta> _rbol;
__int128 Consulta(__int128 i, __int128 d, __int128 p, __int128 c){
    if(_rbol[p].Vac_o or i > c or d < c) return (__int128)LLONG_MAX * (__int128)22222222;
    if(i == c and d == c) return _rbol[p].Evaluar(c);
    int P = (i + d) / 2;
    return min(_rbol[p].Evaluar(c), min(Consulta(i, P, p * 2, c), Consulta(P + 1, d, p * 2 + 1, c)));
}
void Actualizar(int i, int d, int p, Recta v){
    if(v.Vac_o) return;
    int P = (i + d) / 2;
    if(v.Evaluar(P) < _rbol[p].Evaluar(P) or _rbol[p].Vac_o) swap(v, _rbol[p]);
    if(i == d or v.Vac_o) return;
    if(v.Evaluar(i) < _rbol[p].Evaluar(i)) Actualizar(i, P, p * 2, v);
    else Actualizar(P + 1, d, p * 2 + 1, v);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    __int128 c;
    long long C;
    cin>>n>>C;
    c = C;
    _rbol.assign(4444444, Recta(0, 0, 1));
    long long A;
    __int128 a;
    cin>>A;
    a = A;
    n--;
    Actualizar(0, 1000022, 1, Recta(-(__int128)2 * a, a * a, 0));
    while(n--){
        cin>>A;
        a = A;
        if(n == 0){
            cout<<(unsigned long long)(a * a + Consulta(0, 1000022, 1, a) + c);
            return 0;
        }
        Actualizar(0, 1000022, 1, Recta(-(__int128)2 * a, (__int128)2 * a * a + Consulta(0, 1000022, 1, a) + c, 0));
    }
    return 0;
}