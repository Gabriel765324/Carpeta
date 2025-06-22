#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n, x, y;
        string a, b;
        cin>>n>>x>>y>>a>>b;
        long long cn = n;
        vector<long long> p;
        for(long long i = 0; i < n; i++){
            if(a[i] != b[i]) p.push_back(i);
        }
        if(p.size() == 0) cout<<"0\n";
        else if(p.size() % 2 == 1) cout<<"-1\n";
        else {
            long long c = LLONG_MAX;
            n = p.size();
            long long pc = 0;
            if(x < y){
                deque< vector<long long> > Memorizaci_n(3, vector<long long>(5002, 222222222222222222));
                Memorizaci_n[1][0] = 0;
                Memorizaci_n[0][1] = 0;
                for(long long i = n - 2; i > -1; i--){
                    Memorizaci_n.pop_back();
                    Memorizaci_n.push_front(vector<long long>(5002, 222222222222222222));
                    Memorizaci_n[0][0] = min(Memorizaci_n[2][0] + (p[i + 1] - p[i]) * x, Memorizaci_n[1][1] + y);
                    for(long long j = 1; j < 5002; j++){
                        Memorizaci_n[0][j] = min(Memorizaci_n[2][j] + (p[i + 1] - p[i]) * x, min(Memorizaci_n[1][j + 1] + y, Memorizaci_n[1][j - 1]));
                    }
                }
                c = Memorizaci_n[0][0];
            } else {
                long long i = 0;
                for(long long j = n / 2; j < n; j++){
                    if((p[j] - p[i]) == 1LL) pc += x;
                    else pc += y;
                    i++;
                }
                c = min(c, pc);
                pc = 0;
                i = n - 1;
                for(long long j = n / 2 - 1; j > -1; j--){
                    if((p[i] - p[j]) == 1LL) pc += x;
                    else pc += y;
                    i--;
                }
                c = min(c, pc);
                if(p.size() == 2){
                    if((p[1] - p[0]) == 1LL){
                        //cout<<"Truco\n"<<c<<" "<<2 * y<<"\n";
                        if((p[0] - 2) > -1 or (p[1] + 2) < cn){
                            //cout<<"Truco\n"/*<<c<<" "<<2 * y<<"\n"*/;
                            c = min(c, 2 * y);
                        }
                    }
                }
            }
            cout<<c<<"\n";
        }
    }
    return 0;
}