#include "bits/stdc++.h"
using namespace std;
int main(){
    long long n, c = 1, i = 0;
    while(cin>>n) if(n % 2 == 1) break;
    vector< vector<long long> > a(n, vector<long long>(n, -2LL));
    long long j = n / 2;
    while(c <= (n * n)){
        a[i][j] = c;
        c++;
        long long ni = i - 1LL;
        long long nj = j + 1LL;
        if(ni == -1LL) ni = n - 1LL;
        if(nj == n) nj = 0LL;
        if(a[ni][nj] != -2LL){
            i++;
            if(i == n) i = 0LL;
        } else {
            i = ni;
            j = nj;
        }
    }
    long long Mayor = log10(n * n) + 1;
    for(auto E: a){
        for(auto e: E){
            cout<<e;
            for(long long i = log10(e) + 1; i <= Mayor; i++) cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}