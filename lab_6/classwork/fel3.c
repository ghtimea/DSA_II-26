#include <stdio.h>

int countEven(int n) {
  if (n == 0) {
    return 0;
  }

  int lastNr = n % 10;
  int count = 0;

  if (lastNr % 2 == 0) {
    count = 1;
  }
  return count + countEven(n / 10);
}

int main() {
  int n;

  printf("number: ");
  if (scanf("%d", &n) != 1) {
    printf("invalid input\n");
    return 1;
  }
  if (n == 0) {
    printf("number of even digits: 1\n");
  } else {
    if (n < 0)
      n = -n;

    int result = countEven(n);
    printf("number of even digits: %d\n", result);
  }

  return 0;
}