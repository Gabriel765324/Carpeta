#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    vector< vector<long long> > Grafo(n, vector<long long>());
    vector<long long> d(n, 1), a(n);
    for(long long i = 0; i < n; i++){
        cin>>a[i];
        if(a[i] != -1){
            a[i]--;
            Grafo[a[i]].push_back(i);
        }
    }
    long long r = 1;
    for(long long i = 0; i < n; i++){
        if(a[i] == -1){
            deque<long long> Cola(1, i);
            while(!Cola.empty()){
                long long Nodo = Cola[0];
                Cola.pop_front();
                for(auto E: Grafo[Nodo]){
                    if(d[E] == 1){
                        d[E] = d[Nodo] + 1;
                        Cola.push_back(E);
                        r = max(r, d[E]);
                    }
                }
            }
        }
    }
    cout<<r;
    return 0;
}