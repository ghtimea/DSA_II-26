#include <stdio.h>

int main() {
  int money[] = {500, 100, 50, 20, 10, 5, 1};
  int n = sizeof(money) / sizeof(money[0]);

  int price, givenMoney, sum;

  printf("Kifizetendo osszeg: ");
  if (scanf("%d", &price) != 1)
    return 1;

  printf("Kapott penzmennyiseg: ");
  if (scanf("%d", &givenMoney) != 1)
    return 1;

  sum = givenMoney - price;

  if (sum < 0) {
    printf("Nem eleg!\n");
    return 1;
  }

  printf("\nVisszajaro: %d Lei\n", sum);

  for (int i = 0; i < n; i++) {
    if (sum >= money[i]) {
      int piece = sum / money[i];
      sum = sum % money[i];

      printf("%3d Lei: %d db\n", money[i], piece);
    }
  }

  return 0;
}