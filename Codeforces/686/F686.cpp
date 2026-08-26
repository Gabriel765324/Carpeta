#include "bits/stdc++.h"
using namespace std;
vector<long long> A, _rbol;
void Crear(long long i, long long d, long long p){
    if(i == d){
        _rbol[p] = A[i];
    } else {
        long long P = (i + d) / 2;
        Crear(i, P, p * 2);
        Crear(P + 1, d, p * 2 + 1);
        _rbol[p] = min(_rbol[p * 2], _rbol[p * 2 + 1]);
    }
}
long long Consulta(long long i, long long d, long long p, long long I, long long D){
    if(i >= I and d <= D) return _rbol[p];
    if(i > D or d < I) return 2222222222222222;
    long long P = (i + d) / 2;
    return min(Consulta(i, P, p * 2, I, D), Consulta(P + 1, d, p * 2 + 1, I, D));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> a(n), Mi(n, -2), Md(n, -2);
        long long m = 0, Inicio = 0;
        for(long long i = 0; i < n; i++){
            cin>>a[i];
            m = max(a[i], m);
            Mi[i] = max(Mi[i], a[i]);
            if(i > 0) Mi[i] = max(Mi[i], Mi[i - 1]);
        }
        deque<long long> p;
        for(long long i = n - 1; i > -1; i--){
            if(a[i] == m) p.push_front(i);
            Md[i] = max(Md[i], a[i]);
            if(i < (n - 1)) Md[i] = max(Md[i], Md[i + 1]);
        }
        Inicio = p[p.size() / 2];
        long long i = Inicio - 1, d = Inicio + 1;
        bool Joya = 0;
        n--;
        A = a;
        _rbol.assign(n * 4, 0);
        Crear(0, n, 1);
        n++;
        while(1){
            //cout<<i<<" "<<d<<"\n";
            if(d >= n or i < 0) break;
            long long v = Consulta(0, n - 1, 1, i + 1, d - 1);
            //cout<<Mi[i]<<" "<<u<<" "<<Md[d]<<"\n";
            //cout<<i<<" "<<u<<" "<<d<<"\n";
            if(v == Mi[i] and Md[d] == Mi[i]){
                cout<<"YES\n"<<i + 1<<" "<<d - i - 1<<" "<<n - d<<"\n";
                Joya = 1;
                break;
            }
            long long u, w;
            if(i <= 0) u = -22222222;
            else u = min(Mi[i - 1], a[i]);
            if(d >= n - 1) w = -22222222;
            else w = min(Md[d + 1], a[d]);
            if(u > w){
                i--;
            } else {
                d++;
            }
        }
        if(!Joya) cout<<"NO\n";
        /*A = a;
        bool Joya = 0;
        for(long long i = n - 1; i > -1; i--){
            Md[i] = max(Md[i], a[i]);
            if(i < (n - 1)) Md[i] = max(Md[i], Md[i + 1]);
        }
        n--;
        _rbol.assign(n * 4, 0);
        Crear(0, n, 1);
        long long y = n, m = -2;
        for(long long x = 0; x <= n - 2; x++){
            m = max(m, a[x]);
            while((y - 1) >= x and a[y] <= m) y--;
            if((y - 1) < x) y = x + 1;
            cout<<y<<"#\n";
            if(y < n and Consulta(0, n, 1, x + 1, y) == Md[y + 1] and Md[y + 1] == Mi[x]){
                Joya = 1;
                //cout<<y - 1<<"--\n";
                cout<<"YES\n"<<x + 1<<" "<<y - x<<" "<<n - y<<"\n";
                break;
            } else if(y < n and (x - 1) > -1){
                x--;
                //cout<<y - 1<<"--\n";
                if(Consulta(0, n, 1, x + 1, y) == Md[y + 1] and Md[y + 1] == Mi[x]){
                    Joya = 1;
                    cout<<"YES\n"<<x + 1<<" "<<y - x<<" "<<n - y<<"\n";
                    break;
                }
                x++;
            } else if((y + 1) < n){
                y++;
                if(Consulta(0, n, 1, x + 1, y) == Md[y + 1] and Md[y + 1] == Mi[x]){
                    Joya = 1;
                    cout<<"YES\n"<<x + 1<<" "<<y - x<<" "<<n - y<<"\n";
                    break;
                }
                y--;
            } else if(y < n and (x - 2) > -1){
                x -= 2;
                //cout<<y - 1<<"--\n";
                if(Consulta(0, n, 1, x + 1, y) == Md[y + 1] and Md[y + 1] == Mi[x]){
                    Joya = 1;
                    cout<<"YES\n"<<x + 1<<" "<<y - x<<" "<<n - y<<"\n";
                    break;
                }
                x += 2;
            } else if((y + 2) < n){
                y += 2;
                if(Consulta(0, n, 1, x + 1, y) == Md[y + 1] and Md[y + 1] == Mi[x]){
                    Joya = 1;
                    cout<<"YES\n"<<x + 1<<" "<<y - x<<" "<<n - y<<"\n";
                    break;
                }
                y -= 2;
            }
        }
        if(!Joya) cout<<"NO\n";*/
    }
    return 0;
}