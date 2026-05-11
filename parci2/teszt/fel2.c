#include <stdbool.h>
#include <stdio.h>
#define M 4

int m[M][M];
bool op[M];

void printMAtrix() {
  printf("\n");
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void check(int row) {

  if (row == M) {
    printMAtrix();
    return;
  }

  for (int col = 0; col < M; col++) {
    if (!op[col]) {
      m[row][col] = 1;
      op[col] = true;
      check(row + 1);

      op[col] = false;
      m[row][col] = 0;
    }
  }
}

int main() {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      m[i][j] = 0;
    }
  }
  check(0);
  return 0;
}