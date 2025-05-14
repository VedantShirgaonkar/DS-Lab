#include <stdio.h>
#define SIZE 10
#define EMPTY -1
#define R 7 // Prime number smaller than SIZE

int hashTable[SIZE];

// Initialize the hash table
void initTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

// Primary hash function
int h1(int key) {
    return key % SIZE;
}

// Secondary hash function
int h2(int key) {
    return R - (key % R);
}

// Insert using double hashing
void insert(int key) {
    int index = h1(key);
    int step = h2(key);

    int i = 0;
    int newIndex;

    while (i < SIZE) {
        newIndex = (index + i * step) % SIZE;
        if (hashTable[newIndex] == EMPTY) {
            hashTable[newIndex] = key;
            return;
        }
        i++;
    }
    printf("Hash Table is full. Couldn't insert key %d\n", key);
}

// Display hash table
void display() {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == EMPTY)
            printf("[%d] : ---\n", i);
        else
            printf("[%d] : %d\n", i, hashTable[i]);
    }
}

// Main function
int main() {
    int choice, key;
    initTable();

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}