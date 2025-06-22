#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector< pair<long long, long long> > a(n);
        vector<long long> Marcados(2 * n, 0), Doble(2 * n, 0);
        string r = "";
        for(long long i = 0; i < n; i++){
            cin>>a[i].first>>a[i].second;
            a[i].first--;
            a[i].second--;
            if(a[i].second - a[i].first == 0){
                if(Marcados[a[i].first] == 1) Doble[a[i].first] = 1;
                Marcados[a[i].first] = 1;
            }
        }
        for(long long i = 1; i < 2 * n; i++){
            Marcados[i] += Marcados[i - 1];
        }
        for(long long i = 0; i < n; i++){
            long long c = Marcados[a[i].second];
            if(a[i].first > 0) c -= Marcados[a[i].first - 1];
            if(a[i].second - a[i].first > 0){
                if(c == a[i].second - a[i].first + 1) r += "0";
                else r += "1";
            } else {
                if(Doble[a[i].first] == 1) r += "0";
                else r += "1";
            }
        }
        cout<<r<<"\n";
    }
    return 0;
}