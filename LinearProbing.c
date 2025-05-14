#include <stdio.h>
#define SIZE 10
#define EMPTY -1

int linearTable[SIZE];
int quadraticTable[SIZE];

// Initialize hash tables
void initTables() {
    for (int i = 0; i < SIZE; i++) {
        linearTable[i] = EMPTY;
        quadraticTable[i] = EMPTY;
    }
}

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Linear Probing Insert
void insertLinear(int key) {
    int index = hash(key);
    int i = 0;
    while (linearTable[(index + i) % SIZE] != EMPTY && i < SIZE) {
        i++;
    }
    if (i < SIZE) {
        linearTable[(index + i) % SIZE] = key;
    } else {
        printf("Linear Probing: Hash Table is full for key %d\n", key);
    }
}

// Quadratic Probing Insert
void insertQuadratic(int key) {
    int index = hash(key);
    int i = 0;
    int pos;
    while (i < SIZE) {
        pos = (index + i * i) % SIZE;
        if (quadraticTable[pos] == EMPTY) {
            quadraticTable[pos] = key;
            return;
        }
        i++;
    }
    printf("Quadratic Probing: Hash Table is full for key %d\n", key);
}

// Display function
void display(int table[]) {
    for (int i = 0; i < SIZE; i++) {
        if (table[i] == EMPTY)
            printf("[%d] : ---\n", i);
        else
            printf("[%d] : %d\n", i, table[i]);
    }
}

// Main menu
int main() {
    int choice, key;
    initTables();

    do {
        printf("\nMenu:\n");
        printf("1. Insert using Linear Probing\n");
        printf("2. Insert using Quadratic Probing\n");
        printf("3. Display Linear Hash Table\n");
        printf("4. Display Quadratic Hash Table\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insertLinear(key);
                break;
            case 2:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insertQuadratic(key);
                break;
            case 3:
                printf("Linear Probing Table:\n");
                display(linearTable);
                break;
            case 4:
                printf("Quadratic Probing Table:\n");
                display(quadraticTable);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}