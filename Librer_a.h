#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define vll vector<long long>
#define vld vector<long double>
typedef __int128 llllong;
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;
struct Grande{
    llllong v, m;
    Grande(ll a, ll b){
        v = a % b;
        m = b;
    }
    Grande(llllong a, llllong b){
        v = a % b;
        m = b;
    }
    Grande operator*(const Grande& o){
        return Grande((v % m) * (o.v % m), m);
    }
    Grande operator^(const ll& e){
        Grande Copia = *this;
        if(e == 0) return Grande((llllong)1, m);
        if(e == 1) return Copia;
        Grande a = Copia ^ (e / 2LL);
        a = a * a * (Copia ^ (e & 1LL));
        return a;
    }
};
ll Generar_n_mero_aleatorio_entero(ll i, ll d){
    random_device rd;
    mt19937_64 Semilla(rd());
    uniform_int_distribution<ll> Aleatorizador(i, d);
    return Aleatorizador(Semilla);
}
int Generar_n_mero_aleatorio_entero_int(int i, int d){
    random_device rd;
    mt19937 Semilla(rd());
    uniform_int_distribution<int> Aleatorizador(i, d);
    return Aleatorizador(Semilla);
}
ld Generar_n_mero_aleatorio_real(ld i, ld d){
    random_device rd;
    mt19937_64 Semilla(rd());
    uniform_real_distribution<ld> Aleatorizador(i, d);
    return Aleatorizador(Semilla);
}
bool Miller_Rabin(ll n){
    if(n <= 4LL) return n == 2LL or n == 3LL;
    if((n & 1LL) == 0LL) return 0;
    ll s = 0, d = n - 1LL;
    while((d & 1LL) == 0LL){
        s++;
        d >>= 1LL;
    }
    forn(i, 22){
        Grande Base = Grande(Generar_n_mero_aleatorio_entero(2LL, n - 2LL), n) ^ d;
        if(Base.v == (llllong)1 or Base.v == (llllong)(n - 1LL)) continue;
        bool Pasado = 0;
        forn(j, s - 1){
            Base = Base * Base;
            if(Base.v == (llllong)(n - 1LL)){
                Pasado = 1;
                break;
            }
        }
        if(Pasado) continue;
        return 0;
    }
    return 1;
}
long long Sigma(long long x){
    long long r = 1;
    for(long long i = 2; i * i <= x; i++){
        if(x % i != 0LL) continue;
        long long Potencia = 1;
        while(x % i == 0LL){
            Potencia *= i;
            x /= i;
        }
        r *= (Potencia * i - 1LL) / (i - 1LL);
    }
    if(x > 1LL) r *= (x * x - 1LL) / (x - 1LL);
    return r;
}
long long Totiente(long long x){
    long long r = 1;
    for(long long i = 2; i * i <= x; i++){
        if(x % i != 0LL) continue;
        long long Potencia = 1;
        while(x % i == 0LL){
            Potencia *= i;
            x /= i;
        }
        r *= Potencia - Potencia / i;
    }
    if(x > 1LL) r *= x - 1LL;
    return r;
}
long long Reversi_n(long long x){
    string s = to_string(x);
    reverse(s.begin(), s.end());
    return stoll(s);
}
long long Sumar_d_gitos(long long x){
    string s = to_string(x);
    long long Suma = 0;
    for(auto E: s) Suma += (ll)(E - 48);
    return Suma;
}
long long Sumar_d_gitos_pares(long long x){
    string s = to_string(x);
    long long Suma = 0;
    for(auto E: s) if((E & 1) == 0) Suma += (ll)(E - 48);
    return Suma;
}
long long Sumar_d_gitos_impares(long long x){
    string s = to_string(x);
    long long Suma = 0;
    for(auto E: s) if(E & 1) Suma += (ll)(E - 48);
    return Suma;
}
long long Entrada_entera(){
    long long x;
    cout<<"Dé un número.\n";
    cin>>x;
    return x;
}
ld Entrada_real(){
    ld x;
    cout<<"Dé un número.\n";
    cin>>x;
    return x;
}
vll Generar_vector_aleatorio_entero(int n, ll i, ll d){
    vll a(n);
    forn(k, n) a[k] = Generar_n_mero_aleatorio_entero(i, d);
    return a;
}
vld Generar_vector_aleatorio_real(int n, ld i, ld d){
    vld a(n);
    forn(k, n) a[k] = Generar_n_mero_aleatorio_real(i, d);
    return a;
}
ld Promedio_entero(vll a){
    ld Suma = 0;
    forn(i, a.size()) Suma += (ld)a[i];
    return Suma / (ld)a.size();
}
ld Promedio_real(vld a){
    ld Suma = 0;
    forn(i, a.size()) Suma += a[i];
    return Suma / (ld)a.size();
}
ll Mediana_en_el_arreglo_entero(vll a){
    int p = (int)a.size() / 2;
    while(1){
        ll Pivote = a[Generar_n_mero_aleatorio_entero_int(0, int(a.size()) - 1)];
        vll i, d;
        int Contador_de_pivotes = 0;
        for(auto E: a){
            if(E < Pivote) i.pb(E);
            else if(E == Pivote) Contador_de_pivotes++;
            else d.pb(Pivote);
        }
        if(int(i.size()) > p) a = i;
        else if(int(i.size()) + Contador_de_pivotes > p) return Pivote;
        else {
            a = d;
            p -= Contador_de_pivotes + int(i.size());
        }
    }
}
ld Mediana_en_el_arreglo_entero_normal(vll a){
    if(int(a.size()) & 1) return Mediana_en_el_arreglo_entero(a);
    sort(a.begin(), a.end());
    return ((ld)a[int(a.size()) / 2] + (ld)a[int(a.size()) / 2 - 1]) / (ld)2;
}
ld Mediana_en_el_arreglo_real(vll a){
    sort(a.begin(), a.end());
    return a[int(a.size()) / 2];
}
ld Mediana_en_el_arreglo_real_normal(vll a){
    sort(a.begin(), a.end());
    if(int(a.size()) & 1) return a[int(a.size()) / 2];
    return ((ld)a[int(a.size()) / 2] + (ld)a[int(a.size()) / 2 - 1]) / (ld)2;
}
void Imprimir_arreglo_entero(vll a){
    for(auto E: a) cout<<E<<" ";
    cout<<"\n";
}
void Imprimir_arreglo_entero_int(vector<int> a){
    for(auto E: a) cout<<E<<" ";
    cout<<"\n";
}
void Imprimir_arreglo_real(vld a){
    for(auto E: a) cout<<E<<" ";
    cout<<"\n";
}
vll Factores_primos(ll n){
    vll Factores;
    for(ll i = 2; i * i <= n; i++){
        while(n % i == 0LL){
            Factores.pb(i);
            n /= i;
        }
    }
    if(n > 1LL) Factores.pb(n);
    return Factores;
}
vector< pair<ll, int> > Factores_primos_por_cantidad(ll n){
    vector< pair<ll, int> > Factores;
    for(ll i = 2; i * i <= n; i++){
        if(n % i == 0LL) Factores.pb(make_pair(i, 0));
        while(n % i == 0LL){
            Factores.back().second++;
            n /= i;
        }
    }
    if(n > 1LL) Factores.pb(make_pair(n, 1));
    return Factores;
}
vll Generar_primos_de_1_a_n(ll n){
    vll Primos;
    vector<bool> Buenos(n + 1, 1);
    for(ll i = 2; i <= n; i++){
        if(Buenos[i]){
            Primos.pb(i);
            for(ll j = i * i; j <= n; j += i){
                Buenos[j] = 0;
            }
        }
    }
    return Primos;
}
ll Potencia(ll b, int e){
    if(e == 0) return 1LL;
    if(e == 1) return b;
    ll a = Potencia(b, e / 2);
    return a * a * Potencia(b, e & 1);
}
ll Generar_n_mero_aleatorio_de_n_d_gitos(int n){
    return Generar_n_mero_aleatorio_entero(Potencia(10LL, n - 1), Potencia(10LL, n) - 1LL);
}
ll Generar_n_mero_aleatorio_primo_de_n_d_gitos(int n){
    while(1){
        ll Posible = Generar_n_mero_aleatorio_entero(Potencia(10LL, n - 1), Potencia(10LL, n) - 1LL);
        if(Miller_Rabin(Posible)) return Posible;
    }
}
vll Obtener_divisores(ll x){
    if(x == 1LL) return {1LL};
    vector< pair<ll, int> > Descomposici_n = Factores_primos_por_cantidad(x);
    int n = int(Descomposici_n.size());
    vector<int> Exponente(n, 0);
    vll Divisores;
    while(1){
        ll v = 1LL;
        forn(i, n){
            v *= Potencia(Descomposici_n[i].first, Exponente[i]);
        }
        Divisores.pb(v);
        bool Mal = 1;
        forn(i, n){
            Exponente[i]++;
            if(Exponente[i] > Descomposici_n[i].second){
                Exponente[i] = 0;
            } else {
                Mal = 0;
                break;
            }
        }
        if(Mal){
            sort(Divisores.begin(), Divisores.end());
            return Divisores;
        }
    }
}
struct Fracci_n{
    ll n, d;
    Fracci_n(){
        n = 0LL;
        d = 1LL;
    }
    Fracci_n(ll a){
        n = a;
        d = 1LL;
    }
    Fracci_n(ll a, ll b){
        if(b == 0LL) b++;
        n = a;
        d = b;
        if(d < 0LL){
            n *= -1LL;
            d *= -1LL;
        }
        n /= __gcd(a, b);
        d /= __gcd(a, b);
    }
    Fracci_n operator+(const Fracci_n& o){
        return Fracci_n(n * o.d + d * o.n, d * o.d);
    }
    Fracci_n operator-(const Fracci_n& o){
        return Fracci_n(n * o.d - d * o.n, d * o.d);
    }
    Fracci_n operator*(const Fracci_n& o){
        return Fracci_n(n * o.n, d * o.d);
    }
    Fracci_n operator/(const Fracci_n& o){
        return Fracci_n(n * o.d, d * o.n);
    }
    Fracci_n operator+(const ll& o){
        return *this + Fracci_n(o);
    }
    Fracci_n operator-(const ll& o){
        return *this - Fracci_n(o);
    }
    Fracci_n operator*(const ll& o){
        return *this * Fracci_n(o);
    }
    Fracci_n operator/(const ll& o){
        return *this / Fracci_n(o);
    }
    bool operator==(const Fracci_n& o) const{
        return n * o.d == d * o.n;
    }
    bool operator!=(const Fracci_n& o) const{
        return n * o.d != d * o.n;
    }
    bool operator<(const Fracci_n& o) const{
        return n * o.d < d * o.n;
    }
    bool operator<=(const Fracci_n& o) const{
        return n * o.d <= d * o.n;
    }
    bool operator>(const Fracci_n& o) const{
        return n * o.d > d * o.n;
    }
    bool operator>=(const Fracci_n& o) const{
        return n * o.d >= d * o.n;
    }
    bool operator==(const ll& o) const{
        return *this == Fracci_n(o);
    }
    bool operator!=(const ll& o) const{
        return *this != Fracci_n(o);
    }
    bool operator>(const ll& o) const{
        return *this > Fracci_n(o);
    }
    bool operator>=(const ll& o) const{
        return *this >= Fracci_n(o);
    }
    bool operator<(const ll& o) const{
        return *this < Fracci_n(o);
    }
    bool operator<=(const ll& o) const{
        return *this <= Fracci_n(o);
    }
    Fracci_n operator^(const int& o){
        return Fracci_n(Potencia(n, o), Potencia(d, o));
    }
    ld Valor(){
        return (ld)this->n / (ld)this->d;
    }
};
vll Ajuste_polinomial_entero(int n, vll a){
    vector< vll > Ajuste;
    Ajuste.pb(a);
    while(1){
        vll Nuevo;
        forn(i, Ajuste.back().size() - 1){
            Nuevo.pb(Ajuste.back()[i + 1] - Ajuste.back()[i]);
        }
        Ajuste.pb(Nuevo);
        if(int(Nuevo.size()) == 1) break;
    }
    vll Secuencia;
    forn(i, n){
        if(i == int(Ajuste[0].size())){
            Ajuste.back().pb(Ajuste.back().back());
            for(int j = int(Ajuste.size()) - 2; j > -1; j--){
                Ajuste[j].pb(Ajuste[j].back() + Ajuste[j + 1].back());
            }
        }
        Secuencia.pb(Ajuste[0][i]);
    }
    return Secuencia;
}