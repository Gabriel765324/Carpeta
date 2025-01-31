#include "bits/stdc++.h"
using namespace std;
struct Vaca{
    long long Peso, Talento;
};
vector<Vaca> Vacas;
vector< vector<Vaca> > Memorizaci_n;
long long n, w;
Vaca Nada;
bool Igual(Vaca a, Vaca b){
    return a.Peso == b.Peso and a.Talento == b.Talento;
}
Vaca Resolver(long long i, long long W){
    //cerr<<i<<" "<<W<<"\n";
    Vaca Neutro;
    Neutro.Peso = 0;
    Neutro.Talento = 0;
    //cerr<<i<<" "<<n<<" "<<W<<"\n";
    if(W < 0 or i == n) return Neutro;
    //cerr<<Memorizaci_n[i][W].Peso<<" "<<Nada.Peso<<" "<<Memorizaci_n[i][W].Talento<<" "<<Nada.Talento<<"\n";
    if(!Igual(Memorizaci_n[i][W], Nada)) return Memorizaci_n[i][W];
    //cerr<<"?\n";
    Vaca Opci_n1 = Resolver(i + 1, W);
    Vaca Opci_n2 = Resolver(i + 1, W - Vacas[i].Peso);
    Vaca Opci_n3 = Opci_n1;
    Opci_n2.Talento += Vacas[i].Talento;
    Opci_n2.Peso += Vacas[i].Peso;
    Opci_n3.Talento += Vacas[i].Talento;
    Opci_n3.Peso += Vacas[i].Peso;
    cerr<<i<<" "<<W<<"\n";
    cerr<<Opci_n1.Peso<<" "<<Opci_n1.Talento<<" "<<Opci_n2.Peso<<" "<<Opci_n2.Talento<<"\n";
    /*if(Opci_n1.Peso == 0 and Opci_n2.Peso == 0) return Memorizaci_n[i][W] = Neutro;
    if(Opci_n1.Peso == 0){
        cerr<<"2\n";
        return Memorizaci_n[i][W] = Opci_n2;
    }
    if(Opci_n2.Peso == 0){
        cerr<<"1\n";
        return Memorizaci_n[i][W] = Opci_n1;
    }
    if(W - Opci_n1.Peso >= 0 and W - Opci_n2.Peso < 0){
        cerr<<"2\n";
        return Memorizaci_n[i][W] = Opci_n2;
    }
    if(W - Opci_n1.Peso < 0 and W - Opci_n2.Peso >= 0){
        cerr<<"1\n";
        return Memorizaci_n[i][W] = Opci_n1;
    }
    if((double)Opci_n1.Talento / (double)Opci_n1.Peso > (double)Opci_n2.Talento / (double)Opci_n2.Peso){
        cerr<<"1\n";
        return Memorizaci_n[i][W] = Opci_n1;
    } else if((double)Opci_n1.Talento / (double)Opci_n1.Peso < (double)Opci_n2.Talento / (double)Opci_n2.Peso){
        cerr<<"2\n";
        return Memorizaci_n[i][W] = Opci_n2;
    } else {
        if(Opci_n1.Peso < Opci_n2.Peso){
            cerr<<"1\n";
            return Memorizaci_n[i][W] = Opci_n1;
        } else {
            cerr<<"2\n";
            return Memorizaci_n[i][W] = Opci_n2;
        }
    }*/
}
bool operator<(const Vaca &a, const Vaca &b){
    if(a.Peso > b.Peso) return 1;
    else if(a.Peso < b.Peso) return 0;
    else return a.Talento > b.Talento;
}
int main(){
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
    cin>>n>>w;
    Nada.Peso = -2;
    Nada.Talento = -2;
    Vacas.assign(n, Nada);
    Memorizaci_n.assign(n, vector<Vaca>(w, Nada));
    for(long long i = 0; i < n; i++){
        cin>>Vacas[i].Peso>>Vacas[i].Talento;
    }
    sort(Vacas.begin(), Vacas.end());
    for(long long i = 0; i < n; i++) cout<<Vacas[i].Peso<<" "<<Vacas[i].Talento<<"\n";
    cout<<Resolver(0, w - 1).Talento * 1000 / Resolver(0, w - 1).Peso;
    return 0;
}//Está mal. :(