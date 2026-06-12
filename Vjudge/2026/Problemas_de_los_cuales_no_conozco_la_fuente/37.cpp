#include "bits/stdc++.h"
#define ll long long
#define ii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define el "\n"
using namespace std;
struct Misi_n{
    int l, m, w;
    Misi_n(){
        l = 0;
        m = 0;
        w = 0;
    }
};
struct Par{
    int s_0_s_1, s_1_s_2, s;
    string Ignorados;
    Par(int a, int b, int v, string ss){
        s_0_s_1 = a;
        s_1_s_2 = b;
        s = v;
        Ignorados = ss;
    }
    bool operator<(const Par& a){
        if(s_0_s_1 < a.s_0_s_1) return 1;
        if(s_0_s_1 > a.s_0_s_1) return 0;
        if(s_1_s_2 < a.s_1_s_2) return 1;
        if(s_1_s_2 > a.s_1_s_2) return 0;
        if(s < a.s) return 1;
        if(s > a.s) return 0;
        return Ignorados < a.Ignorados;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<Misi_n> a(n);
    forn(i, n){
        cin>>a[i].l>>a[i].m>>a[i].w;
    }
    if(n == 1){
        if(a[0].l == 0 and a[0].m == 0){
            cout<<"LM\n";
            return 0;
        }
        if(a[0].l == 0 and a[0].w == 0){
            cout<<"LW\n";
            return 0;
        }
        if(a[0].m == 0 and a[0].w == 0){
            cout<<"MW\n";
            return 0;
        }
        cout<<"Impossible\n";
        return 0;
    }
    vector<Par> Pares0, Pares1;
    int n0 = 1, n1 = 1;
    forn(i, n / 2) n0 *= 3;
    forn(i, (n + 1) / 2) n1 *= 3;
    forn(Probar, n0){
        int i = 0;
        vector<int> Valores(3, 0);
        string Ignorados = "";
        int Copia = Probar;
        forn(j, n / 2){
            int Ignorar = Copia % 3;
            if(Ignorar == 0){
                Valores[1] += a[i].m;
                Valores[2] += a[i].w;
                Ignorados += "0";
            } else if(Ignorar == 1){
                Valores[0] += a[i].l;
                Valores[2] += a[i].w;
                Ignorados += "1";
            } else {
                Valores[0] += a[i].l;
                Valores[1] += a[i].m;
                Ignorados += "2";
            }
            i++;
            Copia /= 3;
        }
        Pares0.pb(Par(Valores[1] - Valores[0], Valores[2] - Valores[1], Valores[0], Ignorados));
    }
    forn(Probar, n1){
        int i = n / 2;
        vector<int> Valores(3, 0);
        string Ignorados = "";
        int Copia = Probar;
        forsn(j, n / 2, n){
            int Ignorar = Copia % 3;
            if(Ignorar == 0){
                Valores[1] += a[i].m;
                Valores[2] += a[i].w;
                Ignorados += "0";
            } else if(Ignorar == 1){
                Valores[0] += a[i].l;
                Valores[2] += a[i].w;
                Ignorados += "1";
            } else {
                Valores[0] += a[i].l;
                Valores[1] += a[i].m;
                Ignorados += "2";
            }
            i++;
            Copia /= 3;
        }
        Pares1.pb(Par(Valores[1] - Valores[0], Valores[2] - Valores[1], Valores[0], Ignorados));
    }
    sort(all(Pares0));
    sort(all(Pares1));
    int Mayor = INT_MIN, p0, p1;
    /*for(auto E: Pares0){
        cerr<<E.s_0_s_1<<" "<<E.s_1_s_2<<" "<<E.s<<" "<<E.Ignorados<<el;
    }
    cerr<<el;
    for(auto E: Pares1){
        cerr<<E.s_0_s_1<<" "<<E.s_1_s_2<<" "<<E.s<<" "<<E.Ignorados<<el;
    }*/
    forn(i, n0){
        int Posible = lower_bound(all(Pares1), Par(Pares0[i].s_0_s_1, Pares0[i].s_0_s_1, INT_MAX, "")) - Pares1.begin();
        cerr<<i<<" "<<Posible<<el;
        if(Posible >= n1) continue;
        cerr<<Pares0[i].s_0_s_1<<" "<<Pares1[Posible].s_0_s_1<<" "<<Pares0[i].s_1_s_2<<" "
        if(Pares0[i].s_0_s_1 != Pares1[Posible].s_0_s_1 or Pares0[i].s_1_s_2 != Pares1[Posible].s_1_s_2) continue;
        if(Pares0[i].s + Pares1[Posible].s > Mayor){
            Mayor = Pares0[i].s + Pares1[Posible].s;
            p0 = i;
            p1 = Posible;
        }
    }
    if(Mayor == INT_MIN){
        cout<<"Impossible\n";
        return 0;
    }
    for(auto E: Pares0[p0].Ignorados){
        switch(E){
            case '0':
                cout<<"MW\n";
            break;
            case '1':
                cout<<"LW\n";
            break;
            default:
                cout<<"LM\n";
        }
    }
    for(auto E: Pares1[p1].Ignorados){
        switch(E){
            case '0':
                cout<<"MW\n";
            break;
            case '1':
                cout<<"LW\n";
            break;
            default:
                cout<<"LM\n";
        }
    }
    return 0;
}