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

    if(count == 0) {
        printf("No student records.\n");
        return;
    }

    for(i = 0; i < count; i++) {
        printf("\nRoll: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nMarks: %.2f\n", s[i].marks);
    }
}

void deleteStudent() {
    int roll, i, j;

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    for(i = 0; i < count; i++) {
        if(s[i].roll == roll) {

            for(j = i; j < count - 1; j++) {
                s[j] = s[j + 1];
            }

            count--;
            printf("Student deleted successfully.\n");
            return;
        }
    }

    printf("Student not found.\n");
}

int main() {
    int choice;

    while(1) {

        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Delete Student\n");
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
                deleteStudent();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}