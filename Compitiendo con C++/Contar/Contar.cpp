#include "bits/stdc++.h"
using namespace std;
int main(){
    int n, k;
    cin>>n>>k;
    int c = 0;
    while(n--){
        int a;
        cin>>a;
        if(a == k) c++;
    }
    cout<<c<<"\n";
    return 0;
}