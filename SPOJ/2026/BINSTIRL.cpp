#include "bits/stdc++.h"
using namespace std;
//89 18
void Resolver(){
    long long n, m, p = 2, k = 0;
    cin>>n>>m;
    if(n == m or m == 1){
        cout<<"1\n";
        return;
    }
    if(n == 0LL or m == 0LL or n < m){
        cout<<"0\n";
        return;
    }
    n -= m;
    while(1){
        if(p >= (long long)3e9) break;
        p *= 2LL;
        k++;
    }
    while(1){
        long long s = p / 2LL;
        //cerr<<p<<" "<<s<<" "<<k<<" "<<n<<" "<<m<<"\n";
        if(k == 0LL){
            cout<<"1\n";
            return;
        }
        if(n < s / 2LL and m <= s){
            if(m > s - n * 2LL){
                cout<<"0\n";
                return;
            }
        }
        if(n >= s / 2LL){
            n -= s / 2LL;
        } else if(m > s){
            m -= s;
        }
        p = s;
        k--;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        Resolver();
    }
    return 0;
}