Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

// Comparator function required for the qsort() function
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;

    // 1. Read the size of the array
    if (scanf("%d", &n) != 1 || n < 2) {
        printf("Invalid input. Array must contain at least 2 elements.\n");
        return 1;
    }

    int arr[n];

    // 2. Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Sort the array in ascending order using built-in qsort
    qsort(arr, n, sizeof(int), compare);

    // 4. Initialize variables for the two-pointer approach
    int left = 0;
    int right = n - 1;
    
    int min_sum = INT_MAX; // Start with the maximum possible integer
    int res_l = left;      // To store the left index of our best pair
    int res_r = right;     // To store the right index of our best pair

    // 5. Use two pointers to find the closest sum to zero
    while (left < right) {
        int sum = arr[left] + arr[right];

        // If the absolute value of the current sum is less than 
        // our recorded minimum, update the minimum and the result indices
        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            res_l = left;
            res_r = right;
        }

        // If the sum is negative, we need a larger value, so move left pointer right
        if (sum < 0) {
            left++;
        } 
        // If the sum is positive, we need a smaller value, so move right pointer left
        else if (sum > 0) {
            right--;
        } 
        // If the sum is exactly 0, we can't get any closer, so break out early
        else {
            break;
        }
    }

    // 6. Print the result
    printf("%d %d\n", arr[res_l], arr[res_r]);

    return 0;
}