#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue() {
    int value;

    if (rear == MAX -1) {
        printf("Queue Overflow\n");
        return;
    }

    printf("Enter value to enqueue: ");
    scanf("%d", &value);

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;

    printf("Value inserted successfully\n");
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);
    front++;
}

void display() {
    int i;

    if (front == - 1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements:\n");

    for (i = front; i <= rear; i++) {
        printf("%d", queue[i]);
    }

    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n---Queue Menu---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
               enqueue();
               break;

            case 2:
               dequeue();
               break;

            case 3:
               display();
               break;

            case 4:
               return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}