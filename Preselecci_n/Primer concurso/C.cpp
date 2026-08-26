#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<long long> r = {2};
    unordered_set<long long> Cuadrados = {1, 4, 9};
    set<long long> h = {1};
    long long a = 2;
    for(long long c = 3; r.size() < 50; r.push_back(a)){
        h.insert(0);
        for(; 1; a++){
            if(2 * a >= c * c){
                c++;
                Cuadrados.insert(c * c);
            }
            bool Bien = 0;
            for(auto e: Cuadrados){
                if(h.count(e - a) == 1){
                    h.erase(e - a);
                    h.insert(a);
                    Bien = 1;
                    break;
                }
            }
            if(!Bien){
                if(h.count(0) == 1){
                    h.erase(0);
                    h.insert(a);
                } else break;
            }
        }
    }
    //for(auto e: r) cout<<e - 1<<" ";
    long long t, n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<r[n - 1] - 1<<"\n";
    }
    return 0;
}