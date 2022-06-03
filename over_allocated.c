#include <stdlib.h>
#include <stdio.h>

// https://www.reddit.com/r/ProgrammerHumor/comments/jtnrlk/everyone_loves_pointers_right/

#define ONE_GB (1024 * 1024 * 1024)
#define PAGESIZE (4 * 1024)
#define MAX_GB (100)

// 意図的にメモリリークを起こしているので注意
// 実行しないでください
int main() {
  static char *ptrs[MAX_GB];
  int sum = 0;
  int i;
  
  for (i = 0; i < MAX_GB; i++) {
    void *p = malloc(ONE_GB);
    if (p == NULL)
      break;
    ptrs[i] = (char *)p;
    sum++;
  }

  printf("allocated memory %d GB", sum);
  fgetc(stdin);

  for (i = 0; i < sum; i++) {
    int j;
    for (j = 0; j < ONE_GB; j+=PAGESIZE) {
      ptrs[i][j] = 0;
    }
  }

  return 0;
}
