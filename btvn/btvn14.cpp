#include <stdio.h>
#include <stdlib.h>

struct Node {
    char value[10];
    Node* left;
    Node* right;
};

Node* createNode(const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    int i = 0;
    while (value[i] != '\0') {
        newNode->value[i] = value[i];
        i++;
    }
    newNode->value[i] = '\0';
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(char postfix[][10], int* index) {
    if (*index < 0) return NULL;
    Node* newNode = createNode(postfix[*index]);
    (*index)--;
    if (newNode->value[0] == '+' || newNode->value[0] == '-' || 
        newNode->value[0] == '*' || newNode->value[0] == '/' || 
        newNode->value[0] == '^') {
        newNode->right = insertNode(postfix, index);
        newNode->left = insertNode(postfix, index);
    }
    return newNode;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%s", root->value);
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL) return;
    printf("%s ", root->value);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%s ", root->value);
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    char postfix[][10] = {"a", "5", "*", "b", "6", "^", "d", "/", "-", "h", "f", "-", "e", "1", "/", "^", "*", "+"};
    int size = sizeof(postfix) / sizeof(postfix[0]);
    int index = size - 1;
    Node* root = insertNode(postfix, &index);
    
    printf("Trung to: ");
    inorder(root);
    printf("\n");
    
    printf("Tien to: ");
    preorder(root);
    printf("\n");
    
    printf("Hau to: ");
    postorder(root);
    printf("\n");
    
    freeTree(root);
    return 0;
}


