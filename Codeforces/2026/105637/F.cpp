#include "bits/stdc++.h"
using namespace std;
vector< vector<int> > _rbol;
int Consulta1D(int i, int d, int p0, int p1, int I, int D){
    if(i >= I and d <= D) return _rbol[p0][p1];
    if(i > D or d < I) return 0;
    int P = (i + d) / 2;
    return Consulta1D(i, P, p0, p1 * 2, I, D) + Consulta1D(P + 1, d, p0, p1 * 2 + 1, I, D);
}
int Consulta2D(int x0, int x1, int y0, int y1, int p0, int p1, int cx0, int cx1, int cy0, int cy1){
    if(cx0 > cx1) swap(cx0, cx1);
    if(cy0 > cy1) swap(cy0, cy1);
    if(x0 >= cx0 and x1 <= cx1) return Consulta1D(y0, y1, p0, p1, cy0, cy1);
    if(x0 > cx1 or x1 < cx0 or y0 > cy1 or y1 < cy0) return 0;
    int P0 = (x0 + x1) / 2;
    return Consulta2D(x0, P0, y0, y1, p0 * 2, p1, cx0, cx1, cy0, cy1) + Consulta2D(P0 + 1, x1, y0, y1, p0 * 2 + 1, p1, cx0, cx1, cy0, cy1);
}
void Actualizar1D(int i, int d, int p0, int p1, int c, int v){
    if(i == d and d == c){
        _rbol[p0][p1] = v;
        return;
    }
    if(i > c or d < c) return;
    int P = (i + d) / 2;
    Actualizar1D(i, P, p0, p1 * 2, c, v);
    Actualizar1D(P + 1, d, p0, p1 * 2 + 1, c, v);
    _rbol[p0][p1] = _rbol[p0][p1 * 2] + _rbol[p0][p1 * 2 + 1];
}
void Actualizar2D(int x0, int x1, int y0, int y1, int p0, int p1, int ax, int ay, int v){
    if(x0 == x1 and x1 == ax){
        Actualizar1D(y0, y1, p0, p1, ay, v);
        return;
    }
    if(x0 > ax or x1 < ax or y0 > ay or y1 < ay) return;
    int P = (x0 + x1) / 2;
    Actualizar2D(x0, P, y0, y1, p0 * 2, p1, ax, ay, v);
    Actualizar2D(P + 1, x1, y0, y1, p0 * 2 + 1, p1, ax, ay, v);
    _rbol[p0][p1] = _rbol[p0 * 2][p1] + _rbol[p0 * 2 + 1][p1];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector< pair< int, pair<int, int> > > Posiciones(n * m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int a;
            cin>>a;
            a--;
            Posiciones[a] = {a, {i, j}};
        }
    }
    int r = (n - 1) * (m - 1);
    sort(Posiciones.begin(), Posiciones.end());
    _rbol.assign(n * 4 + 22, vector<int>(m * 4 + 22, 0));
    vector< set<int> > v(m), h(n), _v(m), _h(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            h[i].insert(j);
            _h[i].insert(-j);
            v[j].insert(i);
            _v[j].insert(-i);
        }
    }
    for(int i = 0; i < 4; i++){
        int x = Posiciones[i].second.first, y = Posiciones[i].second.second;
        Actualizar2D(0, n - 1, 0, m - 1, 1, 1, x, y, 1);
        v[y].erase(x);
        _v[y].erase(-x);
        h[x].erase(y);
        _h[x].erase(-y);
    }
    for(int i = 4; i < n * m; i++){
        int x = Posiciones[i].second.first, y = Posiciones[i].second.second;
        Actualizar2D(0, n - 1, 0, m - 1, 1, 1, x, y, 1);
        auto xa = v[y].upper_bound(x);
        auto xA = _v[y].upper_bound(-x);
        auto ya = h[x].upper_bound(y);
        auto yA = _h[x].upper_bound(-y);
        if(xa != v[y].end() and ya != h[x].end()){
            if(Consulta2D(0, n - 1, 0, m - 1, 1, 1, x, *xa, y, *ya) == (abs((*xa - x)) + 1) * (abs((*ya - y)) + 1)){
                r++;
            }
        }
        if(xa != v[y].end() and yA != _h[x].end()){
            if(Consulta2D(0, n - 1, 0, m - 1, 1, 1, x, *xa, y, *yA) == (abs((*xa - x)) + 1) * (abs((*yA - y)) + 1)){
                r++;
            }
        }
        if(xA != _v[y].end() and ya != h[x].end()){
            if(Consulta2D(0, n - 1, 0, m - 1, 1, 1, x, *xA, y, *ya) == (abs((*xA - x)) + 1) * (abs((*ya - y)) + 1)){
                r++;
            }
        }
        if(xA != _v[y].end() and yA != _h[x].end()){
            if(Consulta2D(0, n - 1, 0, m - 1, 1, 1, x, *xA, y, *yA) == (abs((*xA - x)) + 1) * (abs((*yA - y)) + 1)){
                r++;
            }
        }
        v[y].erase(x);
        _v[y].erase(-x);
        h[x].erase(y);
        _h[x].erase(-y);
    }
    return 0;
}