#include <stdio.h>
#include <stdlib.h>

int a[3] = {1,2,3};

// a == &a[0]
// a+1 == &a[1]
// *(a+1) = *(&a[1]) == a[1]

// 1+a == &a[1]
// a[1] == 1[a]

int main() {
  printf("value of a[1] : %d\n", a[1]);
  printf("value of *(a+1) : %d\n", *(a+1));
  printf("value of 1[a] : %d\n", 1[a]);
}
