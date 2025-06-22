#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n, m;
        cin>>n>>m;
        if(m >= n * 2){
            cout<<"NO\n";
            continue;
        } else cout<<"YES\n";
        vector< vector<long long> > Respuesta(2 * n, vector<long long>(m, -2));
        long long Color = 1;
        for(long long x = 0; x < 1; x++){
            long long cx = x;
            for(long long y = 0; y < 2 * n and cx < m; y++){
                Respuesta[y][cx] = Color;
                cx++;
            }
            if(x % 2 == 0) Color++;
        }
        Color = n;
        for(long long x = 1; x < m; x++){
            long long cx = x;
            for(long long y = 0; y < 2 * n and cx < m; y++){
                Respuesta[y][cx] = Color;
                cx++;
            }
            if(x % 2 == 0) Color--;
        }
        Color = 1;
        for(long long x = 1; x < 2 * n; x++){
            long long cx = x;
            for(long long y = 0; y < m and cx < 2 * n; y++){
                Respuesta[cx][y] = Color;
                cx++;
            }
            if(x % 2 == 1) Color++;
        }
        for(auto E: Respuesta){
            for(auto e: E) cout<<e<<" ";
            cout<<"\n";
        }
        /*deque<long long> a(n), b(m);
        for(long long i = 0; i < n; i++) cin>>a[i];
        for(long long i = 0; i < m; i++) cin>>b[i];
        long long r = a[0];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for(; a[0] < r; a.pop_front()){}
        while(a.size() >= 2 and a[1] == r) a.pop_front();
        long long Respuesta = 0;
        sort(b.begin(), b.end());
        n = a.size() - 1;
        vector<long long> Puestos;
        for(long long i = 0; i < m; i++){
            if(b[i] <= r){
                Respuesta += 1;
                Puestos.push_back(1);
            } else {
                Respuesta += n;
                Puestos.push_back(n);
            }
        }
        cout<<Respuesta<<" ";
        */
    }
    return 0;
}