#include "bits/stdc++.h"
using namespace std;
vector<string> a;
int f = 0;
bool buscar_h(int g, int h, string i){
    if(f == i.size()) return 1;
    if(g == a.size() or h == a[0].size()){
        return 0;
    }
    if(g == -1 or h == -1){
        return 0;
    }
    //cout<<"Horizontal "<<g<<" "<<h<<" es "<<a[g][h]<<"\n";
    if(a[g][h] == i[f]){
        f++;
        return buscar_h(g, h + 1, i);
    } else {
        return 0;
    }
}
bool buscar_v(int g, int h, string i){
    if(f == i.size()) return 1;
    if(g == a.size() or h == a[0].size()){
        return 0;
    }
    if(g == -1 or h == -1){
        return 0;
    }
    //cout<<"Vertical "<<g<<" "<<h<<" es "<<a[g][h]<<"\n";
    if(a[g][h] == i[f]){
        f++;
        return buscar_v(g + 1, h, i);
    } else {
        return 0;
    }
}
bool buscar_h_(int g, int h, string i){
    if(f == i.size()) return 1;
    if(g == a.size() or h == a[0].size()){
        return 0;
    }
    if(g == -1 or h == -1){
        return 0;
    }
    //cout<<"Horizontal "<<g<<" "<<h<<" es "<<a[g][h]<<"\n";
    if(a[g][h] == i[f]){
        f++;
        return buscar_h_(g, h - 1, i);
    } else {
        return 0;
    }
}
bool buscar_v_(int g, int h, string i){
    if(f == i.size()) return 1;
    if(g == a.size() or h == a[0].size()){
        return 0;
    }
    if(g == -1 or h == -1){
        return 0;
    }
    //cout<<"Vertical "<<g<<" "<<h<<" es "<<a[g][h]<<"\n";
    if(a[g][h] == i[f]){
        f++;
        return buscar_v_(g - 1, h, i);
    } else {
        return 0;
    }
}
bool buscar_d(int g, int h, string i){
    if(f == i.size()) return 1;
    if(g == a.size() or h == a[0].size()){
        return 0;
    }
    if(g == -1 or h == -1){
        return 0;
    }
    //cout<<"Diagonal "<<g<<" "<<h<<" es "<<a[g][h]<<"\n";
    if(a[g][h] == i[f]){
        f++;
        return buscar_d(g + 1, h + 1, i);
    } else {
        return 0;
    }
}
bool buscar_d_(int g, int h, string i){
    if(f == i.size()) return 1;
    if(g == a.size() or h == a[0].size()){
        return 0;
    }
    if(g == -1 or h == -1){
        return 0;
    }
    //cout<<"Diagonal "<<g<<" "<<h<<" es "<<a[g][h]<<"\n";
    if(a[g][h] == i[f]){
        f++;
        return buscar_d_(g - 1, h - 1, i);
    } else {
        return 0;
    }
}
bool buscar_d__(int g, int h, string i){
    if(f == i.size()) return 1;
    if(g == a.size() or h == a[0].size()){
        return 0;
    }
    if(g == -1 or h == -1){
        return 0;
    }
    //cout<<"Diagonal "<<g<<" "<<h<<" es "<<a[g][h]<<"\n";
    if(a[g][h] == i[f]){
        f++;
        return buscar_d__(g - 1, h + 1, i);
    } else {
        return 0;
    }
}
bool buscar_d___(int g, int h, string i){
    if(f == i.size()) return 1;
    if(g == a.size() or h == a[0].size()){
        return 0;
    }
    if(g == -1 or h == -1){
        return 0;
    }
    //cout<<"Diagonal "<<g<<" "<<h<<" es "<<a[g][h]<<"\n";
    if(a[g][h] == i[f]){
        f++;
        return buscar_d___(g + 1, h - 1, i);
    } else {
        return 0;
    }
}
void buscar(string b){
    int d = 0;
    int e = 0;
    while(d < a.size()){
        e = 0;
        while(e < a[d].size()){
            //cout<<d<<" "<<e<<" es "<<a[d][e]<<"\n";
            f = 0;
            if(a[d][e] == b[f]){
                //cout<<"Buscando\n";
                f = 0;
                bool j = buscar_h(d, e, b);
                if(j == 1){
                    cout<<"("<<d<<", "<<e<<") -H";
                    return;
                }
                f = 0;
                j = buscar_v(d, e, b);
                if(j == 1){
                    cout<<"("<<d<<", "<<e<<") -V";
                    return;
                }
                f = 0;
                j = buscar_h_(d, e, b);
                if(j == 1){
                    cout<<"("<<d<<", "<<e<<") -H";
                    return;
                }
                f = 0;
                j = buscar_v_(d, e, b);
                if(j == 1){
                    cout<<"("<<d<<", "<<e<<") -V";
                    return;
                }
                f = 0;
                j = buscar_d(d, e, b);
                if(j == 1){
                    cout<<"("<<d<<", "<<e<<") -D";
                    return;
                }
                f = 0;
                j = buscar_d_(d, e, b);
                if(j == 1){
                    cout<<"("<<d<<", "<<e<<") -D";
                    return;
                }
                f = 0;
                j = buscar_d__(d, e, b);
                if(j == 1){
                    cout<<"("<<d<<", "<<e<<") -D";
                    return;
                }
                f = 0;
                j = buscar_d___(d, e, b);
                if(j == 1){
                    cout<<"("<<d<<", "<<e<<") -D";
                    return;
                }
            }
            e++;
        }
        d++;
    }
}
int main(){
    long long L_neas;
    cin>>L_neas;
    while(L_neas--){
        string b;
        cin>>b;
        a.push_back(b);
    }
    /*long long aaa = 0;
    while(aaa != a.size()){
        cout<<a[aaa]<<"\n";
        aaa++;
    }*/
    string Por_encontar;
    while(cin>>Por_encontar){
        buscar(Por_encontar);
        cout<<"\n";
    }
    return 0;
}