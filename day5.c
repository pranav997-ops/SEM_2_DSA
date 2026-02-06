/*Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed*/

#include <stdio.h>
#include <stdlib.h>

void mergeLogs(int* log1, int p, int* log2, int q) {
    int i = 0, j = 0;

    // Compare elements from both arrays and print the smaller one
    while (i < p && j < q) {
        if (log1[i] < log2[j]) {
            printf("%d ", log1[i]);
            i++;
        } else {
            printf("%d ", log2[j]);
            j++;
        }
    }

    // If there are remaining elements in log1, print them
    while (i < p) {
        printf("%d ", log1[i]);
        i++;
    }

    // If there are remaining elements in log2, print them
    while (j < q) {
        printf("%d ", log2[j]);
        j++;
    }
    printf("\n");
}

int main() {
    int p, q;

    // 1. Read input for first server log
    if (scanf("%d", &p) != 1) return 0; // Check for valid input
    int *log1 = (int*)malloc(p * sizeof(int));
    for (int k = 0; k < p; k++) {
        scanf("%d", &log1[k]);
    }

    // 2. Read input for second server log
    if (scanf("%d", &q) != 1) return 0;
    int *log2 = (int*)malloc(q * sizeof(int));
    for (int k = 0; k < q; k++) {
        scanf("%d", &log2[k]);
    }

    // 3. Perform the merge
    mergeLogs(log1, p, log2, q);

    // 4. Free allocated memory
    free(log1);
    free(log2);

    return 0;
}