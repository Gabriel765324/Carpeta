#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long i = 2, d = 999, Mejor = 2, c = 7;
        while(c--){
            long long _1 = (d - i + 1) / 3 + i, _2 = 2 * (d - i + 1) / 3 + i, r;
            cout<<"? "<<_1<<" "<<_2<<endl;
            cin>>r;
            if(r == -1) return 0;
            if(r == (_1 + 1) * (_2 + 1)){
                Mejor = _1;
                d = _1 - 1;
            } else if(r == _1 * (_2 + 1)){
                Mejor = _2;
                i = _1 + 1;
                d = _2 - 1;
            } else if(r == _1 * _2){
                i = _2 + 1;
            }
        }
        cout<<"! "<<Mejor<<endl;
    }
    return 0;
}