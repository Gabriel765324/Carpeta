#include "bits/stdc++.h"
using namespace std;
void Resolver_1(long long _1, long long _2, long long _3){
    cout<<_1<<" "<<_3<<"\n";
}
void Resolver_2(long long _1, long long _2, long long _3){
    Resolver_1(_1, _3, _2);
    cout<<_1<<" "<<_3<<"\n";
    Resolver_1(_2, _1, _3);
}
void Resolver_3(long long _1, long long _2, long long _3){
    Resolver_2(_1, _3, _2);
    cout<<_1<<" "<<_3<<"\n";
    Resolver_2(_2, _1, _3);
}
void Resolver_4(long long _1, long long _2, long long _3){
    Resolver_3(_1, _3, _2);
    cout<<_1<<" "<<_3<<"\n";
    Resolver_3(_2, _1, _3);
}
void Resolver_5(long long _1, long long _2, long long _3){
    Resolver_4(_1, _3, _2);
    cout<<_1<<" "<<_3<<"\n";
    Resolver_4(_2, _1, _3);
}
void Resolver_6(long long _1, long long _2, long long _3){
    Resolver_5(_1, _3, _2);
    cout<<_1<<" "<<_3<<"\n";
    Resolver_5(_2, _1, _3);
}
void Resolver_7(long long _1, long long _2, long long _3){
    Resolver_6(_1, _3, _2);
    cout<<_1<<" "<<_3<<"\n";
    Resolver_6(_2, _1, _3);
}
void Resolver_8(long long _1, long long _2, long long _3){
    Resolver_7(_1, _3, _2);
    cout<<_1<<" "<<_3<<"\n";
    Resolver_7(_2, _1, _3);
}
void Resolver_9(long long _1, long long _2, long long _3){
    Resolver_8(_1, _3, _2);
    cout<<_1<<" "<<_3<<"\n";
    Resolver_8(_2, _1, _3);
}
void Resolver_10(long long _1, long long _2, long long _3){
    Resolver_9(_1, _3, _2);
    cout<<_1<<" "<<_3<<"\n";
    Resolver_9(_2, _1, _3);
}
void Resolver_11(long long _1, long long _2, long long _3){
    Resolver_10(_1, _3, _2);
    cout<<_1<<" "<<_3<<"\n";
    Resolver_10(_2, _1, _3);
}
void Resolver_12(long long _1, long long _2, long long _3){
    Resolver_11(_1, _3, _2);
    cout<<_1<<" "<<_3<<"\n";
    Resolver_11(_2, _1, _3);
}
void Resolver_13(long long _1, long long _2, long long _3){
    Resolver_12(_1, _3, _2);
    cout<<_1<<" "<<_3<<"\n";
    Resolver_12(_2, _1, _3);
}
void Resolver_14(long long _1, long long _2, long long _3){
    Resolver_13(_1, _3, _2);
    cout<<_1<<" "<<_3<<"\n";
    Resolver_13(_2, _1, _3);
}
void Resolver_15(long long _1, long long _2, long long _3){
    Resolver_14(_1, _3, _2);
    cout<<_1<<" "<<_3<<"\n";
    Resolver_14(_2, _1, _3);
}
void Resolver_16(long long _1, long long _2, long long _3){
    Resolver_15(_1, _3, _2);
    cout<<_1<<" "<<_3<<"\n";
    Resolver_15(_2, _1, _3);
}
int main(){
    long long n;
    cin>>n;
    long long Respuesta = 1;
    for(long long i = 0; i < n; i++) Respuesta *= 2;
    Respuesta--;
    cout<<Respuesta<<"\n";
    switch(n){
        case 1:
        Resolver_1(1, 2, 3);
        break;
        case 2:
        Resolver_2(1, 2, 3);
        break;
        case 3:
        Resolver_3(1, 2, 3);
        break;
        case 4:
        Resolver_4(1, 2, 3);
        break;
        case 5:
        Resolver_5(1, 2, 3);
        break;
        case 6:
        Resolver_6(1, 2, 3);
        break;
        case 7:
        Resolver_7(1, 2, 3);
        break;
        case 8:
        Resolver_8(1, 2, 3);
        break;
        case 9:
        Resolver_9(1, 2, 3);
        break;
        case 10:
        Resolver_10(1, 2, 3);
        break;
        case 11:
        Resolver_11(1, 2, 3);
        break;
        case 12:
        Resolver_12(1, 2, 3);
        break;
        case 13:
        Resolver_13(1, 2, 3);
        break;
        case 14:
        Resolver_14(1, 2, 3);
        break;
        case 15:
        Resolver_15(1, 2, 3);
        break;
        case 16:
        Resolver_16(1, 2, 3);
        break;
    }
}