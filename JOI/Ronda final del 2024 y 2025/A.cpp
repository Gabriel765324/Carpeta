#include "bits/stdc++.h"
using namespace std;
struct Par{
    long long Valor, Posici_n;
};
bool operator<(const Par &a, const Par &b){
    if(a.Valor > b.Valor) return 1;
    if(a.Valor < b.Valor) return 0;
    return a.Posici_n < b.Posici_n;
}
vector<long long> a, b, _rbol_a, _rbol_b, Propagar_a, Propagar_b;
void Crear(long long i, long long d, long long p){
    if(i == d){
        _rbol_a[p] = 1;
        _rbol_b[p] = 1;
        return;
    }
    long long P = (i + d) / 2;
    Crear(i, P, p * 2);
    Crear(P + 1, d, p * 2 + 1);
    _rbol_a[p] = _rbol_a[p * 2] + _rbol_a[p * 2 + 1];
    _rbol_b[p] = _rbol_b[p * 2] + _rbol_b[p * 2 + 1];
}
long long Consulta_a(long long i, long long d, long long p, long long I, long long D){
    if(I > D) return 0;
    if(i != d and Propagar_a[p] != -2){
        _rbol_a[p] = (d - i + 1) * Propagar_a[p];
        Propagar_a[p * 2] = Propagar_a[p];
        Propagar_a[p * 2 + 1] = Propagar_a[p];
        Propagar_a[p] = -2;
    }
    if(I <= i and d <= D) return _rbol_a[p];
    if(i > D or d < I) return 0;
    long long P = (i + d) / 2;
    return Consulta_a(i, P, p * 2, I, D) + Consulta_a(P + 1, d, p * 2 + 1, I, D);
}
long long Consulta_b(long long i, long long d, long long p, long long I, long long D){
    if(I > D) return 0;
    if(i != d and Propagar_b[p] != -2){
        _rbol_b[p] = (d - i + 1) * Propagar_b[p];
        Propagar_b[p * 2] = Propagar_b[p];
        Propagar_b[p * 2 + 1] = Propagar_b[p];
        Propagar_b[p] = -2;
    }
    if(I <= i and d <= D) return _rbol_b[p];
    if(i > D or d < I) return 0;
    long long P = (i + d) / 2;
    return Consulta_b(i, P, p * 2, I, D) + Consulta_b(P + 1, d, p * 2 + 1, I, D);
}
void Actualizar_a(long long i, long long d, long long p, long long I, long long D){
    if(I > D) return;
    if(i != d and Propagar_a[p] != -2){
        _rbol_a[p] = (d - i + 1) * Propagar_a[p];
        Propagar_a[p * 2] = Propagar_a[p];
        Propagar_a[p * 2 + 1] = Propagar_a[p];
        Propagar_a[p] = -2;
    }
    if(I <= i and d <= D){
        _rbol_a[p] = d - i + 1;
        if(i != d){
            Propagar_a[p * 2] = 1;
            Propagar_a[p * 2 + 1] = 1;
            Propagar_a[p] = -2;
        }
        return;
    }
    if(i > D or d < I) return;
    long long P = (i + d) / 2;
    Actualizar_a(i, P, p * 2, I, D);
    Actualizar_a(P + 1, d, p * 2 + 1, I, D);
    _rbol_a[p] = _rbol_a[p * 2] + _rbol_a[p * 2 + 1];
}
void Actualizar_b(long long i, long long d, long long p, long long I, long long D){
    if(I > D) return;
    if(i != d and Propagar_b[p] != -2){
        _rbol_b[p] = (d - i + 1) * Propagar_b[p];
        Propagar_b[p * 2] = Propagar_b[p];
        Propagar_b[p * 2 + 1] = Propagar_b[p];
        Propagar_b[p] = -2;
    }
    if(I <= i and d <= D){
        _rbol_b[p] = d - i + 1;
        if(i != d){
            Propagar_b[p * 2] = 1;
            Propagar_b[p * 2 + 1] = 1;
            Propagar_b[p] = -2;
        }
        return;
    }
    if(i > D or d < I) return;
    long long P = (i + d) / 2;
    Actualizar_b(i, P, p * 2, I, D);
    Actualizar_b(P + 1, d, p * 2 + 1, I, D);
    _rbol_b[p] = _rbol_b[p * 2] + _rbol_b[p * 2 + 1];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    a.assign(n, 0);
    b.assign(n, 0);
    Propagar_a.assign((n + 22) * 4, -2);
    Propagar_b.assign((n + 22) * 4, -2);
    _rbol_a.assign((n + 22) * 4, 0);
    _rbol_b.assign((n + 22) * 4, 0);
    for(long long i = 0; i < n; i++) cin>>a[i];
    for(long long i = 0; i < n; i++) cin>>b[i];
    set<Par> Ordenar_a, Ordenar_b;
    for(long long i = 0; i < n; i++){
        Par Nuevo;
        Nuevo.Valor = a[i];
        Nuevo.Posici_n = -2;
        auto E = Ordenar_a.lower_bound(Nuevo);
        Nuevo.Posici_n = i;
        if(Nuevo.Posici_n == 0) continue;
        if(E == Ordenar_a.end()) Ordenar_a.insert(Nuevo);
        else {
            if((*E).Valor != Nuevo.Valor) Ordenar_a.insert(Nuevo);
            else if((*E).Posici_n > Nuevo.Posici_n){
                Ordenar_a.erase(E);
                Ordenar_a.insert(Nuevo);
            }
        }
    }
    for(long long i = 0; i < n; i++){
        Par Nuevo;
        Nuevo.Valor = b[i];
        Nuevo.Posici_n = -2;
        auto E = Ordenar_b.lower_bound(Nuevo);
        Nuevo.Posici_n = i;
        if(Nuevo.Posici_n == 0) continue;
        if(E == Ordenar_b.end()) Ordenar_b.insert(Nuevo);
        else {
            if((*E).Valor != Nuevo.Valor) Ordenar_b.insert(Nuevo);
            else if((*E).Posici_n > Nuevo.Posici_n){
                Ordenar_b.erase(E);
                Ordenar_b.insert(Nuevo);
            }
        }
    }
    n--;
    //Crear(0, n, 1);
    long long m = 0, c = 0, V_lido_a = n, V_lido_b = n;
    while(Ordenar_a.size() > 0 or Ordenar_b.size() > 0){
        if(Ordenar_a.size() > 0) cout<<(*Ordenar_a.begin()).Valor<<" "<<(*Ordenar_a.begin()).Posici_n<<"\n";
        if(Ordenar_b.size() > 0) cout<<(*Ordenar_b.begin()).Valor<<" "<<(*Ordenar_b.begin()).Posici_n<<"\n";
        for(long long i = 0; i <= n; i++) cout<<Consulta_a(0, n, 1, i, i)<<" ";
        cout<<"\n";
        for(long long i = 0; i <= n; i++) cout<<Consulta_b(0, n, 1, i, i)<<" ";
        cout<<"\n\n";
        if(Ordenar_a.size() == 0 and Ordenar_b.size() > 0){
            auto E = *Ordenar_b.begin();
            Actualizar_b(0, n, 1, E.Posici_n, n);
            long long Cantidad = Consulta_b(0, n, 1, E.Posici_n, V_lido_b) * (n + 1);
            if(E.Valor == a[0]) Cantidad++;
            if(Cantidad == m){
                c = max(c, E.Valor);
            }
            if(Cantidad > m){
                m = Cantidad;
                c = E.Valor;
            }
            V_lido_b = min(V_lido_b, E.Posici_n - 1);
            Ordenar_b.erase(E);
        } else if(Ordenar_a.size() > 0 and Ordenar_b.size() == 0){
            auto E = *Ordenar_a.begin();
            Actualizar_a(0, n, 1, E.Posici_n, n);
            long long Cantidad = Consulta_a(0, n, 1, E.Posici_n, V_lido_a) * (n + 1);
            if(E.Valor == a[0]) Cantidad++;
            if(Cantidad == m){
                c = max(c, E.Valor);
            }
            if(Cantidad > m){
                m = Cantidad;
                c = E.Valor;
            }
            V_lido_a = min(V_lido_a, E.Posici_n - 1);
            Ordenar_a.erase(E);
        } else {
            auto E = *Ordenar_a.begin(), e = *Ordenar_b.begin();
            if(E.Valor == e.Valor){
                Actualizar_a(0, n, 1, E.Posici_n, n);
                Actualizar_b(0, n, 1, e.Posici_n, n);
                long long Cantidad = Consulta_a(0, n, 1, E.Posici_n, V_lido_a) * (n + 1) + Consulta_b(0, n, 1, e.Posici_n, V_lido_b) * (n + 1);
                long long Base = n - E.Posici_n + 1, Altura = n - e.Posici_n + 1;
                Cantidad -= Base * Altura;
                if(E.Valor == a[0]) Cantidad++;
                if(Cantidad == m){
                    c = max(c, E.Valor);
                }
                if(Cantidad > m){
                    m = Cantidad;
                    c = E.Valor;
                }
                V_lido_a = min(V_lido_a, E.Posici_n - 1);
                V_lido_b = min(V_lido_b, e.Posici_n - 1);
                Ordenar_a.erase(E);
                Ordenar_b.erase(e);
            } else if(E.Valor > e.Valor){
                Actualizar_a(0, n, 1, E.Posici_n, n);
                long long Cantidad = Consulta_a(0, n, 1, E.Posici_n, V_lido_a) * (n + 1);
                if(E.Valor == a[0]) Cantidad++;
                if(Cantidad == m){
                    c = max(c, E.Valor);
                }
                if(Cantidad > m){
                    m = Cantidad;
                    c = E.Valor;
                }
                V_lido_a = min(V_lido_a, E.Posici_n - 1);
                Ordenar_a.erase(E);
            } else {
                Actualizar_b(0, n, 1, e.Posici_n, n);
                long long Cantidad = Consulta_b(0, n, 1, e.Posici_n, V_lido_b) * (n + 1);
                if(e.Valor == a[0]) Cantidad++;
                if(Cantidad == m){
                    c = max(c, e.Valor);
                }
                if(Cantidad > m){
                    m = Cantidad;
                    c = e.Valor;
                }
                V_lido_b = min(V_lido_b, e.Posici_n - 1);
                Ordenar_b.erase(e);
            }
        }
    }
    cout<<c<<" "<<m;
    return 0;
}