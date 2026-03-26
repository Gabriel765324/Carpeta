#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> IF(n), ED(n);
        for(int i = 0; i < n; i++) cin>>IF[i];
        for(int i = 0; i < n; i++) cin>>ED[i];
        vector< vector< vector< vector<bool> > > > PD(11, vector< vector< vector<bool> > >(11, vector< vector<bool> >(101, vector<bool>(101, 0))));
        PD[0][0][0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < 11; j++){
                for(int k = 1; k < 11; k++){
                    for(int l = 100; l - IF[i] > -1; l--){
                        for(int m = 100; m - ED[i] > -1; m--){
                            PD[j][k][l][m] = PD[j][k][l][m] or PD[j - 1][k - 1][l - IF[i]][m - ED[i]];
                        }
                    }
                }
            }
        }
        /*for(int i = 0; i <= 4; i++){
            cerr<<"   ";
            for(int aaa = 0; aaa < 27; aaa++){
                cerr<<aaa<<" ";
                if(aaa < 10) cerr<<" ";
            }
            cerr<<"\n";
            for(int j = 0; j < 27; j++){
                cerr<<j<<" ";
                if(j < 10) cerr<<" ";
                for(int k = 0; k < 27; k++){
                    cerr<<PD[i][j][k]<<"  ";
                }
                cerr<<"\n";
            }
            cerr<<"\n\n";
        }*/
        int s;
        cin>>s;
        while(s--){
            int o, k, i, e;
            cin>>o>>k>>i>>e;
            cout<<((/*o >= k and k <= n and o <= n and */PD[o][k][i][e] == 1) ? "YES\n" : "NO\n");
        }
    }
    return 0;
}

/*
1
4
1 2 3 4
5 6 7 8
6
4 2 3 11
1 3 6 14
3 3 6 18
1 1 4 8
3 3 7 4
2 2 2 10

1
3
0 0 0
2 5 7
3
5 1 0 5
3 5 0 35
3 3 0 9

*/