#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    struct Student s[3];   //Array of structure
    int i;
    // Input
    for (i = 0; i < 3; i++) {
        printf("\nEnter details for student %d", i + 1);

        printf("Roll number: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf("%s", s[i].marks);
    }

    //Display
    printf("\n-----Student Records----\n");

    for (i = 0; i < 3; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Roll No: %d\n", s[i].roll);
        printf("Name: %.2f\n",s[i].marks);
    }
    return 0;
}