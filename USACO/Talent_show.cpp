#include "stdio.h"
#include "vector"
using namespace std;
int main(){
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
    int n, w;
    scanf("%d %d", &n, &w);
    vector<int> Mayor_suma(1000001, 0);
    vector< pair<int, int> > Vacas(n);
    for(int i = 0; i < n; i++) scanf("%d %d", &Vacas[i].first, &Vacas[i].second);
    int Mayor = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1000000; j >= Vacas[i].first; j--){
            if(Mayor_suma[j - Vacas[i].first] > 0 or j - Vacas[i].first == 0){
                Mayor_suma[j] = max(Mayor_suma[j], Mayor_suma[j - Vacas[i].first] + Vacas[i].second);
                if(j >= w) Mayor = max(Mayor, Mayor_suma[j] * 1000 / j);
            }
        }
    }
    printf("%d", Mayor);
    return 0;
}
/*
Mal:
3 15
20 21
30 31
1 15
Da: 1483
Debería dar: 1714 al menos.
*/