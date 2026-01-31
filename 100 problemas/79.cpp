#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> s, a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++){
        s.push_back(a[i]);
        if(s.size() > 1){
            int Borrar = s.back() + 1;
            if(s.back() == s[s.size() - 2]){
                s.pop_back();
                s.pop_back();
                while(!s.empty()){
                    if(s.back() == Borrar){
                        Borrar++;
                        s.pop_back();
                    } else break;
                }
                s.push_back(Borrar);
            }
        }
    }
    cout<<s.size();
    return 0;
}