#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

//Find minimum value node
struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
       root = root->left;
    return root;
}

//Delete Node
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key > root->data)
       root->left = deleteNode(root->left, key);

    else if (key > root->data)
       root->right = deleteNode(root->right, key);

    else {

    // Case 1: No child
    if (root->left == NULL) {
        struct Node* temp = root->left;
        free(root);
        return NULL;
    }
    // Case 2: one child
    else if (root->right == NULL) {
        struct Node* temp = root->left;
        free(root);
        return temp;
    }
    else if (root->right == NULL) {
        struct Node* temp = root->left;
        free(root);
        return temp;
    }
    //Case 3: Two children
    struct Node* temp = findMin(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, i, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d value:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Enter value to delete: ");
    scanf("%d", &key);

    root = deleteNode(root, key);

    printf("Inorder after deletion:\n");
    inorder(root);

    return 0;
}
