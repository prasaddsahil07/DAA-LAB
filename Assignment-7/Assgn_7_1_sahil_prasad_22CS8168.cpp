/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Name: Sahil Prasad             		 %
%  Roll: 22CS8168                 		 %
%  Question: modified AVL tree  (q no: 1)%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/



#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr) {}
};

TreeNode* rotateRight(TreeNode* x) {
    TreeNode* y = x->left;
    x->left = y->right;
    if (y->right) y->right->parent = x;
    y->parent = x->parent;
    if (x->parent) {
        if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
    }
    y->right = x;
    x->parent = y;
    return y;
}

TreeNode* rotateLeft(TreeNode* x) {
    TreeNode* y = x->right;
    x->right = y->left;
    if (y->left) y->left->parent = x;
    y->parent = x->parent;
    if (x->parent) {
        if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
    return y;
}

TreeNode* doubleRotate(TreeNode* x) {
    TreeNode* p = x->parent;
    TreeNode* g = p->parent;

    if (p->right == x && g->left == p) {
        rotateLeft(p);
        return rotateRight(g);
    }
    if (p->left == x && g->right == p) {
        rotateRight(p);
        return rotateLeft(g);
    }
    return x;
}

TreeNode* bringToRoot(TreeNode* node) {
    while (node->parent) {
        TreeNode* p = node->parent;
        TreeNode* g = p->parent;

        if (!g) {
            if (p->left == node) node = rotateRight(p);
            else node = rotateLeft(p);
        } else {
            if ((g->left == p && p->right == node) || (g->right == p && p->left == node)) {
                node = doubleRotate(node);
            } else {
                if (p->left == node) node = rotateRight(g);
                else node = rotateLeft(g);
            }
        }
    }
    return node;
}

TreeNode* insert(TreeNode* root, int key) {
    if (!root) return new TreeNode(key);

    TreeNode* current = root;
    TreeNode* parent = nullptr;

    while (current) {
        parent = current;
        if (key < current->data) current = current->left;
        else if (key > current->data) current = current->right;
        else return root;
    }

    TreeNode* newNode = new TreeNode(key);
    newNode->parent = parent;

    if (key < parent->data) parent->left = newNode;
    else parent->right = newNode;

    return bringToRoot(newNode);
}

TreeNode* search(TreeNode* root, int key) {
    TreeNode* current = root;

    while (current && current->data != key) {
        if (key < current->data) current = current->left;
        else current = current->right;
    }

    if (!current) {
        cout << "Key not found!" << endl;
        return root;
    }

    return bringToRoot(current);
}

void preOrderTraversal(TreeNode* node) {
    if (!node) return;
    cout << node->data << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

int main() {
    TreeNode* root = nullptr;
    int choice, key;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert a key\n";
        cout << "2. Search for a key\n";
        cout << "3. Display pre-order traversal\n";
        cout << "4. Exit\n";
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                root = insert(root, key);
                break;

            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                root = search(root, key);
                break;

            case 3:
                cout << "Pre-order traversal of the tree: ";
                preOrderTraversal(root);
                cout << endl;
                break;

            case 4:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}
