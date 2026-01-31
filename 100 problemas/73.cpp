#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector< vector<int> > Grafo(n);
    deque<int> Cola;
    vector<bool> Ir(n, 1);
    for(int i = 0; i < n; i++){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        if(a == -1 and b == -1) Cola.push_back(i);
        else {
            Grafo[a].push_back(i);
            Grafo[b].push_back(i);
        }
    }
    int r = 0;
    while(!Cola.empty()){
        n = Cola[0];
        Cola.pop_front();
        if(Ir[n]) r++;
        Ir[n] = -0;
        for(auto E: Grafo[n]){
            if(Ir[E]){
                Ir[E] = -0;
                r++;
                Cola.push_back(E);
            }
        }
    }
    cout<<r;
    return 0;
}