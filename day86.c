// Day 86 - Question 1: Square Root using Binary Search
// Close
// Problem: Find the integer square root of a given non-negative integer using Binary Search. 
//The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.

// Input:
// - First line: an integer n

// Output:
// - Print the integer square root of n

// Examples:
// Input:
// 64

// Output:
// 8

// Input:
// 20

// Output:
// 4

// Input:
// 1

// Output:
// 1

// Explanation:
// Binary Search is applied on the range 0 to n. At each step, the middle value is squared and compared with n.
//If mid * mid equals n, mid is the square root. If mid * mid is less than n, search continues in the right half; otherwise, in the left half. 
//The final answer is the largest integer whose square does not exceed n.


#include <stdio.h>

long long integerSquareRoot(long long n) {
    if (n < 2) return n;

    long long low = 0, high = n;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long square = mid * mid;

        if (square == n) {
            return mid; // Exact square root found
        } else if (square < n) {
            ans = mid;      // Current mid is a candidate
            low = mid + 1;  // Try for a larger value
        } else {
            high = mid - 1; // Too high, move left
        }
    }
    return ans;
}

int main() {
    long long n;
    if (scanf("%lld", &n) != 1) return 0;

    printf("%lld\n", integerSquareRoot(n));

    return 0;
}
