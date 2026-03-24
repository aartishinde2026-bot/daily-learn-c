#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Create new node
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insert(struct Node* head, int c, int e) {
    struct Node* newNode = createNode(c, e);
    struct Node* temp = head;

    if (head == NULL)
        return newNode;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Add polynomials
struct Node* addPoly(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            result = insert(result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp) {
            result = insert(result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else {
            result = insert(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        result = insert(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        result = insert(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

// Display polynomial
void display(struct Node* head) {
    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->exp);
        if (head->next != NULL)
            printf(" + ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *p1 = NULL, *p2 = NULL, *result = NULL;

    // First polynomial: 5x^2 + 4x^1
    p1 = insert(p1, 5, 2);
    p1 = insert(p1, 4, 1);

    // Second polynomial: 3x^2 + 2x^0
    p2 = insert(p2, 3, 2);
    p2 = insert(p2, 2, 0);

    printf("Polynomial 1: ");
    display(p1);

    printf("Polynomial 2: ");
    display(p2);

    result = addPoly(p1, p2);

    printf("Result: ");
    display(result);

    return 0;
}