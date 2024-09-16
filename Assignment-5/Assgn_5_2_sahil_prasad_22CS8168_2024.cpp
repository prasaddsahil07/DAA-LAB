/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Name: Sahil Prasad             		 %
%  Roll: 22CS8168                 		 %
%  Question: BST_and_AVL_tree  (q no: 2) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left;ī
    Node* right;
    Node* parent;

    Node(int value) : key(value), left(nullptr), right(nullptr), parent(nullptr) {}
};

class BST {
public:
    Node* root;

    BST() : root(nullptr) {}

    // Insert a new key
    void insert(int key) {
        root = insert(root, key, nullptr);
        printPreOrder();
    }

    // Delete a key
    void deleteKey(int key) {
        root = deleteNode(root, key);
        printPreOrder();
    }

    // Print pre-order traversal
    void printPreOrder() {
        preOrderTraversal(root);
        cout << endl;
    }

    // Balance the tree using O(n) divide and conquer technique
    void balanceTree() {
        vector<int> inOrderKeys;
        storeInOrder(root, inOrderKeys);
        root = buildBalancedTree(inOrderKeys, 0, inOrderKeys.size() - 1);
        printPreOrder();
    }

private:
    // Recursive function to insert a new node
    Node* insert(Node* node, int key, Node* parent) {
        if (!node) {
            Node* newNode = new Node(key);
            newNode->parent = parent;
            return newNode;
        }

        if (key < node->key) {
            node->left = insert(node->left, key, node);
        } else if (key > node->key) {
            node->right = insert(node->right, key, node);
        }

        return node;
    }

    // Recursive function to delete a node
    Node* deleteNode(Node* root, int key) {
        if (!root) return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            // Node with one child or no child
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children, use in-order predecessor
            Node* temp = findMax(root->left);
            root->key = temp->key;
            root->left = deleteNode(root->left, temp->key);
        }
        return root;
    }

    // Helper function to find the in-order predecessor (maximum node in left subtree)
    Node* findMax(Node* node) {
        while (node->right) {
            node = node->right;
        }
        return node;
    }

    // Recursive pre-order traversal
    void preOrderTraversal(Node* node) {
        if (node) {
            cout << node->key << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }

    // Store in-order traversal in a vector
    void storeInOrder(Node* node, vector<int>& keys) {
        if (node) {
            storeInOrder(node->left, keys);
            keys.push_back(node->key);
            storeInOrder(node->right, keys);
        }
    }

    // Build a balanced tree from sorted keys (divide-and-conquer, O(n) approach)
    Node* buildBalancedTree(vector<int>& keys, int start, int end) {
        if (start > end) return nullptr;

        int mid = (start + end) / 2;
        Node* node = new Node(keys[mid]);

        node->left = buildBalancedTree(keys, start, mid - 1);
        node->right = buildBalancedTree(keys, mid + 1, end);

        return node;
    }
};

int main() {
    BST bst;
    int choice, key;
    while (true) {
        cout << "1. Insert\n2. Delete\n3. Balance\n4. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                bst.insert(key);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                bst.deleteKey(key);
                break;
            case 3:
                bst.balanceTree();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice, try again.\n";
        }
    }
    return 0;
}
