#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node *left, *right;
};

//Stack for tree nodes
struct Node* stack[100];
int top = -1;

//push
void push(struct Node* node) {
    stack[++top] = node;
}

//pop
struct Node* pop() {
    return stack[top--];
}

//Create node
struct Node* createNode(char value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//Build expression tree
struct Node* buildTree(char postfix[]) {
    int i;

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {
            push(createNode(postfix[i]));
        }
        else {
            struct Node* newNode = createNode(postfix[i]);

            newNode->right = pop();
            newNode->left = pop();

            push(newNode);
        }
    }

    return pop();
}

//Inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
}

int main() {
    char postfix[100];
    struct Node* root;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    root = buildTree(postfix);

    printf("Inorder traversal: ");
    inorder(root);

    return 0;
}