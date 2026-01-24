#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x, y;
    cin>>x>>y;
    double Bien = 0;
    for(int i = 1; i <= 6; i++){
        for(int j = 1; j <= 6; j++){
            if(i + j >= x or abs(i - j) >= y) Bien++;
        }
    }
    cout<<setprecision(22)<<Bien / (double)36;
    return 0;
}