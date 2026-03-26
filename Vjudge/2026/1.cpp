#include "iostream"
#include "algorithm"
#include "vector"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ii pair<int, int>
#define ll long long
#define all(v) (v).begin(), (v).end()
#define F first
#define S second
#define vi vector<int>
#define el "\n"
#define mp make_pair
using namespace std;
const int nn = 2e5 + 22;
ll a[nn];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        double s = 0;
        forn(i, n){
            cin>>a[i];
            s += a[i];
        }
        if(n == 1 or n == 2){
            cout<<"-1\n";
            continue;
        }
        sort(a, a + n);
        ll Izq = 0, Der = s + 22, Res = Der;
        while(1){
            //cerr<<Izq<<" "<<Der<<el;
            ll Pro = (Izq + Der) / 2;
            if((s + (double)Pro) / (double)(n * 2) > a[n / 2]){
                Der = Pro - 1;
                Res = Pro;
            } else {
                Izq = Pro + 1;
            }
            if(Izq >= Der + 1) break;
        }
        cout<<((Res == s + 22) ? -1 : Res)<<el;
    }
    return 0;
}