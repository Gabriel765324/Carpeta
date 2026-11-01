#include "bits/stdc++.h"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define mp make_pair
#define pb push_back
#define all(v) (v).begin(), (v).end()
using namespace std;
struct Ordenador{
    int Valor0, Valor1, i;
    Ordenador(){}
    Ordenador(int V0, int V1, int I){
        Valor0 = V0;
        Valor1 = V1;
        i = I;
    }
    bool operator<(const Ordenador& o){
        return mp(mp(Valor0, Valor1), i) < mp(mp(o.Valor0, o.Valor1), o.i);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    long long k;
    cin>>s>>k;
    int n = int(s.size());
    vector<Ordenador> Ordenable(n);
    vector<int> Asignaciones(2 * n + 22, 0);
    while(int(s.size()) < (n<<1) + 22) s.pb('`');
    vector< vector<Ordenador> > Baldes(n + 4);
    forn(i, n){
        Ordenable[i] = Ordenador(0, int(s[i]) - int('`'), i);
        Asignaciones[i] = int(s[i]) - int('`');
    }
    sort(all(Ordenable));
    for(int p = 1; p <= n; p <<= 1){
        int Anterior = Ordenable[0].Valor0;
        Ordenable[0].Valor0 = Asignaciones[Ordenable[0].i] = 1;
        forsn(i, 1, n){
            int Actual = Ordenable[i].Valor0;
            if(mp(Ordenable[i].Valor0, Ordenable[i].Valor1) == mp(Anterior, Ordenable[i - 1].Valor1)) Ordenable[i].Valor0 = Asignaciones[Ordenable[i].i] = Ordenable[i - 1].Valor0;
            else Ordenable[i].Valor0 = Asignaciones[Ordenable[i].i] = Ordenable[i - 1].Valor0 + 1;
            Anterior = Actual;
        }
        forn(i, n){
            Ordenable[i].Valor1 = Asignaciones[Ordenable[i].i + p];
            Baldes[Ordenable[i].Valor1].push_back(Ordenable[i]);
        }
        int i = 0;
        for(auto& E: Baldes){
            for(auto e: E){
                Ordenable[i] = e;
                i++;
            }
            E.clear();
        }
        forn(I, n) Baldes[Ordenable[I].Valor0].push_back(Ordenable[I]);
        i = 0;
        for(auto& E: Baldes){
            for(auto e: E){
                Ordenable[i] = e;
                i++;
            }
            E.clear();
        }
    }
    //forn(i, n) cout<<Ordenable[i].i<<" "<<s.substr(Ordenable[i].i, n - Ordenable[i].i)<<"\n";
    vector<long long> Suma(n);
    forn(i, n){
        Suma[i] = (long long)(n - Ordenable[i].i);
        if(i > 0) Suma[i] += Suma[i - 1];
    }
    int I = 0, D = n - 1;
    long long Resta = 0;
    string r = "";
    while(1){
        int Anterior = I - 1;
        forn(c, 26){
            int i = I, d = D, m = Anterior;
            while(i < d + 1){
                int p = (i + d)>>1;
                if(s[Ordenable[p].i + int(Resta)] <= char(c + 'a')){
                    m = p;
                    i = p + 1;
                } else d = p - 1;
            }
            if(m < I) continue;
            long long Repeticiones = Suma[m];
            if(Anterior > -1) Repeticiones -= Suma[Anterior];
            Repeticiones -= Resta * (long long)(m - Anterior);
            //cerr<<char(c + 'a')<<" "<<Repeticiones<<" "<<Resta<<" "<<I<<" "<<D<<"\n";
            if(Repeticiones < k){
                k -= Repeticiones;
                Anterior = m;
                I = Anterior + 1;
                continue;
            }
            r += char(c + 'a');
            if((long long)(m - Anterior) >= k){
                cout<<r<<"\n";
                return 0;
            }
            Resta++;
            D = m;
            k -= (long long)(m - Anterior);
            break;
        }
    }
    return 0;
}