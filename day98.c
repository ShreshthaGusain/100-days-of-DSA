// Day 98 - Question 1: Merge Overlapping Intervals
// Close
// Problem: Given intervals, merge all overlapping ones.
// Sort first, then compare with previous.

#include <stdio.h>
#include <stdlib.h>

// Structure to represent an interval
typedef struct {
    int start;
    int end;
} Interval;

// Comparator to sort intervals by start time
int compareIntervals(const void* a, const void* b) {
    Interval* i1 = (Interval*)a;
    Interval* i2 = (Interval*)b;
    return i1->start - i2->start;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void mergeIntervals(Interval intervals[], int n) {
    if (n <= 0) return;

    // 1. Sort intervals based on start time
    qsort(intervals, n, sizeof(Interval), compareIntervals);

    // 2. Merge logic
    int index = 0; // Index of the last merged interval

    for (int i = 1; i < n; i++) {
        // If current interval overlaps with the merged one
        if (intervals[index].end >= intervals[i].start) {
            // Update end of merged interval
            intervals[index].end = max(intervals[index].end, intervals[i].end);
        } else {
            // No overlap, move to the next slot and update it
            index++;
            intervals[index] = intervals[i];
        }
    }

    // 3. Output merged intervals
    for (int i = 0; i <= index; i++) {
        printf("[%d, %d] ", intervals[i].start, intervals[i].end);
    }
    printf("\n");
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    Interval intervals[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    mergeIntervals(intervals, n);

    return 0;
}
