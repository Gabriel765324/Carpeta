#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        map<string, long long> Mapa;
        set<string> Disponibles;
        set<string> Usados;
        set< pair<string, long long> > Posiciones;
        for(long long i = 0; i < n; i++){
            string s;
            cin>>s;
            Mapa[s]++;
            Disponibles.insert(s);
            Posiciones.insert(make_pair(s, i));
            Usados.insert(s);
        }
        long long c = 0;
        vector<string> Respuesta(n);
        for(auto E: Disponibles){
            Mapa[E]--;
            Respuesta[(*Posiciones.lower_bound(make_pair(E, 0))).second] = E;
            Posiciones.erase(Posiciones.lower_bound(make_pair(E, 0)));
            while(Mapa[E]--){
                string s = E;
                for(long long i = 0; i < 4; i++){
                    s = E;
                    for(char j = '0'; j <= '9'; j++){
                        s[i] = j;
                        if(Usados.find(s) == Usados.end()){
                            i = 2222;
                            break;
                        }
                    }
                }
                c++;
                Usados.insert(s);
                Respuesta[(*Posiciones.lower_bound(make_pair(E, 0))).second] = s;
                Posiciones.erase(Posiciones.lower_bound(make_pair(E, 0)));
            }
        }
        cout<<c<<"\n";
        for(auto E: Respuesta) cout<<E<<"\n";
    }
    return 0;
}