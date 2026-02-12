/*Problem: Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).

Input:
- First line: two integers m and n representing the number of rows and columns
- Next m lines: n integers each representing the elements of the matrix

Output:
- Print "Symmetric Matrix" if the given matrix is symmetric
- Otherwise, print "Not a Symmetric Matrix"

Example:
Input:
3 3
1 2 3
2 4 5
3 5 6

Output:
Symmetric Matrix

Explanation:
The matrix is square (3 × 3) and for every i and j, element[i][j] = element[j][i].

Test Cases:

Test Case 1:
Input:
2 2
1 2
2 1
Output:
Symmetric Matrix

Test Case 2:
Input:
3 3
1 0 1
2 3 4
1 4 5
Output:
Not a Symmetric Matrix

Test Case 3:
Input:
2 3
1 2 3
4 5 6
Output:
Not a Symmetric Matrix*/

#include <stdio.h>

#define MAX 100 // Maximum size for rows and columns

int main() {
    int m, n;
    int matrix[MAX][MAX];
    int i, j;
    int isSymmetric = 1; // Flag: 1 means True, 0 means False

    // 1. Read rows and columns
    scanf("%d %d", &m, &n);

    // 2. Read matrix elements
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 3. Logic: Check if square and symmetric
    if (m != n) {
        // A symmetric matrix must be a square matrix (rows == cols)
        isSymmetric = 0;
    } else {
        // Check for Transpose Equality
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                // Compare element at [i][j] with element at [j][i]
                if (matrix[i][j] != matrix[j][i]) {
                    isSymmetric = 0;
                    break; // Found a mismatch, stop checking
                }
            }
            if (isSymmetric == 0) {
                break; // Break the outer loop as well
            }
        }
    }

    // 4. Output the result
    if (isSymmetric == 1) {
        printf("Symmetric Matrix\n");
    } else {
        printf("Not a Symmetric Matrix\n");
    }

    return 0;
}