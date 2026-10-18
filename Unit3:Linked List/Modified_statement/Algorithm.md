**Step 1:** Start the program.

**Step 2:** Initialize the predefined food menu, food prices, `head = NULL`, `tail = NULL`, and Order ID counter.

**Step 3:** Display the main menu containing options to add orders, display orders, display reverse orders, search orders, cancel orders, calculate the bill, display the food menu, and exit.

**Step 4:** Accept the user's choice.

**Step 5:** If the choice is 1, display the predefined food menu, accept the food item number and quantity, validate the input, create a new node, assign a unique Order ID, calculate the amount, and insert the node at the end of the doubly linked list.

**Step 6:** If the choice is 2, traverse the list from `head` using the `next` pointer and display all order details and the total bill.

**Step 7:** If the choice is 3, traverse the list from `tail` using the `prev` pointer and display orders in reverse order.

**Step 8:** If the choice is 4, accept an Order ID, search the list, and display the order details if found; otherwise, display an error message.

**Step 9:** If the choice is 5, accept an Order ID, search for the order, update the previous and next pointers, delete the node if found, and display the cancellation message.

**Step 10:** If the choice is 6, traverse the list, add the amounts of all active orders, and display the total bill.

**Step 11:** If the choice is 7, display all predefined food items and their prices.

**Step 12:** If the choice is 8, release the memory occupied by all remaining nodes, display the thank-you message, and terminate the program.

**Step 13:** If the choice is invalid, display an appropriate error message.

**Step 14:** Repeat Steps 3–13 until the user selects option 8.

**Step 15:** Stop the program.
