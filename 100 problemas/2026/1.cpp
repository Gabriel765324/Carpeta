#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    cout<<((400 % n == 0) ? 400 / n : -1);
    return 0;
}