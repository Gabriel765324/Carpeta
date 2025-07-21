#include "iostream"
#include "vector"
using namespace std;
vector< vector< vector<int> > > PD;
vector<int> Fichas;
int m, t, n;
int Resolver(int i, int j, int k){
    if(j == 0 or k == 0) return (int)(j == 0 and k == 0);
    if(i >= m or j < 0 or k < 0) return 0;
    if(PD[i][j][k] != -2) return PD[i][j][k];
    return PD[i][j][k] = Resolver(i + 1, j - Fichas[i], k - 1) + Resolver(i + 1, j, k);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int g;
    cin>>g;
    vector< vector<int> > Tri_ngulo = {{1}};
    for(int i = 1; i <= 30; i++){
        Tri_ngulo.push_back({1});
        for(int j = 0; j < i - 1; j++){
            Tri_ngulo.back().push_back(Tri_ngulo[i - 1][j] + Tri_ngulo[i - 1][j + 1]);
        }
        Tri_ngulo.back().push_back(1);
    }
    for(int G = 1; G <= g; G++){
        cin>>m;
        Fichas.assign(m, 0);
        for(int i = 0; i < m; i++) cin>>Fichas[i];
        cin>>n>>t;
        PD.assign(m, vector< vector<int> >(t + 1, vector<int>(n + 1, -2)));
        /*vector< vector< vector<int> > > PD(m + 1, vector< vector<int> >(t + 1, vector<int>(n + 1, 0)));
        PD[m][0][0] = 1;
        for(int i = m - 1; i > -1; i--){
            PD[i][0][0] = 1;
            int aaaa = min(Fichas[i], t + 1);
            for(int j = t; j >= aaaa; j--){
                for(int k = n; k >= 1; k--){
                    PD[i][j][k] = PD[i + 1][j][k] + PD[i + 1][j - Fichas[i]][k - 1];
                }
            }
            for(int j = aaaa - 1; j > 0; j--){
                for(int k = n; k >= 1; k--){
                    PD[i][j][k] = PD[i + 1][j][k];
                }
            }
        }*/
        cout<<"Game "<<G<<" -- "<<Resolver(0, t, n)<<" : "<<Tri_ngulo[m][n] - Resolver(0, t, n)<<"\n";
    }
    return 0;
}