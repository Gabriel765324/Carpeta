#include "bits/stdc++.h"
#define el "\n"
#define ll long long
#define ii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define vi vector<int>
#define di deque<int>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define pf push_front
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q, lastans = 0, Ra_z;
    cin>>n;
    Ra_z = sqrt(n);
    vector< di > a;
    vector< vi > Frecuencias;
    di A_adir;
    forn(i, n){
        int Extra;
        cin>>Extra;
        A_adir.pb(Extra);
        if(int(A_adir.size()) == Ra_z or i == n - 1){
            a.pb(A_adir);
            vi Frecuencia(n + 1, 0);
            for(auto E: A_adir) Frecuencia[E]++;
            Frecuencias.pb(Frecuencia);
            A_adir.clear();
        }
    }
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int l, r;
            cin>>l>>r;
            l += lastans - 1 + 22 * n;
            l %= n;
            r += lastans - 1 + 22 * n;
            r %= n;
            if(l > r) swap(l, r);
            int Bloquel = l / Ra_z, Bloquer = r / Ra_z, Valor = a[Bloquer][r % Ra_z];
            a[Bloquer].erase(a[Bloquer].begin() + (r % Ra_z));
            if(Bloquel == Bloquer){
                a[Bloquel].insert(a[Bloquel].begin() + (l % Ra_z), Valor);
                continue;
            }
            Frecuencias[Bloquer][Valor]--;
            for(Bloquer--; Bloquer >= Bloquel; Bloquer--){
                Frecuencias[Bloquer][a[Bloquer].back()]--;
                Frecuencias[Bloquer + 1][a[Bloquer].back()]++;
                a[Bloquer + 1].pf(a[Bloquer].back());
                a[Bloquer].pop_back();
            }
            a[Bloquel].insert(a[Bloquel].begin() + l % Ra_z, Valor);
            Frecuencias[Bloquel][Valor]++;
        } else {
            int l, r, k;
            cin>>l>>r>>k;
            l += lastans - 1 + 22 * n;
            l %= n;
            r += lastans - 1 + 22 * n;
            r %= n;
            k += lastans - 1 + 22 * n;
            k %= n;
            k++;
            if(l > r) swap(l, r);
            int Bloquel = l / Ra_z, Bloquer = r / Ra_z;
            lastans = 0;
            if(Bloquel == Bloquer){
                for(; l <= r; l++){
                    //cerr<<Bloquel<<" "<<l<<" "<<lastans<<" Iguales."<<el;
                    lastans += (a[Bloquel][l % Ra_z] == k ? 1 : 0);
                }
                cout<<lastans<<el;
                continue;
            }
            forsn(i, l % Ra_z, int(a[Bloquel].size())){
                //cerr<<Bloquel<<" "<<i<<" "<<lastans<<" Bloquel"<<el;
                lastans += (a[Bloquel][i] == k ? 1 : 0);
            }
            forn(i, r % Ra_z + 1){
                //cerr<<Bloquer<<" "<<i<<" "<<lastans<<" "<<a[Bloquer][i]<<" "<<k<<" Bloquer."<<el;
                lastans += (a[Bloquer][i] == k ? 1 : 0);
            }
            Bloquel++;
            for(Bloquer--; Bloquel <= Bloquer; Bloquel++){
                //cerr<<Bloquel<<" "<<Frecuencias[Bloquel][k]<<" "<<k<<" Bloques."<<el;
                lastans += Frecuencias[Bloquel][k];
            }
            cout<<lastans<<el;
        }
        /*cerr<<"Bloques.\n";
        for(auto E: a){
            for(auto e: E){
                cerr<<e<<" ";
            }
            cerr<<"\n";
        }
        cerr<<"----\nFrecuencias.\n";
        for(auto E: Frecuencias){
            for(auto e: E){
                cerr<<e<<" ";
            }
            cerr<<"\n";
        }
        cerr<<"----\n";*/
    }
    return 0;
}