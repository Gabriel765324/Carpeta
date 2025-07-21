#include "memory.h"
#include "grader.h"
#include "bits/stdc++.h"
using namespace std;
void play(){
    vector< vector<long long> > a(25);
    long long b = 1;
    while(b <= 50){
        char c = faceup(b);
        char d = faceup(b + 1);
        a[c - 65].push_back(b);
        a[d - 65].push_back(b + 1);
        b++;
        b++;
    }
    b = 0;
    while(b != 25){
        faceup(a[b][0]);
        faceup(a[b][1]);
        b++;
    }
}