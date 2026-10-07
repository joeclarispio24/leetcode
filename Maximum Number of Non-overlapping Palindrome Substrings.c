#include <stdio.h>
#include <string.h>

// Helper to check if s[left...right] is a palindrome
int is_palindrome(const char *s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) return 0;
        left++;
        right--;
    }
    return 1;
}

int maxPalindromes(const char *s, int k) {
    int n = strlen(s);
    int count = 0;
    int i = 0;

    while (i < n) {
        // Check if a palindrome of length k exists starting at i
        if (i + k <= n && is_palindrome(s, i, i + k - 1)) {
            count++;
            i += k; // Jump past this palindrome greedily
        } 
        // Check if a palindrome of length k+1 exists starting at i
        else if (i + k + 1 <= n && is_palindrome(s, i, i + k)) {
            count++;
            i += k + 1; // Jump past this palindrome greedily
        } 
        else {
            i++; // Move to the next character
        }
    }
    return count;
}
