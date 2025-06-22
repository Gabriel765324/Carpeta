#include "bits/stdc++.h"
using namespace std;
vector< vector<string> > Tri_ngulo;
void nCk(long long n, long long k){
    //cout<<n<<" "<<k<<"\n";
    if(n < 0 or k < 0 or k > n) cout<<"0\n";
    else cout<<Tri_ngulo[n][k]<<"\n";
}
string Suma(string &aa, string &bb){
    if(aa.size() < bb.size()) swap(aa, bb);
    //cout<<aa<<" + "<<bb<<" = ";
    deque<long long> a, b;
    for(long long i = 0; i < aa.size(); i++) a.push_back(aa[i] - '0');
    for(long long i = 0; i < bb.size(); i++) b.push_back(bb[i] - '0');
    long long n = a.size();
    while(b.size() < n) b.push_front(0);
    deque<long long> c(n, 0);
    long long _1, _2, _3 = 0;
    for(long long i = n - 1; i > -1; i--){
        _1 = a[i];
        _2 = b[i];
        c[i] = (_1 + _2 + _3) % 10;
        if(_1 + _2 + _3 >= 10) _3 = 1;
        else _3 = 0;
    }
    if(_3 == 1) c.push_front(_3);
    string r;
    for(auto E: c) r += (char)(E + '0');
    //cout<<r<<"";
    return r;
}
void Tri_ngulo_de_Pascal(){
    Tri_ngulo.push_back({"1"});
    //cout<<"1";
    for(long long i = 1; i < 444; i++){
        Tri_ngulo.push_back({});
        for(long long j = 0; j <= i; j++){
            //cout<<i<<" "<<j<<"";
            string I, D;
            if(j == 0) I = "0";
            else I = Tri_ngulo[i - 1][j - 1];
            if(j == i) D = "0";
            else D = Tri_ngulo[i - 1][j];
            //cout<<I<<" "<<D<<"";
            Tri_ngulo[i].push_back(Suma(I, D));
            //cout<<Suma(I, D)<<" ";
        }
        //cout<<"";
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    Tri_ngulo_de_Pascal();
    while(t--){
        long long n, k;
        cin>>n>>k;
        vector<long long> a(k, 0);
        long long s = 0;
        for(long long i = 0; i < k; i++){
            cin>>a[i];
            s += a[i] + 1;
        }
        if(k > 0) s--;
        n -= s;
        nCk(n + k, n);
        //cout<<n + k - 1<<" "<<n<<"";
    }
    return 0;
}