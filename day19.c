// Day 19 - Question 1: Pair Sum Closest to Zero
// Close
// Problem: Given an array of integers, find two elements whose sum is closest to zero.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the pair of elements whose sum is closest to zero

// Example:
// Input:
// 5
// 1 60 -10 70 -80

// Output:
// -10 1

// Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    
    if (scanf("%d", &n) != 1 || n < 2) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int min_abs_sum = INT_MAX;
    int pair1, pair2;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(min_abs_sum)) {
            min_abs_sum = sum;
            pair1 = arr[left];
            pair2 = arr[right];
        }

        if (sum == 0) break;

        if (sum < 0) {
            left++; 
        } else {
            right--; 
        }
    }

    printf("%d %d\n", pair1, pair2);

    return 0;
}

// 918. Maximum Sum Circular Subarray
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

// A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

// A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

// Example 1:

// Input: nums = [1,-2,3,-2]
// Output: 3
// Explanation: Subarray [3] has maximum sum 3.
// Example 2:

// Input: nums = [5,-3,5]
// Output: 10
// Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
// Example 3:

// Input: nums = [-3,-2,-3]
// Output: -2
// Explanation: Subarray [-2] has maximum sum -2.
 

// Constraints:

// n == nums.length
// 1 <= n <= 3 * 104
// -3 * 104 <= nums[i] <= 3 * 104

#include <stdio.h>
#include <stdlib.h>

int maxSubarraySumCircular(int* nums, int numsSize) {
    int totalSum = 0;
    int maxSum = nums[0], currentMax = 0;
    int minSum = nums[0], currentMin = 0;

    for (int i = 0; i < numsSize; i++) {

        currentMax += nums[i];
        if (currentMax > maxSum) maxSum = currentMax;
        if (currentMax < 0) currentMax = 0;

        currentMin += nums[i];
        if (currentMin < minSum) minSum = currentMin;
        if (currentMin > 0) currentMin = 0;

        totalSum += nums[i];
    }

    if (maxSum < 0) {
        return maxSum;
    }

    int circularSum = totalSum - minSum;
    return (maxSum > circularSum) ? maxSum : circularSum;
}

int main() {
    int n;
    printf("Enter size of circular array: ");
    if (scanf("%d", &n) != 1) return 0;

    int* nums = (int*)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = maxSubarraySumCircular(nums, n);
    printf("Maximum Circular Subarray Sum: %d\n", result);

    free(nums);
    return 0;
}
