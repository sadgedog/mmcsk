#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 2048

int main(int argc , char **argv) {
  int i;
  int fd;
  unsigned char buf[BUFFER_SIZE];
  int n;


  if (argc < 2) {
    fprintf(stderr, "%s: file name not given\n", argv[0]);
    exit(1);
  }

  for (i = 1; i < argc; i++) {
    char *path = argv[1];
    fd = open(path, O_RDONLY);
    if (fd < 0)
      printf("%s\n", path);
    for (;;) {
      n = read(fd, buf, sizeof buf);
      if (n < 0) {
        printf("%s\n", path);
        exit(1);
      }
      if (n == 0)
        break;
      if (write(STDOUT_FILENO, buf, n) < 0) {
        printf("%s\n", path);
        exit(1);
      }
    }
    if (close(fd) < 0) {
      printf("%s\n", path);
      exit(1);
    }
  }
  return 0;
}
