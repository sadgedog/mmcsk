#include <stdio.h>
#include <stdlib.h>

// ASCIIコード\007でベルが鳴る
// 黎明期のPCでは物理のベルがなっていた
int main(int argc, char **argv) {
  printf("\007");
  exit(0);
}
