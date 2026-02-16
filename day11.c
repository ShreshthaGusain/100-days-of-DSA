// Day 11 - Question 1: Matrix Addition
// Problem: Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained by adding corresponding elements of the matrices.

// Input:
// - First line: two integers m and n representing the number of rows and columns
// - Next m lines: n integers each representing the elements of the first matrix
// - Next m lines: n integers each representing the elements of the second matrix

// Output:
// - Print the resultant matrix after addition, with each row on a new line and elements separated by spaces

// Example:
// Input:
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9
// 9 8 7
// 6 5 4
// 3 2 1

// Output:
// 10 10 10
// 10 10 10
// 10 10 10

// Explanation:
// Each element of the result matrix is the sum of the corresponding elements from the two input matrices.

// Test Cases:

// Test Case 1:
// Input:
// 2 2
// 1 2
// 3 4
// 5 6
// 7 8
// Output:
// 6 8
// 10 12

// Test Case 2:
// Input:
// 1 3
// 10 20 30
// 1 2 3
// Output:
// 11 22 33

// Test Case 3:
// Input:
// 3 1
// 1
// 2
// 3
// 4
// 5
// 6
// Output:
// 5
// 7
// 9

#include <stdio.h>

int main() {
    int m, n;
    
    if (scanf("%d %d", &m, &n) != 2) return 0;

    int matrix1[m][n];
    int matrix2[m][n];
    int sum[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d", sum[i][j]);

            if (j < n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

// 867. Transpose Matrix
// Hint
// Given a 2D integer array matrix, return the transpose of matrix.

// The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.



 

// Example 1:

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[1,4,7],[2,5,8],[3,6,9]]
// Example 2:

// Input: matrix = [[1,2,3],[4,5,6]]
// Output: [[1,4],[2,5],[3,6]]
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 1000
// 1 <= m * n <= 105
// -109 <= matrix[i][j] <= 109

#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int m = matrixSize;
    int n = matrixColSize[0];

    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    int** result = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = m;
        result[i] = (int*)malloc(m * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}

int main() {
    int row1[] = {1, 2, 3};
    int row2[] = {4, 5, 6};
    
    int* matrix[] = {row1, row2}; 
    
    int matrixSize = 2;      
    int matrixColSize[] = {3, 3}; 
    
    int returnSize;           
    int* returnColSizes;   
    
    int** result = transpose(matrix, matrixSize, matrixColSize, &returnSize, &returnColSizes);

    printf("Transposed Matrix:\n");
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
