#include "bits/stdc++.h"
#include "conio.h"
using namespace std;
int main(){
    vector<long long> a(10);
    for(int i = 0; i < 10; i++){
        a[i] = ((long long)i + 1LL) * 2LL;
        cout<<a[i]<<" ";
    }
    getch();
    return 0;
}