#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

struct Student s[100];
int count = 0;

void addStudent() {
    printf("Enter Roll Number: ");
    scanf("%d", &s[count].roll);

    printf("Enter Name: ");
    scanf("%s", s[count].name);

    printf("Enter Marks: ");
    scanf("%f", &s[count].marks);

    count++;
}

void displayStudent() {
    int i;

    for(i = 0; i < count; i++) {
        printf("\nRoll: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nMarks: %.2f\n", s[i].marks);
    }
}

void updateStudent() {
    int roll, i, found = 0;

    printf("Enter roll number to update: ");
    scanf("%d", &roll);

    for(i = 0; i < count; i++) {
        if(s[i].roll == roll) {
            printf("Enter new name: ");
            scanf("%s", s[i].name);

            printf("Enter new marks: ");
            scanf("%f", &s[i].marks);

            printf("Student updated successfully.\n");
            found = 1;
        }
    }

    if(!found)
        printf("Student not found.\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n---Student Management System---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Update Student\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudent();
                break;

            case 3:
                updateStudent();
                break;

            case 4:
                 return 0;

            default:
                 printf("Invalid choice\n");
        }
    }
}