#include "bits/stdc++.h"
using namespace std;
int main(){
    long long n, c = 1, i = 0;
    do{
        cout<<"Ingrese un número impar.\n";
        cin>>n;
    } while((n % 2) == 0);
    vector< vector<long long> > a(n, vector<long long>(n, -2LL));
    long long j = n / 2;
    while(c <= (n * n)){
        a[i][j] = c;
        c++;
        long long ni = i - 1LL;
        long long nj = j + 1LL;
        if(ni == -1LL) ni = n - 1LL;
        if(nj == n) nj = 0LL;
        if(a[ni][nj] != -2LL){
            i++;
            if(i == n) i = 0LL;
        } else {
            i = ni;
            j = nj;
        }
    }
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}