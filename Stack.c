#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;

//Push function
void push(int data) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = data;
}

//Pop function
int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

//Peek function
void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", stack[top]);
}

//Display function
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

//Menu function
int main() {
    int choice, data;
    while (1) {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                data = pop();
                if (data != -1) {
                    printf("Popped element: %d\n", data);
                }
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}