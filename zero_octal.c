#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// https://stackoverflow.com/questions/6895522/is-0-a-decimal-literal-or-an-octal-literal

int main() {
  int foo[3] = {0, 1, 2};
  printf("%p\n", foo);
  printf("%p\n", foo+1);
  printf("%p\n", foo+2);
  
}
