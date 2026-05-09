#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, i = 0, d = 222222, a, b;
    char c;
    cin>>n;
    while(n--){
        cin>>a>>b>>c;
        switch(c){
            case 'E':
            if((b - a) % 2 != 0){
                cout<<"*";
                return 0;
            }
            i = max((a + b) / 2, i);
            d = min((a + b) / 2, d);
            break;
            case 'A':
            if((b - a) % 2 == 0) d = min(d, (a + b) / 2 - 1);
            else d = min(d, (a + b) / 2);
            break;
            default:
            i = max(i, (a + b) / 2 + 1);
        }
    }
    if(i > d) cout<<"*";
    else cout<<i<<" "<<d<<"\n";
    return 0;
}