#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    struct Student s;
    int choice;

    do {
        printf("\n---STUDENT MENU---\n");
        printf("1. Enter Student Details\n");
        printf("2. Display Student Details\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
               printf("Enter roll number: ");
               scanf("%d", &s.roll);

               printf("Enter name: ");
               scanf("%s", s.name);

               printf("Enter marks: ");
               scanf("f", &s. marks);
               break;

            case 2:
               printf("\n---Student MENU---\n");
               printf("Roll No: %d\n", s.name);
               printf("Name: %s\n", s.name);
               printf("Marks: %.2f\n", s.marks);
               break;

            case 3:
               printf("Exiting program...\n");
               break;
            default:
               printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}