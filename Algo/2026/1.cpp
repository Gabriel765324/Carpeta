#include "bits/stdc++.h"
using namespace std;
void J(){
    int n, k;
    cin>>n>>k;
    k--;
    vector< multiset<char> > Jugar(n);
    map<char, char> Mapa;
    Mapa['A'] = 'a';
    char Asignar = '2', Dar_este = 'b';
    for(; Asignar <= '9'; Asignar++){
        Mapa[Asignar] = Dar_este;
        Dar_este++;
    }
    Mapa['D'] = Dar_este;
    Dar_este++;
    Mapa['J'] = Dar_este;
    Dar_este++;
    Mapa['Q'] = Dar_este;
    Dar_este++;
    Mapa['K'] = Dar_este;
    Mapa[' '] = ' ';
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        if(i == k) s += ' ';
        for(auto E: s) Jugar[i].insert(Mapa[E]);
    }
    int i = k;
    bool Comod_n = 0;
    while(1){
        cerr<<"-------------\n"<<i + 1<<"\n";
        for(auto E: Jugar[i]) cerr<<E;
        cerr<<"\n";
        cerr<<"\n";
        for(auto E: Jugar[(i + 1) % n]) cerr<<E;
        cerr<<"\n";
        cerr<<"\n";
        map<char, int> Cuenta;
        if(Jugar[i].size() == 4){
            char Ganar = *Jugar[i].begin();
            auto E = Jugar[i].end();
            E--;
            if(Ganar == *E){
                cout<<i + 1;
                return;
            }
        }
        set<char> Tengo;
        for(auto E: Jugar[i]){
            if(E != ' '){
                Tengo.insert(E);
                Cuenta[E]++;
            }
        }
        int Menor = 2222;
        bool Empate = 0;
        char Este = '-';
        for(auto E: Tengo){
            if(Cuenta[E] < Menor){
                Empate = 0;
                Este = E;
                Menor = Cuenta[E];
            } else if(Cuenta[E] == Menor){
                Empate = 1;
            }
        }
        if(!Empate){
            if(Comod_n and *Jugar[i].begin() == ' '){
                Jugar[i].erase(' ');
                Jugar[(i + 1) % n].insert(' ');
                Comod_n = 0;
            } else {
                Jugar[i].erase(Jugar[i].find(Este));
                Jugar[(i + 1) % n].insert(Este);
                Comod_n = 1;
            }
        } else {
            if(Comod_n and *Jugar[i].begin() == ' '){
                Jugar[i].erase(' ');
                Jugar[(i + 1) % n].insert(' ');
                Comod_n = 0;
            } else if(*Jugar[i].begin() == ' ' and !Comod_n){
                Jugar[i].erase(Jugar[i].find(Este));
                Jugar[(i + 1) % n].insert(Este);
                Comod_n = 1;
            } else {
                Comod_n = 1;
                Jugar[i].erase(Jugar[i].find(Este));
                Jugar[(i + 1) % n].insert(Este);
            }
        }
        for(auto E: Jugar[i]) cerr<<E;
        cerr<<"\n";
        cerr<<"\n";
        for(auto E: Jugar[(i + 1) % n]) cerr<<E;
        cerr<<"\n";
        cerr<<"\n";
        if(Jugar[i].size() == 4){
            char Ganar = *Jugar[i].begin();
            auto E = Jugar[i].end();
            E--;
            if(Ganar == *E){
                cout<<i + 1;
                return;
            }
        }
        i++;
        i %= n;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    J();
    return 0;
}