
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node
{
    int key, height;
    Node *left, *right;

    Node(int k)
    {
        key = k;
        height = 1;
        left = right = NULL;
    }
};

int h(Node *n)
{
    return n == NULL ? 0 : n->height;
}

int bf(Node *n)
{
    return n == NULL ? 0 : h(n->left) - h(n->right);
}

Node* rightRotate(Node *y)
{
    Node *x = y->left;
    Node *t = x->right;

    x->right = y;
    y->left = t;

    y->height = 1 + max(h(y->left), h(y->right));
    x->height = 1 + max(h(x->left), h(x->right));

    return x;
}

Node* leftRotate(Node *x)
{
    Node *y = x->right;
    Node *t = y->left;

    y->left = x;
    x->right = t;

    x->height = 1 + max(h(x->left), h(x->right));
    y->height = 1 + max(h(y->left), h(y->right));

    return y;
}

void inorder(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->key);
    inorder(root->right, v);
}

void display(Node *root, int space = 0)
{
    if (root == NULL)
        return;

    space += 6;
    display(root->right, space);

    cout << endl;
    for (int i = 6; i < space; i++)
        cout << " ";

    cout << root->key << "(BF=" << bf(root) << ")" << endl;
    display(root->left, space);
}

Node* insert(Node *root, int key, bool show = false)
{
    if (root == NULL)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key, show);
    else if (key > root->key)
        root->right = insert(root->right, key, show);
    else
        return root;

    root->height = 1 + max(h(root->left), h(root->right));

    int balance = bf(root);

    if (balance > 1 && key < root->left->key)
    {
        if (show)
            cout << "\nLL case at node " << root->key
                 << ", BF = " << balance << endl;
        return rightRotate(root);
    }

    if (balance < -1 && key > root->right->key)
    {
        if (show)
            cout << "\nRR case at node " << root->key
                 << ", BF = " << balance << endl;
        return leftRotate(root);
    }

    if (balance > 1 && key > root->left->key)
    {
        if (show)
            cout << "\nLR case at node " << root->key
                 << ", BF = " << balance << endl;
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->key)
    {
        if (show)
            cout << "\nRL case at node " << root->key
                 << ", BF = " << balance << endl;
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void runDemo(int choice)
{
    Node *root = NULL;
    int a[3];

    if (choice == 1)
    {
        a[0] = 30; a[1] = 20; a[2] = 10;
    }
    else if (choice == 2)
    {
        a[0] = 10; a[1] = 20; a[2] = 30;
    }
    else if (choice == 3)
    {
        a[0] = 30; a[1] = 10; a[2] = 20;
    }
    else
    {
        a[0] = 10; a[1] = 30; a[2] = 20;
    }

    cout << "\nTree before the final insertion:\n";
    root = insert(root, a[0]);
    root = insert(root, a[1]);
    display(root);

    vector<int> before;
    inorder(root, before);

    cout << "\nInserting " << a[2] << "...\n";
    root = insert(root, a[2], true);

    cout << "\nTree after insertion and rotation:\n";
    display(root);

    vector<int> after;
    inorder(root, after);

    cout << "\nFinal inorder traversal: ";
    for (int i = 0; i < (int)after.size(); i++)
        cout << after[i] << " ";

    vector<int> expected;
    expected.push_back(a[0]);
    expected.push_back(a[1]);
    expected.push_back(a[2]);
    sort(expected.begin(), expected.end());

    if (after == expected)
        cout << "\nInorder verification: PASSED\n";
    else
        cout << "\nInorder verification: FAILED\n";
}

int main()
{
    int choice;

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

        if (choice >= 1 && choice <= 4)
            runDemo(choice);
        else if (choice == 5)
            cout << "Program ended.\n";
        else
            cout << "Invalid choice!\n";

    } while (choice != 5);

    return 0;
}

