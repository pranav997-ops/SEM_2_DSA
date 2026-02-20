/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3*/

#include <stdio.h>

// Helper function to reverse a portion of the array
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n, k;

    // 1. Read the size of the array
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for array size.\n");
        return 1;
    }

    int arr[n];

    // 2. Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Read the rotation count 'k'
    if (scanf("%d", &k) != 1) {
        printf("Invalid input for rotation count.\n");
        return 1;
    }

    // Optimize k in case it is larger than the array size
    k = k % n; 

    // Handle negative k (optional, but good practice for left rotation if k < 0)
    if (k < 0) {
        k = k + n;
    }

    if (k > 0) {
        // Step A: Reverse the entire array
        reverse(arr, 0, n - 1);
        
        // Step B: Reverse the first 'k' elements
        reverse(arr, 0, k - 1);
        
        // Step C: Reverse the remaining 'n - k' elements
        reverse(arr, k, n - 1);
    }

    // 4. Print the rotated array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}