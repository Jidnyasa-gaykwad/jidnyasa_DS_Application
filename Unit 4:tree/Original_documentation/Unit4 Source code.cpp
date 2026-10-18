
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    int height;

    Node(int value)
    {
        data = value;
        left = right = NULL;
        height = 1;
    }
};

int height(Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

int balanceFactor(Node *n)
{
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

// Display tree in sideways format
void displayTree(Node *root, int space = 0)
{
    if (root == NULL)
        return;

    space += 5;

    displayTree(root->right, space);

    cout << endl;
    for (int i = 5; i < space; i++)
        cout << " ";

    cout << root->data << endl;

    displayTree(root->left, space);
}

// LL Rotation: Right Rotation
Node* rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left),
                        height(y->right));
    x->height = 1 + max(height(x->left),
                        height(x->right));

    return x;
}

// RR Rotation: Left Rotation
Node* leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left),
                        height(x->right));
    y->height = 1 + max(height(y->left),
                        height(y->right));

    return y;
}

// AVL insertion with rotation demonstration
Node* insert(Node *root, int key)
{
    if (root == NULL)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = balanceFactor(root);

    // LL Case
    if (balance > 1 && key < root->left->data)
    {
        cout << "\nLL Rotation required at node "
             << root->data << endl;
        cout << "Before Rotation:\n";
        displayTree(root);

        root = rightRotate(root);

        cout << "\nAfter LL Rotation:\n";
        displayTree(root);
        cout << "\n";
        return root;
    }

    // RR Case
    if (balance < -1 && key > root->right->data)
    {
        cout << "\nRR Rotation required at node "
             << root->data << endl;
        cout << "Before Rotation:\n";
        displayTree(root);

        root = leftRotate(root);

        cout << "\nAfter RR Rotation:\n";
        displayTree(root);
        cout << "\n";
        return root;
    }

    // LR Case
    if (balance > 1 && key > root->left->data)
    {
        cout << "\nLR Rotation required at node "
             << root->data << endl;
        cout << "Before Rotation:\n";
        displayTree(root);

        root->left = leftRotate(root->left);
        root = rightRotate(root);

        cout << "\nAfter LR Rotation:\n";
        displayTree(root);
        cout << "\n";
        return root;
    }

    // RL Case
    if (balance < -1 && key < root->right->data)
    {
        cout << "\nRL Rotation required at node "
             << root->data << endl;
        cout << "Before Rotation:\n";
        displayTree(root);

        root->right = rightRotate(root->right);
        root = leftRotate(root);

        cout << "\nAfter RL Rotation:\n";
        displayTree(root);
        cout << "\n";
        return root;
    }

    return root;
}

int main()
{
    int choice, n, value;
    Node *root = NULL;

    do
    {
        cout << "\n===== AVL ROTATION DEMONSTRATION =====\n";
        cout << "1. LL Rotation (30, 20, 10)\n";
        cout << "2. RR Rotation (10, 20, 30)\n";
        cout << "3. LR Rotation (30, 10, 20)\n";
        cout << "4. RL Rotation (10, 30, 20)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        root = NULL;

        switch (choice)
        {
            case 1:
                root = insert(root, 30);
                root = insert(root, 20);
                root = insert(root, 10);
                break;

            case 2:
                root = insert(root, 10);
                root = insert(root, 20);
                root = insert(root, 30);
                break;

            case 3:
                root = insert(root, 30);
                root = insert(root, 10);
                root = insert(root, 20);
                break;

            case 4:
                root = insert(root, 10);
                root = insert(root, 30);
                root = insert(root, 20);
                break;

            case 5:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

        if (choice >= 1 && choice <= 4)
        {
            cout << "\nFinal Balanced AVL Tree:\n";
            displayTree(root);
            cout << "\n";
        }

    } while (choice != 5);

    return 0;
}

