#include "bits/stdc++.h"
using namespace std;
deque< deque<int> > Suma;
int Consulta(int i, int j, int k, int l){
    if(i > k) swap(i, k);
    if(j > l) swap(j, l);
    //cerr<<i<<" "<<j<<" "<<k<<" "<<l<<"\n";
    //cerr<<"Sumas "<<Suma[k][l]<<" "<<Suma[i - 1][j]<<" "<<Suma[i][j - 1]<<" "<<Suma[i - 1][j - 1]<<"\n";
    return Suma[k][l] - Suma[i - 1][l] - Suma[k][j - 1] + Suma[i - 1][j - 1];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    Suma.assign(n, deque<int>(m, 0));
    for(int i = 0; i < n; i++){
        string a;
        cin>>a;
        for(int j = 0; j < m; j++){
            Suma[i][j] = a[j] - '0';
        }
        Suma[i].push_front(1);
    }
    Suma.push_front(deque<int>(m + 1, 1));
    for(int i = 1; i <= n; i++) Suma[i][0] = i + 1;
    for(int i = 1; i <= m; i++) Suma[0][i] = i + 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            Suma[i][j] += Suma[i - 1][j] + Suma[i][j - 1] - Suma[i - 1][j - 1];
        }
    }
    /*for(auto E: Suma){
        for(auto e: E){
            cerr<<e<<" ";
        }
        cerr<<"\n";
    }*/
    int r = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 1; k <= n; k++){
                for(int l = 1; l <= m; l++){
                    if(Consulta(i, j, k, l) == 0){
                        //cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<2 * (abs(i - k) + 1) + 2 * (abs(l - j) + 1)<<"\n";
                        r = max(r, 2 * (abs(i - k) + 1) + 2 * (abs(l - j) + 1));
                    }
                }
            }
        }
    }
    cout<<r;
    return 0;
}