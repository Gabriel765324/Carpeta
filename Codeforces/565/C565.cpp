#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
        long long n;
        cin>>n;
        deque<long long> a(n);
        for(long long i = 0; i < n; i++) cin>>a[i];
        map<long long, long long> So;
        vector<bool> Buenos(n, 0);
        for(long long i = 0; i < n; i++){
            switch(a[i]){
                case 4:
                    So[4]++;
                    Buenos[i] = 1;
                break;
                case 8:
                    if(So[4] > 0){
                        So[4]--;
                        So[8]++;
                        Buenos[i] = 1;
                    }
                break;
                case 15:
                    if(So[8] > 0){
                        So[8]--;
                        So[15]++;
                        Buenos[i] = 1;
                    }
                break;
                case 16:
                    if(So[15] > 0){
                        So[15]--;
                        So[16]++;
                        Buenos[i] = 1;
                    }
                break;
                case 23:
                    if(So[16] > 0){
                        So[16]--;
                        So[23]++;
                        Buenos[i] = 1;
                    }
                break;
                case 42:
                    if(So[23] > 0){
                        So[23]--;
                        Buenos[i] = 1;
                    }
                break;
            }
        }
        long long r = 0;
        for(auto E: Buenos) r += (long long)(!E);
        r += So[4];
        r += So[8] * 2;
        r += So[15] * 3;
        r += So[16] * 4;
        r += So[23] * 5;
        cout<<r<<"\n";
    return 0;
}