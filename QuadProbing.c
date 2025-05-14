#include <stdio.h>
#define SIZE 10
#define EMPTY -1

// Constants for quadratic probing
#define C1 1
#define C2 3

int hashTable[SIZE];

// Initialize table
void initTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

// Primary hash function
int h_prime(int key) {
    return key % SIZE;
}

// Quadratic probing insert using the formula:
// h(k, i) = (h'(k) + c1*i + c2*i^2) % m
void insert(int key) {
    int i = 0;
    int index;
    int baseHash = h_prime(key);

    while (i < SIZE) {
        index = (baseHash + C1 * i + C2 * i * i) % SIZE;
        if (hashTable[index] == EMPTY) {
            hashTable[index] = key;
            return;
        }
        i++;
    }

    printf("Hash Table is full. Couldn't insert key %d\n", key);
}

// Display the hash table
void display() {
    printf("\nHash Table (Quadratic Probing):\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == EMPTY)
            printf("[%d] : ---\n", i);
        else
            printf("[%d] : %d\n", i, hashTable[i]);
    }
}

// Main function with menu
int main() {
    int choice, key;
    initTable();

    do {
        printf("\nMenu:\n");
        printf("1. Insert a key\n");
        printf("2. Display table\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
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
                printf("Invalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}