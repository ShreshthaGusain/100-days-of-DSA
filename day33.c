// Day 33 - Question 1: Infix to Postfix Conversion
// Close
// Problem: Convert an infix expression to postfix notation using stack.

// Input:
// - Single line: infix expression (operands are single characters)

// Output:
// - Print the postfix expression

// Example:
// Input:
// A+B*C

// Output:
// ABC*+

// Explanation:
// Operator precedence: * > +
// Use stack to handle operator precedence and associativity

#include <stdio.h>
#include <ctype.h> // for isalnum

// Helper to define operator priority
int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void infixToPostfix(char* exp) {
    char stack[100];
    int top = -1;

    for (int i = 0; exp[i]; i++) {
        char c = exp[i];

        // 1. If character is an operand, print it
        if (isalnum(c)) {
            printf("%c", c);
        }
        // 2. If '(', push to stack
        else if (c == '(') {
            stack[++top] = '(';
        }
        // 3. If ')', pop until '(' is found
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                printf("%c", stack[top--]);
            }
            top--; // Remove '(' from stack
        }
        // 4. If an operator is encountered
        else {
            while (top != -1 && prec(stack[top]) >= prec(c)) {
                printf("%c", stack[top--]);
            }
            stack[++top] = c;
        }
    }

    // 5. Pop all remaining operators from stack
    while (top != -1) {
        printf("%c", stack[top--]);
    }
    printf("\n");
}

int main() {
    char exp[100];
    scanf("%s", exp);
    infixToPostfix(exp);
    return 0;
}

// 150. Evaluate Reverse Polish Notation
// Medium
// Topics
// premium lock icon
// Companies
// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

// Evaluate the expression. Return an integer that represents the value of the expression.

// Note that:

// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish notation.
// The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

// Example 1:

// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
// Example 2:

// Input: tokens = ["4","13","5","/","+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6
// Example 3:

// Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
// Output: 22
// Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
// = ((10 * (6 / (12 * -11))) + 17) + 5
// = ((10 * (6 / -132)) + 17) + 5
// = ((10 * 0) + 17) + 5
// = (0 + 17) + 5
// = 17 + 5
// = 22
 

// Constraints:

// 1 <= tokens.length <= 104
// tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evalRPN(char** tokens, int tokensSize) {
    // Create a stack large enough for all tokens
    int* stack = (int*)malloc(tokensSize * sizeof(int));
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        char* s = tokens[i];

        // Check if the token is an operator (and not a negative number)
        // Note: s[1] == '\0' ensures it's a single-char operator, not "-11"
        if ((s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/') && s[1] == '\0') {
            // Pop the two operands
            int b = stack[top--];
            int a = stack[top--];

            // Perform operation and push result
            if (s[0] == '+') stack[++top] = a + b;
            else if (s[0] == '-') stack[++top] = a - b;
            else if (s[0] == '*') stack[++top] = a * b;
            else if (s[0] == '/') stack[++top] = a / b; // C's '/' truncates toward zero by default
        } 
        else {
            // It's a number (could be negative, e.g., "-11")
            stack[++top] = atoi(s);
        }
    }

    int result = stack[top];
    free(stack); // Clean up memory
    return result;
}
