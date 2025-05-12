#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char ch) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = ch;
}

// Pop function
char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}

// Peek function
char peek() {
    if (top == -1) {
        return '\0';
    }
    return stack[top];
}

// Check precedence of operators
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Check if operator is right associative
int isRightAssociative(char op) {
    return op == '^';
}

// Check if character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    int i, k = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        // Operand → directly add to output
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        // Opening bracket → push to stack
        else if (ch == '(') {
            push(ch);
        }
        // Closing bracket → pop until '('
        else if (ch == ')') {
            while (peek() != '(' && top != -1) {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        // Operator
        else if (isOperator(ch)) {
            while (isOperator(peek()) &&
                  ((precedence(ch) < precedence(peek())) ||
                   (precedence(ch) == precedence(peek()) && !isRightAssociative(ch)))) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    // Pop any remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0'; // End the string
}

// Main function
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}