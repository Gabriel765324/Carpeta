#include "bits/stdc++.h"
#include "conio.h"
using namespace std;
int main(){
    vector<long long> a = {1, 2, 3, 4, 5};
    long long s = 0;
    for(int i = 0; i < a.size(); i++) s += a[i];
    cout<<"La suma es "<<s<<".";
    getch();
    return 0;
}