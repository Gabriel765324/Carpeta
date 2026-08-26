#include <bits/stdc++.h>
using namespace std;
void Transformar(vector< complex<double> >& a, bool Inverso){
    int n = int(a.size());
    if(n == 1) return;
    vector< complex<double> > a0, a1;
    for(int i = 0; i * 2 < n; i++){
        a0.push_back(a[2 * i]);
        a1.push_back(a[2 * i + 1]);
    }
    Transformar(a0, Inverso);
    Transformar(a1, Inverso);
    double _ngulo = 2 * acos(-1) / n;
    if(Inverso) _ngulo /= -1;
    complex<double> w(1), wn(cos(_ngulo), sin(_ngulo));
    for(int i = 0; i * 2 < n; i++){
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if(Inverso){
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector< complex<double> > a(n), b(m);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];
    int t = 1;
    while(t < n + m) t *= 2;
    while(int(a.size()) < t) a.push_back(0);
    while(int(b.size()) < t) b.push_back(0);
    Transformar(a, 0);
    Transformar(b, 0);
    n = t;
    for(int i = 0; i < n; i++) a[i] *= b[i];
    Transformar(a, 1);
    for(int i = 0; i < n; i++) cout<<round(a[i].real())<<" ";
    return 0;
}