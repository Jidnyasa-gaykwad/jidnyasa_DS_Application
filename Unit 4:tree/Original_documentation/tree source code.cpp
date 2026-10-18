
#include <iostream>
using namespace std;

struct Node {
    int id;
    Node *left, *right;

    Node(int value) {
        id = value;
        left = right = NULL;
    }
};

Node* insert(Node* root, int id) {
    if (root == NULL)
        return new Node(id);

    if (id < root->id)
        root->left = insert(root->left, id);
    else if (id > root->id)
        root->right = insert(root->right, id);

    return root;
}

bool search(Node* root, int id) {
    if (root == NULL)
        return false;

    if (root->id == id)
        return true;

    if (id < root->id)
        return search(root->left, id);

    return search(root->right, id);
}

Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;

    return root;
}

Node* deleteNode(Node* root, int id) {
    if (root == NULL)
        return root;

    if (id < root->id)
        root->left = deleteNode(root->left, id);
    else if (id > root->id)
        root->right = deleteNode(root->right, id);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->id = temp->id;
        root->right = deleteNode(root->right, temp->id);
    }

    return root;
}

void display(Node* root) {
    if (root != NULL) {
        display(root->left);
        cout << root->id << " ";
        display(root->right);
    }
}

int main() {
    Node* root = NULL;
    int choice, id;

    do {
        cout << "\n\n1. Insert Employee ID";
        cout << "\n2. Search Employee ID";
        cout << "\n3. Delete Employee ID";
        cout << "\n4. Display Employee IDs";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Employee ID: ";
            cin >> id;
            if (search(root, id))
                cout << "Employee ID already exists!";
            else {
                root = insert(root, id);
                cout << "Employee ID inserted successfully.";
            }
            break;

        case 2:
            cout << "Enter Employee ID to search: ";
            cin >> id;
            if (search(root, id))
                cout << "Employee ID found.";
            else
                cout << "Employee ID not found.";
            break;

        case 3:
            cout << "Enter Employee ID to delete: ";
            cin >> id;
            if (search(root, id)) {
                root = deleteNode(root, id);
                cout << "Employee ID deleted successfully.";
            }
            else
                cout << "Employee ID not found.";
            break;

        case 4:
            cout << "Employee IDs in sorted order: ";
            display(root);
            break;

        case 5:
            cout << "Program terminated.";
            break;

        default:
            cout << "Invalid choice!";
        }
    } while (choice != 5);

    return 0;
}

