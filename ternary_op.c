#include <stdio.h>

int main() {
  int a = 0;
  int b = 12;
  int c = 24;

  // ternary op
  int r = a > b ? a : b;
  printf("%d\n", r);

  // nest
  r = a > b ? a > c ? a : b : b > c ? b : c;
  printf("%d\n", r);
}
