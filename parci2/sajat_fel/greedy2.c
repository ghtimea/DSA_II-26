#include <stdio.h>

int main() {
  int money[] = {500, 100, 50, 20, 10, 5, 1};
  int n = sizeof(money) / sizeof(money[0]);

  int sum;

  if (sum < 0) {
    printf("Pozitiv kell legyen!\n");
    return 1;
  }

  if (scanf("%d", &sum) != 1)
    return 1;

  for (int i = 0; i < n; i++) {
    if (sum >= money[i]) {
      int piece = sum / money[i];
      sum = sum % money[i];

      printf("%3d Lei: %d db\n", money[i], piece);
    }
  }

  return 0;
}