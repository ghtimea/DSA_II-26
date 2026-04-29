#include <stdbool.h>
#include <stdio.h>

bool guess(int low, int high) {
  if (low > high) {
    return false;
  }

  int tipp = low + (high - low) / 2;
  char valasz;

  printf(" %d ? (k / n / e): ", tipp);
  scanf(" %c", &valasz);

  if (valasz == 'e') {
    printf("A helyes valasz: %d\n", tipp);
    return true;
  }

  if (valasz == 'k') {
    if (guess(low, tipp - 1)) {
      return true;
    }
  } else if (valasz == 'n') {
    if (guess(tipp + 1, high)) {
      return true;
    }
  } else {
    printf("Kerlek 'k', 'n' vagy 'e'-t irj.\n");
    return guess(low, high);
  }

  return false;
}

int main() {
  printf("Gondolj egy szamra 1 es 100 kozott!\n");
  printf("'k' (kisebb), 'n' (nagyobb), 'e' (egyenlo).\n\n");

  if (!guess(1, 100)) {
    printf("Ezt a sort sose szabad lasd. Ha ezt latod akkor hazudtal nekem.\n");
  }

  return 0;
}