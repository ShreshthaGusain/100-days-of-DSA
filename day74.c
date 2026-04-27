// Day 74 - Question 1: Winner of an Election
// Close
// Problem Statement
// Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

// Input Format
// First line contains an integer n representing number of votes.
// Second line contains n space-separated strings representing candidate names.

// Output Format
// Print the name of the winning candidate followed by the number of votes received.

// Sample Input
// 13
// john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

// Sample Output
// john 4

// Explanation
// Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Standard comparator for qsort
int compare(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main() {
    int n;
    scanf("%d", &n);
    char** votes = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        votes[i] = malloc(100 * sizeof(char));
        scanf("%s", votes[i]);
    }

    // Sort names lexicographically
    qsort(votes, n, sizeof(char*), compare);

    char* winner = votes[0];
    int maxVotes = 0, currentVotes = 1;

    for (int i = 1; i <= n; i++) {
        // If name changes or we reach end, check counts
        if (i == n || strcmp(votes[i], votes[i-1]) != 0) {
            if (currentVotes > maxVotes) {
                maxVotes = currentVotes;
                winner = votes[i-1];
            }
            currentVotes = 1;
        } else {
            currentVotes++;
        }
    }

    printf("%s %d\n", winner, maxVotes);
    return 0;
}
