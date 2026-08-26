#include "bits/stdc++.h"
using namespace std;
vector< vector<int> > Grafo;
struct Valor{
    int Respuesta, Suma_1;
    vector< pair<int, int> > Posibles;
    Valor(){
        Respuesta = -2;
        Suma_1 = 0;
    }
    Valor(int r){
        Respuesta = r;
        Suma_1 = 0;
    }
};
vector< vector<Valor> > PD;
int Respuesta = INT_MAX;
int Resolver(int Nodo, int Usar, int Padre){
    if(int(Grafo[Nodo].size()) == 1 and Padre != -2){
        if(Usar == 1){
            PD[Nodo][Usar] = Valor(2);
            return 2;
        }
        PD[Nodo][Usar] = Valor(0);
        return 0;
    }
    if(PD[Nodo][Usar].Respuesta != -2) return PD[Nodo][Usar].Respuesta;
    PD[Nodo][Usar].Respuesta = INT_MAX;
    PD[Nodo][Usar].Suma_1 = 0;
    for(auto E: Grafo[Nodo]){
        if(E == Padre) continue;
        PD[Nodo][Usar].Suma_1 += Resolver(E, 1, Nodo);
        if(Usar == 1) PD[Nodo][Usar].Posibles.push_back({Resolver(E, 0, Nodo), Resolver(E, 1, Nodo)});
    }
    if(Usar == 0){
        return PD[Nodo][Usar].Respuesta = PD[Nodo][Usar].Suma_1;
    }
    int Dar = INT_MAX;
    for(auto E: PD[Nodo][Usar].Posibles){
        Dar = min(Dar, PD[Nodo][Usar].Suma_1 - E.second + E.first + 1);
    }
    return PD[Nodo][Usar].Respuesta = Dar;
}
void Reraiceando(int Nodo, int Padre){
    PD[Nodo][0] = Valor();
    PD[Nodo][1] = Valor();
    int Sumita = 0;
    for(auto E: Grafo[Nodo]){
        Sumita += PD[E][1].Respuesta;
        PD[Nodo][1].Posibles.push_back({PD[E][0].Respuesta, PD[E][1].Respuesta});
    }
    PD[Nodo][0].Suma_1 = Sumita;
    PD[Nodo][0].Respuesta = Sumita;
    PD[Nodo][1].Suma_1 = Sumita;
    int Dar = INT_MAX;
    for(auto E: PD[Nodo][1].Posibles){
        Dar = min(Dar, Sumita - E.second + E.first + 1);
    }
    PD[Nodo][1].Respuesta = Dar;
    Respuesta = min(Respuesta, Dar);
    //cerr<<Nodo<<"\n";
    //for(auto E: PD) cout<<E[0].Respuesta<<" "<<E[1].Respuesta<<"\n";
    vector< pair<int, int> > Quitar;
    int i = 0;
    for(auto E: Grafo[Nodo]){
        Quitar.push_back({PD[Nodo][1].Posibles[i].first - PD[Nodo][1].Posibles[i].second, E});
    }
    sort(Quitar.begin(), Quitar.end());
    for(auto E: Grafo[Nodo]){
        if(E == Padre) continue;
        vector<int> Restaurar = {PD[Nodo][0].Suma_1, PD[Nodo][0].Respuesta, PD[Nodo][1].Suma_1, PD[Nodo][1].Respuesta};
        PD[Nodo][0].Suma_1 -= PD[E][1].Respuesta;
        PD[Nodo][0].Respuesta = PD[Nodo][0].Suma_1;
        PD[Nodo][1].Suma_1 -= PD[E][1].Respuesta;
        PD[Nodo][1].Respuesta -= PD[E][1].Respuesta;
        if(int(Quitar.size()) == 1){
            PD[Nodo][0].Respuesta = 0;
            PD[Nodo][1].Respuesta = 2;
        } else {
            if(Quitar[0].second == E){
                PD[Nodo][1].Respuesta -= Quitar[0].first;
                PD[Nodo][1].Respuesta += Quitar[1].first;
            }
        }
        Reraiceando(E, Nodo);
        PD[Nodo][0].Suma_1 = Restaurar[0];
        PD[Nodo][0].Respuesta = Restaurar[1];
        PD[Nodo][1].Suma_1 = Restaurar[2];
        PD[Nodo][1].Respuesta = Restaurar[3];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    if(n == 1){
        cout<<"2\n";
        return 0;
    }
    if(n == 2){
        cout<<"1\n";
        return 0;
    }
    if(n == 3){
        cout<<"3\n";
        return 0;
    }
    Grafo.assign(n, {});
    PD.assign(n, vector<Valor>(2));
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        Grafo[a].push_back(b);
        Grafo[b].push_back(a);
    }
    Respuesta = Resolver(0, 1, -2);
    Resolver(0, 0, -2);
    //for(auto E: PD) cout<<E[0].Respuesta<<" "<<E[1].Respuesta<<"\n";
    Reraiceando(0, -2);
    cout<<Respuesta<<"\n";
    return 0;
}