#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Insert at beginning
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

    printf("Inserted successfully\n");
}

// Display
void display() {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Elements:\n");

    while (temp != NULL) {
        printf("%d ", temp->data);  // Added space for clarity
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n---Doubly Linked List---\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
