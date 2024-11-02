#include "bits/stdc++.h"
using namespace std;
long long p(long long b, long long e){
    if(e == 0) return 1;
    if(e == 1) return b;
    long long a = p(b, e / 2);
    a *= a;
    if((e % 2) == 1) a *= b;
    return a;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    vector<long long> Respuestas;
    while(t--){
        long long n, r = 1, n2 = 0;
        cin>>n;
        cout<<n<<" ";
        if(Respuestas.size() > n) cout<<Respuestas[n] - 1<<"\n";
        else {
            for(long long i = Respuestas.size(); i <= n; i++){
                stringstream c;
                long long j = i;
                c<<j;
                string nn;
                c>>nn;
                Respuestas.push_back(1);
                for(j = 0; j < (nn.size() / 2); j++){
                    if(nn[j] != nn[nn.size() - j - 1]){
                        Respuestas.back() = 0;
                        break;
                    }
                }
                if((Respuestas.size() - 2) > 0) Respuestas.back() += Respuestas[Respuestas.size() - 2];
            }
            cout<<Respuestas.back()<<"\n";
        }
        //long long d = (long long)log10(n) + 1;
        /*long long j = nn.size() - 1;
        for(long long i = 0; i <= j; i++){
            long long m = min(nn[i], nn[j]) - '0' - 1;
            m = max(m, 0LL);
            r += m * p(10, (j - i) / 2 + (long long)((j - i) % 2) == 0);
        }
        for(long long i = 1; i < d; i++){
            if((i % 2) == 0){
                n2++;
                long long a = p(10, n2);
                a -= n2 + 1;
                r += a;
            } else {
                long long a = 10;
                a *= p(10, n2);
                a -= n2 + 1;
                r += a;
            }
            //cout<<r<<" ";
        }
        //cout<<r<<" ";
        long long j = nn.size() - 1;
        for(long long i = 0; i <= j; i++){
            long long m = min(nn[i], nn[j]) - '0' - 1;
            m = max(m, 0LL);
            r += m * p(10, (j - i) / 2 + (long long)((j - i) % 2) == 0);
        }*/
        //cout<<r<<"\n";
    }
    return 0;
}