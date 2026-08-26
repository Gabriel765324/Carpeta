#include "bits/stdc++.h"
using namespace std;
vector< vector<int> > Permutaciones;
vector<int> operator+(const vector<int>& a, const vector<int>& b){
    vector<int> c;
    for(int i = 0; i < int(a.size()); i++){
        c.push_back(b[a[i]]);
    }
    return c;
}
long long Premio(const vector<int>& a){
    long long r = 0;
    for(int i = 0; i < int(a.size()); i++){
        r += (long long)(i + 1) * (long long)(a[i] + 1);
    }
    return r;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, m, q;
        cin>>n>>m;
        Permutaciones.assign(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>Permutaciones[i][j];
                Permutaciones[i][j]--;
            }
        }
        cin>>q;
        if(n <= 444){
            vector< vector<long long> > Chanchullo(n, vector<long long>(n));
            for(int i = 0; i < n; i++){
                vector<int> Copia = Permutaciones[i];
                Chanchullo[i][i] = Premio(Copia);
                for(int j = i + 1; j < n; j++){
                    Copia = Copia + Permutaciones[j];
                    Chanchullo[i][j] = Premio(Copia);
                }
            }
            while(q--){
                int a, b;
                cin>>a>>b;
                cout<<Chanchullo[a - 1][b - 1]<<"\n";
            }
        } else {
            vector< vector< pair< vector<int>, int > > > Mesa(n);
            for(int i = 0; i < n - 1; i++){
                Mesa[i].push_back({Permutaciones[i + 1], i + 1});
            }
            for(int i = n - 2; i > -1; i--){
                int Anterior = i + 1;
                for(int j = 0; j < Mesa[Anterior].size(); j++){
                    Mesa[i].push_back({Mesa[i].back().first + Mesa[Anterior][j].first, Mesa[Anterior][j].second});
                    Anterior = Mesa[Anterior][j].second;
                }
            }
            /*for(auto E: Mesa){
                for(auto e: E){
                    for(auto EE: e.first){
                        cerr<<EE + 1<<" ";
                    }
                    cerr<<" "<<e.second<<"\n";
                }
                cerr<<"\n";
            }*/
            while(q--){
                int a, b, m;
                cin>>a>>b;
                a--;
                b--;
                vector<int> Copia = Permutaciones[a];
                int d = b - a, Bit = 0;
                while(a < b){
                    /*cerr<<a + 1<<"  ";
                    for(auto E: Copia) cerr<<E + 1<<" ";
                    cerr<<"\n";*/
                    if((1<<Bit) & d){
                        d -= Bit;
                        Copia = Copia + Mesa[a][Bit].first;
                        a = Mesa[a][Bit].second;
                    }
                    Bit++;
                }
                /*cerr<<a + 1<<"  ";
                for(auto E: Copia) cerr<<E + 1<<" ";
                cerr<<"\n";*/
                cout<<Premio(Copia)<<"\n";
            }
        }
    }
    return 0;
}