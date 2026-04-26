// Day 72 - Question 1: First Repeated Character
// Close
// Problem Statement
// Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.

// Input Format
// A single string s.

// Output Format
// Print the first repeated character. If no character is repeated, print -1.

// Sample Input
// geeksforgeeks

// Sample Output
// e

#include <stdio.h>
#include <string.h>

char findFirstRepeated(char* s) {
    // Array to track seen characters (alphabet size 26)
    int seen[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        // If we've seen this character before, this is the 
        // first "second occurrence" in the string.
        if (seen[index] == 1) {
            return s[i];
        }

        // Mark character as seen
        seen[index] = 1;
    }

    // No repeated character found
    return '\0';
}

int main() {
    char s[100001]; // Adjust size based on constraints
    if (scanf("%s", s) != 1) return 0;

    char result = findFirstRepeated(s);

    if (result == '\0') {
        printf("-1\n");
    } else {
        printf("%c\n", result);
    }

    return 0;
}
