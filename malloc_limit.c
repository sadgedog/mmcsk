#include <stdlib.h>
#include <stdio.h>

// mallocでアロケートできる限界を知る
// 実際のメモリより多くの容量をアロケートできる
// この段階ではアロケートしているだけでメモリリークは起きない
int main() {
  // 1GB
  int gb = 1024 * 1024 * 1024;
  // allocated memory size
  int sum = 0;
  for (;;) {
    void *p = malloc(gb);
    if (p == NULL)
      break;
    sum++;
  }
  
  printf("allocated memory %d GB\n", sum);
  
  return 0;
}
