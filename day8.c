// Day 8 - Question 1: Compute Power Using Recursion
// Problem: Given integers a and b, compute a^b using recursion without using pow() function.

// Input:
// - Two space-separated integers a and b
// Output:
// - Print a raised to power b

// Example:
// Input:
// 2 5
// Output:
// 32

// Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32

#include <stdio.h>

long long power(int a, int b) {
    if (b == 0)
        return 1;
    return a * power(a, b - 1);
}

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    printf("%lld", power(a, b));
    
    return 0;
}

// 231. Power of Two
// Given an integer n, return true if it is a power of two. Otherwise, return false.
// An integer n is a power of two, if there exists an integer x such that n == 2x.

// Example 1:

// Input: n = 1
// Output: true
// Explanation: 20 = 1
// Example 2:

// Input: n = 16
// Output: true
// Explanation: 24 = 16
// Example 3:

// Input: n = 3
// Output: false
 
// Constraints:

// -231 <= n <= 231 - 1

#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    if (n == 1) return true; 
    if (n % 2 != 0) return false; 
    return isPowerOfTwo(n / 2);
}

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    if (isPowerOfTwo(n)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
