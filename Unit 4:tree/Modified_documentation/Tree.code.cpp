
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ==========================================
// BUS DETAILS
// ==========================================
struct Bus
{
    int routeNo;
    string busName, source, destination;
};

vector<Bus> routes;

// Predefined bus routes
Bus predefined[] =
{
    {101, "Shivneri", "Pune", "Mumbai"},
    {102, "Express", "Nashik", "Pune"},
    {103, "Citybus", "Mumbai", "Nashik"},
    {104, "Deccan", "Pune", "Nashik"},
    {105, "MSRTC", "Ahmednagar", "Pune"}
};

const int TOTAL_BUSES = 5;

// ==========================================
// BINARY TREE / BST NODE
// ==========================================
struct Node
{
    Bus bus;
    Node *left, *right;
    int height;
};

Node* createNode(Bus b)
{
    Node* n = new Node;
    n->bus = b;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

// ==========================================
// BST OPERATIONS
// ==========================================
Node* insertBST(Node* root, Bus b)
{
    if (root == NULL)
        return createNode(b);

    if (b.routeNo < root->bus.routeNo)
        root->left = insertBST(root->left, b);
    else if (b.routeNo > root->bus.routeNo)
        root->right = insertBST(root->right, b);

    return root;
}

Node* searchBST(Node* root, int no)
{
    if (root == NULL || root->bus.routeNo == no)
        return root;

    if (no < root->bus.routeNo)
        return searchBST(root->left, no);

    return searchBST(root->right, no);
}

void displayBus(Bus b)
{
    cout << "\nRoute Number : " << b.routeNo;
    cout << "\nBus Name     : " << b.busName;
    cout << "\nSource       : " << b.source;
    cout << "\nDestination  : " << b.destination;
    cout << "\n-----------------------------\n";
}

// Inorder: Left, Root, Right
void inorder(Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        displayBus(root->bus);
        inorder(root->right);
    }
}

// Preorder: Root, Left, Right
void preorder(Node* root)
{
    if (root != NULL)
    {
        displayBus(root->bus);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder: Left, Right, Root
void postorder(Node* root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        displayBus(root->bus);
    }
}

Node* findMin(Node* root)
{
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

Node* findMax(Node* root)
{
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

// ==========================================
// AVL TREE
// ==========================================
int nodeHeight(Node* n)
{
    if (n == NULL)
        return 0;

    return n->height;
}

int balanceFactor(Node* n)
{
    if (n == NULL)
        return 0;

    return nodeHeight(n->left) - nodeHeight(n->right);
}

void updateHeight(Node* n)
{
    n->height = 1 + max(nodeHeight(n->left),
                        nodeHeight(n->right));
}

// Right rotation: LL case
Node* rotateRight(Node* y)
{
    Node* x = y->left;
    Node* temp = x->right;

    x->right = y;
    y->left = temp;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Left rotation: RR case
Node* rotateLeft(Node* x)
{
    Node* y = x->right;
    Node* temp = y->left;

    y->left = x;
    x->right = temp;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// AVL insertion with LL, RR, LR and RL rotations
Node* insertAVL(Node* root, Bus b)
{
    if (root == NULL)
        return createNode(b);

    if (b.routeNo < root->bus.routeNo)
        root->left = insertAVL(root->left, b);
    else if (b.routeNo > root->bus.routeNo)
        root->right = insertAVL(root->right, b);
    else
        return root;

    updateHeight(root);

    int balance = balanceFactor(root);

    // LL rotation
    if (balance > 1 &&
        b.routeNo < root->left->bus.routeNo)
        return rotateRight(root);

    // RR rotation
    if (balance < -1 &&
        b.routeNo > root->right->bus.routeNo)
        return rotateLeft(root);

    // LR rotation
    if (balance > 1 &&
        b.routeNo > root->left->bus.routeNo)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // RL rotation
    if (balance < -1 &&
        b.routeNo < root->right->bus.routeNo)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// ==========================================
// THREADED BINARY SEARCH TREE
// ==========================================
struct ThreadNode
{
    Bus bus;
    ThreadNode *left, *right;
    bool rightThread;
};

ThreadNode* createThreadNode(Bus b)
{
    ThreadNode* n = new ThreadNode;

    n->bus = b;
    n->left = NULL;
    n->right = NULL;
    n->rightThread = false;

    return n;
}

ThreadNode* insertThreadBST(ThreadNode* root, Bus b)
{
    if (root == NULL)
        return createThreadNode(b);

    if (b.routeNo < root->bus.routeNo)
        root->left = insertThreadBST(root->left, b);

    else if (b.routeNo > root->bus.routeNo)
        root->right = insertThreadBST(root->right, b);

    return root;
}

// Collect nodes in inorder before creating threads
void collectInorder(ThreadNode* root,
                    vector<ThreadNode*>& nodes)
{
    if (root == NULL)
        return;

    collectInorder(root->left, nodes);
    nodes.push_back(root);

    if (!root->rightThread)
        collectInorder(root->right, nodes);
}

// Create threads to inorder successors
void createThreads(ThreadNode* root)
{
    vector<ThreadNode*> nodes;
    collectInorder(root, nodes);

    for (int i = 0; i < (int)nodes.size(); i++)
    {
        if (nodes[i]->right == NULL)
        {
            nodes[i]->rightThread = true;

            if (i + 1 < (int)nodes.size())
                nodes[i]->right = nodes[i + 1];
        }
    }
}

// Inorder traversal without recursion or stack
void threadedInorder(ThreadNode* root)
{
    if (root == NULL)
    {
        cout << "\nNo routes available!\n";
        return;
    }

    ThreadNode* current = root;

    // Find leftmost node
    while (current->left != NULL)
        current = current->left;

    cout << "\n===== THREADED BST INORDER =====\n";

    while (current != NULL)
    {
        displayBus(current->bus);

        if (current->rightThread)
            current = current->right;
        else
        {
            current = current->right;

            while (current != NULL &&
                   current->left != NULL)
                current = current->left;
        }
    }
}

// ==========================================
// REBUILD ALL TREES FROM ACTIVE ROUTES
// ==========================================
Node* bstRoot = NULL;
Node* avlRoot = NULL;
ThreadNode* threadRoot = NULL;

void rebuildTrees()
{
    bstRoot = NULL;
    avlRoot = NULL;
    threadRoot = NULL;

    for (int i = 0; i < (int)routes.size(); i++)
    {
        bstRoot = insertBST(bstRoot, routes[i]);
        avlRoot = insertAVL(avlRoot, routes[i]);
        threadRoot = insertThreadBST(threadRoot, routes[i]);
    }

    createThreads(threadRoot);
}

// ==========================================
// ADD PREDEFINED ROUTE
// ==========================================
void addRoute()
{
    int no;

    cout << "\n===== AVAILABLE BUS ROUTES =====\n";

    for (int i = 0; i < TOTAL_BUSES; i++)
    {
        cout << predefined[i].routeNo << " - "
             << predefined[i].busName << " - "
             << predefined[i].source << " to "
             << predefined[i].destination << "\n";
    }

    cout << "\nEnter route number to add (0 to cancel): ";
    cin >> no;

    if (no == 0)
    {
        cout << "\nOperation cancelled.\n";
        return;
    }

    for (int i = 0; i < (int)routes.size(); i++)
    {
        if (routes[i].routeNo == no)
        {
            cout << "\nRoute already added!\n";
            return;
        }
    }

    for (int i = 0; i < TOTAL_BUSES; i++)
    {
        if (predefined[i].routeNo == no)
        {
            routes.push_back(predefined[i]);
            rebuildTrees();

            cout << "\nBus route added successfully!\n";
            return;
        }
    }

    cout << "\nInvalid route number!\n";
}

// ==========================================
// TREE TERMINOLOGY
// ==========================================
int countNodes(Node* root)
{
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left)
             + countNodes(root->right);
}

int countLeaves(Node* root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaves(root->left)
         + countLeaves(root->right);
}

void displayTreeInfo(Node* root)
{
    cout << "\n===== BINARY TREE INFORMATION =====\n";

    if (root == NULL)
    {
        cout << "Tree is empty.\n";
        return;
    }

    cout << "Root Route Number : "
         << root->bus.routeNo << "\n";

    cout << "Total Nodes       : "
         << countNodes(root) << "\n";

    cout << "Leaf Nodes        : "
         << countLeaves(root) << "\n";

    cout << "Tree Height       : "
         << nodeHeight(root) << "\n";

    cout << "Root Balance Factor: "
         << balanceFactor(root) << "\n";

    cout << "Left Child        : ";

    if (root->left != NULL)
        cout << root->left->bus.routeNo << "\n";
    else
        cout << "NULL\n";

    cout << "Right Child       : ";

    if (root->right != NULL)
        cout << root->right->bus.routeNo << "\n";
    else
        cout << "NULL\n";
}

// ==========================================
// DELETE ROUTE FROM ACTIVE ROUTES
// ==========================================
void deleteRoute()
{
    int no;

    cout << "\nEnter route number to delete: ";
    cin >> no;

    for (int i = 0; i < (int)routes.size(); i++)
    {
        if (routes[i].routeNo == no)
        {
            routes.erase(routes.begin() + i);
            rebuildTrees();

            cout << "\nRoute deleted successfully!\n";
            return;
        }
    }

    cout << "\nRoute not found!\n";
}

// ==========================================
// MAIN MENU
// ==========================================
int main()
{
    int choice, no;
    Node* result;

    do
    {
        cout << "\n\n===== BUS ROUTE MANAGEMENT =====";
        cout << "\n1. Add Predefined Bus Route";
        cout << "\n2. Search Bus Route";
        cout << "\n3. Display Routes in Sorted Order";
        cout << "\n4. Preorder Traversal";
        cout << "\n5. Inorder Traversal";
        cout << "\n6. Postorder Traversal";
        cout << "\n7. Delete Bus Route";
        cout << "\n8. Find Minimum Route Number";
        cout << "\n9. Find Maximum Route Number";
        cout << "\n10. Display Binary Tree Information";
        cout << "\n11. Threaded BST Inorder Traversal";
        cout << "\n12. Display AVL Tree Traversal";
        cout << "\n13. Display AVL Height and Balance";
        cout << "\n14. Exit";
        cout << "\nEnter your choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                addRoute();
                break;

            case 2:
                cout << "Enter route number to search: ";
                cin >> no;

                result = searchBST(bstRoot, no);

                if (result != NULL)
                    displayBus(result->bus);
                else
                    cout << "\nRoute not found!\n";
                break;

            case 3:
                if (bstRoot == NULL)
                    cout << "\nNo routes added!\n";
                else
                    inorder(bstRoot);
                break;

            case 4:
                if (bstRoot == NULL)
                    cout << "\nNo routes added!\n";
                else
                    preorder(bstRoot);
                break;

            case 5:
                if (bstRoot == NULL)
                    cout << "\nNo routes added!\n";
                else
                    inorder(bstRoot);
                break;

            case 6:
                if (bstRoot == NULL)
                    cout << "\nNo routes added!\n";
                else
                    postorder(bstRoot);
                break;

            case 7:
                deleteRoute();
                break;

            case 8:
                result = findMin(bstRoot);

                if (result != NULL)
                    cout << "\nMinimum Route Number: "
                         << result->bus.routeNo << "\n";
                else
                    cout << "\nNo routes available!\n";
                break;

            case 9:
                result = findMax(bstRoot);

                if (result != NULL)
                    cout << "\nMaximum Route Number: "
                         << result->bus.routeNo << "\n";
                else
                    cout << "\nNo routes available!\n";
                break;

            case 10:
                displayTreeInfo(bstRoot);
                break;

            case 11:
                threadedInorder(threadRoot);
                break;

            case 12:
                if (avlRoot == NULL)
                    cout << "\nNo routes added!\n";
                else
                {
                    cout << "\n===== AVL TREE INORDER =====\n";
                    inorder(avlRoot);
                }
                break;

            case 13:
                if (avlRoot == NULL)
                    cout << "\nAVL tree is empty!\n";
                else
                {
                    cout << "\nAVL Tree Height: "
                         << nodeHeight(avlRoot) << "\n";

                    cout << "Root Balance Factor: "
                         << balanceFactor(avlRoot) << "\n";

                    cout << "\nAVL Tree Preorder:\n";
                    preorder(avlRoot);
                }
                break;

            case 14:
                cout << "\nThank you for using Bus Route Management!\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while (choice != 14);

    return 0;
}

