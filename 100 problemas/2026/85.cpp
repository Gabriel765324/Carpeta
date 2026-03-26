#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    __int128 n = N;
    vector<__int128> a;
    for(int i = 0; i < N; i++){
        //cerr<<i<<" ";
        long long b;
        cin>>b;
        a.push_back(b);
    }
    sort(a.rbegin(), a.rend());
    __int128 r = 0;
    for(__int128 i = 0; i < n; i++){
        //cerr<<(int)i<<" ";
        r += a[i] * (n - (__int128)1);
    }
    for(__int128 i = 0; i < n; i++){
        __int128 I = i + 1, D = n - (__int128)1, m = i;
        //cerr<<(int)i<<" ";
        while(1){
            if(I >= D + (__int128)1) break;
            __int128 p = (I + D) /  (__int128)2;
            if(a[p] + a[i] >= (__int128)1e8){
                m = p;
                I = p + 1;
            } else {
                D = p - 1;
            }
            if(I >= D + (__int128)1) break;
        }
        r -= (__int128)1e8 * (m - i);
    }
    cout<<(unsigned long long)r;
    return 0;
}