#include <stdlib.h>
#include <stdio.h>

#define ONE_GB (1024 * 1024 * 1024)
// mallocでアロケートできる限界を知る
// この段階ではアロケートしているだけでメモリリークは起きない
int main() {
  int sum = 0;
  for (;;) {
    void *p = malloc(ONE_GB);
    if (p == NULL)
      break;
    sum++;
  }

  printf("allocated memory %d GB\n", sum);
  
  return 0;
}
