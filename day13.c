/*Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

Input:
- First line: two integers r and c representing the number of rows and columns
- Next r lines: c integers each representing the matrix elements

Output:
- Print all visited elements in the order of traversal, separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
1 2 3 6 9 8 7 4 5

Explanation:
The traversal begins along the top row, proceeds down the rightmost column, then moves across the bottom row in reverse, and finally goes up the leftmost column. The same pattern repeats for the inner submatrix.

Test Cases:

Test Case 1:
Input:
2 3
1 2 3
4 5 6
Output:
1 2 3 6 5 4

Test Case 2:
Input:
3 1
7
8
9
Output:
7 8 9*/

#include <stdio.h>

void spiralTraversal(int r, int c, int matrix[r][c]) {
    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    while (top <= bottom && left <= right) {
        
        // 1. Traverse Right (Top Row)
        for (int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++; // Move the top boundary down

        // 2. Traverse Down (Right Column)
        for (int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--; // Move the right boundary left

        // 3. Traverse Left (Bottom Row)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--; // Move the bottom boundary up
        }

        // 4. Traverse Up (Left Column)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++; // Move the left boundary right
        }
    }
}

int main() {
    int r, c;
    
    // Reading dimensions
    if (scanf("%d %d", &r, &c) != 2) return 0;

    int matrix[r][c];

    // Reading matrix elements
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Function call
    spiralTraversal(r, c, matrix);

    return 0;
}