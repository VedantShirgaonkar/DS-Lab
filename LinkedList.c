#include<stdio.h>
#include<stdlib.h>

//Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};

//Insert at start
void insertStart(int data){
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

//Insert at end
void insertEnd(int data){
    struct Node* newnode = createNode(data);
    if(head==NULL){
        head = newnode;
        return;
    }
    struct Node* temp = head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}

//Insert after a specific value
void insertAfter(int prevData, int data){
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    while(temp!=NULL && temp->data!=prevData){
        temp = temp->next;
    }
    if(temp==NULL){
        printf("Given value not found int he list.\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

//Insert before a specific value
void insertBefore(int nextData, int data){
    struct Node* newNode = createNode(data);
    if(head==NULL){
        printf("List is empty");
        return;
    }
    if(head->data == nextData){
        insertStart(data);
        return;
    }
    struct Node* temp = head;
    while(temp->next!=NULL && temp->next->data!=nextData){
        temp = temp->next;
    }
    if(temp->next==NULL){
        printf("Given value not found in the list.\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

//Delete start
void deleteStart(){
    if(head==NULL){
        printf("List is empty");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

//Delete end
void deleteEnd(){
    if(head==NULL){
        printf("List is empty");
        return;
    }
    if(head->next==NULL){
        deleteStart();
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

//Delete a node
void deleteNode(int data){
    if(head==NULL){
        printf("List is empty");
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    while(temp!=NULL && temp->data!=data){
        prev = temp;
        temp = temp->next;
    }
    if(temp==NULL){
        printf("Given value not found in the list.\n");
        return;
    }
    if(prev==NULL){
        deleteStart();
    }
    else if(temp->next==NULL){
        deleteEnd();
    }
    else{
        prev->next = temp->next;
        free(temp);
    }
}

//Delete after a specific value
void deleteAfter(int prevData){
    if(head==NULL){
        printf("List is empty");
        return;
    }
    struct Node* temp = head;
    while(temp!=NULL && temp->data!=prevData){
        temp = temp->next;
    }
    if(temp==NULL || temp->next==NULL){
        printf("Given value not found in the list or no node after it.\n");
        return;
    }
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

//Delete before a specific value
void deleteBefore(int nextData){
    if(head==NULL){
        printf("List is empty");
        return;
    }
    if(head->data == nextData){
        printf("No node before the head.\n");
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    while(temp->next!=NULL && temp->next->data!=nextData){
        prev = temp;
        temp = temp->next;
    }
    if(temp->next==NULL){
        printf("Given value not found in the list.\n");
        return;
    }
    else{
        prev->next = temp->next;
        free(temp);
    }
}

//Display the list
void displayList(){
    struct Node* temp = head;
    if(temp==NULL){
        printf("List is empty");
        return;
    }
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//Search for a value
int searchValue(int data){
    struct Node* temp = head;
    while(temp!=NULL){
        if(temp->data == data){
            return 1; // Value found
        }
        temp = temp->next;
    }
    return 0; // Value not found
}

//Reverse the list
void reverse(){
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* after = NULL;
    while(current!=NULL){
        after = current->next;
        current->next = prev;
        prev = current;
        current = after;
    }
    head = prev;
}

//User driven menu
void menu(){
    int choice, data, prevData;
    while(1){
        printf("\n1. Insert at start\n");
        printf("2. Insert at end\n");
        printf("3. Insert after a specific value\n");
        printf("4. Insert before a specific value\n");
        printf("5. Delete start\n");
        printf("6. Delete end\n");
        printf("7. Delete a node\n");
        printf("8. Delete after a specific value\n");
        printf("9. Delete before a specific value\n");
        printf("10. Display list\n");
        printf("11. Search for a value\n");
        printf("12. Reverse the list\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertStart(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 3:
                printf("Enter previous value: ");
                scanf("%d", &prevData);
                printf("Enter data: ");
                scanf("%d", &data);
                insertAfter(prevData, data);
                break;
            case 4:
                printf("Enter next value: ");
                scanf("%d", &prevData);
                printf("Enter data: ");
                scanf("%d", &data);
                insertBefore(prevData, data);
                break;
            case 5:
                deleteStart();
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;
            case 8:
                printf("Enter previous value: ");
                scanf("%d", &prevData);
                deleteAfter(prevData);
                break;
            case 9:
                printf("Enter next value: ");
                scanf("%d", &prevData);
                deleteBefore(prevData);
                break;
            case 10:
                displayList();
                break;
            case 11:
                printf("Enter value to search: ");
                scanf("%d", &data);
                if(searchValue(data)){
                    printf("Value found in the list.\n");
                    }
                    else{
                        printf("Value not found in the list.\n");
                    }
                    break;
            case 12:
                    reverse();
                    break;
            case 13:
                    exit(0);
                    default:
                    printf("Invalid choice. Please try again.\n");
        }
    }
}
int main(){
    menu();
    return 0;
}

