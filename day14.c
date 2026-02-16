/*Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

Input:
- First line: integer n representing number of rows and columns
- Next n lines: n integers each representing the matrix elements

Output:
- Print "Identity Matrix" if the matrix satisfies the condition
- Otherwise, print "Not an Identity Matrix"

Example:
Input:
3
1 0 0
0 1 0
0 0 1

Output:
Identity Matrix*/

#include <stdio.h>

int main() {
    int n;
    int isIdentity = 1; // Flag: 1 means True, 0 means False

    // 1. Read the size of the matrix
    if (scanf("%d", &n) != 1) return 0;

    int matrix[n][n]; // Variable Length Array (C99 standard)

    // 2. Read matrix elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 3. Check Identity Matrix conditions
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Check Diagonal Elements
            if (i == j) {
                if (matrix[i][j] != 1) {
                    isIdentity = 0;
                    break;
                }
            } 
            // Check Non-Diagonal Elements
            else {
                if (matrix[i][j] != 0) {
                    isIdentity = 0;
                    break;
                }
            }
        }
        // Break outer loop if violation found
        if (isIdentity == 0) {
            break;
        }
    }

    // 4. Output the result
    if (isIdentity) {
        printf("Identity Matrix\n");
    } else {
        printf("Not an Identity Matrix\n");
    }

    return 0;
}