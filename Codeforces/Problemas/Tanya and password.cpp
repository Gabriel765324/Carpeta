#include "bits/stdc++.h"
using namespace std;
vector< vector<long long> > Grafo;
unordered_map<string, long long> Cambio;
unordered_map<long long, string> Cambio_inverso;
multiset< pair<string, string> > Pendientes;
deque<long long> Respuesta;
void DFS(long long Nodo){
    //cout<<Cambio_inverso[Nodo]<<"\n";
    while(!Grafo[Nodo].empty() and !Pendientes.empty()){
        Pendientes.erase(Pendientes.find(make_pair(Cambio_inverso[Nodo], Cambio_inverso[Grafo[Nodo].back()])));
        long long So = Grafo[Nodo].back();
        Grafo[Nodo].pop_back();
        DFS(So);
    }
    Respuesta.push_front(Nodo);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long ID = 0;
    string Caracteres = "";
    for(long long i = 'a'; i <= 'z'; i++){
        Caracteres += i;
    }
    for(long long i = 'A'; i <= 'Z'; i++){
        Caracteres += i;
    }
    for(long long i = '0'; i <= '9'; i++){
        Caracteres += i;
    }
    long long n = Caracteres.size();
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < n; j++){
            string a = "";
            a += Caracteres[i];
            a += Caracteres[j];
            Cambio[a] = ID;
            Cambio_inverso[ID] = a;
            ID++;
        }
    }
    n *= n;
    Grafo.assign(n, {});
    vector<long long> Entra(n, 0), Sale(n, 0);
    cin>>n;
    string Posible_inicio;
    for(long long i = 0; i < n; i++){
        string a = "", b = a, c;
        cin>>c;
        a += c[0];
        a += c[1];
        b += c[1];
        b += c[2];
        if(i == 0) Posible_inicio = a;
        Grafo[Cambio[a]].push_back(Cambio[b]);
        Sale[Cambio[a]]++;
        Entra[Cambio[b]]++;
        Pendientes.insert(make_pair(a, b));
    }
    bool Entra_m_s = 0, Sale_m_s = 0;
    long long Inicio = -2, Final = -2;
    for(long long i = 0; i < Entra.size(); i++){
        if(abs(Entra[i] - Sale[i]) >= 2){
            cout<<"NO";
            return 0;
        }
        if(abs(Entra[i] - Sale[i]) == 1){
            if(Entra[i] > Sale[i]){
                /*if(Entra_m_s){
                    cout<<"NO";
                    return 0;
                } else {
                    Entra_m_s = 1;*/
                    Final = i;
                //}
            } else {
                /*if(Sale_m_s){
                    cout<<"NO";
                    return 0;
                } else {
                    Sale_m_s = 1;*/
                    Inicio = i;
                //}
            }
        }
    }
    if(Inicio == -2) Inicio = Cambio[Posible_inicio];
    multiset< pair<string, string> > Validador = Pendientes;
    DFS(Inicio);
    long long aa = Respuesta.size();
    string r = "";
    for(long long i = 0; i < aa; i++){
        r += Cambio_inverso[Respuesta[i]][0];
    }
    r += Cambio_inverso[Respuesta.back()][1];
    //cout<<r<<"\n";
    if(Pendientes.size() > 0){
        cout<<"NO";
        return 0;
    }
    if(r.size() == n + 2){
        for(long long i = 0; i < n; i++){
            pair<string, string> Hola = make_pair(r.substr(i, 2), r.substr(i + 1, 2));
            auto E = Validador.find(Hola);
            if(E == Validador.end() or *E != Hola){
                cout<<"NO";
                return 0;
            } else Validador.erase(E);
        }
        cout<<"YES\n"<<r;
    } else cout<<"NO";
    return 0;
}