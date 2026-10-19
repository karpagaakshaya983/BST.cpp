#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* insert(Node* root, int value) {
    if (root == NULL) {
        Node* temp = new Node();
        temp->data = value;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int ids[] = {50, 30, 70, 20, 40, 60, 80};

    for (int id : ids)
        root = insert(root, id);

    cout << "Employee IDs in BST: ";
    inorder(root);

    return 0;
}
