#include "bits/stdc++.h"
using namespace std;
long long n, m = 1000000007;
string s;
//vector< vector< vector< vector<long long> > > > Memorizaci_n;
long long Suma(long long a, long long b){
    return (a % m + b % m) % m;
}
/*long long Resolver(long long i, long long p, long long Invertido, long long Usado){
    if(p < 0 or p >= n + 2) return 0;
    if(i == n and p == 0 and Invertido == 0) return 1;
    if(i == n and (p != 0 or Invertido != 0)) return 0;
    if(Memorizaci_n[i][p][Invertido][Usado] != -2) return Memorizaci_n[i][p][Invertido][Usado] % m;
    long long Retorno = 0;
    if(s[i] == '('){
        if(Invertido == 0){
            if(Usado == 0){
                Retorno = Suma(Retorno, Resolver(i + 1, p + 1, 0, 0));
                Retorno = Suma(Retorno, Resolver(i + 1, p - 1, 1, 1));
            } else {
                Retorno = Suma(Retorno, Resolver(i + 1, p + 1, 0, 1));
            }
        } else {
            Retorno = Suma(Retorno, Resolver(i + 1, p - 1, 1, 1));
            Retorno = Suma(Retorno, Resolver(i + 1, p + 1, 0, 1));
        }
    } else if(s[i] == ')'){
        if(Invertido == 0){
            if(Usado == 0){
                Retorno = Suma(Retorno, Resolver(i + 1, p - 1, 0, 0));
                Retorno = Suma(Retorno, Resolver(i + 1, p + 1, 1, 1));
            } else {
                Retorno = Suma(Retorno, Resolver(i + 1, p - 1, 0, 1));
            }
        } else {
            Retorno = Suma(Retorno, Resolver(i + 1, p + 1, 1, 1));
            Retorno = Suma(Retorno, Resolver(i + 1, p - 1, 0, 1));
        }
    } else {
        if(Invertido == 0){
            if(Usado == 0){
                Retorno = Suma(Retorno, Resolver(i + 1, p + 1, 0, 0));
                Retorno = Suma(Retorno, Resolver(i + 1, p - 1, 1, 1));
                Retorno = Suma(Retorno, Resolver(i + 1, p - 1, 0, 0));
                Retorno = Suma(Retorno, Resolver(i + 1, p + 1, 1, 1));
            } else {
                Retorno = Suma(Retorno, Resolver(i + 1, p + 1, 0, 1));
                Retorno = Suma(Retorno, Resolver(i + 1, p - 1, 0, 1));
            }
        } else {
            Retorno = Suma(Retorno, Resolver(i + 1, p - 1, 1, 1));
            Retorno = Suma(Retorno, Resolver(i + 1, p + 1, 0, 1));
            Retorno = Suma(Retorno, Resolver(i + 1, p + 1, 1, 1));
            Retorno = Suma(Retorno, Resolver(i + 1, p - 1, 0, 1));
        }
    }
    return Memorizaci_n[i][p][Invertido][Usado] = Retorno;
}*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long Contador = 0;
    cin>>n>>s;
    vector<long long> Posiciones;
    if(n % 2 == 1){
        cout<<0;
        return 0;
    }
    for(long long i = 0; i < n; i++){
        if(s[i] == 'x') Posiciones.push_back(i);
    }
    if(Posiciones.empty()){
        long long Par_ntesis = 0;
        for(long long i = 0; i < n; i++){
            if(s[i] == '(') Par_ntesis++;
            else Par_ntesis--;
            if(Par_ntesis < 0) break;
        }
        if(Par_ntesis == 0) cout<<1;
        else {
            for(long long i = 0; i < n; i++){
                for(long long j = i; j < n; j++){
                    Par_ntesis = 0;
                    for(long long k = 0; k < n; k++){
                        if((s[k] == '(' and (k < i or k > j)) or (s[k] == ')' and (k >= i and k <= j))) Par_ntesis++;
                        else Par_ntesis--;
                        if(Par_ntesis < 0) break;
                    }
                    if(Par_ntesis == 0){
                        cout<<1;
                        return 0;
                    }
                }
            }
            cout<<0;
        }
        return 0;
    }
    for(long long Probar = 0; Probar < (1LL<<(long long)Posiciones.size()); Probar++){
        for(long long i = 0; i < Posiciones.size(); i++){
            if(Probar & (1LL<<i)) s[Posiciones[i]] = '(';
            else s[Posiciones[i]] = ')';
        }
        bool Continuar = 1;
        for(long long i = 0; i < n and Continuar; i++){
            for(long long j = i; j < n and Continuar; j++){
                long long Par_ntesis = 0;
                for(long long k = 0; k < n; k++){
                    if((s[k] == '(' and (k < i or k > j)) or (s[k] == ')' and (k >= i and k <= j))) Par_ntesis++;
                    else Par_ntesis--;
                    if(Par_ntesis < 0) break;
                }
                if(Par_ntesis == 0){
                    Contador++;
                    Continuar = 0;
                }
            }
        }
        if(Continuar){
            long long Par_ntesis = 0;
            for(long long i = 0; i < n and Continuar; i++){
                if(s[i] == '(') Par_ntesis++;
                else Par_ntesis--;
                if(Par_ntesis < 0) Continuar = 0;
            }
            if(Continuar and Par_ntesis == 0) Contador++;
        }
        //cout<<s<<" "<<((Continuar == 0) ? "Bien" : "Mal")<<"\n";
    }
    cout<<Contador;
    /*vector<long long> Posiciones;
    if(n % 2 == 1){
        cout<<0;
        return 0;
    }
    for(long long i = 0; i < n; i++){
        if(s[i] == 'x') Posiciones.push_back(i);
    }
    if(Posiciones.empty()){
        vector< vector< vector< vector<bool> > > > Memorizaci_n(n + 2, vector< vector< vector<bool> > >(n / 2 + 22, vector< vector<bool> >(2, vector<bool>(2, 0))));
        Memorizaci_n[n][0][0][0] = 1;
        Memorizaci_n[n][0][0][1] = 1;
        for(long long i = n - 1; i > -1; i--){
            for(long long p = 0; p < n / 2 + 16; p++){
                for(long long Invertido = 0; Invertido < 2; Invertido++){
                    for(long long Usado = 0; Usado < 2; Usado++){
                        if(s[i] == '('){
                            if(Invertido == 0){
                                if(Usado == 0){
                                    Memorizaci_n[i][p][Invertido][Usado] = Memorizaci_n[i][p][Invertido][Usado] or Memorizaci_n[i + 1][p + 1][0][0];
                                    if(p > 0) Memorizaci_n[i][p][Invertido][Usado] = Memorizaci_n[i][p][Invertido][Usado] or Memorizaci_n[i + 1][p - 1][1][1];
                                } else {
                                    Memorizaci_n[i][p][Invertido][Usado] = Memorizaci_n[i][p][Invertido][Usado] or Memorizaci_n[i + 1][p + 1][0][1];
                                }
                            } else {
                                if(p > 0) Memorizaci_n[i][p][Invertido][Usado] = Memorizaci_n[i][p][Invertido][Usado] or Memorizaci_n[i + 1][p - 1][1][1];
                                Memorizaci_n[i][p][Invertido][Usado] = Memorizaci_n[i][p][Invertido][Usado] or Memorizaci_n[i + 1][p + 1][0][1];
                            }
                        } else if(s[i] == ')'){
                            if(Invertido == 0){
                                if(Usado == 0){
                                    if(p > 0) Memorizaci_n[i][p][Invertido][Usado] = Memorizaci_n[i][p][Invertido][Usado] or Memorizaci_n[i + 1][p - 1][0][0];
                                    Memorizaci_n[i][p][Invertido][Usado] = Memorizaci_n[i][p][Invertido][Usado] or Memorizaci_n[i + 1][p + 1][1][1];
                                } else {
                                    if(p > 0) Memorizaci_n[i][p][Invertido][Usado] = Memorizaci_n[i][p][Invertido][Usado] or Memorizaci_n[i + 1][p - 1][0][1];
                                }
                            } else {
                                Memorizaci_n[i][p][Invertido][Usado] = Memorizaci_n[i][p][Invertido][Usado] or Memorizaci_n[i + 1][p + 1][1][1];
                                if(p > 0) Memorizaci_n[i][p][Invertido][Usado] = Memorizaci_n[i][p][Invertido][Usado] or Memorizaci_n[i + 1][p - 1][0][1];
                            }
                        }
                        cout<<i<<" "<<p<<" "<<Invertido<<" "<<Usado<<" "<<s[i]<<" "<<Memorizaci_n[i][p][Invertido][Usado]<<"\n";
                    }
                }
            }
        }
        cout<<Memorizaci_n[0][0][0][0];
        return 0;
    } else {
        for(long long Probar = 0; Probar < (1LL<<(long long)Posiciones.size()); Probar++){
            for(long long j = 0; j < Posiciones.size(); j++){
                if(Probar & (1LL<<j)) s[Posiciones[j]] = '(';
                else s[Posiciones[j]] = ')';
            }
            vector< vector< vector< vector<bool> > > > Memorizaci_n(n + 2, vector< vector< vector<bool> > >(n + 2, vector< vector<bool> >(2, vector<bool>(2, 0))));
            Memorizaci_n[n][0][0][0] = 1;
            Memorizaci_n[n][0][0][1] = 1;
            for(long long i = n - 1; i > -1; i--){
                for(long long p = 0; p < n / 2 + 16; p++){
                    for(long long Invertido = 0; Invertido < 2; Invertido++){
                        for(long long Usado = 0; Usado < 2; Usado++){
                            cout<<i<<" "<<p<<" "<<Invertido<<" "<<Usado<<" "<<s[i]<<"\n";
                            if(s[i] == '('){
                                if(Invertido == 0){
                                    if(Usado == 0){
                                        Memorizaci_n[i][p][Invertido][Usado] = Memorizaci_n[i][p][Invertido][Usado] or Memorizaci_n[i + 1][p + 1][0][0];
                                        if(p > 0) Memorizaci_n[i][p][Invertido][Usado] = Memorizaci_n[i][p][Invertido][Usado] or Memorizaci_n[i + 1][p - 1][1][1];
                                    } else {
                                        Memorizaci_n[i][p][Invertido][Usado] = Memorizaci_n[i][p][Invertido][Usado] or Memorizaci_n[i + 1][p + 1][0][1];
                                    }
                                } else {
                                    if(p > 0) Memorizaci_n[i][p][Invertido][Usado] = Memorizaci_n[i][p][Invertido][Usado] or Memorizaci_n[i + 1][p - 1][1][1];
                                    Memorizaci_n[i][p][Invertido][Usado] = Memorizaci_n[i][p][Invertido][Usado] or Memorizaci_n[i + 1][p + 1][0][1];
                                }
                            } else if(s[i] == ')'){
                                if(Invertido == 0){
                                    if(Usado == 0){
                                        if(p > 0) Memorizaci_n[i][p][Invertido][Usado] = Memorizaci_n[i][p][Invertido][Usado] or Memorizaci_n[i + 1][p - 1][0][0];
                                        Memorizaci_n[i][p][Invertido][Usado] = Memorizaci_n[i][p][Invertido][Usado] or Memorizaci_n[i + 1][p + 1][1][1];
                                    } else {
                                        if(p > 0) Memorizaci_n[i][p][Invertido][Usado] = Memorizaci_n[i][p][Invertido][Usado] or Memorizaci_n[i + 1][p - 1][0][1];
                                    }
                                } else {
                                    Memorizaci_n[i][p][Invertido][Usado] = Memorizaci_n[i][p][Invertido][Usado] or Memorizaci_n[i + 1][p + 1][1][1];
                                    if(p > 0) Memorizaci_n[i][p][Invertido][Usado] = Memorizaci_n[i][p][Invertido][Usado] or Memorizaci_n[i + 1][p - 1][0][1];
                                }
                            }
                        }
                    }
                }
            }
            Contador += Memorizaci_n[0][0][0][0];
        }
        cout<<Contador % m;
    }*/
    //Memorizaci_n.assign(n + 2, vector< vector< vector<long long> > >(n + 2, vector< vector<long long> >(2, vector<long long>(2, -2))));
    //cout<<Resolver(0, 0, 0, 0) % m;
    /*for(long long i = n; i > -1; i--){
        vector< vector< vector<long long> > > Memorizaci_n(n + 2, vector< vector<long long> >(n / 2 + 22, vector<long long>(2, 0)));
        Memorizaci_n[n][0][0] = 1;
        //Memorizaci_n[n][0][1] = 1;
        for(long long j = n - 1; j > -1; j--){
            for(long long k = 1; k < n / 2 + 16; k++){
                for(long long l = 0; l < 2; l++){
                    switch(s[j]){
                        case '(':
                        if(l == 0){
                            if(j >= i - 1) Memorizaci_n[j][k][l] = Memorizaci_n[j + 1][k + 1][0], Memor orzaci_n[j + 1][k + 1][1]);
                           else Memorizaci_n[j][k][l] = Memorizaci_n[j + 1][k + 1][0];
                        } else if(j >= i and k > 0) Memorizaci_n[j][k][l] = Memorizaci_n[j + 1][k - 1][0], Memor orzaci_n[j + 1][k - 1][1]);
                       break;
                        case ')':
                        if(l == 0){
                            if(j >= i - 1 and k > 0) Memorizaci_n[j][k][l] = Memorizaci_n[j + 1][k - 1][0], Memor orzaci_n[j + 1][k - 1][1]);
                           else if(k > 0) Memorizaci_n[j][k][l] = Memorizaci_n[j + 1][k - 1][0];
                        } else if(j >= i) Memorizaci_n[j][k][l] = Memorizaci_n[j + 1][k + 1][0], Memor orzaci_n[j + 1][k + 1][1]);
                       break;
                        case 'x':
                        if(l == 0){
                            if(j >= i - 1) Memorizaci_n[j][k][l] = Memorizaci_n[j + 1][k + 1][0], Memor orzaci_n[j + 1][k + 1][1]);
                           else Memorizaci_n[j][k][l] = Memorizaci_n[j + 1][k + 1][0];
                        } else if(j >= i and k > 0) Memorizaci_n[j][k][l] = Memorizaci_n[j + 1][k - 1][0], Memor orzaci_n[j + 1][k - 1][1]);
                       if(l == 0){
                            if(j >= i - 1 and k > 0) Memorizaci_n[j][k][l] += Memorizaci_n[j + 1][k - 1][0], Memor orzaci_n[j + 1][k - 1][1]);
                           else if(k > 0) Memorizaci_n[j][k][l] += Memorizaci_n[j + 1][k - 1][0];
                        } else if(j >= i) Memorizaci_n[j][k][l] += Memorizaci_n[j + 1][k + 1][0], Memor orzaci_n[j + 1][k + 1][1]);
                       Memorizaci_n[j][k][l] %= m;
                        break;
                    }
                }
            }
            for(auto E: Memorizaci_n){
                for(auto e : E){
                    cout<<e[0]<<" ";
                }
                cout<<"\n";
            }
            cout<<"\n";
            for(auto E: Memorizaci_n){
                for(auto e : E){
                    cout<<e[1]<<" ";
                }
                cout<<"\n";
            }
            cout<<"\n";
            cout<<"\n";
        }
        if(i == 0) Contador = Contador, Memorizaci_n[0][0][1]);
   or     else Contador = Contador, Meorizaci_n[0][0][0]);
   or }*/
    return 0;
}