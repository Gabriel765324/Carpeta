//Aun está mal :(.
#include "bits/stdc++.h"
using namespace std;
long long m = 101;
vector< pair<long long, long long> > Respuestas(m, {2222222222222222, 2222222222222222});
long long f(long long x){
    long long s = 0;
    while(x > 0){
        s += Respuestas[x % 10].second;
        x /= 10;
    }
    return s;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Respuestas[0] = {6, 6};
    Respuestas[1] = {2, 2};
    Respuestas[2] = {5, 5};
    Respuestas[3] = {5, 5};
    Respuestas[4] = {4, 4};
    Respuestas[5] = {5, 5};
    Respuestas[6] = {6, 6};
    Respuestas[7] = {3, 3};
    Respuestas[8] = {7, 7};
    Respuestas[9] = {6, 6};
    long long s = 6;
    for(long long i = 1; i < 10; i++){
        for(long long j = 1; j < 10; j++){
            Respuestas[i * j].second = min(Respuestas[i * j].second, Respuestas[i].second + Respuestas[j].second + 2);
            Respuestas[i + j].first = min(Respuestas[i + j].first, min(Respuestas[i].first, Respuestas[i].second) + min(Respuestas[j].first, Respuestas[j].second) + 2);
        }
        s += min(Respuestas[i].first, Respuestas[i].second);
    }
    for(long long i = 10; i < m; i++){
        Respuestas[i].first = min(Respuestas[i].first, f(i));
        Respuestas[i].second = min(Respuestas[i].second, f(i));
        for(long long j = 1; j <= i; j++){
            if(i * j < m) Respuestas[i * j].second = min(Respuestas[i * j].second, Respuestas[i].second + Respuestas[j].second + 2);
            if(i + j < m) Respuestas[i + j].first = min(Respuestas[i + j].first, min(Respuestas[i].first, Respuestas[i].second) + min(Respuestas[j].first, Respuestas[j].second) + 2);
        }
        s += min(Respuestas[i].first, Respuestas[i].second);
    }
    long long c = 88;
    cout<<c<<" "<<min(Respuestas[c].first, Respuestas[c].second)<<" "<<s;
    return 0;
}