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
        bool Usado = 0;
        string r(n, '0');
        long long Contador = 0;
        for(long long i = 0; i < n; i++){
            long long Resta = 0;
            if(Norte % 2 == 1) Resta = 1;
            if(Contador < Norte - Resta and s[i] == 'N'){
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
                long long Resta = 0;
                if(Sur % 2 == 1) Resta = 1;
                if(Contador < Sur - Resta and s[i] == 'S'){
                    if(Contador % 2 == 0) r[i] = 'R';
                    else {
                        r[i] = 'H';
                        Usado = 1;
                    }
                    Contador++;
                }
            }
        } else {
            for(long long i = 0; i < n; i++){
                long long Resta = 0;
                if(Sur % 2 == 1) Resta = 1;
                if(Contador < Sur - Resta and s[i] == 'S'){
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
        if(Usado){
            for(long long i = 0; i < n; i++){
                long long Resta = 0;
                if(Este % 2 == 1) Resta = 1;
                if(Contador < Este - Resta and s[i] == 'E'){
                    if(Contador % 2 == 0) r[i] = 'R';
                    else {
                        r[i] = 'H';
                        Usado = 1;
                    }
                    Contador++;
                }
            }
        } else {
            for(long long i = 0; i < n; i++){
                long long Resta = 0;
                if(Este % 2 == 1) Resta = 1;
                if(Contador < Este - Resta and s[i] == 'E'){
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
        if(Usado){
            for(long long i = 0; i < n; i++){
                long long Resta = 0;
                if(Oeste % 2 == 1) Resta = 1;
                if(Contador < Oeste - Resta and s[i] == 'W'){
                    if(Contador % 2 == 0) r[i] = 'R';
                    else {
                        r[i] = 'H';
                        Usado = 1;
                    }
                    Contador++;
                }
            }
        } else {
            for(long long i = 0; i < n; i++){
                long long Resta = 0;
                if(Oeste % 2 == 1) Resta = 1;
                if(Contador < Oeste - Resta and s[i] == 'W'){
                    if(Contador % 2 == 1) r[i] = 'R';
                    else {
                        r[i] = 'H';
                        Usado = 1;
                    }
                    Contador++;
                }
            }
        }
        Norte %= 2;
        Sur %= 2;
        Este %= 2;
        Oeste %= 2;
        if(Norte != Sur or Este != Oeste){
            cout<<"NO\n";
            continue;
        }
        if(Usado){
            for(long long i = 0; i < n and (Norte + Sur) > 0; i++){
                if(r[i] == '0'){
                    if(Norte > 0 and s[i] == 'N'){
                        r[i] = 'R';
                        Norte--;
                    }
                    if(Sur > 0 and s[i] == 'S'){
                        r[i] = 'R';
                        Sur--;
                    }
                }
            }
        } else {
            for(long long i = 0; i < n and (Norte + Sur) > 0; i++){
                if(r[i] == '0'){
                    if(Norte > 0 and s[i] == 'N'){
                        r[i] = 'H';
                        Usado = 1;
                        Norte--;
                    }
                    if(Sur > 0 and s[i] == 'S'){
                        r[i] = 'H';
                        Usado = 1;
                        Sur--;
                    }
                }
            }
        }
        if(Usado){
            for(long long i = 0; i < n and (Este + Oeste) > 0; i++){
                if(r[i] == '0'){
                    if(Oeste > 0 and s[i] == 'W'){
                        r[i] = 'R';
                        Oeste--;
                    }
                    if(Este > 0 and s[i] == 'E'){
                        r[i] = 'R';
                        Este--;
                    }
                }
            }
        } else {
            for(long long i = 0; i < n and (Este + Oeste) > 0; i++){
                if(r[i] == '0'){
                    if(Oeste > 0 and s[i] == 'W'){
                        r[i] = 'H';
                        Usado = 1;
                        Oeste--;
                    }
                    if(Este > 0 and s[i] == 'E'){
                        r[i] = 'H';
                        Usado = 1;
                        Este--;
                    }
                }
            }
        }
        if(Usado){
            long long vr = 0, hr = 0, vh = 0, hh = 0;
            bool R = 0, H = 0;
            for(long long i = 0; i < n; i++){
                if(r[i] == '0'){
                    vr = vh + 1;
                    break;
                }
                if(r[i] == 'R'){
                    R = 1;
                    switch(s[i]){
                        case 'N':
                        vr++;
                        break;
                        case 'S':
                        vr--;
                        break;
                        case 'E':
                        hr++;
                        break;
                        case 'W':
                        hr--;
                    }
                } else {
                    H = 1;
                    switch(s[i]){
                        case 'N':
                        vh++;
                        break;
                        case 'S':
                        vh--;
                        break;
                        case 'E':
                        hh++;
                        break;
                        case 'W':
                        hh--;
                    }
                }
            }
            if(vr == vh and hr == hh and R and H) cout<<r<<"\n";
            else cout<<"NO\n";
        } else cout<<"NO\n";
    }
    return 0;
}