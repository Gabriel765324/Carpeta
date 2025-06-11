#include "artclass.h"
#include "bits/stdc++.h"
using namespace std;
int style(int n, int m, int r[500][500], int g[500][500], int b[500][500]){
    double Diferencia = -0;
    //cerr<<n<<" "<<m<<"\n";
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < m; j++){
            //cerr<<i<<" "<<j<<"\n";
            if(i + 1 < n) Diferencia += abs(r[i][j] - r[i + 1][j]) + abs(g[i][j] - g[i + 1][j]) + abs(b[i][j] - b[i + 1][j]);
            if(j + 1 < m) Diferencia += abs(r[i][j] - r[i][j + 1]) + abs(g[i][j] - g[i][j + 1]) + abs(b[i][j] - b[i][j + 1]);
        }
    }
    Diferencia /= (double)((n - 1) * m + (m - 1) * n);
    //cerr<<Diferencia<<"\n";
    double _1 = 17.7084888888888888888888888;
    double _2 = 31.9318888888888888888888888;
    double _3 = 86.5908;
    double _4 = 3.7592888888888888888888888;
    _1 = abs(_1 - Diferencia);
    _2 = abs(_2 - Diferencia);
    _3 = abs(_3 - Diferencia);
    _4 = abs(_4 - Diferencia);
    double Menor = 22222222;
    if(_1 < Menor) Menor = _1;
    if(_2 < Menor) Menor = _2;
    if(_3 < Menor) Menor = _3;
    if(_4 < Menor) Menor = _4;
    if(Menor == _1) return 1;
    if(Menor == _2) return 2;
    if(Menor == _3) return 3;
    if(Menor == _4) return 4;
}