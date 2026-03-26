#include "bits/stdc++.h"
using namespace std;
vector< vector<long long> > PD, a;
long long Resolver(long long i, long long j){
    if(i == PD.size()) return 0;
    if(PD[i][j] != -2) return PD[i][j];
    long long m = 0;
    if(j >= 7){
        long long Mayor = 0;
        long long Suma = 0;
        for(long long k = 0; k < 3; k++){
            Mayor = max(Mayor, a[i][k]);
            Suma += a[i][k];
        }
        m = max(m, Resolver(i + 1, (j + 3) % 10) + Suma + Mayor);
    } else {
        long long Suma = 0;
        for(long long k = 0; k < 3; k++){
            Suma += a[i][k];
        }
        m = max(m, Resolver(i + 1, (j + 3) % 10) + Suma);
    }
    if(j >= 8){
        m = max(m, Resolver(i + 1, (j + 2) % 10) + a[i][0] + a[i][1] + max(a[i][0], a[i][1]));
        m = max(m, Resolver(i + 1, (j + 2) % 10) + a[i][2] + a[i][1] + max(a[i][2], a[i][1]));
        m = max(m, Resolver(i + 1, (j + 2) % 10) + a[i][0] + a[i][2] + max(a[i][0], a[i][2]));
        m = max(m, Resolver(i + 1, (j + 2) % 10) + a[i][0] + a[i][3] + max(a[i][0], a[i][3]));
        m = max(m, Resolver(i + 1, (j + 2) % 10) + a[i][1] + a[i][3] + max(a[i][1], a[i][3]));
        m = max(m, Resolver(i + 1, (j + 2) % 10) + a[i][2] + a[i][3] + max(a[i][2], a[i][3]));
    } else {
        m = max(m, Resolver(i + 1, (j + 2) % 10) + a[i][0] + a[i][1]);
        m = max(m, Resolver(i + 1, (j + 2) % 10) + a[i][2] + a[i][1]);
        m = max(m, Resolver(i + 1, (j + 2) % 10) + a[i][0] + a[i][2]);
        m = max(m, Resolver(i + 1, (j + 2) % 10) + a[i][0] + a[i][3]);
        m = max(m, Resolver(i + 1, (j + 2) % 10) + a[i][1] + a[i][3]);
        m = max(m, Resolver(i + 1, (j + 2) % 10) + a[i][2] + a[i][3]);
    }
    if(j == 9){
        for(long long k = 0; k < 5; k++){
            m = max(m, Resolver(i + 1, (j + 1) % 10) + 2 * a[i][k]);
        }
    } else {
        for(long long k = 0; k < 5; k++){
            m = max(m, Resolver(i + 1, (j + 1) % 10) + a[i][k]);
        }
    }
    m = max(Resolver(i + 1, j), m);
    return PD[i][j] = m;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    PD.assign(n, vector<long long>(10, -2));
    a.assign(n, vector<long long>());
    for(long long i = 0; i < n; i++){
        long long k;
        cin>>k;
        vector<long long> b(5, -2222222222222222);
        for(long long j = 0; j < k; j++){
            long long c, d;
            cin>>c>>d;
            if(c == 3) b[4] = max(b[4], d);
            if(c == 2) b[3] = max(b[3], d);
            if(c == 1){
                bool Bien = 0;
                for(long long l = 0; l < 3; l++){
                    if(b[l] == -1){
                        b[l] = d;
                        Bien = 1;
                        break;
                    }
                }
                long long Menor = 2222222222222222, p;
                for(long long l = 0; l < 3 and !Bien; l++){
                    if(b[l] < Menor){
                        p = l;
                        Menor = b[l];
                    }
                    if(l == 2){
                        b[p] = max(d, b[p]);
                    }
                }
            }
        }
        a[i] = b;
    }
    cout<<Resolver(0, 0); //Por favor no des tiempo límite excedido.
    return 0;
}