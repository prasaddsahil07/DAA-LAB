/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Name: Sahil Prasad             		 %
%  Roll: 22CS8168                 		 %
%  Question: modified AVL tree  (q no: 1)%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/


#include <bits/stdc++.h>
using namespace std;

// Struct for the record of a student
struct record {
    char name[100];
    int roll;
    float cgpa;
};

// AVL Tree node for name
struct node_name {
    char name[100];
    record* data;
    node_name* left;
    node_name* right;
    int height;
};

// AVL Tree node for roll
struct node_roll {
    int roll;
    record* data;
    node_roll* left;
    node_roll* right;
    int height;
};

// AVL Tree node for CGPA
struct node_cgpa {
    float cgpa;
    record* data;
    node_cgpa* left;
    node_cgpa* right;
    int height;
};

// Utility function to get the height of a node
template<typename T>
int height(T* root) {
    return (root == nullptr) ? 0 : root->height;
}

// Utility function to get maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Right rotate utility for balancing the AVL tree
template<typename T>
T* rightRotate(T* y) {
    T* x = y->left;
    T* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotate utility for balancing the AVL tree
template<typename T>
T* leftRotate(T* x) {
    T* y = x->right;
    T* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Get balance factor of node
template<typename T>
int getBalance(T* root) {
    if (root == nullptr)
        return 0;
    return height(root->left) - height(root->right);
}

// Insert function for AVL Tree based on name
node_name* insertName(node_name* root, record* data) {
    if (root == nullptr) {
        node_name* newNode = new node_name();
        strcpy(newNode->name, data->name);
        newNode->data = data;
        newNode->left = newNode->right = nullptr;
        newNode->height = 1;
        return newNode;
    }

    if (strcmp(data->name, root->name) < 0)
        root->left = insertName(root->left, data);
    else if (strcmp(data->name, root->name) > 0)
        root->right = insertName(root->right, data);
    else
        return root;

    // Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Get balance factor
    int balance = getBalance(root);

    // Balance the tree
    if (balance > 1 && strcmp(data->name, root->left->name) < 0)
        return rightRotate(root);

    if (balance < -1 && strcmp(data->name, root->right->name) > 0)
        return leftRotate(root);

    if (balance > 1 && strcmp(data->name, root->left->name) > 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && strcmp(data->name, root->right->name) < 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Insert function for AVL Tree based on roll number
node_roll* insertRoll(node_roll* root, record* data) {
    if (root == nullptr) {
        node_roll* newNode = new node_roll();
        newNode->roll = data->roll;
        newNode->data = data;
        newNode->left = newNode->right = nullptr;
        newNode->height = 1;
        return newNode;
    }

    if (data->roll < root->roll)
        root->left = insertRoll(root->left, data);
    else if (data->roll > root->roll)
        root->right = insertRoll(root->right, data);
    else
        return root;

    // Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Get balance factor
    int balance = getBalance(root);

    // Balance the tree
    if (balance > 1 && data->roll < root->left->roll)
        return rightRotate(root);

    if (balance < -1 && data->roll > root->right->roll)
        return leftRotate(root);

    if (balance > 1 && data->roll > root->left->roll) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && data->roll < root->right->roll) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Insert function for AVL Tree based on CGPA
node_cgpa* insertCGPA(node_cgpa* root, record* data) {
    if (root == nullptr) {
        node_cgpa* newNode = new node_cgpa();
        newNode->cgpa = data->cgpa;
        newNode->data = data;
        newNode->left = newNode->right = nullptr;
        newNode->height = 1;
        return newNode;
    }

    if (data->cgpa < root->cgpa)
        root->left = insertCGPA(root->left, data);
    else if (data->cgpa > root->cgpa)
        root->right = insertCGPA(root->right, data);
    else
        return root;

    // Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Get balance factor
    int balance = getBalance(root);

    // Balance the tree
    if (balance > 1 && data->cgpa < root->left->cgpa)
        return rightRotate(root);

    if (balance < -1 && data->cgpa > root->right->cgpa)
        return leftRotate(root);

    if (balance > 1 && data->cgpa > root->left->cgpa) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && data->cgpa < root->right->cgpa) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Search functions
node_name* searchName(node_name* root, const char* name) {
    if (root == nullptr || strcmp(root->name, name) == 0)
        return root;
    
    if (strcmp(name, root->name) < 0)
        return searchName(root->left, name);
    
    return searchName(root->right, name);
}

node_roll* searchRoll(node_roll* root, int roll) {
    if (root == nullptr || root->roll == roll)
        return root;
    
    if (roll < root->roll)
        return searchRoll(root->left, roll);
    
    return searchRoll(root->right, roll);
}

node_cgpa* searchCGPA(node_cgpa* root, float cgpa) {
    if (root == nullptr || root->cgpa == cgpa)
        return root;
    
    if (cgpa < root->cgpa)
        return searchCGPA(root->left, cgpa);
    
    return searchCGPA(root->right, cgpa);
}

// Function to print records in sorted order (in-order traversal)
template<typename T>
void printInOrder(T* root) {
    if (root != nullptr) {
        printInOrder(root->left);
        cout << "(" << root->data->name << "," << root->data->roll << "," << root->data->cgpa << ")" << endl;
        printInOrder(root->right);
    }
}

// Options for users
void menu() {
    node_name* root_name = nullptr;
    node_roll* root_roll = nullptr;
    node_cgpa* root_cgpa = nullptr;

    int choice;
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        record* student = new record();
        
        cout << "Enter name: ";
        cin.ignore();
        cin.getline(student->name, 100);
        
        cout << "Enter roll number: ";
        cin >> student->roll;
        
        cout << "Enter CGPA: ";
        cin >> student->cgpa;

        root_name = insertName(root_name, student);
        root_roll = insertRoll(root_roll, student);
        root_cgpa = insertCGPA(root_cgpa, student);
    }

    while (true) {
        cout << "\nMenu\n";
        cout << "1. Search by Name\n";
        cout << "2. Search by Roll\n";
        cout << "3. Search by CGPA\n";
        cout << "4. Print ascending by Name\n";
        cout << "5. Print descending by Name\n";
        cout << "6. Print ascending by Roll\n";
        cout << "7. Print descending by Roll\n";
        cout << "8. Print ascending by CGPA\n";
        cout << "9. Print descending by CGPA\n";
        cout << "10. Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        if (choice == 1) {
            char name[100];
            cout << "Enter name: ";
            cin.ignore();
            cin.getline(name, 100);
            node_name* result = searchName(root_name, name);
            if (result)
                cout << "(" << result->data->name << ", " << result->data->roll << ", " << result->data->cgpa << ")" << endl;
            else
                cout << "No record found for " << name << endl;
        }
        else if (choice == 2) {
            int roll;
            cout << "Enter roll number: ";
            cin >> roll;
            node_roll* result = searchRoll(root_roll, roll);
            if (result)
                cout << "(" << result->data->name << ", " << result->data->roll << ", " << result->data->cgpa << ")" << endl;
            else
                cout << "No record found for roll " << roll << endl;
        }
        else if (choice == 3) {
            float cgpa;
            cout << "Enter CGPA: ";
            cin >> cgpa;
            node_cgpa* result = searchCGPA(root_cgpa, cgpa);
            if (result)
                cout << "(" << result->data->name << ", " << result->data->roll << ", " << result->data->cgpa << ")" << endl;
            else
                cout << "No record found for CGPA " << cgpa << endl;
        }
        else if (choice == 4) {
            cout << "Ascending by Name:\n";
            printInOrder(root_name);
        }
        else if (choice == 5) {
            cout << "Descending by Name:\n";
            printInOrder(root_name);
        }
        else if (choice == 6) {
            cout << "Ascending by Roll:\n";
            printInOrder(root_roll);
        }
        else if (choice == 7) {
            cout << "Descending by Roll:\n";
            printInOrder(root_roll); 
        }
        else if (choice == 8) {
            cout << "Ascending by CGPA:\n";
            printInOrder(root_cgpa);
        }
        else if (choice == 9) {
            cout << "Descending by CGPA:\n";
            printInOrder(root_cgpa);
        }
        else if (choice == 10) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }
}

int main() {
    menu();
    return 0;
}
