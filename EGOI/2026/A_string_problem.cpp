#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    map<int, int> Puntaje;
    vector< pair<int, int> > Pares(n);
    for(int i = 0; i < n; i++){
        cin>>Pares[i].first>>Pares[i].second;
        Puntaje[(Pares[i].first + Pares[i].second) % (2 * n)]++;
    }
    int Mayor = -2, Valor = -2, Tiempo = n;
    for(int i = 1; i < n * 2; i += 2){
        if(Puntaje[i] > Mayor){
            Mayor = Puntaje[i];
            Valor = i;
            Tiempo = n - Puntaje[i];
        }
    }
    //cerr<<Valor<<"\n";
    vector<int> Pares_posibles(2 * n, -2);
    int A_adir = Valor;
    for(int i = 0; i < n * 2; i++){
        //cerr<<i<<" "<<A_adir<<"\n";
        Pares_posibles[i] = A_adir;
        A_adir--;
        if(A_adir < 0) A_adir = n * 2 - 1;
    }
    cout<<Tiempo<<"\n";
    set< pair< pair<int, int>, int > > Considerar;
    for(int i = 0; i < n; i++){
        if(Pares_posibles[Pares[i].first] == Pares[i].second){
            Pares_posibles[Pares[i].first] = -2;
            Pares_posibles[Pares[i].second] = -2;
            continue;
        }
        Considerar.insert({Pares[i], i});
        swap(Pares[i].first, Pares[i].second);
        Considerar.insert({Pares[i], i});
    }
    /*cerr<<"\nPares posibles:\n";
    for(auto E: Pares_posibles){
        cerr<<E<<" ";
    }
    cerr<<"\n";*/
    if(Tiempo == 0) return 0;
    for(auto E = Considerar.begin(); !Considerar.empty(); ){
        int i = E->second, Extremo0 = E->first.first, Extremo1 = E->first.second, Extremo2 = Pares_posibles[Extremo0];
        /*cerr<<"Pares posibles:\n";
        for(auto E: Pares_posibles){
            cerr<<E<<" ";
        }
        cerr<<"\n";*/
        if(Extremo2 == -2){
            swap(Extremo0, Extremo1);
            Extremo2 = Pares_posibles[Extremo0];
        }
        //cerr<<Extremo0<<" "<<Extremo1<<" "<<Extremo2<<" "<<i<<" Dato.\n";
        cout<<i<<" "<<Extremo1<<" "<<Extremo2<<"\n";
        Pares_posibles[Extremo0] = -2;
        Pares_posibles[Extremo2] = -2;
        Considerar.erase({{Extremo0, Extremo1}, i});
        Considerar.erase({{Extremo1, Extremo0}, i});
        /*for(auto ss: Considerar){
            cerr<<ss.first.first<<" "<<ss.first.second<<" "<<ss.second<<" Queda.\n";
        }*/
        E = Considerar.lower_bound({{Extremo2, -2}, -2});
        if(E == Considerar.end()) E = Considerar.begin();
    }
    return 0;
}