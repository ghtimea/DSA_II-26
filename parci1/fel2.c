#include <stdbool.h>
#include <stdio.h>

bool guess_digit(int level, int correct, int low, int high) {
  if (level == 3) {
    printf("A végleges szám: %d\n", correct);
    return true;
  }
  printf("level = %d, correct = %d, low = %d, high = %d\n", level, correct, low,
         high);
  printf("\n");

  if (low > high) {
    return false;
  }
  if (high - low == 1) {
    if (guess_digit(level + 1, correct * 10 + low, 0, 9)) {
      return true;
    }
  }

  //---------------

  int guess = low + (high - low) / 2;

  int multiplier = 1;
  if (level == 0)
    multiplier = 100;
  if (level == 1)
    multiplier = 10;
  if (level == 2)
    multiplier = 1;

  int tipp = (correct * multiplier * 10) + (guess * multiplier);
  char valasz;

  //--------------
  printf(" %d ? (k / n / e): ", tipp);
  scanf(" %c", &valasz);

  // EGYENLO---------------------
  if (valasz == 'e') {
    if (guess_digit(level + 1, (tipp / multiplier), 0, 9)) {
      return true;
    }
    return false;
  }
  // KISEBB---------------------
  if (valasz == 'k') {
    if (guess_digit(level, correct, low, guess)) {
      return true;
    }
    // NAGYOBB--------------------
  } else if (valasz == 'n') {
    if (guess_digit(level, correct, guess, high)) {
      return true;
    }
  } else {
    printf("Kerlek 'k', 'n' vagy 'e'-t irj.\n");
    return guess_digit(level, correct, low, high);
  }

  return false;
}

int main() {
  printf("-------- START --------\n\n");
  printf("\n\nGondolj egy szamra 0 es 999 kozott!\n\n");
  printf("'k' (kisebb), 'n' (nagyobb), 'e' (egyenlo).\n\n");

  if (!guess_digit(0, 0, 0, 9)) {
    printf(
        "Ezt a sort sose szabad lasd. Ha ezt latod, akkor hazudtal nekem.\n");
  }

  return 0;
}