#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Order {
    int orderID;
    string customerName;
    string foodItem;
    int quantity;
};

int main() {
    queue<Order> orders;
    int choice;
    int orderID = 1;

    do {
        cout << "\n===== FOOD ORDER MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Food Order\n";
        cout << "2. Display All Orders\n";
        cout << "3. Process Order\n";
        cout << "4. Cancel First Order\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Order newOrder;

            newOrder.orderID = orderID++;

            cout << "Enter Customer Name: ";
            cin.ignore();
            getline(cin, newOrder.customerName);

            cout << "Enter Food Item: ";
            getline(cin, newOrder.foodItem);

            cout << "Enter Quantity: ";
            cin >> newOrder.quantity;

            orders.push(newOrder);

            cout << "\nOrder added successfully!\n";
            cout << "Order ID: " << newOrder.orderID << endl;
        }

        else if (choice == 2) {
            if (orders.empty()) {
                cout << "\nNo orders available.\n";
            }
            else {
                queue<Order> temp = orders;

                cout << "\n===== ALL ORDERS =====\n";

                while (!temp.empty()) {
                    Order current = temp.front();

                    cout << "\nOrder ID: " << current.orderID;
                    cout << "\nCustomer: " << current.customerName;
                    cout << "\nFood Item: " << current.foodItem;
                    cout << "\nQuantity: " << current.quantity << endl;

                    temp.pop();
                }
            }
        }

        else if (choice == 3) {
            if (orders.empty()) {
                cout << "\nNo order to process.\n";
            }
            else {
                Order current = orders.front();

                cout << "\nProcessing Order...\n";
                cout << "Order ID: " << current.orderID << endl;
                cout << "Customer: " << current.customerName << endl;
                cout << "Food Item: " << current.foodItem << endl;

                orders.pop();

                cout << "Order processed successfully!\n";
            }
        }

        else if (choice == 4) {
            if (orders.empty()) {
                cout << "\nNo order to cancel.\n";
            }
            else {
                cout << "\nOrder ID "
                     << orders.front().orderID
                     << " cancelled successfully.\n";

                orders.pop();
            }
        }

        else if (choice == 5) {
            cout << "\nThank you for using Food Order Management System!\n";
        }

        else {
            cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
