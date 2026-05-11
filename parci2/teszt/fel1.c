#include <stdio.h>
#include <stdlib.h>

int binarySearchRecursive(int arr[], int left, int right, int target) {
  if (left > right) {
    return -8;
  }

  int mid = left + (right - left) / 2;

  if (arr[mid] == target) {
    return mid;

  } else if (arr[mid] > target) {
    return binarySearchRecursive(arr, left, mid - 1, target);

  } else {
    return binarySearchRecursive(arr, mid + 1, right, target);
  }
}

int main() {
  FILE *f = fopen("adatok.txt", "r");
  if (f == NULL)
    return 1;

  int n, target;
  fscanf(f, "%d", &n);

  int v[n];
  for (int i = 0; i < n; i++) {
    fscanf(f, "%d", &v[i]);
  }
  fclose(f);

  printf("Keresett elem: ");
  scanf("%d", &target);

  int result = binarySearchRecursive(v, 0, n - 1, target);

  printf("%d\n", result);

  return 0;
}
