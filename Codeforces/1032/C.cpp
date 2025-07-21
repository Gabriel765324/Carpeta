#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector< vector<int> > a(n, vector<int>(m));
        int Mayor = 0;
        deque< pair<int, int> > Mayores;
        int x, y, cx, cy;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>a[i][j];
                if(a[i][j] > Mayor){
                    Mayores.clear();
                    Mayor = a[i][j];
                    Mayores.push_back({i, j});
                    x = i;
                    y = j;
                } else if(a[i][j] == Mayor) Mayores.push_back({i, j});
            }
        }
        int Posible = 1;
        cx = x;
        cy = y;
        Mayores.pop_front();
        n = Mayores.size();
        if(n >= 1){
            int i;
            for(i = 0; i < n; i++){
                if(Mayores[i].first != x and Mayores[i].second != y){
                    break;
                }
            }
            if(i < n){
                x = Mayores[i].first;
                for(int j = 0; j < n; j++){
                    if(Mayores[j].first != x and Mayores[j].second != y){
                        Posible = 0;
                        break;
                    }
                }
                if(!Posible){
                    x = cx;
                    y = Mayores[i].second;
                    Posible = 1;
                    for(int j = 0; j < n; j++){
                        if(Mayores[j].first != x and Mayores[j].second != y){
                            Posible = 0;
                            break;
                        }
                    }
                }
            }
        }
        cout<<Mayor - Posible<<"\n";
    }
    return 0;
}