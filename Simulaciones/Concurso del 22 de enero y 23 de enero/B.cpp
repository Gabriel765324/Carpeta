#include "bits/stdc++.h"
using namespace std;
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    long long n;
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
            long long r;
            cin>>r;
            if(r == 1) a = {1, 0};
            else a = {0, 1};
            i++;
        } else {
            long long Izquierda = 0, Derecha = a.size() - 1, Mejor = 0;
            while(1){
                long long Promedio = (Izquierda + Derecha) / 2;
                cout<<"? 2 "<<a[Promedio]<<" "<<i<<endl;
                long long r;
                cin>>r;
                if(Promedio == 0 and r == 1){
                    Mejor = -1;
                    break;
                }
                if(r == 0){
                    Izquierda = Promedio + 1;
                    Mejor = Promedio;
                } else Derecha = Promedio - 1;
                if(Izquierda >= Derecha + 1) break;
            }
            a.insert(a.begin() + Mejor + 1, i);
        }
        /*for(auto E: a) cerr<<E<<" ";
        cerr<<"\n";*/
    }
    for(long long i = 0; i < a.size(); i++){
        Respuesta[a[i]] = i;
    }
    cout<<"! ";
    for(auto E: Respuesta) cout<<E<<" ";
    cout<<endl;
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