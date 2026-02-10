/*Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh

Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored*/


#include <stdio.h>
#include <string.h>

int main() {
    char str[1001]; // Buffer to store the input string (max 1000 chars)
    
    // Read the input string
    scanf("%s", str);
    
    // Calculate the length of the string
    int len = strlen(str);
    
    // Pointers for the start and end of the string
    int start = 0;
    int end = len - 1;
    char temp;

    // Loop to swap characters from both ends until meeting in the middle
    while (start < end) {
        // Swap logic
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // Move pointers towards the center
        start++;
        end--;
    }

    // Print the transformed (mirrored) string
    printf("%s\n", str);

    return 0;
}