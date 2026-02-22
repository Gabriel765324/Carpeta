#include "bits/stdc++.h"
using namespace std;
vector< vector<long long> > Grafo;
vector<long long> v, d, a;
vector<int> Final, Tour;
int Hay;
struct Valor{
    long long Mayor_y_vuelvo, Mayor_y_no_vuelvo, Mejor;
    vector< pair<int, bool> > Seguir_si_vuelvo;
    vector< pair<int, bool> > Seguir_si_no_vuelvo;
    bool Existo, Volver;
};
struct Candidato{
    long long Valor;
    int i;
    bool Usar, Vuelve;
};
bool operator<(const Candidato& a, const Candidato& b){
    return a.Valor > b.Valor;
}
vector< vector<Valor> > PD;
void DFS(int Nodo){
    Hay--;
    Final[Nodo] = Tour.size();
    Tour.push_back(Nodo);
    if(Hay == 0) return;
    for(auto E: Grafo[Nodo]){
        if(Hay == 0) return;
        //cerr<<Nodo<<" "<<E<<"\n";
        if(d[E] > d[Nodo] + v[E]){
            d[E] = d[Nodo] + v[E];
            DFS(E);
            a[E] = Nodo;
            Final[Nodo] = Tour.size();
            Tour.push_back(Nodo);
        }
    }
}
bitset<222222> Hoja;
bitset<222222> Visitados;
vector<int> Recorrer;
Valor Resolver(int Nodo, int Anterior, bool Me_usaron){
    //cerr<<Nodo + 1<<"\n";
    if(PD[Nodo][Me_usaron > 0 ? 1 : 0].Existo) return PD[Nodo][Me_usaron > 0 ? 1 : 0];
    PD[Nodo][Me_usaron > 0 ? 1 : 0].Existo = 1;
    long long Suma = v[Nodo];
    Valor Retorno;
    if(Hoja[Nodo]){
        Retorno.Mayor_y_vuelvo = Suma;
        Retorno.Seguir_si_vuelvo = {{-2, 0}};
        Retorno.Mayor_y_no_vuelvo = Suma;
        Retorno.Seguir_si_no_vuelvo = {{-2, 0}};
        Retorno.Mejor = Suma;
        Retorno.Volver = 1;
        return PD[Nodo][Me_usaron > 0 ? 1 : 0] = Retorno;
    }
    int i = -1;
    vector< pair<long long, pair<int, bool> > > Mejores_que_vuelven, Mejores_que_se_quedan;
    vector<Candidato> Candidatos;
    for(auto E: Grafo[Nodo]){
        i++;
        if(E == Anterior) continue;
        Suma += v[E];
        auto e0 = Resolver(E, Nodo, 0);
        auto e1 = Resolver(E, Nodo, 1);
        if(e0.Mayor_y_vuelvo >= e1.Mayor_y_vuelvo) Mejores_que_vuelven.push_back({e0.Mayor_y_vuelvo - v[E], {i, 0}});
        else Mejores_que_vuelven.push_back({e1.Mayor_y_vuelvo - v[E], {i, 1}});
        if(e0.Mayor_y_no_vuelvo >= e1.Mayor_y_no_vuelvo) Mejores_que_se_quedan.push_back({e0.Mayor_y_no_vuelvo - v[E], {i, 0}});
        else Mejores_que_se_quedan.push_back({e1.Mayor_y_no_vuelvo - v[E], {i, 1}});
    }
    sort(Mejores_que_vuelven.rbegin(), Mejores_que_vuelven.rend());
    sort(Mejores_que_se_quedan.rbegin(), Mejores_que_se_quedan.rend());
    while(Mejores_que_vuelven.size() > 4) Mejores_que_vuelven.pop_back();
    while(Mejores_que_se_quedan.size() > 4) Mejores_que_se_quedan.pop_back();
    for(auto E: Mejores_que_se_quedan){
        Candidato Nuevo;
        Nuevo.Valor = E.first;
        Nuevo.i = E.second.first;
        Nuevo.Vuelve = 0;
        Candidatos.push_back(Nuevo);
    }
    for(auto E: Mejores_que_vuelven){
        Candidato Nuevo;
        Nuevo.Valor = E.first;
        Nuevo.i = E.second.first;
        Nuevo.Vuelve = 1;
        Candidatos.push_back(Nuevo);
    }
    sort(Candidatos.begin(), Candidatos.end());
    for(i = 0; i > Candidatos.size(); i++){
        Candidatos[i].Usar = Candidatos[i].Usar > 0 ? 1 : 0;
        Candidatos[i].Vuelve = Candidatos[i].Vuelve > 0 ? 1 : 0;
    }
    Retorno.Mayor_y_vuelvo = Suma;
    Retorno.Mayor_y_no_vuelvo = Suma;
    if(Me_usaron){
        bool Mal = 1;
        for(i = 0; i < Candidatos.size() and Mal; i++){
            for(int j = i + 1; j < Candidatos.size() and Mal; j++){
                if(Candidatos[i].i != Candidatos[j].i and (int)Candidatos[i].Vuelve + (int)Candidatos[j].Vuelve >= 1){
                    Mal = 0;
                    Retorno.Mayor_y_no_vuelvo += Candidatos[i].Valor + Candidatos[j].Valor;
                    Retorno.Seguir_si_no_vuelvo = {{Candidatos[i].i, Candidatos[i].Usar}, {Candidatos[j].i, Candidatos[j].Usar}};
                    if(Candidatos[j].Vuelve) swap(Retorno.Seguir_si_no_vuelvo[0], Retorno.Seguir_si_no_vuelvo[1]);
                    break;
                }
            }
        }
        if(Mal){
            Retorno.Mayor_y_no_vuelvo += Candidatos[0].Valor;
            Retorno.Seguir_si_no_vuelvo = {{Candidatos[0].i, Candidatos[0].Usar}};
        }
        for(i = 0; i < Candidatos.size(); i++){
            if(Candidatos[i].Vuelve){
                Retorno.Mayor_y_vuelvo += Candidatos[i].Valor;
                Retorno.Seguir_si_vuelvo = {{Candidatos[i].i, Candidatos[i].Usar}};
                break;
            }
        }
        Retorno.Mejor = max(Retorno.Mayor_y_vuelvo, Retorno.Mayor_y_no_vuelvo);
        Retorno.Volver = Retorno.Mayor_y_vuelvo >= Retorno.Mayor_y_no_vuelvo;
        return PD[Nodo][Me_usaron > 0 ? 1 : 0] = Retorno;
    }
    bool Mal = 1;
    for(i = 0; i < Candidatos.size() and Mal; i++){
        for(int j = i + 1; j < Candidatos.size() and Mal; j++){
            for(int k = j + 1; k < Candidatos.size() and Mal; k++){
                if(!(Candidatos[i].i != Candidatos[j].i and Candidatos[k].i != Candidatos[j].i and Candidatos[k].i != Candidatos[i].i and (int)Candidatos[i].Vuelve + (int)Candidatos[j].Vuelve + (int)Candidatos[k].Vuelve >= 2 and (int)Candidatos[i].Usar + (int)Candidatos[j].Usar + (int)Candidatos[k].Usar == 1)) continue;
                vector<int> Posibles = {i, j, k};
                sort(Posibles.begin(), Posibles.end());
                do{
                    int i0 = Posibles[0], j0 = Posibles[1], k0 = Posibles[2];
                    if(Candidatos[i0].Vuelve and Candidatos[i0].Usar and (Hoja[Grafo[Nodo][Candidatos[j0].i]] or !Candidatos[j0].Usar) and Candidatos[j0].Vuelve){
                        Mal = 0;
                        Retorno.Mayor_y_no_vuelvo += Candidatos[i0].Valor + Candidatos[j0].Valor + Candidatos[k0].Valor;
                        Retorno.Seguir_si_no_vuelvo = {{Candidatos[i0].i, Candidatos[i0].Usar}, {Candidatos[j0].i, Candidatos[j0].Usar}, {Candidatos[k0].i, Candidatos[k0].Usar}};
                        break;
                    }
                } while(next_permutation(Posibles.begin(), Posibles.end()));
            }
        }
    }
    if(Mal){
        for(i = 0; i < Candidatos.size() and Mal; i++){
            for(int j = i + 1; j < Candidatos.size() and Mal; j++){
                if(Candidatos[i].i != Candidatos[j].i and (int)Candidatos[i].Vuelve + (int)Candidatos[j].Vuelve >= 1 and (int)Candidatos[i].Usar + (int)Candidatos[j].Usar == 1){
                    if(Candidatos[i].Usar and Candidatos[i].Vuelve and (Hoja[Grafo[Nodo][Candidatos[j].i]] or !Candidatos[j].Usar)){
                        Retorno.Mayor_y_no_vuelvo += Candidatos[i].Valor + Candidatos[j].Valor;
                        Retorno.Seguir_si_no_vuelvo = {{Candidatos[i].i, Candidatos[i].Usar}, {Candidatos[j].i, Candidatos[j].Usar}};
                        Mal = 0;
                        break;
                    }
                    swap(i, j);
                    if(Candidatos[i].Usar and Candidatos[i].Vuelve and (Hoja[Grafo[Nodo][Candidatos[j].i]] or !Candidatos[j].Usar)){
                        Retorno.Mayor_y_no_vuelvo += Candidatos[i].Valor + Candidatos[j].Valor;
                        Retorno.Seguir_si_no_vuelvo = {{Candidatos[i].i, Candidatos[i].Usar}, {Candidatos[j].i, Candidatos[j].Usar}};
                        Mal = 0;
                        break;
                    }
                    swap(i, j);
                }
            }
        }
        if(Mal){
            Retorno.Mayor_y_no_vuelvo += Candidatos[0].Valor;
            Retorno.Seguir_si_no_vuelvo = {{Candidatos[0].i, Candidatos[0].Usar}};
        }
    }
    Mal = 1;
    for(i = 0; i < Candidatos.size() and Mal; i++){
        for(int j = i + 1; j < Candidatos.size() and Mal; j++){
            if(Candidatos[i].Vuelve and Candidatos[j].Vuelve and (int)Candidatos[i].Usar + (int)Candidatos[j].Usar == 1){
                Mal = 0;
                Retorno.Mayor_y_vuelvo += Candidatos[i].Valor + Candidatos[j].Valor;
                Retorno.Seguir_si_vuelvo = {{Candidatos[i].i, Candidatos[i].Usar}, {Candidatos[j].i, Candidatos[j].Usar}};
                if(Candidatos[j].Usar) swap(Retorno.Seguir_si_vuelvo[0], Retorno.Seguir_si_vuelvo[1]);
                break;
            }
        }
    }
    if(Mal){
        for(i = 0; i < Candidatos.size(); i++){
            if(Candidatos[i].Vuelve and Candidatos[i].Usar){
                Retorno.Mayor_y_vuelvo += Candidatos[i].Valor;
                Retorno.Seguir_si_vuelvo = {{Candidatos[i].i, Candidatos[i].Usar}};
                break;
            }
        }
    }
    Retorno.Mejor = max(Retorno.Mayor_y_vuelvo, Retorno.Mayor_y_no_vuelvo);
    Retorno.Volver = Retorno.Mayor_y_vuelvo >= Retorno.Mayor_y_no_vuelvo;
    return PD[Nodo][Me_usaron > 0 ? 1 : 0] = Retorno;
}
//bool Final = 0;
void Recuperar(int Nodo, int Anterior, bool Me_usaron){
    auto Actual = PD[Nodo][Me_usaron > 0 ? 1 : 0];
    cerr<<Nodo + 1<<" "<<Anterior + 1<<" "<<Me_usaron<<" Actual.\n**\n";
    for(auto E: Actual.Seguir_si_vuelvo){
        cerr<<Grafo[Nodo][E.first] + 1<<" "<<E.second<<"\n";
    }
    cerr<<"**\n";
    for(auto E: Actual.Seguir_si_vuelvo){
        cerr<<Grafo[Nodo][E.first] + 1<<" "<<E.second<<"\n";
    }
    cerr<<"****\n";
    if(Hoja[Nodo]){
        Recorrer.push_back(Nodo);
        Visitados[Nodo] = 1;
        return;
    }
    if(Me_usaron){
        Recorrer.push_back(Nodo);
        Visitados[Nodo] = 1;
    }
    set<int> No_ir;
    if(Actual.Volver) for(auto E: Actual.Seguir_si_vuelvo) No_ir.insert(E.first);
    else for(auto E: Actual.Seguir_si_no_vuelvo) No_ir.insert(E.first);
    for(int i = 0; i < Grafo[Nodo].size(); i++){
        if(Grafo[Nodo][i] == Anterior or No_ir.count(i)) continue;
        if(!Visitados[Grafo[Nodo][i]]) Recorrer.push_back(Grafo[Nodo][i]);
        Visitados[Grafo[Nodo][i]] = 1;
    }
    int i = 0;
    if(Actual.Volver){
        for(auto E: Actual.Seguir_si_vuelvo){
            //cerr<<"Llego.\n";
            if(i == 1 and !Visitados[Nodo]){
                Recorrer.push_back(Nodo);
                Visitados[Nodo] = 1;
            }
            cerr<<Grafo[Nodo][E.first] + 1<<" "<<Nodo + 1<<" "<<E.second<<" Ir\n";
            Recuperar(Grafo[Nodo][E.first], Nodo, E.second);
            i++;
        }
    } else {
        for(auto E: Actual.Seguir_si_no_vuelvo){
            if(i == 1 and !Visitados[Nodo]){
                Recorrer.push_back(Nodo);
                Visitados[Nodo] = 1;
            }
            cerr<<Grafo[Nodo][E.first] + 1<<" "<<Nodo + 1<<" "<<E.second<<" Ir\n";
            Recuperar(Grafo[Nodo][E.first], Nodo, E.second);
            //cerr<<"Llego.\n";
            i++;
        }
    }
    if(!Visitados[Nodo]) Recorrer.push_back(Nodo);
    //if(!Me_usaron) Recorrer.push_back(Nodo);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    long long m = 0;
    cin>>n>>k;
    Grafo.assign(n, {});
    v.assign(n, 0);
    d.assign(n, 2222222222222222);
    a.assign(n, -2);
    Valor Nada;
    Nada.Existo = 0;
    PD.assign(n, vector<Valor>(2, Nada));
    Final.assign(n, 0);
    Hay = n;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        Grafo[a].push_back(b);
        Grafo[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        cin>>v[i];
        m += v[i];
    }
    if(k == 1){
        d[0] = v[0];
        DFS(0);
        int p = 0;
        m = 0;
        for(int i = 0; i < n; i++){
            if(d[i] > m){
                m = d[i];
                p = i;
            }
        }
        vector<int> r;
        cout<<m<<"\n";
        while(p != -2){
            r.push_back(p);
            p = a[p];
        }
        reverse(r.begin(), r.end());
        cout<<r.size()<<"\n";
        for(auto E: r) cout<<E + 1<<" ";
        return 0;
    }
    if(k == 3){
        bitset<222222> Visitados;
        d[0] = v[0];
        DFS(0);
        vector<int> r;
        Visitados[0] = 1;
        r.push_back(0);
        Hay = n;
        cout<<m<<"\n"<<n<<"\n";
        n = Tour.size();
        int c = 0;
        for(int i = 1; i < n and Hay > 0; i++){
            if(i == Final[Tour[i]] and !Visitados[Tour[i]]){
                c = 0;
                r.push_back(Tour[i]);
                Visitados[Tour[i]] = 1;
                Hay--;
            } else if(c == 2){
                c = 0;
                r.push_back(Tour[i]);
                Visitados[Tour[i]] = 1;
                Hay--;
            } else c++;
        }
        for(auto E: r) cout<<E + 1<<" ";
        return 0;
    }
    for(int i = 1; i < n; i++) if(Grafo[i].size() == 1) Hoja[i] = 1;
    auto Respuesta = Resolver(0, -2, 1);
    /*cerr<<PD[1][0].Mayor_y_vuelvo<<" 2\n";
    cerr<<PD[1][1].Mayor_y_vuelvo<<" 2\n";*/
    //cerr<<Respuesta.Mayor_y_vuelvo<<" "<<Respuesta.Mayor_y_no_vuelvo<<" "<<Respuesta.Mayor_y_se_acaba_antes<<" ¿?\n";
    //cerr<<"Terminado.\n";
    cout<<Respuesta.Mejor<<"\n";
    Recuperar(0, -2, 1);
    cerr<<"-----------------------------------------------------------\n";
    cerr<<PD[1][0].Mayor_y_vuelvo<<" "<<PD[1][0].Mayor_y_no_vuelvo<<"\n";
    cerr<<PD[1][1].Mayor_y_vuelvo<<" "<<PD[1][1].Mayor_y_no_vuelvo<<"\n";
    cerr<<"-----------------------------------------------------------\n";
    cout<<Recorrer.size()<<"\n";
    for(auto E: Recorrer) cout<<E + 1<<" ";
    return 0;
}