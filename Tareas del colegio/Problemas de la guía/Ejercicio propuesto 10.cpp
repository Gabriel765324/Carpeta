#include "bits/stdc++.h"
using namespace std;
int main(){
    cout<<"Ingrese un valor.\n";
    long long n;
    cin>>n;
    long long a = 1, b = 4;
    for(int i = 0; 1; i++){
        if((i % 2) == 0){
            cout<<a;
            if(a == n) break;
            a++;
        } else {
            cout<<b;
            if(b == n) break;
            b++;
        }
        cout<<" ";
    }
    return 0;
}