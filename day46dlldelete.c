#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

//Insert at beginning
void insert() {
    int value;
    struct Node* newNode;

    printf("Enter value: ");
    scanf("%d", &value);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
       head->prev = newNode;

    head = newNode;
}

//Delete node
void deleteNode() {
    int value;
    struct Node *temp = head;

    printf("Enter value to delete: ");
    scanf("%d", &value);

    while (temp != NULL) {
        if (temp->data == value) {

            // If node is node
            if (temp->prev == NULL) {
                head = temp->next;
                if (head != NULL)
                   head->prev = NULL;
            }
            else {
                temp->prev->next = temp->next;
                if (temp->next != NULL)
                   temp->next->prev = temp->prev;
            }

            free(temp);
            printf("Node deleted\n");
            return;
        }
        temp = temp->next;
    }

    printf("Value not found\n");
}

//Display
void display() {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Elements:\n");

    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice;

    while (1) {

        printf("\n---Doubly Linked List---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        switch (choice) {
            case 1: insert(); break;
            case 2: deleteNode(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}