/*Q1-

Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)*/

#include <stdio.h>

int main() {
    int n, k, found = 0, c = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);
    for (int i = 0; i < n; i++) {
        c++;
        if (arr[i] == k) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", c);
    return 0;
}

/*Q2-

You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element.

Examples:

Input: arr[] = [1, 2, 3, 5]
Output: 4
Explanation: All the numbers from 1 to 5 are present except 4.
Input: arr[] = [8, 2, 4, 5, 3, 7, 1]
Output: 6
Explanation: All the numbers from 1 to 8 are present except 6.
Input: arr[] = [1]
Output: 2
Explanation: Only 1 is present so the missing element is 2.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ arr.size() + 1
*/
#include <stdio.h>

int missingNum(int *arr, int size) {
    long n = size + 1;
    long total = (n * (n + 1)) / 2;
    long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (int)(total - sum);
}

int main() {
    int arr[] = {1, 2, 3, 5};
    int size = 4;
    printf("%d\n", missingNum(arr, size));
    return 0;
}
