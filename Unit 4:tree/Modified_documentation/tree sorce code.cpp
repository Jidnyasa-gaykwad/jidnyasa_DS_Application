
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Node structure
struct Node {
    int id;
    Node* left;
    Node* right;

    Node(int value) {
        id = value;
        left = right = nullptr;
    }
};

// Insert employee ID into BST
Node* insertBST(Node* root, int id) {
    if (root == nullptr)
        return new Node(id);

    if (id < root->id)
        root->left = insertBST(root->left, id);
    else if (id > root->id)
        root->right = insertBST(root->right, id);
    else
        cout << "Duplicate Employee ID not allowed.\n";

    return root;
}

// Search employee ID
bool searchBST(Node* root, int id) {
    if (root == nullptr)
        return false;

    if (root->id == id)
        return true;

    if (id < root->id)
        return searchBST(root->left, id);

    return searchBST(root->right, id);
}

// Find minimum node
Node* findMin(Node* root) {
    while (root != nullptr && root->left != nullptr)
        root = root->left;

    return root;
}

// Delete employee ID
Node* deleteBST(Node* root, int id) {
    if (root == nullptr)
        return nullptr;

    if (id < root->id) {
        root->left = deleteBST(root->left, id);
    } else if (id > root->id) {
        root->right = deleteBST(root->right, id);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->id = temp->id;
        root->right = deleteBST(root->right, temp->id);
    }

    return root;
}

// Inorder traversal
void inorder(Node* root, vector<int>& result) {
    if (root == nullptr)
        return;

    inorder(root->left, result);
    result.push_back(root->id);
    inorder(root->right, result);
}

void displayInorder(Node* root) {
    vector<int> result;
    inorder(root, result);

    if (result.empty()) {
        cout << "Tree is empty.\n";
        return;
    }

    for (int id : result)
        cout << id << " ";

    cout << "\n";
}

// Calculate height and balance factor
int height(Node* root) {
    if (root == nullptr)
        return 0;

    return 1 + max(height(root->left),
                   height(root->right));
}

int balanceFactor(Node* root) {
    if (root == nullptr)
        return 0;

    return height(root->left) - height(root->right);
}

// Right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* temp = x->right;

    x->right = y;
    y->left = temp;

    return x;
}

// Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* temp = y->left;

    y->left = x;
    x->right = temp;

    return y;
}

// Free memory
void freeTree(Node* root) {
    if (root == nullptr)
        return;

    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

// Demonstrate selected AVL rotation
void demonstrateAVL() {
    int choice;

    cout << "\n--- AVL Rotation Cases ---\n";
    cout << "1. LL Rotation\n";
    cout << "2. RR Rotation\n";
    cout << "3. LR Rotation\n";
    cout << "4. RL Rotation\n";
    cout << "Select rotation case: ";
    cin >> choice;

    vector<int> values;

    switch (choice) {
        case 1:
            values = {30, 20, 10};
            break;
        case 2:
            values = {10, 20, 30};
            break;
        case 3:
            values = {30, 10, 20};
            break;
        case 4:
            values = {10, 30, 20};
            break;
        default:
            cout << "Invalid rotation choice.\n";
            return;
    }

    Node* root = nullptr;

    // Build an unbalanced BST for demonstration
    for (int id : values)
        root = insertBST(root, id);

    cout << "\nTree values inserted: ";
    for (int id : values)
        cout << id << " ";
    cout << "\n";

    cout << "Root ID: " << root->id << "\n";
    cout << "Root balance factor: "
         << balanceFactor(root) << "\n";

    if (root->left != nullptr)
        cout << "Left child balance factor: "
             << balanceFactor(root->left) << "\n";

    if (root->right != nullptr)
        cout << "Right child balance factor: "
             << balanceFactor(root->right) << "\n";

    vector<int> before;
    inorder(root, before);

    cout << "Inorder before rotation: ";
    displayInorder(root);

    // Apply the selected rotation
    switch (choice) {
        case 1: // LL
            cout << "Applying Right Rotation (LL).\n";
            root = rightRotate(root);
            break;

        case 2: // RR
            cout << "Applying Left Rotation (RR).\n";
            root = leftRotate(root);
            break;

        case 3: // LR
            cout << "Applying Left-Right Rotation (LR).\n";
            root->left = leftRotate(root->left);
            root = rightRotate(root);
            break;

        case 4: // RL
            cout << "Applying Right-Left Rotation (RL).\n";
            root->right = rightRotate(root->right);
            root = leftRotate(root);
            break;
    }

    vector<int> after;
    inorder(root, after);

    cout << "New root ID: " << root->id << "\n";
    cout << "Inorder after rotation: ";
    displayInorder(root);

    if (before == after)
        cout << "Verification successful: Inorder unchanged.\n";
    else
        cout << "Verification failed: Inorder changed.\n";

    cout << "New root balance factor: "
         << balanceFactor(root) << "\n";

    freeTree(root);
}

int main() {
    Node* root = nullptr;
    int choice, id;

    do {
        cout << "\n=== Employee ID Management ===\n";
        cout << "1. Insert Employee ID\n";
        cout << "2. Search Employee ID\n";
        cout << "3. Delete Employee ID\n";
        cout << "4. Display Sorted Employee IDs\n";
        cout << "5. AVL Rotation Demonstration\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting.\n";
            break;
        }

        switch (choice) {
            case 1:
                cout << "Enter Employee ID: ";
                cin >> id;
                root = insertBST(root, id);
                break;

            case 2:
                cout << "Enter Employee ID to search: ";
                cin >> id;

                if (searchBST(root, id))
                    cout << "Employee ID found.\n";
                else
                    cout << "Employee ID not found.\n";
                break;

            case 3:
                cout << "Enter Employee ID to delete: ";
                cin >> id;

                if (searchBST(root, id)) {
                    root = deleteBST(root, id);
                    cout << "Employee ID deleted.\n";
                } else {
                    cout << "Employee ID not found.\n";
                }
                break;

            case 4:
                cout << "Employee IDs in sorted order: ";
                displayInorder(root);
                break;

            case 5:
                demonstrateAVL();
                break;

            case 6:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    freeTree(root);
    return 0;
}

