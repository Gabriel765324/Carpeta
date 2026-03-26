#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin>>n>>m>>k;
    vector< vector<int> > a(n, vector<int>(m, 22222222));
    while(k--){
        int x, y, s;
        cin>>x>>y>>s;
        x--;
        y--;
        int p = 1, Nuevos = 0, Pasos = 1;
        if(x > -1 and x < n and y > -1 and y < m){
            Nuevos++;
            a[x][y] = min(a[x][y], Pasos);
        }
        Pasos++;
        while(Nuevos < n * m){
            for(int i = 0; i < p; i++){
                if(p % 2 == 1) x--;
                else x++;
                if(x > -1 and x < n and y > -1 and y < m){
                    Nuevos++;
                    a[x][y] = min(a[x][y], Pasos);
                }
                Pasos++;
                /*for(auto E: a){
                    for(auto e: E) cerr<<e<<" ";
                    cerr<<"\n";
                }
                cerr<<"----\n";*/
            }
            for(int i = 0; i < p; i++){
                if(p % 2 == 1){
                    if(s == 0) y++;
                    else y--;
                } else {
                    if(s == 0) y--;
                    else y++;
                }
                if(x > -1 and x < n and y > -1 and y < m){
                    Nuevos++;
                    a[x][y] = min(a[x][y], Pasos);
                }
                Pasos++;
                /*for(auto E: a){
                    for(auto e: E) cerr<<e<<" ";
                    cerr<<"\n";
                }
                cerr<<"----\n";*/
            }
            p++;
        }
    }
    for(auto E: a){
        for(auto e: E) cout<<e<<" ";
        cout<<"\n";
    }
    return 0;
}