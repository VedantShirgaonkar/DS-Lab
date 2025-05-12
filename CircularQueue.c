#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

//Check if full
int isFull() {
    return (rear + 1) % MAX == front;
}

//Check if empty
int isEmpty() {
    return front == -1;
}

//Enqueue function
void enqueue(int value) {
    if (isFull()) {
        printf("Queue overflow\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = value;
}

//Dequeue function
void dequeue() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return;
    }
    int value = queue[front];
    if (front == rear) {
        front = rear = -1; // Queue is empty after this dequeue
    } else {
        front = (front + 1) % MAX;
    }
    printf("Dequeued: %d\n", value);
}

//Peek function
void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

//Display function
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

//Menu function
int main() {
    int choice, data;
    while (1) {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
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