#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* mergeSortedLists(struct Node* l1, struct Node* l2) {
    // Allocate dummy node on heap
    struct Node* dummy = (struct Node*) malloc(sizeof(struct Node));
    dummy->next = NULL;

    struct Node* tail = dummy;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Append remaining nodes
    tail->next = (l1 != NULL) ? l1 : l2;

    // Store the head of the real merged list
    struct Node* mergedHead = dummy->next;

    // Free the dummy node (not part of the final list)
    free(dummy);

    return mergedHead;
}