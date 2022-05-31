#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

void error(char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  vfprintf(stderr, fmt, ap);
  fprintf(stderr, "\n");
  exit(1);
}

int main(int argc, char **argv) {
  if (argc < 3)
    error("invalid argument number");
  
  int a, b;
  a = atoi(argv[1]);
  b = atoi(argv[2]);
  printf("befor XOR swap: %d, %d\n", a, b);

  // XOR swap
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
  printf("after XOR swap: %d, %d\n", a, b);

  /* ex.  */
  /* 2, 3 */

  /* binary */
  /*   a = 0010 */
  /*   b = 0011 */

  /*   a ^ b = 0001 */
  /*   b = 0011  */
  /*   b = a ^ b = 0010 */

  /*   a ^ b = 0001 */
  /*   b = 0010 */
  /*   a = a ^ b = 0011 */
  
  return 0;
}
