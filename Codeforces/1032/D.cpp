#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) cin>>a[i];
        for(int i = 0; i < n; i++) cin>>b[i];
        vector< pair<int, int> > r;
        for(int i = 0; i < n; i++){
            for(int j = i; j > 0; j--){
                if(a[j] < a[j - 1]){
                    swap(a[j], a[j - 1]);
                    r.push_back({1, j});
                } else break;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = i; j > 0; j--){
                if(b[j] < b[j - 1]){
                    swap(b[j], b[j - 1]);
                    r.push_back({2, j});
                } else break;
            }
        }
        for(int i = 0; i < n; i++){
            if(a[i] > b[i]){
                swap(a[i], b[i]);
                r.push_back({3, i + 1});
            }
        }
        cout<<r.size()<<"\n";
        for(auto E: r) cout<<E.first<<" "<<E.second<<"\n";
        /*cerr<<"\n";
        for(auto E: a) cerr<<E<<" ";
        cerr<<"\n";
        for(auto E: b) cerr<<E<<" ";
        cerr<<"\n\n";*/
    }
    return 0;
}