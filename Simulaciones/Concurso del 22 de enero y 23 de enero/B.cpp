#include "bits/stdc++.h"
using namespace std;
int main(){
    //vector<long long> p = {4, 1, 0, 2, 3};
    long long n/* = p.size()*/;
    cin>>n;
    if(n == 1){
        cout<<"! 0"<<endl;
        return 0;
    }
    vector<long long> a, Respuesta(n, -2);
    for(long long i = 0; i < n; i++) a.push_back(i);
    for(long long i = 0; i < n; i++){
        if(i == 0){
            cout<<"? 2 0 1"<<endl;
            long long r/* = (long long)(p[0] > p[1])*/;
            cin>>r;
            //cout<<r<<endl;
            if(r == 0) a = {0, 1};
            else a = {1, 0};
            i++;
        } else {
            vector<long long> c = {a[0], i};
            for(long long j = 1; j < a.size(); j++){
                c.push_back(a[j]);
                c.push_back(a[0]);
                c.push_back(i);
            }
            cout<<"? "<<c.size()<<" ";
            for(auto E: c) cout<<E<<" ";
            cout<<endl;
            long long r = 0;
            cin>>r;
            /*for(long long j = 0; j < c.size() - 1; j++) r += (long long)(p[c[j]] > p[c[j + 1]]);
            cout<<r<<endl;*/
            r -= i - 1;
            if(r == i) a.insert(a.begin(), i);
            else a.insert(a.begin() + r + 1, i);
        }
        /*for(auto E: a) cerr<<E<<" ";
        cerr<<"\n";*/
    }
    for(long long i = 0; i < a.size(); i++){
        Respuesta[a[i]] = i;
    }
    cout<<"! ";
    for(auto E: Respuesta) cout<<E<<" ";
    cout<<endl/*<<((Respuesta != p) ? "Mal." : "Bien.")<<endl*/;
    //long long Inversos = 0;
    /*for(long long i = 2; i <= n; i++){
        cout<<"? "<<i<<" ";
        if(i == 2) for(long long j = 0; j < i; j++) cout<<j<<" ";
        else {
            for(auto E: a) cout<<E<<" ";
            cout<<i - 1;
        }
        cout<<endl;
        long long A_ver;
        cin>>A_ver;
        if(i == 2){
            if(A_ver == 1){
                a.push_back(0);
                a.push_front(1);
            } else {
                a.push_back(0);
                a.push_back(1);
            }
            //Inversos = A_ver;
        } else {
            if(A_ver == 1) a.push_back(i - 1);
            else a.push_back(i - 1);
        }
    }
    vector<long long> r(n, 0);
    for(long long i = 0; i < n; i++){
        r[a[i]] = i;
    }
    cout<<"! ";
    for(auto E: r) cout<<E<<" ";
    cout<<endl;*/
    return 0;
}