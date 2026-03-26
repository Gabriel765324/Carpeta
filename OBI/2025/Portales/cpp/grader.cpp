#include "portales.h"
#include <cassert>
#include <cstdio>
#include <iostream>

using namespace std;

const int MAX_N = 1e5;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int N;
  cin >> N;
  assert(N > 0 && N <= MAX_N);

  vector<int> portales(N);
  for (auto &v:portales) {
    int a;
    cin >> a;
    assert(1 <= a && a <= 1e9);
    v = a;
  }

  auto result = portales_magicos(N, portales);


  for (int i = 0; i < (int)result.size(); i++) {
    if (i) {
      cout << " ";
    }
    cout << result[i];
  }

  return 0;
}
