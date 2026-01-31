#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin>>n>>q;
    vector<int> Bien(n * 2 + 2, 0);
    for(int i = 1; i <= q; i++){
        int a;
        cin>>a;
        a--;
        Bien[a % n]++;
        if(Bien[a % n] == n){
            cout<<i;
            return 0;
        }
        Bien[a / n + n]++;
        if(Bien[a / n + n] == n){
            cout<<i;
            return 0;
        }
        if(a % (n + 1) == 0 and a / (n + 1) < n){
            Bien[n * 2]++;
            if(Bien[n * 2] == n){
                cout<<i;
                return 0;
            }
        }
        if(a % (n - 1) == 0 and a / (n - 1) <= n and a != 0){
            Bien.back()++;
            if(Bien.back() == n){
                cout<<i;
                return 0;
            }
        }
        /*for(auto E: Bien) cerr<<E<<" ";
        cerr<<"\n";*/
    }
    cout<<-1;
    return 0;
}