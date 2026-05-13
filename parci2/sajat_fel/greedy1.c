#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) { return (*(int *)b - *(int *)a); }

int main() {
  int nums[5];
  int goal = 10;
  int currentSum = 0;

  printf("5 numbers:\n");
  for (int i = 0; i < 5; i++) {
    scanf("%d", &nums[i]);
  }

  qsort(nums, 5, sizeof(int), comp);

  printf("\nUsed numbers: ");
  for (int i = 0; i < 5; i++) {
    currentSum += nums[i];
    printf("%d ", nums[i]);

    if (currentSum >= goal) {
      break;
    }
  }

  if (currentSum >= goal) {
    printf("\nSum: %d", currentSum);
  } else {
    printf("\nThe numebrs are too small\n");
  }

  return 0;
}