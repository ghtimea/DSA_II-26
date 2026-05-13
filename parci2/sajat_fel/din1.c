#include <stdio.h>

int main() {
  int n;

  if (scanf("%d", &n) != 1)
    return 1;

  if (n < 0) {
    printf("Nem lehet negativ!\n");
    return 1;
  }

  long f[n + 2];

  f[0] = 0;
  f[1] = 1;
  printf("%ld ", f[1]);

  for (int i = 2; i <= n; i++) {
    f[i] = f[i - 1] + f[i - 2];
    printf("%ld ", f[i]);
  }

  printf("\n%d. Fibonacci szam: %ld\n", n, f[n]);

  return 0;
}