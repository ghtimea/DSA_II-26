#include <stdio.h>
#include <string.h>

void find(char *str, char *result, int *used, int level, int n) {
  if (level == n) {
    result[n] = '\0';
    printf("%s\n", result);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      used[i] = 1;
      result[level] = str[i];

      find(str, result, used, level + 1, n);

      used[i] = 0;
    }
  }
}

int main() {
  char str[100];
  printf("Szó: ");
  scanf("%s", str);

  int n = strlen(str);
  char result[n + 1];
  int used[n];

  for (int i = 0; i < n; i++)
    used[i] = 0;

  printf("Anagrammák:\n");
  find(str, result, used, 0, n);

  return 0;
}