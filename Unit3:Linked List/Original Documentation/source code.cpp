
#include <iostream>
using namespace std;

struct Node
{
    int orderID;
    string foodName;
    int quantity;
    float amount;
    Node* next;
};

Node* head = NULL;
int idCounter = 1;

// Add a new food order
void addOrder()
{
    Node* newNode = new Node;

    newNode->orderID = idCounter++;

    cout << "Enter Food Name: ";
    cin >> newNode->foodName;

    cout << "Enter Quantity: ";
    cin >> newNode->quantity;

    cout << "Enter Total Amount: ";
    cin >> newNode->amount;

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "\nOrder Added Successfully!\n";
    cout << "Order ID: " << newNode->orderID << endl;
}

// Display all orders
void displayOrders()
{
    if (head == NULL)
    {
        cout << "\nNo Orders Available.\n";
        return;
    }

    Node* temp = head;

    cout << "\n----- Food Orders -----\n";

    while (temp != NULL)
    {
        cout << "\nOrder ID: " << temp->orderID;
        cout << "\nFood Name: " << temp->foodName;
        cout << "\nQuantity: " << temp->quantity;
        cout << "\nAmount: Rs. " << temp->amount << endl;

        temp = temp->next;
    }
}

// Search order by ID
void searchOrder()
{
    int id;
    cout << "Enter Order ID to Search: ";
    cin >> id;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->orderID == id)
        {
            cout << "\nOrder Found!\n";
            cout << "Order ID: " << temp->orderID << endl;
            cout << "Food Name: " << temp->foodName << endl;
            cout << "Quantity: " << temp->quantity << endl;
            cout << "Amount: Rs. " << temp->amount << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "\nOrder Not Found.\n";
}

// Delete order by ID
void deleteOrder()
{
    int id;
    cout << "Enter Order ID to Delete: ";
    cin >> id;

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->orderID != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "\nOrder Not Found.\n";
        return;
    }

    if (prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    delete temp;
    cout << "\nOrder Deleted Successfully!\n";
}

// Calculate total bill
void calculateBill()
{
    Node* temp = head;
    float total = 0;

    while (temp != NULL)
    {
        total += temp->amount;
        temp = temp->next;
    }

    cout << "\nTotal Bill: Rs. " << total << endl;
}

// Release allocated memory
void clearOrders()
{
    Node* temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== Food Order Management =====\n";
        cout << "1. Add Food Order\n";
        cout << "2. Display All Orders\n";
        cout << "3. Search Order\n";
        cout << "4. Delete Order\n";
        cout << "5. Calculate Total Bill\n";
        cout << "6. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addOrder();
                break;

            case 2:
                displayOrders();
                break;

            case 3:
                searchOrder();
                break;

            case 4:
                deleteOrder();
                break;

            case 5:
                calculateBill();
                break;

            case 6:
                clearOrders();
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}

