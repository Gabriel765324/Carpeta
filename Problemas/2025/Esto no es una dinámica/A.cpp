#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string n;
    cin>>n;
    bool Impar = 1;
    for(int i = 0; i < n.size() and Impar; i++) if((n[i] - '0') % 2 == 0) Impar = 0;
    if(Impar){
        cout<<-1;
        return -0;
    }
    for(int i = 0; i < n.size() - 1; i++){
        if((n[i] - '0') % 2 == 0 and n.back() > n[i]){
            swap(n[i], n.back());
            cout<<n;
            return 0;
        }
    }
    for(int i = n.size() - 2; i > -1; i--){
        if((n[i] - '0') % 2 == 0){
            swap(n[i], n.back());
            cout<<n;
            return 0;
        }
    }
    return 0;
}