#include <bits/stdc++.h>
#define FastIO cin.tie(NULL); ios_base::sync_with_stdio(false);
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i< int(n); i++)
#define all(v) (v).begin(), (v).end()
#define ll long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define el "\n"
using namespace std;
struct Arista{
    int i, p;
    long long d;
};
bool operator<(const Arista& a, const Arista& b){
    return a.p < b.p;
}
int main(){
    FastIO;
    int n, m;
    cin>>n>>m;
    deque<Arista> a(m);
    deque<long long> Mejores(n - 1, -2);
    int Contador = 0;
    for(int i = 0; i < m; i++){
        cin>>a[i].i>>a[i].d>>a[i].p;
        a[i].i--;
    }
    sort(a.begin(), a.end());
    long long r = 0;
    int q;
    cin>>q;
    vector< pair<int, int> > Consulta(q);
    vector<long long> Respuestas(q);
    for(int i = 0; i < q; i++){
        cin>>Consulta[i].first;
        Consulta[i].second = i;
    }
    sort(Consulta.rbegin(), Consulta.rend());
    for(auto E: Consulta){
        while(!a.empty()){
            if(a.back().p >= E.first){
                if(Mejores[a.back().i] == -2){
                    Mejores[a.back().i] = a.back().d;
                    Contador++;
                    r += a.back().d;
                } else {
                    if(Mejores[a.back().i] > a.back().d){
                        r -= Mejores[a.back().i] - a.back().d;
                        Mejores[a.back().i] = a.back().d;
                    }
                }
                a.pop_back();
            } else break;
        }
        if(Contador >= n - 1) Respuestas[E.second] = r;
        else Respuestas[E.second] = -2;
    }
    for(auto E: Respuestas){
        if(E == -2) cout<<"impossible";
        else cout<<E;
        cout<<el;
    }
    return 0;
}