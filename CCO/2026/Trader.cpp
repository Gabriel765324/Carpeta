#include "bits/stdc++.h"
using namespace std;
struct Valor{
    long long Mejor_y_vuelvo, Mejor_y_me_quedo;
    bool Existo;
    vector<int> Nodos_volver, Usar_volver, Nodos_no_volver, Usar_no_volver;
};
struct Candidato_usar_volver{
    int _ndice;
    long long Mejor;
};
struct Candidato_no_usar_volver{
    int _ndice;
    long long Mejor;
};
struct Candidato_usar_no_volver{
    int _ndice;
    long long Mejor;
};
struct Candidato_no_usar_no_volver{
    int _ndice;
    long long Mejor;
};
struct Candidato{
    long long Mejor;
    int Usar, Volver, _ndice;
};
bool operator<(const Candidato_usar_volver& A, const Candidato_usar_volver& B){
    return A.Mejor < B.Mejor;
}
bool operator<(const Candidato_no_usar_volver& A, const Candidato_no_usar_volver& B){
    return A.Mejor < B.Mejor;
}
bool operator<(const Candidato_usar_no_volver& A, const Candidato_usar_no_volver& B){
    return A.Mejor < B.Mejor;
}
bool operator<(const Candidato_no_usar_no_volver& A, const Candidato_no_usar_no_volver& B){
    return A.Mejor < B.Mejor;
}
bool operator<(const Candidato& A, const Candidato& B){
    return A.Mejor < B.Mejor;
}
vector< vector<Valor> > PD;
bitset<222222> Hoja, Visitados;
vector< vector<long long> > Grafo;
vector<long long> v, d, a;
vector<int> Final, Tour;
deque<int> Recorrido;
Valor Resolver(int Nodo, int Anterior, int Usar){
    Valor Retorno;
    if(PD[Nodo][Usar].Existo == 1) return PD[Nodo][Usar];
    //cerr<<Nodo + 1<<" "<<Usar<<"\n";
    Retorno.Existo = 1;
    PD[Nodo][Usar].Existo = 1;
    if(Hoja[Nodo]){
        Retorno.Mejor_y_me_quedo = v[Nodo];
        Retorno.Mejor_y_vuelvo = v[Nodo];
        return PD[Nodo][Usar] = Retorno;
    }
    long long Suma = v[Nodo];
    int n = Grafo[Nodo].size();
    vector<Candidato_no_usar_volver> _0;
    vector<Candidato_no_usar_no_volver> _1;
    vector<Candidato_usar_volver> _2;
    vector<Candidato_usar_no_volver> _3;
    for(int i = 0; i < n; i++){
        if(Grafo[Nodo][i] == Anterior) continue;
        Suma += v[Grafo[Nodo][i]];
        auto e0 = Resolver(Grafo[Nodo][i], Nodo, 0);
        auto e1 = Resolver(Grafo[Nodo][i], Nodo, 1);
        e0.Mejor_y_me_quedo -= v[Grafo[Nodo][i]];
        e0.Mejor_y_vuelvo -= v[Grafo[Nodo][i]];
        e1.Mejor_y_me_quedo -= v[Grafo[Nodo][i]];
        e1.Mejor_y_vuelvo -= v[Grafo[Nodo][i]];
        Candidato_no_usar_volver __0;
        __0.Mejor = e0.Mejor_y_vuelvo;
        __0._ndice = i;
        _0.push_back(__0);
        Candidato_no_usar_no_volver __1;
        __1.Mejor = e0.Mejor_y_me_quedo;
        __1._ndice = i;
        _1.push_back(__1);
        Candidato_usar_volver __2;
        __2.Mejor = e1.Mejor_y_vuelvo;
        __2._ndice = i;
        _2.push_back(__2);
        Candidato_usar_no_volver __3;
        __3.Mejor = e1.Mejor_y_me_quedo;
        __3._ndice = i;
        _3.push_back(__3);
    }
    sort(_0.begin(), _0.end());
    sort(_1.begin(), _1.end());
    sort(_2.begin(), _2.end());
    sort(_3.begin(), _3.end());
    vector<Candidato> Mejores;
    int c = 0;
    for(int i = _0.size() - 1; i > -1 and c < 3; i--){
        Candidato Nuevo;
        Nuevo.Mejor = _0[i].Mejor;
        Nuevo.Usar = 0;
        Nuevo.Volver = 1;
        Nuevo._ndice = _0[i]._ndice;
        Mejores.push_back(Nuevo);
        c++;
    }
    c = 0;
    for(int i = _1.size() - 1; i > -1 and c < 3; i--){
        Candidato Nuevo;
        Nuevo.Mejor = _1[i].Mejor;
        Nuevo.Usar = 0;
        Nuevo.Volver = 0;
        Nuevo._ndice = _1[i]._ndice;
        Mejores.push_back(Nuevo);
        c++;
    }
    c = 0;
    for(int i = _2.size() - 1; i > -1 and c < 3; i--){
        Candidato Nuevo;
        Nuevo.Mejor = _2[i].Mejor;
        Nuevo.Usar = 1;
        Nuevo.Volver = 1;
        Nuevo._ndice = _2[i]._ndice;
        Mejores.push_back(Nuevo);
        c++;
    }
    c = 0;
    for(int i = _3.size() - 1; i > -1 and c < 3; i--){
        Candidato Nuevo;
        Nuevo.Mejor = _3[i].Mejor;
        Nuevo.Usar = 1;
        Nuevo.Volver = 0;
        Nuevo._ndice = _3[i]._ndice;
        Mejores.push_back(Nuevo);
        c++;
    }
    /*sort(Mejores.begin(), Mejores.end());
    reverse(Mejores.begin(), Mejores.end());*/
    Retorno.Mejor_y_me_quedo = Suma;
    Retorno.Mejor_y_vuelvo = Suma;
    n = Mejores.size();
    vector<int> p_0, p_1, p_2, p_3, p_02, p_13;
    //cerr<<Nodo + 1<<" "<<Usar<<"\n";
    for(int i = 0; i < n; i++){
        if(Mejores[i].Usar == 0 and Mejores[i].Volver == 1){
            p_0.push_back(i);
            p_02.push_back(i);
            //cerr<<i<<" "<<Mejores[i]._ndice<<" ";
            if(Hoja[Mejores[i]._ndice]) p_2.push_back(i);
        } else if(Mejores[i].Usar == 0 and Mejores[i].Volver == 0){
            p_1.push_back(i);
            p_13.push_back(i);
            //cerr<<i<<" "<<Mejores[i]._ndice<<" ";
            if(Hoja[Mejores[i]._ndice]) p_3.push_back(i);
        } else if(Mejores[i].Usar == 1 and Mejores[i].Volver == 1){
            p_2.push_back(i);
            p_02.push_back(i);
            //cerr<<i<<" "<<Mejores[i]._ndice<<" ";
            if(Hoja[Mejores[i]._ndice]) p_0.push_back(i);
        } else if(Mejores[i].Usar == 1 and Mejores[i].Volver == 0){
            p_3.push_back(i);
            p_13.push_back(i);
            //cerr<<i<<" "<<Mejores[i]._ndice<<" ";
            if(Hoja[Mejores[i]._ndice]) p_1.push_back(i);
        }
    }
    long long Mejor = -2;
    vector<int> Nodo_para_ir, Usar_nodos;
    //cerr<<Nodo + 1<<" "<<Usar<<" Par.\n";
    if(Usar == 1){
        for(auto E: p_02){
            //cerr<<"Candidato para mejor que vuelve. "<<Mejores[E].Mejor<<" "<<Grafo[Nodo][Mejores[E]._ndice] + 1<<"\n";
            if(Mejores[E].Mejor > Mejor){
                Mejor = Mejores[E].Mejor;
                Nodo_para_ir = {Mejores[E]._ndice};
                Usar_nodos = {Mejores[E].Usar};
            }
        }
        Retorno.Mejor_y_vuelvo += Mejor;
        Retorno.Nodos_volver = Nodo_para_ir;
        Retorno.Usar_volver = Usar_nodos;
        //cerr<<Retorno.Mejor_y_vuelvo<<" Volver.\n";
        Mejor = -2;
        Nodo_para_ir.clear();
        Usar_nodos.clear();
        for(auto E: p_0){
            for(auto e: p_3){
                //cerr<<"Candidatos para mejor que no vuelve. "<<Mejores[E].Mejor<<" "<<Mejores[e].Mejor<<" "<<Grafo[Nodo][Mejores[E]._ndice] + 1<<" "<<Grafo[Nodo][Mejores[e]._ndice] + 1<<"\n";
                if(Mejores[E].Mejor + Mejores[e].Mejor > Mejor and Mejores[E]._ndice != Mejores[e]._ndice){
                    Mejor = Mejores[E].Mejor + Mejores[e].Mejor;
                    Nodo_para_ir = {Mejores[E]._ndice, Mejores[e]._ndice};
                    Usar_nodos = {0, 1};
                }
            }
        }
        for(auto E: p_13){
            if(Mejores[E].Mejor > Mejor){
                Mejor = Mejores[E].Mejor;
                Nodo_para_ir = {Mejores[E]._ndice};
                Usar_nodos = {Mejores[E].Usar};
            }
        }
        Retorno.Mejor_y_me_quedo += Mejor;
        //cerr<<Retorno.Mejor_y_me_quedo<<" No volver.\n";
        Retorno.Nodos_no_volver = Nodo_para_ir;
        Retorno.Usar_no_volver = Usar_nodos;
        return PD[Nodo][Usar] = Retorno;
    }
    Mejor = -2;
    Nodo_para_ir.clear();
    Usar_nodos.clear();
    for(auto E: p_2){
        //cerr<<"Candidato para mejor que vuelve. "<<Mejores[E].Mejor<<" "<<Grafo[Nodo][Mejores[E]._ndice] + 1<<"\n";
        if(Mejores[E].Mejor > Mejor){
            Mejor = Mejores[E].Mejor;
            Nodo_para_ir = {Mejores[E]._ndice};
            Usar_nodos = {1};
        }
        for(auto e: p_02){
            //cerr<<"Candidatos para mejor que vuelve. "<<Mejores[E].Mejor<<" "<<Mejores[e].Mejor<<" "<<Grafo[Nodo][Mejores[E]._ndice] + 1<<" "<<Grafo[Nodo][Mejores[e]._ndice] + 1<<"\n";
            if(Mejores[E].Mejor + Mejores[e].Mejor > Mejor and Mejores[E]._ndice != Mejores[e]._ndice){
                Mejor = Mejores[E].Mejor + Mejores[e].Mejor;
                Nodo_para_ir = {Mejores[E]._ndice, Mejores[e]._ndice};
                Usar_nodos = {1, Mejores[e].Usar};
            }
        }
    }
    Retorno.Mejor_y_vuelvo += Mejor;
    //cerr<<Retorno.Mejor_y_vuelvo<<" Volver.\n";
    Retorno.Nodos_volver = Nodo_para_ir;
    Retorno.Usar_volver = Usar_nodos;
    Mejor = -2;
    Nodo_para_ir.clear();
    Usar_nodos.clear();
    for(auto E: p_13){
        //cerr<<"Candidato para mejor que no vuelve. "<<Mejores[E].Mejor<<" "<<Grafo[Nodo][Mejores[E]._ndice] + 1<<"\n";
        if(Mejores[E].Mejor > Mejor and Mejores[E].Usar == 1){
            Mejor = Mejores[E].Mejor;
            Nodo_para_ir = {Mejores[E]._ndice};
            Usar_nodos = {1};
        }
        for(auto e: p_2){
            //cerr<<"Candidatos para mejor que no vuelve. "<<Mejores[e].Mejor<<" "<<Mejores[E].Mejor<<" "<<Grafo[Nodo][Mejores[e]._ndice] + 1<<" "<<Grafo[Nodo][Mejores[E]._ndice] + 1<<"\n";
            if(Mejores[E].Mejor + Mejores[e].Mejor > Mejor and Mejores[E]._ndice != Mejores[e]._ndice){
                Mejor = Mejores[E].Mejor + Mejores[e].Mejor;
                Nodo_para_ir = {Mejores[e]._ndice, Mejores[E]._ndice};
                Usar_nodos = {1, Mejores[E].Usar};
            }
            /*vector<Candidato_no_usar_volver> _0;
            vector<Candidato_no_usar_no_volver> _1;
            vector<Candidato_usar_volver> _2;
            vector<Candidato_usar_no_volver> _3;*/
            for(auto EEE/*¿SANS?*/: p_0){
                //cerr<<"Candidatos para mejor que no vuelve. "<<Mejores[e].Mejor<<" "<<Mejores[EEE].Mejor<<" "<<Mejores[E].Mejor<<" "<<Grafo[Nodo][Mejores[EEE]._ndice] + 1<<" "<<Grafo[Nodo][Mejores[e]._ndice] + 1<<" "<<Grafo[Nodo][Mejores[E]._ndice] + 1<<"\n";
                if(Mejores[E].Mejor + Mejores[e].Mejor + Mejores[EEE].Mejor > Mejor and Mejores[EEE]._ndice != Mejores[E]._ndice and Mejores[e]._ndice != Mejores[EEE]._ndice and Mejores[E]._ndice != Mejores[e]._ndice and Mejores[E].Usar == 1){
                    Mejor = Mejores[E].Mejor + Mejores[e].Mejor + Mejores[EEE].Mejor;
                    Nodo_para_ir = {Mejores[e]._ndice, Mejores[EEE]._ndice, Mejores[E]._ndice};
                    Usar_nodos = {1, 0, 1};
                }
            }
        }
    }
    Retorno.Mejor_y_me_quedo += Mejor;
    //cerr<<Retorno.Mejor_y_me_quedo<<" No volver.\n";
    Retorno.Nodos_no_volver = Nodo_para_ir;
    Retorno.Usar_no_volver = Usar_nodos;
    return PD[Nodo][Usar] = Retorno;
}
void Reconstruir(int Nodo, int Anterior, int Usar, int Volver){
    //Visitados[Nodo] = 1;
    //cerr<<Nodo + 1<<" "<<Usar<<" "<<Volver<<" Reconstrucción.\n";
    if(Hoja[Nodo]){
        Recorrido.push_back(Nodo);
        return;
    }
    if(Usar == 1) Recorrido.push_back(Nodo);
    set<int> No_ir;
    if(Volver == 1){
        for(auto E: PD[Nodo][Usar].Nodos_volver){
            //cerr<<Nodo + 1<<" -> "<<Grafo[Nodo][E] + 1<<"\n";
            No_ir.insert(E);
        }
    } else {
        for(auto E: PD[Nodo][Usar].Nodos_no_volver){
            //cerr<<Nodo + 1<<" -> "<<Grafo[Nodo][E] + 1<<"\n";
            No_ir.insert(E);
        }
    }
    int n = Grafo[Nodo].size();
    for(int i = 0; i < n; i++){
        if(Grafo[Nodo][i] == Anterior or No_ir.count(i) >= 1) continue;
        //cerr<<Nodo + 1<<" - "<<Grafo[Nodo][i] + 1<<"\n";
        Recorrido.push_back(Grafo[Nodo][i]);
    }
    int i = 0;
    if(Volver == 1){
        n = PD[Nodo][Usar].Nodos_volver.size();
        auto e = PD[Nodo][Usar].Usar_volver.begin();
        for(auto E: PD[Nodo][Usar].Nodos_volver){
            if(i == 1 and Usar == 0){
                Usar = 1;
                Recorrido.push_back(Nodo);
            }
            //cerr<<Nodo + 1<<" entra a "<<Grafo[Nodo][E] + 1<<"\n";
            Reconstruir(Grafo[Nodo][E], Nodo, *e, 1);
            e++;
            i++;
        }
    } else {
        n = PD[Nodo][Usar].Nodos_no_volver.size();
        auto e = PD[Nodo][Usar].Usar_no_volver.begin();
        for(auto E: PD[Nodo][Usar].Nodos_no_volver){
            if(i == 1 and Usar == 0){
                Usar = 1;
                Recorrido.push_back(Nodo);
            }
            int Regresa_aqu_ = 1;
            if(i == n - 1) Regresa_aqu_ = 0;
            //cerr<<Nodo + 1<<" entra a "<<Grafo[Nodo][E] + 1<<"\n";
            Reconstruir(Grafo[Nodo][E], Nodo, *e, Regresa_aqu_);
            e++;
            i++;
        }
    }
    if(Usar == 0) Recorrido.push_back(Nodo);
}
int Hay;
void DFS(int Nodo){
    //cerr<<Nodo<<"\n";
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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    long long m = 0;
    cin>>n>>k;
    Valor Nada;
    Nada.Existo = 0;
    PD.assign(n, vector<Valor>(2, Nada));
    Grafo.assign(n, {});
    v.assign(n, 0);
    d.assign(n, 2222222222222222);
    a.assign(n, -2);
    Final.assign(n, 0);
    Hay = n;
    for(int i = 0; i < n - 1; i++){
        int A, B;
        cin>>A>>B;
        A--;
        B--;
        Grafo[A].push_back(B);
        Grafo[B].push_back(A);
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
    for(int i = 1; i < n; i++){
        if(Grafo[i].size() == 1){
            Hoja[i] = 1;
            //cerr<<i + 1<<" Hoja.\n";
        }
    }
    auto Respuesta = Resolver(0, -2, 1);
    cout<<max(Respuesta.Mejor_y_vuelvo, Respuesta.Mejor_y_me_quedo)<<"\n";
    Reconstruir(0, -2, 1, (Respuesta.Mejor_y_vuelvo > Respuesta.Mejor_y_me_quedo ? 1 : 0));
    cout<<Recorrido.size()<<"\n";
    for(auto E: Recorrido) cout<<E + 1<<" ";
    return 0;
}