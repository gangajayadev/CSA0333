#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int* index) {
    int val = arr[(*index)++];
    struct Node* root = createNode(val);
    if (root == NULL) return NULL;
    root->left = buildTree(arr, index);
    root->right = buildTree(arr, index);
    return root;
}

void inorder(struct Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int arr[100], n = 0, x;
    printf("Enter tree in preorder (-1 for NULL), e.g. 1 2 -1 -1 3 -1 -1:\n");
    while (scanf("%d", &x) == 1) arr[n++] = x;

    int index = 0;
    struct Node* root = buildTree(arr, &index);

    printf("\nInorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\n");

    return 0;
}
