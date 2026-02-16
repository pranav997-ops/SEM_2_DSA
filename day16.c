/*Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count

Example:
Input:
5
1 2 2 3 1

Output:
1:2 2:2 3:1*/

#include <stdio.h>

void countFrequency(int arr[], int n) {
    // Array to keep track of visited elements
    // 0 = not visited, 1 = visited
    int visited[n];
    
    // Initialize visited array to 0
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        // Skip this element if already processed
        if (visited[i] == 1) {
            continue;
        }

        int count = 1;
        
        // Check remaining elements for duplicates
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = 1; // Mark duplicate as visited
                count++;
            }
        }
        
        // Print the result for this distinct element
        printf("%d:%d ", arr[i], count);
    }
}

int main() {
    int n;

    // Reading input size
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];

    // Reading array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Function call
    countFrequency(arr, n);

    return 0;
}