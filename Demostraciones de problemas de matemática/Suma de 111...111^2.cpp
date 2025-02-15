#include "bits/stdc++.h"
using namespace std;
long long f(long long n){
    if(n < 10) return n * n;
    if(n == 10) return 82;
    if((n - 10) % 9 != 0){
        long long s = 84 + ((n - 10) / 9) * 81;
        for(long long i = 2; i <= (n - 10) % 9; i++){
            i *= 2;
            s += i;
            i /= 2;
        }
        s += (n - 10) % 9;
        return s;
    }
    return 82 + (n - 10) * 9;
}
string Suma(string a, string b){
    while(a.size() < b.size()) a = '0' + a;
    while(b.size() < a.size()) b = '0' + b;
    long long i = a.size() - 1;
    long long j = b.size() - 1;
    string c = "";
    bool Llevo = 0;
    while(i > -1 and j > -1){
        long long A = a[i] - '0';
        long long B = b[j] - '0';
        long long C = A + B + (long long)Llevo;
        Llevo = 0;
        if(C < 10) c = (char)(C + '0') + c;
        else {
            c = (char)(C + '0' - 10) + c;
            Llevo = 1;
        }
        i--;
        j--;
    }
    if(Llevo) c = '1' + c;
    return c;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(long long n = 1; n <= 1022; n++){
        string a(n, '1');
        string r = "-2";
        for(long long i = 0; i < n; i++){
            if(r == "-2") r = a;
            else {
                r = Suma(r, a);
            }
            a += '0';
        }
        long long s = n, c = n;
        c = 0;
        for(long long i = 0; i < r.size(); i++) c += r[i] - '0';
        cout<<r<<" "<<f(s)<<" "<<c<<"\n";
        if(f(s) != c){
            cout<<"Mal. "<<r<<" "<<f(s)<<" "<<c;
            return 0;
        }
    }
    cout<<"Correcto.";
    return 0;
}