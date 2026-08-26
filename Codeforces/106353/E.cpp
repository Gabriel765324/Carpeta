#include "bits/stdc++.h"
using namespace std;
vector< vector< vector<long double> > > PD;
long double Suma = 0;
long double Resolver(int a, int b, int c){
    vector<int> Conversor = {a, b, c};
    sort(Conversor.begin(), Conversor.end());
    a = Conversor[0];
    b = Conversor[1];
    c = Conversor[2];
    if(a == 0 and b == 0) return 0;
    if(PD[a][b][c] >= -1) return PD[a][b][c];
    if(a > 0) return PD[a][b][c] = (Resolver(a - 1, b + 1, c) + Resolver(a - 1, b, c + 1) + (long double)3) / (long double)2;
    return PD[a][b][c] = Suma * b;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long double m = 0.5;
    for(long double i = 1; i <= 2222; i++){
        Suma += i * m;
        m /= (long double)2;
    }
    Suma = 3;
    int n, a = 0, b = 0, c = 0;
    string s;
    cin>>n>>s;
    for(int i = 0; i < n; i++){
        if(s[i] == 'r') a++;
        if(s[i] == 'g') b++;
        if(s[i] == 'b') c++;
    }
    PD.assign(n + 1, vector< vector<long double> >(n + 1, vector<long double>(n + 1, -2)));
    cout<<setprecision(22)<<Resolver(a, b, c)<<"\n";
    return 0;
}