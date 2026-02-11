/* Q1-
Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
10 30 40 50

Explanation: Delete position 2 (element 20), remaining elements shift left
*/

#include <stdio.h>
int main() {
    int n,pos;
    scanf("%d",&n);
    
    int arr[n];
    for (int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&pos);

    if (pos<1||pos>n) {
        return 0;
    }

    for (int i=pos-1;i<n-1;i++) {
        arr[i]=arr[i+1];
    }

    for (int i=0;i<n-1;i++) {
        printf("%d", arr[i]);
        if (i<n-2){
            printf(" ");
        }
    }

    return 0;
}

/* Q2-
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 
Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104
*/

#include <stdio.h>
int maxProfit(int* prices, int pricesSize) {
    int minPrice = 10001;
    int maxProfit = 0;
    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }
    return maxProfit;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int size = sizeof(prices) / sizeof(prices[0]);
    int result = maxProfit(prices, size);
    printf("%d\n", result);
    return 0;
}