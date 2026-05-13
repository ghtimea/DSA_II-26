#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int start;
  int end;
} Interval;

int compare(const void *a, const void *b) {
  Interval *i1 = (Interval *)a;
  Interval *i2 = (Interval *)b;
  if (i1->start != i2->start)
    return i1->start - i2->start;
  return i2->end - i1->end; // Secondary sort: longer intervals first
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
  int count = 0, current_end = 0, i = 0, possible = 1;

  while (current_end < m_target) {
    int best_end = current_end;
    int best_idx = -1;

    // Check all intervals that could continue from the current_end
    // We don't increment i permanently in a way that loses data
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

    // Optimization: If we found an interval that covers the target, we stop.
    if (current_end >= m_target)
      break;
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