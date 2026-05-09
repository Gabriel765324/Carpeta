#include <algorithm>
#include <vector>
#include <iostream>

#define forn(i, n) for(int i = 0; i < int(n); i++)

using namespace std;

int main(){
    int n, d; cin >> n >> d;
    vector<int> arr(n, 0);
    forn(i, d){
        int k; cin >> k;
        forn(j, k) arr[j]++;
        sort(begin(arr), begin(arr)+k);
    }
    sort(begin(arr), end(arr));
    cout << arr.back() << endl;
}