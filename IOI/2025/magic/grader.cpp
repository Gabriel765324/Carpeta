#include "magic.h"
#include <cassert>
#include <cstdio>
#include <cstdlib>
 
int main() {
  int N;
  assert(1 == scanf("%d", &N));

  std::vector<int> P(N, 0);
  for (int i = 0; i < N; i++) {
    assert(1 == scanf("%d", &P[i]));
    printf("%d ", P[i]);
  }
  printf("\n");
  fclose(stdin);

  std::vector<int> Q = Alicia(P);

  

  std::vector<int> B = Beatriz(Q);

  int T = (int)B.size();
  /*int S = (int)Q.size();
  printf("%d\n", S);
  for (int i = 0; i < S; i++) {
    printf("%d%c", Q[i], " \n"[i == S - 1]);
  }*/
  printf("%d\n", T);
  for (int i = 0; i < T; i++) {
    printf("%d%c", B[i], " \n"[i == T - 1]);
  }
  bool Bien = 1;
  for(int i = 0; i < T; i++){
    if(B[i] != P[i]){
      printf("Bien mal. %d %d %d\n", i, B[i], P[i]);
      Bien = 0;
      break;
    }
  }
  if(Bien) printf("Bien.\n");
  fclose(stdout);

  return 0;
}
