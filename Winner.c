#include<stdio.h>
#include<stdlib.h>

#define MAX 100
int queue[MAX];
int front = -1, rear = -1;

//Enqueue function
void enqueue(int value) {
    if((rear + 1) % MAX == front) {
        printf("Queue overflow\n");
        return;
    }
    if(front == -1) {
        front = 0;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = value;
}

//Dequeue function
int dequeue() {
    if(front == -1) {
        printf("Queue underflow\n");
        return -1;
    }
    int value = queue[front];
    if(front == rear) {
        front = rear = -1; // Queue is empty after this dequeue
    } else {
        front = (front + 1) % MAX;
    }
    return value;
}

//Function to find the winner
int findWinner(int n, int k) {
    // Step 1: Enqueue all players
    for (int i = 1; i <= n; i++) {
        enqueue(i);
    }

    // Step 2: Eliminate every k-th player
    while (front != rear) {
        for (int i = 1; i < k; i++) {
            int temp = dequeue();
            enqueue(temp); // rotate
        }
        // Eliminate k-th player
        dequeue();
    }

    return dequeue(); // Winner
}

int main() {
    int n, k;

    printf("Enter the number of players: ");
    scanf("%d", &n);
    printf("Enter the count number (k): ");
    scanf("%d", &k);

    int winner = findWinner(n, k);
    printf("The winner is at position: %d\n", winner);

    return 0;
}