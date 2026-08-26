#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int n = s.size(), c = 0;
    map<int, int> Pares, iPares;
    vector<int> Pendiente;
    vector<int> Cambiar(n, 0);
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            Pendiente.push_back(i);
            c++;
            Cambiar[i] = 1;
        } else if(s[i] == ')'){
            Pares[Pendiente.back()] = i;
            iPares[i] = Pendiente.back();
            c--;
            Pendiente.pop_back();
            Cambiar[i] = 2;
        } else if(c % 2 == 1){
            if(s[i] <= 'Z') s[i] += 'a' - 'A';
            else s[i] -= 'a' - 'A';
        }
    }
    int Seguir = 1;
    for(int i = 0; i < n; i += Seguir){
        if(Cambiar[i] == 1){
            Cambiar[i] = -1;
            Seguir = -Seguir;
            i = Pares[i];
        } else if(Cambiar[i] == 2){
            Cambiar[i] = -2;
            Seguir = -Seguir;
            i = iPares[i];
        } else if(Cambiar[i] == -1){
            Cambiar[i] = 0;
            i = Pares[i];
            Seguir = -Seguir;
        } else if(Cambiar[i] == -2){
            Cambiar[i] = 0;
            i = iPares[i];
            Seguir = -Seguir;
        } else if(s[i] != '(' and s[i] != ')') cout<<s[i];
    }
    return 0;
}