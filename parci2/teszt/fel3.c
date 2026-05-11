#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int start;
  int end;
} Interval;

int compare(const void *a, const void *b) {
  return ((Interval *)a)->start - ((Interval *)b)->start;
}

int main() {
  int n, m_target;
  if (scanf("%d %d", &n, &m_target) != 2)
    return 1;

  Interval intervals[n];
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &intervals[i].start, &intervals[i].end);
  }

  qsort(intervals, n, sizeof(Interval), compare);

  Interval result[n];
  int count = 0;
  int current_end = 0;
  int i = 0;
  int possible = 1;

  while (current_end < m_target) {
    int best_end = -1;
    int best_idx = -1;

    while (i < n && intervals[i].start <= current_end) {
      if (intervals[i].end > best_end) {
        best_end = intervals[i].end;
        best_idx = i;
      }
      i++;
    }

    if (best_idx == -1) {
      possible = 0;
      break;
    }

    result[count++] = intervals[best_idx];
    current_end = best_end;
  }

  if (possible && current_end >= m_target) {
    printf("%d\n", count);
    for (int j = 0; j < count; j++) {
      printf("(%d,%d) ", result[j].start, result[j].end);
    }
    printf("\n");
  } else {
    printf("Nem fedheto le a teljes szakasz.\n");
  }

  return 0;
}