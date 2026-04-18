// Day 60 - Question 1: Validate Min-Heap
// Close
// Problem Statement:
// Check whether a given binary tree satisfies the Min-Heap property.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal

// Output Format:
// - Print YES if valid Min-Heap, otherwise NO

// Example:
// Input:
// 7
// 1 3 5 7 9 8 10

// Output:
// YES

// Explanation:
// Each parent node must be smaller than its children.

#include <stdio.h>
#include <stdlib.h>

/**
 * Logic:
 * In a Min-Heap represented as an array:
 * For a node at index i:
 * - Left child is at 2*i + 1
 * - Right child is at 2*i + 2
 */
const char* checkMinHeap(int arr[], int n) {
    // We only need to check nodes that have at least one child.
    // These nodes exist up to index (n-2)/2.
    for (int i = 0; i <= (n - 2) / 2; i++) {
        
        // Check Left Child
        int left = 2 * i + 1;
        if (left < n && arr[i] > arr[left]) {
            return "NO";
        }

        // Check Right Child
        int right = 2 * i + 2;
        if (right < n && arr[i] > arr[right]) {
            return "NO";
        }
    }
    return "YES";
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    // Handle empty tree or single node
    if (n <= 0) {
        return 0;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Special case for NULL nodes (-1) if the input includes them
    // Most Heap problems assume a complete array, but if -1 is present,
    // the logic slightly changes. Assuming standard heap array here.
    
    printf("%s\n", checkMinHeap(arr, n));

    free(arr);
    return 0;
}
