#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, m, o = 0, l = 0, s = 0, z = 0, t = 0;
    cin>>n>>m;
    deque<string> Matriz(n);
    for(long long i = 0; i < n; i++) cin>>Matriz[i];
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < m; j++){
            if(Matriz[i][j] == '.') continue;
            if(j + 3 < m and Matriz[i][j + 1] == Matriz[i][j] and Matriz[i][j + 2] == Matriz[i][j] and Matriz[i][j + 3] == Matriz[i][j]){
                l++;
                Matriz[i][j] = '.';
                Matriz[i][j + 1] = '.';
                Matriz[i][j + 2] = '.';
                Matriz[i][j + 3] = '.';
            } else if(i + 3 < n and Matriz[i + 1][j] == Matriz[i][j] and Matriz[i + 2][j] == Matriz[i][j] and Matriz[i + 3][j] == Matriz[i][j]){
                l++;
                Matriz[i][j] = '.';
                Matriz[i + 1][j] = '.';
                Matriz[i + 2][j] = '.';
                Matriz[i + 3][j] = '.';
            } else if(i + 1 < n and j + 1 < m and Matriz[i + 1][j] == Matriz[i][j] and Matriz[i][j + 1] == Matriz[i][j] and Matriz[i + 1][j + 1] == Matriz[i][j]){
                o++;
                Matriz[i][j] = '.';
                Matriz[i + 1][j] = '.';
                Matriz[i + 1][j + 1] = '.';
                Matriz[i][j + 1] = '.';
            } else if(i + 1 < n and j - 1 > -1 and j + 1 < m and Matriz[i][j + 1] == Matriz[i][j] and Matriz[i + 1][j] == Matriz[i][j] and Matriz[i + 1][j - 1] == Matriz[i][j]){
                s++;
                Matriz[i][j] = '.';
                Matriz[i + 1][j] = '.';
                Matriz[i][j + 1] = '.';
                Matriz[i + 1][j - 1] = '.';
            } else if(i + 2 < n and j + 1 < m and Matriz[i + 1][j] == Matriz[i][j] and Matriz[i + 1][j + 1] == Matriz[i][j] and Matriz[i + 2][j + 1] == Matriz[i][j]){
                s++;
                Matriz[i][j] = '.';
                Matriz[i + 1][j] = '.';
                Matriz[i + 1][j + 1] = '.';
                Matriz[i + 2][j + 1] = '.';
            } else if(i + 1 < n and j - 1 > -1 and j + 1 < m and Matriz[i][j - 1] == Matriz[i][j] and Matriz[i + 1][j] == Matriz[i][j] and Matriz[i + 1][j + 1] == Matriz[i][j]){
                z++;
                Matriz[i][j] = '.';
                Matriz[i + 1][j] = '.';
                Matriz[i][j - 1] = '.';
                Matriz[i + 1][j + 1] = '.';
            } else if(i + 2 < n and j - 1 > -1 and Matriz[i + 1][j] == Matriz[i][j] and Matriz[i + 1][j - 1] == Matriz[i][j] and Matriz[i + 2][j - 1] == Matriz[i][j]){
                z++;
                Matriz[i][j] = '.';
                Matriz[i + 1][j] = '.';
                Matriz[i + 1][j - 1] = '.';
                Matriz[i + 2][j - 1] = '.';
            } else t++;
        }
    }
    cout<<o<<"\n"<<l<<"\n"<<s<<"\n"<<z<<"\n"<<t / 4;
    return 0;
}