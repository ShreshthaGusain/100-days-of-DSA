// Day 40 - Question 1: Heap Sort Using Max-Heap
// Close
// Implement Heap Sort using a Max Heap to sort an array in ascending order. 
//First build a max heap, then repeatedly extract the maximum element and place it at the end of the array.

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Restores the max-heap property for a subtree rooted at index i
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // 1. Build max heap (rearrange array)
    // We start from the last non-leaf node and go up to the root
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }

    // 2. Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root (maximum) to the end
        swap(&arr[0], &arr[i]);

        // Call maxHeapify on the reduced heap
        maxHeapify(arr, i, 0);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    heapSort(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1 ? "" : " "));
    }
    printf("\n");

    return 0;
}
