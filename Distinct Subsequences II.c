#include <string.h>

int distinctSubseqII(char* s) {
    long long MOD = 1000000007;
    long long ends[26] = {0}; // Tracks count of unique subsequences ending in 'a'-'z'
    long long currentTotal = 0; // Tracks the total sum of elements in ends

    for (int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';
        long long oldEndValue = ends[idx];

        // New unique subsequences ending in this char = current total + 1 (standalone character)
        ends[idx] = (currentTotal + 1) % MOD;

        // Update the running total: remove old count for this char, add new count
        // Added +MOD to ensure the result remains positive during subtraction modulo operations
        currentTotal = (currentTotal - oldEndValue + ends[idx] + MOD) % MOD;
    }

    return (int)currentTotal;
}
