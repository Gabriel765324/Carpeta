#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n, k;
        string s;
        cin>>n>>k>>s;
        vector< string > Casos;
        for(long long i = 0; i < n / k; i++){
            long long Puntero = 0;
            string Caso = "";
            for(long long j = i * k; Puntero < (k + 1) / 2; Puntero++){
                Caso += s[j];
                j++;
            }
            Casos.push_back(Caso);
        }
        for(long long i = 0; i < n / 2; i++) swap(s[i], s[n - i - 1]);
        for(long long i = 0; i < n / k; i++){
            long long Puntero = 0;
            string Caso = "";
            for(long long j = i * k; Puntero < (k + 1) / 2; Puntero++){
                Caso += s[j];
                j++;
            }
            Casos.push_back(Caso);
        }
        vector< map<long long, long long> > Caracteres((k + 1) / 2);
        vector<long long> Suma((1 + k) / 2, 0);
        for(long long i = 0; i < Casos.size(); i++){
            for(long long j = 0; j < (k + 1) / 2; j++){
                Caracteres[j][Casos[i][j]]++;
                Suma[j] = Casos.size();
            }
        }
        //for(auto E: Casos) cerr<<E<<"\n";
        vector<long long> Menores((1 + k) / 2, 2222222222222222);
        for(long long i = 0; i < Casos.size(); i++){
            for(long long j = 0; j < (1 + k) / 2; j++){
                long long Valor = Suma[j] - Caracteres[j][Casos[i][j]];
                if(j + 1 == (1 + k) / 2 and k % 2 == 1) Valor /= 2;
                Menores[j] = min(Menores[j], Valor);
            }
        }
        long long Menor = 0;
        for(long long i = 0; i < (k + 1) / 2; i++){
            Menor += Menores[i];
            //cerr<<Menores[i]<<" ";
        }
        cout<<Menor<<"\n";
    }
    return 0;
}