#include "bits/stdc++.h"
using namespace std;
vector<long long> Representante, Tama_o, Anterior;
vector< vector<long long> > Grafo;
map< pair<long long, long long>, long long > Pesos;
vector< pair<long long, long long> > Ordenamiento;
long long o, Peso;
bool Imprimir = 0;
struct Arista{
    long long u, v, w, ID;
};
struct Informaci_n{
    long long Ancestro, Mayor;
};
vector< vector<Informaci_n> > Informaci_n_anterior;
bool operator<(const Arista& a, const Arista& b){
    if(a.w < b.w) return 1;
    if(a.w > b.w) return 0;
    if(a.ID < b.ID) return 1;
    if(a.ID > b.ID) return 0;
    if(a.u < b.u) return 1;
    if(a.u > b.u) return 0;
    return a.v < b.v;
}
void Crear(long long n){
    Representante.assign(n, 0);
    Tama_o.assign(n, 1);
    Anterior.assign(n, -1);
    Grafo.assign(n, {});
    Informaci_n_anterior.assign(n, {});
    Ordenamiento.assign(n, make_pair(-2, -2));
    o = 0;
    Peso = 0;
    for(long long i = 0; i < n; i++) Representante[i] = i;
}
long long Buscar(long long a){
    if(Representante[a] == a) return a;
    return Representante[a] = Buscar(Representante[a]);
}
bool Unir(long long a, long long b){
    a = Buscar(a);
    b = Buscar(b);
    if(a != b){
        if(Tama_o[a] < Tama_o[b]) swap(a, b);
        Tama_o[a] += Tama_o[b];
        Representante[b] = a;
        return 1;
    }
    return 0;
}
void Anteriores(long long Nodo, long long A){
    Anterior[Nodo] = A;
    Ordenamiento[Nodo].first = o;
    o++;
    if(A != -2){
        long long Mayor_arista = Pesos[make_pair(Nodo, A)];
        Informaci_n _1;
        _1.Ancestro = A;
        _1.Mayor = Mayor_arista;
        Informaci_n_anterior[Nodo].push_back(_1);
        long long Revisar = A;
        for(long long i = 0; 1; i++){
            if(i >= Informaci_n_anterior[Revisar].size()) break;
            _1.Ancestro = Informaci_n_anterior[Revisar][i].Ancestro;
            _1.Mayor = max(Informaci_n_anterior[Revisar][i].Mayor, Mayor_arista);
            Mayor_arista = _1.Mayor;
            Informaci_n_anterior[Nodo].push_back(_1);
            Revisar = Informaci_n_anterior[Revisar][i].Ancestro;
        }
    }
    for(auto E: Grafo[Nodo]){
        if(Anterior[E] == -1){
            Anteriores(E, Nodo);
        }
    }
    Ordenamiento[Nodo].second = o;
    o++;
}
bool Contiene(long long a, long long b){
    return Ordenamiento[a].first < Ordenamiento[b].first and Ordenamiento[a].second > Ordenamiento[b].second;
}
long long Consulta(long long u, long long v, long long w){
    if(Imprimir) cout<<"Consulta "<<u<<" "<<v<<" "<<w<<"\n";
    if(Pesos[make_pair(u, v)] == w) return Peso;
    long long M_nimo_ancestro_com_n = -2, Mayor_hasta_ahora = 0;
    if(Contiene(u, v)) M_nimo_ancestro_com_n = u;
    if(Contiene(v, u)){
        M_nimo_ancestro_com_n = v;
        swap(u, v);
    }
    long long Ubicaci_n = 0, Revisar;
    if(M_nimo_ancestro_com_n == -2){
        for(Revisar = u; !Contiene(Anterior[Revisar], v); Revisar = Informaci_n_anterior[Revisar][Ubicaci_n].Ancestro){
            long long i = 0, d = Informaci_n_anterior[Revisar].size() - 1;
            Ubicaci_n = d;
            if(Imprimir) cout<<"u "<<Revisar<<"  ";
            if(Imprimir) for(auto E: Informaci_n_anterior[Revisar]) cout<<E.Ancestro<<" ";
            if(Imprimir) cout<<"\n";
            while(1){
                long long p = (i + d) / 2;
                Informaci_n Actual = Informaci_n_anterior[Revisar][p];
                if(Contiene(Actual.Ancestro, v)){
                    d = p - 1;
                } else {
                    i = p + 1;
                    M_nimo_ancestro_com_n = Actual.Ancestro;
                    Ubicaci_n = p;
                    Mayor_hasta_ahora = max(Mayor_hasta_ahora, Actual.Mayor);
                }
                if(i >= d + 1) break;
            }
        }
        M_nimo_ancestro_com_n = Anterior[Revisar];
        Mayor_hasta_ahora = max(Mayor_hasta_ahora, Pesos[make_pair(Revisar, Anterior[Revisar])]);
    }
    for(Revisar = v; Anterior[Revisar] != M_nimo_ancestro_com_n; Revisar = Informaci_n_anterior[Revisar][Ubicaci_n].Ancestro){
        if(Imprimir) cout<<"v "<<Revisar<<"  ";
        if(Imprimir) for(auto E: Informaci_n_anterior[Revisar]) cout<<E.Ancestro<<" ";
        if(Imprimir) cout<<"\n";
        long long i = 0, d = Informaci_n_anterior[Revisar].size() - 1;
        Ubicaci_n = d;
        while(1){
            long long p = (i + d) / 2;
            Informaci_n Actual = Informaci_n_anterior[Revisar][p];
            if(Contiene(Actual.Ancestro, u) or Actual.Ancestro == u){
                d = p - 1;
            } else {
                i = p + 1;
                Ubicaci_n = p;
                Mayor_hasta_ahora = max(Mayor_hasta_ahora, Actual.Mayor);
            }
            if(i >= d + 1) break;
        }
        //if(Imprimir) cout<<Mayor_hasta_ahora<<" Mayor.\n";
    }
    Mayor_hasta_ahora = max(Mayor_hasta_ahora, Pesos[make_pair(Revisar, M_nimo_ancestro_com_n)]);
    if(Imprimir) cout<<M_nimo_ancestro_com_n<<" "<<Mayor_hasta_ahora<<"\n";
    return Peso - Mayor_hasta_ahora + w;
}
int main(){
    //freopen("01.in", "r", stdin);
    //freopen("01.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //Imprimir = 1;
    long long n, m;
    cin>>n>>m;
    vector<Arista> a(m);
    for(long long i = 0; i < m; i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
        a[i].u--;
        a[i].v--;
        a[i].ID = i;
        //if(Imprimir) cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<" "<<i<<"\n";
    }
    if(m == 0) return 0;
    Crear(n);
    sort(a.begin(), a.end());
    for(long long i = 0; i < m; i++){
        if(Unir(a[i].u, a[i].v)){
            Peso += a[i].w;
            Grafo[a[i].u].push_back(a[i].v);
            Grafo[a[i].v].push_back(a[i].u);
            Pesos[make_pair(a[i].u, a[i].v)] = a[i].w;
            Pesos[make_pair(a[i].v, a[i].u)] = a[i].w;
            if(Imprimir) cout<<"Tomo "<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<"\n";
        }
    }
    Anteriores(0, -2);
    /*for(long long i = 0; i < n and Imprimir; i++){
        cout<<i<<"\n";
        for(auto e: Informaci_n_anterior[i]){
            cout<<e.Ancestro<<" "<<e.Mayor<<"\n";
        }
        cout<<"\n";
    }*/
    vector<long long> Respuesta(m);
    for(long long i = 0; i < m; i++){
        Respuesta[a[i].ID] = Consulta(a[i].u, a[i].v, a[i].w);
        //if(Imprimir) cout<<i<<" ";
    }
    for(auto E: Respuesta) cout<<E<<"\n";
    return 0;
}