#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;

void outq(int q[N]) {
    for (int i = 0; i < N; i++) {
      printf("%d ", q[i]);
    }
    printf("\n");
}

void change(int board[N][N], int i, int j, int d) {
  // 縦横を変える
  for (int k = 0; k < N; k++) {
    board[i][k] += d;
    board[k][j] += d;
  }
  // 斜め
  if (i > j) {
    for (int k = 0; k < N-(i-j); k++) {
      board[k+(i-j)][k] += d;
    }
  } else {
    for (int k = 0; k < N-(j-i); k++) {
      board[k][k+(j-i)] += d;
    }
  }
  if (i+j < N) {
    for (int k = 0; k <= i+j; k++) {
      board[i+j-k][k] += d;
    }
  } else {
    for (int k = i+j-N+1; k < N; k++) {
      board[i+j-k][k] += d;
    }
  }
}

void setq(int q[N], int board[N][N], int i) {
  if (i == N) {
    outq(q);
    return;
  }
  for (int j = 0; j < N; j++) {
    if (board[i][j] == 0) {
      q[i] = j;
      change(board, i, j, 1);
      setq(q, board, i+1);
      change(board, i, j, -1);
    }
  }
}

void solver() {
  int q[N];
  int board[N][N];
  memset(board, 0, sizeof(board));
  setq(q, board, 0);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("invalid argument number\n");
  }
  N = atoi(argv[1]);
  solver();
  return 0;
}
