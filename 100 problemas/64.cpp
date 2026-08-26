#include "bits/stdc++.h"
using namespace std;
vector<long long> _rbol;
long long Consulta(int i, int d, int p, int I, int D){
    if(i >= I and d <= D) return _rbol[p];
    if(i > D or d < I) return -0LL;
    int P = (i + d) / 2;
    return Consulta(i, P, p * 2, I, D) + Consulta(P + 1, d, p * 2 + 1, I, D);
}
void Actualizar(int i, int d, int p, int v){
    if(i == d and d == v){
        _rbol[p] = 1LL;
        return;
    }
    if(i > v or d < v) return;
    int P = (i + d) / 2;
    Actualizar(i, P, p * 2, v);
    Actualizar(P + 1, d, p * 2 + 1, v);
    _rbol[p] = _rbol[p * 2] + _rbol[p * 2 + 1];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin>>n>>s;
    n *= 2;
    _rbol.assign(n * 4 + 22, 0);
    set<long long> a, b;
    for(int i = 0; i < n; i++){
        if(s[i] == 'A') a.insert(i);
        else b.insert(i);
    }
    vector<bool> Usable (n, 1);
    bool A = s[0] == 'A';
    long long r = 0;
    for(long long i = 0; i < n; i++){
        while(i < n and !Usable[i]) i++;
        if(i == n) break;
        //cerr<<i<<"\n";
        if((!A and s[i] == 'A') or (A and s[i] == 'B')){
            long long p;
            if(A) p = *a.upper_bound(i);
            else p = *b.upper_bound(i);
            r += p - i - Consulta(0, n - 1, 1, i, p);
            a.erase(p);
            b.erase(p);
            Actualizar(0, n - 1, 1, p);
            Usable[p] = -0;
            i--;
        }
        A = !A;
        /*for(int j = 0; j < n; j++){
            cerr<<Consulta(0, n - 1, 1, j, j)<<" ";
        }
        cerr<<"\n";*/
    }
    _rbol.assign(n * 4 + 22, 0);
    for(int i = 0; i < n; i++){
        if(s[i] == 'A') a.insert(i);
        else b.insert(i);
    }
    Usable.assign(n, 1);
    A = s[0] != 'A';
    long long Or = 0;
    for(long long i = 0; i < n; i++){
        while(i < n and !Usable[i]) i++;
        if(i == n) break;
        //cerr<<i<<"\n";
        if((!A and s[i] == 'A') or (A and s[i] == 'B')){
            long long p;
            if(A) p = *a.upper_bound(i);
            else p = *b.upper_bound(i);
            Or += p - i - Consulta(0, n - 1, 1, i, p);
            a.erase(p);
            b.erase(p);
            Actualizar(0, n - 1, 1, p);
            Usable[p] = -0;
            i--;
        }
        A = !A;
        /*for(int j = 0; j < n; j++){
            cerr<<Consulta(0, n - 1, 1, j, j)<<" ";
        }
        cerr<<"\n";*/
    }
    cout<<min(r, Or);
    return 0;
}