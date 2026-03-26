#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a;
    cin>>n>>a;
    n--;
    int i = 2;
    while(n--){
        int b;
        cin>>b;
        if(b > a){
            cout<<i;
            return 0;
        }
        i++;
    }
    cout<<-1;
    return 0;
}