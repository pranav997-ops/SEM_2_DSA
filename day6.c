/*Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    
    // 1. Read the size of the array
    if (scanf("%d", &n) != 1) return 0;

    // Handle edge case: empty array
    if (n == 0) return 0;

    // Allocate memory for the array
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 2. Remove Duplicates In-Place
    // 'k' is the index where the next unique element will be stored.
    // We start at 1 because the first element (index 0) is always unique.
    int k = 1; 

    for (int i = 1; i < n; i++) {
        // If current element is different from the previous one
        if (arr[i] != arr[i - 1]) {
            arr[k] = arr[i]; // Store the unique element at 'k'
            k++;             // Move the 'unique' pointer forward
        }
    }

    // 3. Print the result
    // We only print up to 'k', which is the new count of unique elements.
    for (int i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free memory
    free(arr);

    return 0;
}