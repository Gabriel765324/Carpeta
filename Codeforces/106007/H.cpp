#include "bits/stdc++.h"
using namespace std;
void Resolver(){
    int n;
    cin>>n;
    vector<int> a(n);
    bool Volver = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    if(n == 1){
        cout<<a[0]<<"\n";
        return;
    }
    cout<<a[0]<<" ";
    for(int i = 1; i < n - 1; ){
        if(i + 1 == n - 1){
            cout<<a[i]<<" ";
            break;
        }
        if(a[i] <= a[i + 1]){
            cout<<a[i]<<" ";
            i++;
        } else {
            cout<<a[i + 1]<<" "<<a[i]<<" ";
            i += 2;
            if(i < n - 1){
                cout<<a[i]<<" ";
                i++;
            }
        }
    }
    cout<<a.back()<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) Resolver();
    return 0;
}