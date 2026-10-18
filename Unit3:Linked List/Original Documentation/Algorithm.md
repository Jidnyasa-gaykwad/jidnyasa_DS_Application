# Algorithm: Food Order Management System Using Doubly Linked List

## Step 1: Start
Start the program and initialize the predefined food menu, food prices, head pointer, tail pointer, and order ID counter.

## Step 2: Display Main Menu
Display the following options:
1. Add Food Order
2. Display All Orders
3. Display Orders in Reverse
4. Search Order
5. Cancel Order
6. Calculate Total Bill
7. Display Food Menu
8. Exit

## Step 3: Accept User Choice
Accept the user's choice and execute the corresponding operation using a switch statement.

## Step 4: Add Food Order
1. Display the predefined food menu with food names and prices.
2. Accept the food item number from the user.
3. Validate the food item number.
4. Accept the required quantity and validate it.
5. Create a new node dynamically.
6. Assign a unique Order ID, food item, quantity, and total amount.
7. Set the previous pointer to the current tail and the next pointer to NULL.
8. If the list is empty, set both head and tail to the new node.
9. Otherwise, link the current tail to the new node and update the tail pointer.
10. Display the order details and total amount.

## Step 5: Display All Orders
1. Check whether the linked list is empty.
2. If empty, display "No orders found".
3. Otherwise, start from the head pointer.
4. Traverse the list using the next pointer.
5. Display the Order ID, food name, quantity, and amount for each order.
6. Calculate and display the total bill of all orders.

## Step 6: Display Orders in Reverse
1. Check whether the linked list is empty.
2. If empty, display "No orders found".
3. Otherwise, start from the tail pointer.
4. Traverse the list using the previous pointer.
5. Display each order in reverse order.

## Step 7: Search Order
1. Accept the Order ID to search.
2. Start traversal from the head pointer.
3. Compare the Order ID of each node with the entered ID.
4. If a match is found, display the order details.
5. Otherwise, display "Order not found".

## Step 8: Cancel Order
1. Accept the Order ID to cancel.
2. Search for the order by traversing the list from the head.
3. If the order is found, update the previous and next pointers of the adjacent nodes.
4. If the first node is deleted, update the head pointer.
5. If the last node is deleted, update the tail pointer.
6. Delete the selected node and display a success message.
7. If the Order ID is not found, display "Order not found".

## Step 9: Calculate Total Bill
1. Initialize the total bill to zero.
2. Traverse the linked list from the head pointer.
3. Add the amount of each order to the total bill.
4. Display the final total bill.

## Step 10: Display Food Menu
Display all predefined food items and their prices.

## Step 11: Exit
If the user selects option 8, release the memory occupied by all remaining nodes, display the thank-you message, and terminate the program.

## Step 12: Stop
Stop the execution of the program.
