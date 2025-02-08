//Mal.
#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n;
        string s;
        cin>>n>>s;
        long long Norte = 0, Sur = 0, Este = 0, Oeste = 0;
        for(long long i = 0; i < n; i++){
            switch(s[i]){
                case 'N':
                Norte++;
                break;
                case 'S':
                Sur++;
                break;
                case 'E':
                Este++;
                break;
                case 'W':
                Oeste++;
            }
        }
        long long v = min(Norte, Sur), h = min(Este, Oeste);
        Norte -= v;
        Sur -= v;
        Este -= h;
        Oeste -= h;
        if(((Norte + Sur) % 2 == 1) or ((Este + Oeste) % 2 == 1)){
            cout<<"NO\n";
            continue;
        }
        long long Contador = 0;
        string r(n, '0');
        bool Usado = 0;
        for(long long i = 0; i < n; i++){
            if(Contador < v and s[i] == 'N'){
                if(Contador % 2 == 0) r[i] = 'R';
                else {
                    r[i] = 'H';
                    Usado = 1;
                }
                Contador++;
            }
        }
        Contador = 0;
        for(long long i = 0; i < n; i++){
            if(Contador < v and s[i] == 'S'){
                if(Contador % 2 == 0) r[i] = 'R';
                else {
                    r[i] = 'H';
                    Usado = 1;
                }
                Contador++;
            }
        }
        Contador = 0;
        if(Usado){
            for(long long i = 0; i < n; i++){
                if(Contador < h and s[i] == 'E'){
                    if(Contador % 2 == 0) r[i] = 'R';
                    else r[i] = 'H';
                    Contador++;
                }
            }
            Contador = 0;
            for(long long i = 0; i < n; i++){
                if(Contador < h and s[i] == 'W'){
                    if(Contador % 2 == 0) r[i] = 'R';
                    else r[i] = 'H';
                    Contador++;
                }
            }
        } else {
            for(long long i = 0; i < n; i++){
                if(Contador < h and s[i] == 'E'){
                    if(Contador % 2 == 1) r[i] = 'R';
                    else {
                        r[i] = 'H';
                        Usado = 1;
                    }
                    Contador++;
                }
            }
            Contador = 0;
            for(long long i = 0; i < n; i++){
                if(Contador < h and s[i] == 'W'){
                    if(Contador % 2 == 1) r[i] = 'R';
                    else {
                        r[i] = 'H';
                        Usado = 1;
                    }
                    Contador++;
                }
            }
        }
        Contador = 0;
        v = (Norte + Sur) / 2;
        h = (Este + Oeste) / 2;
        if(Usado){
            for(long long i = 0; i < n; i++){
                if(Contador < v and (s[i] == 'N' or s[i] == 'S') and r[i] == '0'){
                    Contador++;
                    r[i] = 'R';
                } else if((s[i] == 'N' or s[i] == 'S') and r[i] == '0'){
                    Contador++;
                    r[i] = 'H';
                }
            }
            Contador = 0;
            for(long long i = 0; i < n; i++){
                if(Contador < h and (s[i] == 'E' or s[i] == 'O') and r[i] == '0'){
                    Contador++;
                    r[i] = 'R';
                } else if((s[i] == 'E' or s[i] == 'O') and r[i] == '0'){
                    Contador++;
                    r[i] = 'H';
                }
            }
        } else {
            for(long long i = 0; i < n; i++){
                if(Contador < v and (s[i] == 'N' or s[i] == 'S') and r[i] == '0'){
                    Contador++;
                    r[i] = 'H';
                    Usado = 1;
                } else if((s[i] == 'N' or s[i] == 'S') and r[i] == '0'){
                    Contador++;
                    r[i] = 'R';
                }
            }
            Contador = 0;
            for(long long i = 0; i < n; i++){
                if(Contador < h and (s[i] == 'E' or s[i] == 'O') and r[i] == '0'){
                    Contador++;
                    r[i] = 'H';
                    Usado = 1;
                } else if((s[i] == 'E' or s[i] == 'O') and r[i] == '0'){
                    Contador++;
                    r[i] = 'R';
                }
            }
        }
        if(!Usado) cout<<"NO\n";
        else {
            Usado = 0;
            for(long long i = 0; i < n; i++){
                if(r[i] == 'R'){
                    Usado = 1;
                    break;
                }
            }
            if(Usado) cout<<r<<"\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}