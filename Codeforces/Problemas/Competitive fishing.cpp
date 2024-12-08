#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n, k, Suma = 0;
        string s;
        bool Bien = 0;
        cin>>n>>k>>s;
        vector<long long> a(n);
        for(long long i = n - 1; i > 0; i--){
            if(s[i] == '1') Suma++;
            else Suma--;
            a[i] = Suma;
        }
        sort(a.rbegin(), a.rend());
        Suma = 0;
        for(long long i = 0; i < n; i++){
            Suma += a[i];
            if(Suma >= k){
                Bien = 1;
                cout<<i + 2;
                break;
            }
        }
        if(!Bien) cout<<-1;
        cout<<"\n";
    }
    return 0;
}