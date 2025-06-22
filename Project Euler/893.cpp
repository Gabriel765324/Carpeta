#include "bits/stdc++.h"
using namespace std;
long long m = 1000001;
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
    long long s = 0;
    for(long long i = 1; i < 10; i++){
        for(long long j = 1; j < 10; j++){
            Respuestas[i + j].first = min(Respuestas[i + j].first, Respuestas[i].first + Respuestas[j].first + 2);
            //Respuestas[i * j].first = min(Respuestas[i * j].first, Respuestas[i].first + Respuestas[j].first + 2);
            Respuestas[i * j].second = min(Respuestas[i * j].second, Respuestas[i].second + Respuestas[j].second + 2);
            //Respuestas[i + j].first = min(Respuestas[i + j].first, min(Respuestas[i].first, Respuestas[i].second) + min(Respuestas[j].first, Respuestas[j].second) + 2);
        }
        s += min(Respuestas[i].first, Respuestas[i].second);
    }
    for(long long i = 10; i < m; i++){
        Respuestas[i].first = min(Respuestas[i].first, f(i));
        Respuestas[i].second = min(Respuestas[i].second, f(i));
        if(i % 10000 == 0) cerr<<i<<"\n";
        //if(i % 10000 == 0) cerr<<i<<"\n";
        for(long long j = 1; j <= i; j++){
            /*if(i + j < m) Respuestas[i + j].first = min(Respuestas[i + j].first, Respuestas[i].first + Respuestas[j].first + 2);
            else break;
            if(i * j < m){
                Respuestas[i * j].first = min(Respuestas[i * j].first, Respuestas[i].first + Respuestas[j].first + 2);
            }*/
            if(i + j < m) Respuestas[i + j].first = min(Respuestas[i + j].first, min(Respuestas[i].first, Respuestas[i].second) + min(Respuestas[j].first, Respuestas[j].second) + 2);
            else break;
            if(i * j < m) Respuestas[i * j].second = min(Respuestas[i * j].second, Respuestas[i].second + Respuestas[j].second + 2);
            
        }
        s += min(Respuestas[i].first, Respuestas[i].second);
    }
    cout<<s/*<<"\n"*/;
    /*vector< pair<long long, long long> > Mejores = Respuestas;
    for(long long i = 0; i < m; i++){
        for(long long j = i + 1; j < m; j++){
            for(long long k = j + 1; k < m; k++){
                if(i + j + k < m) Mejores[i + j + k].first = min(min(Respuestas[i].first, Respuestas[i].second) + min(Respuestas[j].first, Respuestas[j].second) + min(Respuestas[k].first, Respuestas[k].second) + 4, Mejores[i + j + k].first);
                else break;
                if(i * j * k < m) Mejores[i * j * k].second = min(Respuestas[i].second + Respuestas[j].second + Respuestas[k].second + 4, Mejores[i * j * k].first);
            }
        }
    }*/
    /*for(long long c = 1; c < m; c++){
        cout<<c<<" "<<min(Respuestas[c].first, Respuestas[c].second)<<" "<<s<<" "<<min(Mejores[c].first, Mejores[c].second)<<((min(Respuestas[c].first, Respuestas[c].second) != min(Mejores[c].first, Mejores[c].second)) ? " Aquí." : "")<<"\n";
    }*/
    return 0;
} //La respuesta es 26688208.