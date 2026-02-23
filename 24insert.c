#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

//Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    return newNode;
}

//Insert into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
       return createNode(value);

    if (value < root->data)
       root->left = insert(root->left, value);
    else
       root->right = insert(root->right,value);
    return root;
}

//Inorder Traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Inorder Traversal (Sorted Order):\n");
    inorder(root);

    return 0;
}