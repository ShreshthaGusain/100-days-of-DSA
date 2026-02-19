// Day 18 - Question 1: Rotate Array by K Positions
// Problem: Given an array of integers, rotate the array to the right by k positions.

// Input:
// - First line: integer n
// - Second line: n integers
// - Third line: integer k

// Output:
// - Print the rotated array

// Example:
// Input:
// 5
// 1 2 3 4 5
// 2

// Output:
// 4 5 1 2 3

#include <stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n, k;

    if (scanf("%d", &n) != 1) return 0;

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    k = k % n;
    
    if (k != 0) {
        reverse(arr, 0, n - 1);
        reverse(arr, 0, k - 1);
        reverse(arr, k, n - 1);
    }

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");

    return 0;
}

// 238. Product of Array Except Self
// Medium
// Hint
// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]
 

// Constraints:

// 2 <= nums.length <= 105
// -30 <= nums[i] <= 30
// The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    res[0] = 1; 
    for (int i = 1; i < numsSize; i++) {
        res[i] = res[i - 1] * nums[i - 1];
    }

    int suffixProduct = 1; 
    for (int i = numsSize - 1; i >= 0; i--) {
        res[i] = res[i] * suffixProduct;
        
        suffixProduct *= nums[i];
    }

    return res;
}

int main() {
    int nums[] = {1, 2, 3, 4};
    int n = 4;
    int returnSize;
    
    int* result = productExceptSelf(nums, n, &returnSize);
    
    printf("Output: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
