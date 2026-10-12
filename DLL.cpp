
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int N = 6;

string food[N] = {
    "Pizza", "Burger", "Sandwich",
    "French Fries", "Dosa", "Cold Coffee"
};

int price[N] = {150, 80, 60, 70, 50, 90};

struct Node
{
    int orderID;
    int item;
    int quantity;
    int amount;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;
int idCounter = 1;

void displayMenu()
{
    cout << "\n========== FOOD MENU ==========\n";
    cout << "No.\tFood Name\tPrice\n";
    cout << "--------------------------------\n";

    for (int i = 0; i < N; i++)
    {
        cout << i + 1 << "\t"
             << food[i] << "\tRs. "
             << price[i] << endl;
    }

    cout << "================================\n";
}

void placeOrder()
{
    int choice, quantity;

    // Show the predefined menu first
    displayMenu();

    cout << "Select food number (1-6): ";
    cin >> choice;

    if (choice < 1 || choice > N)
    {
        cout << "Invalid food number!\n";
        return;
    }

    cout << "Enter quantity: ";
    cin >> quantity;

    if (quantity <= 0)
    {
        cout << "Invalid quantity!\n";
        return;
    }

    Node* newNode = new Node;

    newNode->orderID = idCounter++;
    newNode->item = choice - 1;
    newNode->quantity = quantity;
    newNode->amount = price[choice - 1] * quantity;
    newNode->prev = tail;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        tail->next = newNode;
    }

    tail = newNode;

    cout << "\nOrder added successfully!\n";
    cout << "Order ID: " << newNode->orderID << endl;
    cout << "Food: " << food[newNode->item] << endl;
    cout << "Price: Rs. " << price[newNode->item] << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Total Amount: Rs. "
         << newNode->amount << endl;
}

void displayOrders()
{
    Node* temp = head;

    if (temp == NULL)
    {
        cout << "\nNo orders found!\n";
        return;
    }

    cout << "\n========== ALL ORDERS ==========\n";
    int total = 0;

    while (temp != NULL)
    {
        cout << "Order ID: " << temp->orderID
             << " | Food: " << food[temp->item]
             << " | Quantity: " << temp->quantity
             << " | Amount: Rs. " << temp->amount
             << endl;

        total += temp->amount;
        temp = temp->next;
    }

    cout << "Total Bill: Rs. " << total << endl;
}

void displayReverse()
{
    Node* temp = tail;

    if (temp == NULL)
    {
        cout << "\nNo orders found!\n";
        return;
    }

    cout << "\n======= REVERSE ORDER LIST =======\n";

    while (temp != NULL)
    {
        cout << "Order ID: " << temp->orderID
             << " | Food: " << food[temp->item]
             << " | Quantity: " << temp->quantity
             << " | Amount: Rs. " << temp->amount
             << endl;

        temp = temp->prev;
    }
}

void searchOrder()
{
    int id;
    cout << "Enter Order ID to search: ";
    cin >> id;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->orderID == id)
        {
            cout << "Order found: "
                 << food[temp->item]
                 << ", Quantity: " << temp->quantity
                 << ", Amount: Rs. " << temp->amount
                 << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Order not found!\n";
}

void cancelOrder()
{
    int id;
    cout << "Enter Order ID to cancel: ";
    cin >> id;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->orderID == id)
        {
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            else
                tail = temp->prev;

            delete temp;
            cout << "Order cancelled successfully!\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Order not found!\n";
}

void calculateBill()
{
    Node* temp = head;
    int total = 0;

    while (temp != NULL)
    {
        total += temp->amount;
        temp = temp->next;
    }

    cout << "Total Bill: Rs. " << total << endl;
}

void clearOrders()
{
    Node* temp = head;

    while (temp != NULL)
    {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    head = NULL;
    tail = NULL;
}

int main()
{
    int choice;

    do
    {
        cout << "\n================================\n";
        cout << " FOOD ORDER MANAGEMENT SYSTEM\n";
        cout << "================================\n";
        cout << "1. Add Food Order\n";
        cout << "2. Display All Orders\n";
        cout << "3. Display Orders in Reverse\n";
        cout << "4. Search Order\n";
        cout << "5. Cancel Order\n";
        cout << "6. Calculate Total Bill\n";
        cout << "7. Display Food Menu\n";
        cout << "8. Exit\n";
        cout << "================================\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                placeOrder();
                break;

            case 2:
                displayOrders();
                break;

            case 3:
                displayReverse();
                break;

            case 4:
                searchOrder();
                break;

            case 5:
                cancelOrder();
                break;

            case 6:
                calculateBill();
                break;

            case 7:
                displayMenu();
                break;

            case 8:
                clearOrders();
                cout << "Thank you!\n";
                break;

            default:
                cout << "Invalid choice! Enter 1 to 8.\n";
        }

    } while (choice != 8);

    return 0;
}

