// Day 17 - Question 1: Find Maximum and Minimum Element
// Close
// Problem: Write a program to find the maximum and minimum values present in a given array of integers.

// Input:
// - First line: integer n
// - Second line: n integers

// Output:
// - Print the maximum and minimum elements

// Example:
// Input:
// 6
// 3 5 1 9 2 8

// Output:
// Max: 9
// Min: 1

#include <stdio.h>

int main() {
    int n;

    // 1. Get the size of the array
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];

    // 2. Read the elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Initialize Max and Min with the first element
    int max = arr[0];
    int min = arr[0];

    // 4. Single pass to find both
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // 5. Output result in the required format
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}

// 53. Maximum Subarray
// Medium
// Topics
// premium lock icon
// Companies
// Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.
// Example 2:

// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.
// Example 3:

// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104

#include <stdio.h>
#include <stdlib.h>

// The LeetCode Function
int maxSubArray(int* nums, int numsSize) {
    // Initialize max_sum with the first element
    int max_sum = nums[0];
    int current_sum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        // Step 1: Decide whether to extend the existing subarray or start a new one
        // If current_sum is negative, it's better to just start fresh with nums[i]
        if (current_sum < 0) {
            current_sum = nums[i];
        } else {
            current_sum += nums[i];
        }

        // Step 2: Update the global maximum if the current subarray is better
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    return max_sum;
}

// Main function for local testing
int main() {
    int n;

    // 1. Get array size
    printf("Enter array size: ");
    if (scanf("%d", &n) != 1) return 0;

    int* nums = (int*)malloc(n * sizeof(int));

    // 2. Get array elements
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // 3. Solve and Print
    int result = maxSubArray(nums, n);
    printf("Maximum Subarray Sum: %d\n", result);

    // Clean up
    free(nums);
    return 0;
}
