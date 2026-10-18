#include <iostream>
#include <string>
using namespace std;

// Structure for bus route details
struct Bus
{
    int routeNo;
    string busName;
    string source;
    string destination;
};

// Binary Search Tree node
struct Node
{
    Bus bus;
    Node *left;
    Node *right;
};

// Predefined bus routes
Bus menuBuses[] =
{
    {101, "Shivneri", "Pune", "Mumbai"},
    {102, "Express", "Nashik", "Pune"},
    {103, "Citybus", "Mumbai", "Nashik"},
    {104, "Deccan", "Pune", "Nashik"},
    {105, "MSRTC", "Ahmednagar", "Pune"}
};

const int TOTAL_BUSES = 5;
Node *root = NULL;

// Create a new BST node
Node* createNode(Bus b)
{
    Node *newNode = new Node;
    newNode->bus = b;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a bus route into BST
Node* insertRoute(Node *root, Bus b)
{
    if (root == NULL)
        return createNode(b);

    if (b.routeNo < root->bus.routeNo)
        root->left = insertRoute(root->left, b);
    else if (b.routeNo > root->bus.routeNo)
        root->right = insertRoute(root->right, b);

    return root;
}

// Search for a bus route
Node* searchRoute(Node *root, int routeNo)
{
    if (root == NULL || root->bus.routeNo == routeNo)
        return root;

    if (routeNo < root->bus.routeNo)
        return searchRoute(root->left, routeNo);

    return searchRoute(root->right, routeNo);
}

// Display bus details
void displayBus(Bus b)
{
    cout << "\nRoute Number : " << b.routeNo;
    cout << "\nBus Name     : " << b.busName;
    cout << "\nSource       : " << b.source;
    cout << "\nDestination  : " << b.destination << endl;
}

// Find the smallest node
Node* findMin(Node *root)
{
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

// Find the largest node
Node* findMax(Node *root)
{
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

// Delete a bus route
Node* deleteRoute(Node *root, int routeNo)
{
    if (root == NULL)
        return NULL;

    if (routeNo < root->bus.routeNo)
    {
        root->left = deleteRoute(root->left, routeNo);
    }
    else if (routeNo > root->bus.routeNo)
    {
        root->right = deleteRoute(root->right, routeNo);
    }
    else
    {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // Case 2: One child
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node *temp = findMin(root->right);
        root->bus = temp->bus;
        root->right = deleteRoute(root->right,
                                  temp->bus.routeNo);
    }

    return root;
}

// Display routes in ascending order
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        displayBus(root->bus);
        cout << "-------------------------\n";
        inorder(root->right);
    }
}

// Display predefined bus menu
void displayBusMenu()
{
    cout << "\n======= AVAILABLE BUS ROUTES =======\n";

    for (int i = 0; i < TOTAL_BUSES; i++)
    {
        cout << i + 1 << ". Route No: "
             << menuBuses[i].routeNo
             << " | " << menuBuses[i].busName
             << " | " << menuBuses[i].source
             << " to " << menuBuses[i].destination
             << endl;
    }
}

// Add a predefined bus route
void addRoute()
{
    int choice;

    displayBusMenu();

    cout << "\nSelect a bus route (1-5): ";
    cin >> choice;

    if (choice < 1 || choice > TOTAL_BUSES)
    {
        cout << "\nInvalid selection!\n";
        return;
    }

    Bus b = menuBuses[choice - 1];

    if (searchRoute(root, b.routeNo) != NULL)
    {
        cout << "\nThis bus route already exists!\n";
        return;
    }

    root = insertRoute(root, b);

    cout << "\nBus route added successfully!\n";
    displayBus(b);
}

// Search operation
void searchBus()
{
    int routeNo;

    cout << "\nEnter route number to search: ";
    cin >> routeNo;

    Node *result = searchRoute(root, routeNo);

    if (result != NULL)
    {
        cout << "\nBus route found!\n";
        displayBus(result->bus);
    }
    else
    {
        cout << "\nBus route not found!\n";
    }
}

// Delete operation
void removeBus()
{
    int routeNo;

    cout << "\nEnter route number to delete: ";
    cin >> routeNo;

    if (searchRoute(root, routeNo) == NULL)
    {
        cout << "\nBus route not found!\n";
        return;
    }

    root = deleteRoute(root, routeNo);

    cout << "\nBus route deleted successfully!\n";
}

// Minimum route
void displayMinimum()
{
    Node *temp = findMin(root);

    if (temp == NULL)
        cout << "\nNo bus routes available!\n";
    else
    {
        cout << "\nMinimum Route Number:\n";
        displayBus(temp->bus);
    }
}

// Maximum route
void displayMaximum()
{
    Node *temp = findMax(root);

    if (temp == NULL)
        cout << "\nNo bus routes available!\n";
    else
    {
        cout << "\nMaximum Route Number:\n";
        displayBus(temp->bus);
    }
}

// Free allocated memory
void freeTree(Node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
}

// Main function
int main()
{
    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << "   BUS ROUTE MANAGEMENT SYSTEM\n";
        cout << "       Using Binary Search Tree\n";
        cout << "====================================\n";
        cout << "1. Add Bus Route\n";
        cout << "2. Search Bus Route\n";
        cout << "3. Delete Bus Route\n";
        cout << "4. Display Routes in Sorted Order\n";
        cout << "5. Find Minimum Route Number\n";
        cout << "6. Find Maximum Route Number\n";
        cout << "7. Exit\n";
        cout << "====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addRoute();
                break;

            case 2:
                searchBus();
                break;

            case 3:
                removeBus();
                break;

            case 4:
                if (root == NULL)
                {
                    cout << "\nNo bus routes available!\n";
                }
                else
                {
                    cout << "\n======= BUS ROUTES IN SORTED ORDER =======\n";
                    inorder(root);
                }
                break;

            case 5:
                displayMinimum();
                break;

            case 6:
                displayMaximum();
                break;

            case 7:
                cout << "\nExiting Bus Route Management System.\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 7);

    freeTree(root);
    root = NULL;

    return 0;
}
