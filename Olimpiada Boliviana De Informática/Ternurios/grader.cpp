#include "ternurios.h"
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

  vector<int> ternurios(N);
  for (auto &v:ternurios) {
    int a;
    cin >> a;
    assert(-1000 <= a && a <= 1000);
    v = a;
  }

  int result = max_ternurios(N, ternurios);


  cout << result << '\n';

  return 0;
}
