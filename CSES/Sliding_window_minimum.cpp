#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    long long a, b, c, x;
    cin>>n>>k>>x>>a>>b>>c;
    priority_queue< pair<int, int> , vector< pair<int, int> >, greater< pair<int, int> > > Cola;
    int Respuesta = 0;
    for(int i = 0; i < n; i++){
        Cola.push({x, i});
        x = (a * x + b) % c;
        if(i >= k - 1){
            while(Cola.top().second <= i - k) Cola.pop();
            Respuesta ^= Cola.top().first;
        }
    }
    cout<<Respuesta;
    return 0;
}