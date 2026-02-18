// Day 16 - Question 1: Frequency Counter in Array
// Close
// Problem: Given an array of integers, count the frequency of each distinct element and print the result.

// Input:
// - First line: integer n (size of array)
// - Second line: n integers

// Output:
// - Print each element followed by its frequency in the format element:count

// Example:
// Input:
// 5
// 1 2 2 3 1

// Output:
// 1:2 2:2 3:1

#include <stdio.h>

int main() {
    int n;

    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    int visited[n]; 

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0; 
    }

    for (int i = 0; i < n; i++) {
        
        if (visited[i] == 1) {
            continue;
        }

        int count = 1;
 
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1; 
            }
        }

        printf("%d:%d ", arr[i], count);
    }

    printf("\n");
    return 0;
}

// 189. Rotate Array
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 
// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
// Example 2:

// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]
 

// Constraints:
// 1 <= nums.length <= 105
// -231 <= nums[i] <= 231 - 1
// 0 <= k <= 105

#include <stdio.h>
#include <stdlib.h>

void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    if (numsSize == 0) return;

    k = k % numsSize;
    if (k == 0) return;

    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}

int main() {
    int n, k;

    printf("Enter array size: ");
    if (scanf("%d", &n) != 1) return 0;
    
    int* nums = (int*)malloc(n * sizeof(int));

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter k (rotation steps): ");
    scanf("%d", &k);

    rotate(nums, n, k);

    printf("Rotated Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    free(nums);
    return 0;
}
