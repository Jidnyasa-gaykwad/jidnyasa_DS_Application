Algorithm: AVL Rotation Demonstration (After Modification)
1. Start the program.
2. Initialize an empty AVL tree.
3. Display the menu with LL, RR, LR, RL rotation options and Exit.
4. Accept the user's choice.
5. Select the appropriate insertion sequence:
   - LL: 30, 20, 10
   - RR: 10, 20, 30
   - LR: 30, 10, 20
   - RL: 10, 30, 20
6. Insert the first two elements into the AVL tree.
7. Display the tree before the final insertion.
8. Store the inorder traversal of the tree.
9. Insert the third element into the tree.
10. Calculate the height and balance factor of each affected node.
11. Identify the rotation case and display the unbalanced node's balance factor.
12. Perform the appropriate rotation:
    - LL: Right rotation.
    - RR: Left rotation.
    - LR: Left rotation on the left child, followed by right rotation.
    - RL: Right rotation on the right child, followed by left rotation.
13. Display the final balanced AVL tree with the balance factors of its nodes.
14. Perform inorder traversal after rotation.
15. Compare the inorder traversal with the sorted sequence of inserted elements to verify that the BST property is preserved.
16. Display the verification result as PASSED or FAILED.
17. Return to the menu until the user selects Exit.
18. Stop the program.
