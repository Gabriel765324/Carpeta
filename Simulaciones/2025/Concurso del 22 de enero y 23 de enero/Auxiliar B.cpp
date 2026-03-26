#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    map< vector<long long>, vector<long long> > Decodificador;
    set< vector<long long> > Tenemos;
    for(long long n = 1; n <= 5; n++){
        vector<long long> a;
        deque<long long> c(n);
        for(long long i = 0; i < n; i++) a.push_back(i);
        do{
            for(long long i = 0; i < n; i++) c[i] = i;
            long long i = 0;
            for(auto E: a) cout<<E<<" ";
            cout<<"   ";
            vector<long long> C_digo;
            do{
                long long Contador = 0;
                for(long long j = 0; j < n - 1; j++){
                    if(a[c[j]] > a[c[j + 1]]) Contador++;
                }
                cout<<Contador<<" ";
                C_digo.push_back(Contador);
                c.push_front(c.back());
                c.pop_back();
                i++;
            } while(i < n);
            cout<<"\n";
            Decodificador[C_digo] = a;
            //if(Tenemos.find(C_digo) != Tenemos.end()) cout<<"La conjetura falla.";
            Tenemos.insert(C_digo);
        } while(next_permutation(a.begin(), a.end()));
        cout<<"\n";
    }
    /*for(auto E: Tenemos){
        for(auto e: E) cout<<e<<" ";
        cout<<"   ";
        for(auto e: Decodificador[E]) cout<<e<<" ";
        cout<<"\n";
    }*/
    return 0;
}