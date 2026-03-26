#include "bits/stdc++.h"
using namespace std;
int main(){
    freopen("01.in", "r", stdin);
    freopen("01F.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    long long f, c, q;
    cin>>f>>c>>q;
    vector< vector<long long> > Tablero(f, vector<long long>(c, 0));
    map<long long, long long> Colorcitos;
    set<long long> Tenemos;
    Colorcitos[0] = f * c;
    Tenemos.insert(0);
    while(q--){
        long long t, i, co;
        cin>>t>>i>>co;
        i--;
        if(t == 1){
            for(long long j = 0; j < c; j++){
                Colorcitos[Tablero[i][j]]--;
                if(Colorcitos[Tablero[i][j]] == 0) Tenemos.erase(Tablero[i][j]);
                Tablero[i][j] = co;
                Colorcitos[co]++;
                Tenemos.insert(co);
                //cout<<j<<" ";
            }
        } else {
            for(long long j = 0; j < f; j++){
                Colorcitos[Tablero[j][i]]--;
                if(Colorcitos[Tablero[j][i]] == 0) Tenemos.erase(Tablero[j][i]);
                Tablero[j][i] = co;
                Colorcitos[co]++;
                Tenemos.insert(co);
                //cout<<j<<" ";
            }
        }
        /*cout<<"\n---\n";
        for(auto E: Tablero){
            for(auto e: E){
                cout<<e<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";*/
    }
    for(auto E: Tenemos){
        cout<<E<<" "<<Colorcitos[E]<<"\n";
    }
    return 0;
}