#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Define structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a queue for Node pointers using array
struct Node* queue[MAX];
int front = -1;
int rear = -1;

// Enqueue function using your logic
void enqueue(struct Node* data) {
    if (rear == MAX - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = data;
}

// Dequeue function using your logic
struct Node* dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        return NULL;
    }
    return queue[front++];
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder traversal
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Level Order traversal using your queue logic
void levelOrder(struct Node* root) {
    if (root == NULL) return;

    // Reset queue state before use
    front = rear = -1;

    enqueue(root);

    while (front != -1 && front <= rear) {
        struct Node* temp = dequeue();
        if (temp != NULL) {
            printf("%d ", temp->data);
            if (temp->left) enqueue(temp->left);
            if (temp->right) enqueue(temp->right);
        }
    }
}

// Recursive function to build tree from user input
struct Node* buildTree() {
    int data;
    printf("Enter node value (-1 for NULL): ");
    scanf("%d", &data);
    if (data == -1) return NULL;

    struct Node* node = createNode(data);
    printf("Enter left child of %d:\n", data);
    node->left = buildTree();
    printf("Enter right child of %d:\n", data);
    node->right = buildTree();
    return node;
}

// User menu
int main() {
    struct Node* root = NULL;
    int choice;

    printf("Binary Tree Creation\n");
    root = buildTree();

    do {
        printf("\nMenu:\n");
        printf("1. Inorder Traversal\n");
        printf("2. Preorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Level Order Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("Traversal Result: ");
        switch (choice) {
            case 1:
                inorder(root);
                break;
            case 2:
                preorder(root);
                break;
            case 3:
                postorder(root);
                break;
            case 4:
                levelOrder(root);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
        printf("\n");

    } while (choice != 5);

    return 0;
}