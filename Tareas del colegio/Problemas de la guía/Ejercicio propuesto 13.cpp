#include "bits/stdc++.h"
using namespace std;
int main(){
    string n;
    bool a = 1;
    while(a){
        cout<<"Ingrese un número solo con dígitos impares.\n";
        cin>>n;
        a = 0;
        for(int i = 0; i < n.size(); i++){
            if(((int)n[i] - (int)'0') % 2 == 0) a = 1;
        }
    }
    for(int i = 0; i < n.size(); i++){
        if(i != (n.size() / 2)) cout<<n[i];
    }
    return 0;
}