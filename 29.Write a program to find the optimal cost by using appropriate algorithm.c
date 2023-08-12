#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Interval {
    int start;
    int end;
};

int compareIntervals(const void *a, const void *b) {
    return ((struct Interval *)a)->end - ((struct Interval *)b)->end;
}

void intervalScheduling(struct Interval intervals[], int n) {
    qsort(intervals, n, sizeof(struct Interval), compareIntervals);

    int selectedIntervals = 1;
    int lastSelected = 0;

    for (int i = 1; i < n; i++) {
        if (intervals[i].start >= intervals[lastSelected].end) {
            selectedIntervals++;
            lastSelected = i;
        }
    }

    printf("Maximum non-overlapping intervals that can be scheduled: %d\n", selectedIntervals);
}

int main() {
    int n;

    printf("Enter the number of intervals: ");
    scanf("%d", &n);

    struct Interval intervals[n];

    printf("Enter the start and end times of each interval:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    intervalScheduling(intervals, n);

    return 0;
}
