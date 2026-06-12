#include "bits/stdc++.h"
#define el "\n"
#define vi vector<int>
#define ll long long
#define ii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define pf push_front
#define di deque<int>
#define all(v) (v).begin(), (v).end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
using namespace std;
struct Nodo{
    long long Suma, Menor;
    Nodo(long long s, long long m){
        Suma = s;
        Menor = m;
    }
    Nodo(int v){
        Suma = (long long)v;
        Menor = (long long)v;
    }
    Nodo(){
        Suma = 0LL;
        Menor = -2LL;
    }
    Nodo operator+(const Nodo& a){
        if(a.Menor == -2LL) return *this;
        if(Menor == -2LL) return a;
        return Nodo(Suma + a.Suma, min(Menor, a.Menor));
    }
};
int Ix, Dx, Iy, Dy;
struct _rbol{
    int n, m;
    vector< vector<Nodo> > a;
    int Tama_o(int i, int d){
        return (d - i + 1) * 2;
    }
    void Creary(int i, int d, int p, vector< vector<int> >& Base, int Fila, int p__rbol){
        if(i == d){
            a[p__rbol][p] = Nodo(Base[Fila][i]);
            return;
        }
        int P = (i + d) / 2, Extra = Tama_o(i, P);
        Creary(i, P, p + 1, Base, Fila, p__rbol);
        Creary(P + 1, d, p + Extra, Base, Fila, p__rbol);
        a[p__rbol][p] = a[p__rbol][p + 1] + a[p__rbol][p + Extra];
    }
    void Crearx(int i, int d, int p, vector< vector<int> >& Base){
        if(i == d){
            Creary(0, m - 1, 0, Base, i, p);
            /*cerr<<i<<" "<<p<<"\n";
            for(auto E: a[p]) cerr<<E.Suma<<" ";
            cerr<<"\n\n";*/
            return;
        }
        int P = (i + d) / 2, Extra = Tama_o(i, P);
        Crearx(i, P, p + 1, Base);
        Crearx(P + 1, d, p + Extra, Base);
        for(int j = 0; j < m * 2 + 22; j++){
            a[p][j] = a[p + 1][j] + a[p + Extra][j];
        }
    }
    _rbol(int N, int M, vector< vector<int> >& Base){
        n = N;
        m = M;
        a.assign(n * 2 + 22, vector<Nodo>(m * 2 + 22, Nodo()));
        Crearx(0, n - 1, 0, Base);
    }
    Nodo Consultay(int i, int d, int p, int p__rbol){
        //cerr<<i<<" "<<d<<" "<<p<<" "<<p__rbol<<" y\n";
        if(i >= Iy and d <= Dy) return a[p__rbol][p];
        if(i > Dy or d < Iy) return Nodo();
        int P = (i + d) / 2, Extra = Tama_o(i, P);
        return Consultay(i, P, p + 1, p__rbol) + Consultay(P + 1, d, p + Extra, p__rbol);
    }
    Nodo Consultax(int i, int d, int p){
        //cerr<<i<<" "<<d<<" "<<p<<" "<<Ix<<" "<<Dx<<" x\n";
        if(i >= Ix and d <= Dx) return Consultay(0, m - 1, 0, p);
        if(i > Dx or d < Ix) return Nodo();
        int P = (i + d) / 2, Extra = Tama_o(i, P);
        return Consultax(i, P, p + 1) + Consultax(P + 1, d, p + Extra);
    }
    Nodo Consulta(vector<int> c){
        Ix = c[0];
        Dx = c[1];
        Iy = c[2];
        Dy = c[3];
        return Consultax(0, n - 1, 0);
    }
};
struct Valorcito{
    long long Aporte;
    int x, y;
    Valorcito(long long a, int X, int Y){
        Aporte = a;
        x = X;
        y = Y;
    }
    bool operator<(const Valorcito& a){
        if(Aporte < a.Aporte) return 1;
        if(Aporte > a.Aporte) return 0;
        if(x < a.x) return 1;
        if(x > a.x) return 0;
        return y < a.y;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    cin>>n>>m>>a>>b;
    vector<int> Respuesta;
    vector< bitset<1222> > Marcados(n);
    vector<Valorcito> Tenemos;
    vector< vector<int> > Base(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>Base[i][j];
        }
    }
    _rbol Ayudante = _rbol(n, m, Base);
    //Base.clear();
    for(int i = 0; i < n; i++){
        if(i + a - 1 >= n) break;
        for(int j = 0; j < m; j++){
            if(j + b - 1 >= m) break;
            auto E = Ayudante.Consulta({i, i + (int)a - 1, j, j + (int)b - 1});
            //cerr<<i<<" "<<i + (int)a - 1<<" "<<j<<" "<<j + (int)b - 1<<"\n";
            //cerr<<E.Suma<<" "<<E.Menor<<"\n\n";
            Tenemos.push_back(Valorcito(E.Suma - E.Menor * (long long)a * (long long)b, i, j));
        }
    }
    //Ayudante.a.clear();
    sort(Tenemos.begin(), Tenemos.end());
    int Posici_n = 0;
    for(auto E: Tenemos){
        int x = E.x, y = E.y;
        if(!Marcados[x][y] and !Marcados[x + a - 1][y] and !Marcados[x][y + b - 1] and !Marcados[x + a - 1][y + b - 1]){
            for(int i = x; i < x + a; i++){
                for(int j = y; j < y + b; j++){
                    Marcados[i][j] = 1;
                }
            }
            Respuesta.push_back(Posici_n);
        }
        Posici_n++;
    }
    //Marcados.clear();
    cout<<int(Respuesta.size())<<"\n";
    for(auto E: Respuesta){
        cout<<Tenemos[E].x + 1<<" "<<Tenemos[E].y + 1<<" "<<Tenemos[E].Aporte<<"\n";
    }
    return 0;
}