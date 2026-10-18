1. Start the program.
2. Define a node structure containing data, left pointer, right pointer, and height.
3. Initialize the AVL tree as empty.
4. Display the menu containing LL, RR, LR, RL rotations, and Exit.
5. Accept the user's choice.
6. Insert the elements according to the selected sequence:
   - LL: 30, 20, 10
   - RR: 10, 20, 30
   - LR: 30, 10, 20
   - RL: 10, 30, 20
7. Update the height of each node after insertion.
8. Calculate the balance factor using:
\[
BF = \text{Height(left)}-\text{Height(right)}
\]

9. Identify the unbalanced case:
   - LL: Perform a right rotation.
   - RR: Perform a left rotation.
   - LR: Perform a left rotation on the left child, followed by a right rotation.
   - RL: Perform a right rotation on the right child, followed by a left rotation.
10. Display the tree before and after the required rotation.
11. Display the final balanced AVL tree.
12. Repeat the menu until the user selects Exit.
13. Stop the program.
