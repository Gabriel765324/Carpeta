#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q, c = 0, r;
    cin>>n>>q;
    vector<int> a(n + 2, 0);
    for(int i = 0; i < q; i++){
        cin>>r;
        a[r] = 1 - a[r];
        if(a[r] == 1){
            int Suma = 0;
            if(a[r - 1] + a[r + 1] == 0) Suma = 1;
            if(a[r - 1] + a[r + 1] == 2) Suma = -1;
            c += Suma;
        } else {
            int Suma = 0;
            if(a[r - 1] + a[r + 1] == 0) Suma = -1;
            if(a[r - 1] + a[r + 1] == 2) Suma = 1;
            c += Suma;
        }
        cout<<c<<"\n";
    }
    return 0;
}