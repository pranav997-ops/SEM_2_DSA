/*Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

Input:
- First line: two integers m and n
- Next m lines: n integers each

Output:
- Print the sum of the primary diagonal elements

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
15

Explanation:
1 + 5 + 9 = 15*/

#include <stdio.h>

int main() {
    int m, n;
    int sum = 0;

    // 1. Read matrix dimensions
    if (scanf("%d %d", &m, &n) != 2) return 0;

    int matrix[m][n]; // Variable Length Array (VLA)

    // 2. Read matrix elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 3. Calculate Diagonal Sum
    // We only iterate up to the smaller dimension (min of m and n)
    int limit = (m < n) ? m : n;

    for (int i = 0; i < limit; i++) {
        sum += matrix[i][i];
    }

    // 4. Print the result
    printf("%d\n", sum);

    return 0;
}