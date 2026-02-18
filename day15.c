// Day 15 - Question 1: Matrix Diagonal Sum
// Close
// Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

// Input:
// - First line: two integers m and n
// - Next m lines: n integers each

// Output:
// - Print the sum of the primary diagonal elements

// Example:
// Input:
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9

// Output:
// 15

// Explanation:
// 1 + 5 + 9 = 15

#include <stdio.h>

int main() {
    int m, n;
    
    if (scanf("%d %d", &m, &n) != 2) return 0;

    int matrix[m][n];
    long long sum = 0; 

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int limit = (m < n) ? m : n;
    for (int i = 0; i < limit; i++) {
        sum += matrix[i][i];
    }

    printf("%lld\n", sum);

    return 0;
}


// 73. Set Matrix Zeroes

// Hint
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.

 

// Example 1:
// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]Output: [[1,0,1],[0,0,0],[1,0,1]]

// Example 2:
// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

 
// Constraints:
// m == matrix.length
// n == matrix[0].length
// 1 <= m, n <= 200
// -231 <= matrix[i][j] <= 231 - 1

#include <stdio.h>
#include <stdlib.h>

void setZeroes(int** matrix, int m, int n) {
    int row_zero[m]; 
    int col_zero[n];
    
    for(int i = 0; i < m; i++) row_zero[i] = 0;
    for(int j = 0; j < n; j++) col_zero[j] = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                row_zero[i] = 1;
                col_zero[j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (row_zero[i] == 1 || col_zero[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    int m, n;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int** matrix = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    setZeroes(matrix, m, n);

    printf("\nResulting Matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
