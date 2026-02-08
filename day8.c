/*Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32

Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32*/

#include <stdio.h>

// Recursive function to calculate a^b
// Using long long to prevent overflow for larger results
long long power(int base, int exponent) {
    // Base Case: Any number raised to the power of 0 is 1
    if (exponent == 0) {
        return 1;
    }
    // Recursive Step: base^exponent = base * base^(exponent-1)
    else {
        return base * power(base, exponent - 1);
    }
}

int main() {
    int a, b;

    // Read input: a (base) and b (exponent)
    scanf("%d %d", &a, &b);

    // Ensure we handle the negative exponent case if necessary, 
    // though this simple logic assumes b >= 0
    if (b < 0) {
        printf("Exponent should be non-negative for this integer implementation.\n");
    } else {
        printf("%lld", power(a, b));
    }

    return 0;
}