#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
char stack[MAX];
int top = -1;

//Push function
void push(char ch) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = ch;
}

//Pop function
char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack[top--];
}

// Function to check if two brackets match
int isMatchingPair(char opening, char closing) {
    return ((opening == '(' && closing == ')') ||
            (opening == '{' && closing == '}') ||
            (opening == '[' && closing == ']'));
}

// Function to check if parentheses are balanced
int isBalanced(char* expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            char topChar = pop();
            if (!isMatchingPair(topChar, ch)) {
                return 0; // Unbalanced
            }
        }
    }

    // Stack should be empty if balanced
    return (top == -1);
}

// Main function
int main() {
    char expr[MAX];

    printf("Enter the expression: ");
    scanf("%s", expr);

    if (isBalanced(expr))
        printf("The expression is balanced.\n");
    else
        printf("The expression is NOT balanced.\n");

    return 0;
}