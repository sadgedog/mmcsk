#include <stdio.h>

void no_void() {
  printf("no_void(12, 34) : compilable but warning\n");
}

void ex_void(void) {
  printf("ex_void(void) : of course compilable\n");
}

int main(void) {
  ex_void();
  no_void(12, 34);
  return 0;
}
