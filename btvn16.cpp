#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

int height(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int balance_factor(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

int manual_max(int a, int b) {
    return (a > b) ? a : b;
}

Node* rotate_left(Node* root) {
    Node* new_root = root->right;
    root->right = new_root->left;
    new_root->left = root;
    root->height = 1 + manual_max(height(root->left), height(root->right));
    new_root->height = 1 + manual_max(height(new_root->left), height(new_root->right));
    return new_root;
}

Node* rotate_right(Node* root) {
    Node* new_root = root->left;
    root->left = new_root->right;
    new_root->right = root;
    root->height = 1 + manual_max(height(root->left), height(root->right));
    new_root->height = 1 + manual_max(height(new_root->left), height(new_root->right));
    return new_root;
}

Node* rotate_left_right(Node* root) {
    root->left = rotate_left(root->left);
    return rotate_right(root);
}

Node* rotate_right_left(Node* root) {
    root->right = rotate_right(root->right);
    return rotate_left(root);
}

Node* insert(Node* node, int data) {
    if (node == nullptr) {
        return new Node(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        return node;
    }
    node->height = 1 + manual_max(height(node->left), height(node->right));
    int balance = balance_factor(node);
    if (balance > 1 && data < node->left->data) {
        return rotate_right(node);
    }
    if (balance < -1 && data > node->right->data) {
        return rotate_left(node);
    }
    if (balance > 1 && data > node->left->data) {
        return rotate_left_right(node);
    }
    if (balance < -1 && data < node->right->data) {
        return rotate_right_left(node);
    }
    return node;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void free_tree(Node* root) {
    if (root != nullptr) {
        free_tree(root->left);
        free_tree(root->right);
        delete root;
    }
}

int main() {
    int values[] = {17, 23, 201, 98, 67, 83, 13, 23, 10, 191, 84, 58};
    int n = sizeof(values) / sizeof(values[0]);
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }
    cout << "Cay AVL theo thu tu duyet:\n";
    inorder(root);
    cout << endl;
    free_tree(root);
    return 0;
}
