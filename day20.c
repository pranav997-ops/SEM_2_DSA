/*Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

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

    // 3. Initialize variables to track the minimum sum and the pair indices
    int min_sum = INT_MAX; 
    int res_l = 0;
    int res_r = 1;

    // 4. Brute Force: Use nested loops to evaluate every possible pair
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            
            // If the absolute value of the current sum is smaller, update our trackers
            if (abs(sum) < abs(min_sum)) {
                min_sum = sum;
                res_l = i;
                res_r = j;
            }
        }
    }

    // 5. Print the pair that resulted in the closest sum to zero
    printf("%d %d\n", arr[res_l], arr[res_r]);

    return 0;
}