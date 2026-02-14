// Day 6 - Question 1: Remove Duplicates from Sorted Array
// Close
// Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (sorted array)

// Output:
// - Print unique elements only, space-separated

// Example:
// Input:
// 6
// 1 1 2 2 3 3

// Output:
// 1 2 3

// Explanation: Keep first occurrence of each element: 1, 2, 3

#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[k]) {
            k++;
            arr[k] = arr[i];
        }
    }

    for (int i = 0; i <= k; i++) {
        printf("%d", arr[i]);
        if (i < k) printf(" ");
    }
    printf("\n");

    return 0;
}

//Q2- 283. Move Zeroes

// Hint

// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

// Example 1:
// Input: nums = [0,1,0,3,12]Output: [1,3,12,0,0]

// Example 2:
// Input: nums = [0]Output: [0]

// Constraints:

// 1 <= nums.length <= 104
// -231 <= nums[i] <= 231 - 1

#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            int temp = nums[k];
            nums[k] = nums[i];
            nums[i] = temp;
            k++;
        }
    }
}

int main() {
    int nums[] = {0, 1, 0, 3, 12};
    int size = 5;
    
    moveZeroes(nums, size);
    
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", nums[i]);
        if (i < size - 1) printf(",");
    }
    printf("]\n");
    
    return 0;
}
