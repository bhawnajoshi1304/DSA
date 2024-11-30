// Different tree traversal are: BFS/DFS.

    // There are three types of Depth First Search for trees:
    // Inorder Traversal - left root right
    // Preorder Traversal - root left right
    // Postorder Traversal - left right root

//           10
//       /        \
//      5           15
//    /   \       /    \
//   2     6    13      22 
//  /          /  \
// 1          12   14

    // In-Order Traversal:   1 2 5 6 10 12 13 14 15 22
    // Pre-Order Traversal:  10 5 2 1 6 15 13 12 14 22
    // Post-Order Traversal: 1 2 6 5 12 14 13 22 15 10

    // Time Complexity: O(n)
    // Space Complexity: O(n) | O(log n)


    // For Breadth First Search travels level wise in a tree also known as Level Order Traversal:
    // Level Order Traversal:  10 5 15 2 6 13 22 1 12 14