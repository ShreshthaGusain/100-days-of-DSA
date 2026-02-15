// Day 9 - Question 1: Mirror the Code Name
// Close
// Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

// Input:
// - Single line: a lowercase string containing only alphabetic characters (no spaces)
// Output:
// - Print the transformed code name after applying the mirror operation

// Example:
// Input:
// hello
// Output:
// olleh

// Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored

#include <stdio.h>
#include <string.h>

void mirror(char* str, int index) {
    if (str[index] == '\0') {
        return;
    }
    
    mirror(str, index + 1);
    
    printf("%c", str[index]);
}

int main() {
    char codeName[100];
    scanf("%s", codeName);
    mirror(codeName, 0);
    
    return 0;
}

// 344. Reverse String
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.

// Example 1:
// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]

// Example 2:
// Input: s = ["H","a","n","n","a","h"]
// Output: ["h","a","n","n","a","H"]
 
// Constraints:
// 1 <= s.length <= 105

#include <stdio.h>

void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize - 1;
    
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        
        left++;
        right--;
    }
}

int main() {
    char s1[] = {'h', 'e', 'l', 'l', 'o'};
    int size1 = sizeof(s1) / sizeof(s1[0]);
    
    reverseString(s1, size1);
    
    printf("Output 1: ");
    for (int i = 0; i < size1; i++) {
        printf("\"%c\" ", s1[i]);
    }
    printf("\n");

    char s2[] = {'H', 'a', 'n', 'n', 'a', 'h'};
    int size2 = sizeof(s2) / sizeof(s2[0]);
    
    reverseString(s2, size2);
    
    printf("Output 2: ");
    for (int i = 0; i < size2; i++) {
        printf("\"%c\" ", s2[i]);
    }
    printf("\n");

    return 0;
}
