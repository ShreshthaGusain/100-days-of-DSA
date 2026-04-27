// Day 75 - Question 1: Largest Subarray with Zero Sum
// Close
// Problem Statement
// Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

// Input Format
// An integer array arr[].

// Output Format
// Print the length of the longest subarray with sum equal to zero.

// Sample Input
// 15 -2 2 -8 1 7 10 23

// Sample Output
// 5

// Explanation
// The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int maxLen(vector<int>& arr) {
    unordered_map<int, int> first_occurrence;
    int sum = 0;
    int maxLength = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        // Case 1: Prefix sum itself is 0
        if (sum == 0) {
            maxLength = i + 1;
        }

        // Case 2: Prefix sum has been seen before
        if (first_occurrence.find(sum) != first_occurrence.end()) {
            // Calculate length between current index and first occurrence
            int currentLength = i - first_occurrence[sum];
            maxLength = max(maxLength, currentLength);
        } else {
            // Store only the first occurrence to maximize the subarray length
            first_occurrence[sum] = i;
        }
    }

    return maxLength;
}

int main() {
    int val;
    vector<int> arr;
    // Reading input until EOF or non-integer
    while (cin >> val) {
        arr.push_back(val);
    }

    cout << maxLen(arr) << endl;
    return 0;
}
