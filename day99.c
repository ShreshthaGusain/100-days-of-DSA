// Day 99 - Question 1: Car Fleet Calculation
// Close
// Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
// Sort cars by position in descending order and calculate time to reach target.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    double time;
} Car;

// Sort cars by position in descending order
int compareCars(const void* a, const void* b) {
    return ((Car*)b)->pos - ((Car*)a)->pos;
}

int main() {
    int target, n;
    if (scanf("%d %d", &target, &n) != 2) return 0;

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    int positions[n];
    int speeds[n];
    Car cars[n];

    for (int i = 0; i < n; i++) scanf("%d", &positions[i]);
    for (int i = 0; i < n; i++) scanf("%d", &speeds[i]);

    for (int i = 0; i < n; i++) {
        cars[i].pos = positions[i];
        cars[i].time = (double)(target - positions[i]) / speeds[i];
    }

    // Sort cars by position: closest to target first
    qsort(cars, n, sizeof(Car), compareCars);

    int fleets = 0;
    double currentTimeLimit = 0.0;

    for (int i = 0; i < n; i++) {
        // If this car takes more time than the current fleet leader,
        // it starts a new fleet because it can't catch up.
        if (cars[i].time > currentTimeLimit) {
            fleets++;
            currentTimeLimit = cars[i].time;
        }
    }

    printf("%d\n", fleets);

    return 0;
}
