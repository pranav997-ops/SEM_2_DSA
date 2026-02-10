/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[1001]; // Buffer to store the input string
    
    // Read the input string
    scanf("%s", s);
    
    int left = 0;             // Pointer to the start
    int right = strlen(s) - 1; // Pointer to the end
    int isPalindrome = 1;      // Flag: 1 (true) initially

    // 

    // Loop until the pointers meet in the middle
    while (left < right) {
        // Compare characters at current pointers
        if (s[left] != s[right]) {
            isPalindrome = 0; // Mismatch found, not a palindrome
            break;            // Exit loop immediately
        }
        
        // Move pointers inward
        left++;
        right--;
    }

    // Output result based on the flag
    if (isPalindrome) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}